// Problem: K. Zigzags
// Contest: Codeforces - Practice Round
// URL: https://starcontest22.contest.codeforces.com/group/ZbfYu7B821/contest/378187/problem/K
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
int arr[NMAX];
int mem[NMAX][2];

int go(int i, bool b){
	
	if(i==n){
		return 0;
	}	
	
	int &ret = mem[i][b];
	if(ret+1) return ret;
	
	int ans = n-i-1;
	
	for(int j = i+1; j < n; j++){
		if(!b && arr[i] < arr[j]){
			ans = min(ans, j-i-1 + go(j, !b));
		}
		else if(b && arr[i] > arr[j]){
			ans = min(ans, j-i-1 + go(j, !b));
		}
	}
	
	return ret = ans;
}

vi calc_res;

void calc(int i, bool b){
		
	int ans = go(i, b);
	
	if(ans == n-i-1){
		for(int j = i+1; j < n; j++){
			calc_res.push_back(j);
		}
		return;
	}
	
	int p=-1;
	
	for(int j = i+1; j < n; j++){
		
		if(!b && arr[i] < arr[j] && (ans==(j-i-1 + go(j, !b)))){
			p = j;
			break;		
		}
		else if(b && arr[i] > arr[j] && (ans==(j-i-1 + go(j, !b)))){
			p = j;
			break;
		}
	}
	
	assert(p != -1);
	
	for(int j = i+1; j < p; j++){
		calc_res.push_back(j);
	}
	
	calc(p, !b);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    memset(mem, -1, sizeof mem);
    
    pii p;
    int ans = INFLL;
    
    for(int i = 0; i < n; i++){
    	
    	if(i+go(i, 0) < ans){
    		ans = i+go(i, 0);
    		p = {i, 0};
    	}
    	if(i+go(i, 1) < ans){
    		ans = i+go(i, 1);
    		p = {i, 1};
    	}
    }
    
    calc(p.first, p.second);
    
    cout << calc_res.size() << endl;
    for(auto i : calc_res) cout << i+1 << ' '; cout << endl;
}
