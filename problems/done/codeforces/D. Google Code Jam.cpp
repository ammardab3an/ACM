// Problem: D. Google Code Jam
// Contest: Codeforces - Codeforces Round #170 (Div. 1)
// URL: https://codeforces.com/contest/277/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 2e3 + 10;
typedef long double dtype;

int n, max_t;

struct struct_e{
	int scoreSmall, scoreLarge;
	int timeSmall, timeLarge;
	dtype probFail;
} arr[NMAX];

struct struct_p{
	dtype expectedScore;
	dtype expectedTime;
	dtype consumedTime;
} mem[NMAX][NMAX];

bool vis[NMAX][NMAX];

struct_p comp(const struct_p &a, const struct_p &b){
	if(abs(a.expectedScore-b.expectedScore) > EPS){
		return a.expectedScore > b.expectedScore ? a : b;
	}
	else{
		return a.expectedTime < b.expectedTime ? a : b;
	}
}

struct_p go(int i, int rm){
	
	if(i == n){
		return {0, 0, 0};
	}	
	
	auto &ret = mem[i][rm];
	if(vis[i][rm]) return ret;
	vis[i][rm] = true;
	
	auto ans = go(i+1, rm);

	if(rm >= arr[i].timeSmall){
		auto nxt = go(i+1, rm-arr[i].timeSmall);
		nxt.expectedScore += arr[i].scoreSmall;
		nxt.expectedTime += arr[i].timeSmall;
		nxt.consumedTime += arr[i].timeSmall;
		ans = comp(ans, nxt);
	}
	
	if(rm >= (arr[i].timeSmall+arr[i].timeLarge)){
		
		auto nxt = go(i+1, rm-(arr[i].timeSmall + arr[i].timeLarge));
		
		nxt.expectedScore += arr[i].scoreSmall;
		nxt.expectedTime += arr[i].timeSmall;
		nxt.consumedTime += arr[i].timeSmall;
		
		nxt.expectedScore += arr[i].scoreLarge * (dtype(1.0)-arr[i].probFail);
		nxt.expectedTime *= arr[i].probFail;
		nxt.expectedTime += (nxt.consumedTime + arr[i].timeLarge) * (dtype(1.0)-arr[i].probFail);
		nxt.consumedTime += arr[i].timeLarge;
		
		ans = comp(ans, nxt);
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> max_t;
    
    for(int i = 0; i < n; i++){
    	cin >> arr[i].scoreSmall;
    	cin >> arr[i].scoreLarge;
    	cin >> arr[i].timeSmall;
    	cin >> arr[i].timeLarge;
    	cin >> arr[i].probFail;
    }
    
	sort(arr, arr+n, [](const struct_e &a, const struct_e &b){
		return a.timeLarge*a.probFail*(dtype(1.0)-b.probFail) < 
			   b.timeLarge*b.probFail*(dtype(1.0)-a.probFail);
	});
	
	reverse(arr, arr+n);
	
	struct_p ans = go(0, max_t);
	cout << fixed << setprecision(10) << ans.expectedScore << endl;
	cout << fixed << setprecision(10) << ans.expectedTime << endl;
}

    /*
    
    1- its better to do small tasks before large tasks
    	so we should but all tasks with 0 fail prob at first, and other last,
    	
    now what about 0 <= p <= 1
    
    2- if we have two elements ai and aj then: (i <= j)
    
    	(ai.timeLarge + aj.timeLarge).(1-aj.probFail) + ai.timeLarge.(1-ai.probFail).aj.probFail
    	<
    	(aj.timeLarge + ai.timeLarge).(1-ai.probFail) + aj.timeLarge.(1-aj.probFail).ai.probFail
    	
    	=>
    	
    	(ai.timeLarge + aj.timeLarge).(-aj.probFail) + ai.timeLarge.(1-ai.probFail).aj.probFail
    	<
    	(aj.timeLarge + ai.timeLarge).(-ai.probFail) + aj.timeLarge.(1-aj.probFail).ai.probFail
    	
    	=>
    	
    	-ai.timeLarge.aj.probFail -aj.timeLarge.aj.probFail + ai.timeLarge.aj.probFail -ai.timeLarge.ai.probFail.aj.probFail
    	<
    	-aj.timeLarge.ai.probFail -ai.timeLarge.ai.probFail + aj.timeLarge.ai.probFail -aj.timeLarge.aj.probFail.ai.probFail
    	
    	=>
    	
    	-aj.timeLarge.aj.probFail -ai.timeLarge.ai.probFail.aj.probFail
    	<
    	-ai.timeLarge.ai.probFail -aj.timeLarge.aj.probFail.ai.probFail
    	
    	=>
    	
    	ai.timeLarge.ai.probFail + aj.timeLarge.aj.probFail.ai.probFail
    	<
    	aj.timeLarge.aj.probFail + ai.timeLarge.ai.probFail.aj.probFail
    	
    	=>
    	
    	ai.timeLarge.ai.probFail - ai.timeLarge.ai.probFail.aj.probFail 
    	<
    	aj.timeLarge.aj.probFail - aj.timeLarge.aj.probFail.ai.probFail
    	
    	=>
    	
    	ai.timeLarge.ai.probFail . (1-aj.probFail) 
    	<
    	aj.timeLarge.aj.probFail . (1-ai.probFail) 
    	
    	=>
    	
    	ai.timeLarge.ai.probFail / (1-ai.probFail) 
    	<
    	aj.timeLarge.aj.probFail / (1-aj.probFail) 
    	
    */