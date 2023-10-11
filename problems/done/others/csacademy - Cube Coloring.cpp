// Problem: Cube Coloring
// Contest: CS Academy
// URL: https://csacademy.com/contest/archive/task/cube-coloring/
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int choose(int n, int c){
	
	if(c > n) return 0;
	
	int ret = 1;
	for(int i = 0; i < c; i++){
		ret *= n-i;
		ret /= i+1;
	}
	
	return ret;
}

int factorial(int n){
	
	if(n < 0) return 0;
	
	int ret = 1;
	for(int i = 2; i <= n; i++){
		ret *= i;
	}
	
	return ret;
}

int n, ans;
int ob[6], cnt[2];
vector<vi> mvs;

vi vals(6, -1);
void go(int i, int col, int cnt_2){
	
	if(i==6){
		
		int cur = 0;
		for(auto &v : mvs){
			vi nvals(6);
			for(int i = 0; i < 6; i++){
				nvals[i] = vals[v[i]];
			}
			if(nvals==vals){
				cur++;
			}
		}
		
		int c0 = choose(cnt[1], cnt_2) * factorial(cnt_2);
		int c1 = choose(n-cnt_2, col-cnt_2) * factorial(col-cnt_2);
		ans += cur * c0 * c1;
		
		return;
	}
	
	if(vals[i] != -1){
		go(i+1, col, cnt_2);
		return;
	}
	
	if(vals[i]==-1){
		vals[i] = col;
		go(i+1, col+1, cnt_2);
		vals[i] = -1;
	}
	
	if(vals[i]==-1 && vals[ob[i]]==-1) {
		vals[i] = vals[ob[i]] = col;
		go(i+1, col+1, cnt_2+1);
		vals[i] = vals[ob[i]] = -1;
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	ob[0] = 5;
	ob[5] = 0;
	ob[1] = 3;
	ob[3] = 1;
	ob[2] = 4;
	ob[4] = 2;
	
	mvs = {
		{0, 1, 2, 3, 4, 5},
		{0, 2, 3, 4, 1, 5},
		{0, 3, 4, 1, 2, 5},
		{0, 4, 1, 2, 3, 5},
		{5, 1, 4, 3, 2, 0},
		{5, 4, 3, 2, 1, 0},
		{5, 3, 2, 1, 4, 0},
		{5, 2, 1, 4, 3, 0},
		{1, 5, 2, 0, 4, 3},
		{1, 2, 0, 4, 5, 3},
		{1, 0, 4, 5, 2, 3},
		{1, 4, 5, 2, 0, 3},
		{3, 4, 0, 2, 5, 1},
		{3, 0, 2, 5, 4, 1},
		{3, 2, 5, 4, 0, 1},
		{3, 5, 4, 0, 2, 1},
		{2, 0, 1, 5, 3, 4},
		{2, 1, 5, 3, 0, 4},
		{2, 5, 3, 0, 1, 4},
		{2, 3, 0, 1, 5, 4},	
		{2, 3, 5, 1, 0, 4},
		{2, 5, 1, 0, 3, 4},
		{2, 1, 0, 3, 5, 4},
		{2, 0, 3, 5, 1, 4},
	};
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int ai;
		cin >> ai;
		if(ai==1){
			cnt[0]++;
		}
		else if(ai >= 2){
			cnt[1]++;
		}
	}
	
	go(0, 0, 0);
	assert(ans%24==0);
	cout << ans/24 << endl;
}
