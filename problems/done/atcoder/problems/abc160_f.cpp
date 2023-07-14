// Problem: F - Distributing Integers
// Contest: AtCoder - AtCoder Beginner Contest 160
// URL: https://atcoder.jp/contests/abc160/tasks/abc160_f
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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

int fac[NMAX], ifac[NMAX];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

vi adj[NMAX];
int sz[NMAX];
int val[NMAX];
int ans[NMAX];

void dfs(int u, int p){
	
	sz[u] = 1;
	int cval = 1;
	
	for(auto v : adj[u]) if(v != p){
		dfs(v, u);
		sz[u] += sz[v];
		cval = mul(cval, mul(val[v], ifac[sz[v]]));
	}	
	
	cval = mul(cval, fac[sz[u]-1]);
	val[u] = cval;
}

void go(int u, int p){
	
	ans[u] = val[u];
	
	for(auto v : adj[u]) if(v != p){
		
		val[u] = mul(val[u], ifac[sz[u]-1]);
		sz[u] -= sz[v];
		val[u] = mul(val[u], fac[sz[u]-1]);
		val[u] = mul(val[u], mul(inv(val[v]), fac[sz[v]]));
		
		val[v] = mul(val[v], ifac[sz[v]-1]);
		sz[v] += sz[u];
		val[v] = mul(val[v], fac[sz[v]-1]);
		val[v] = mul(val[v], mul(val[u], ifac[sz[u]]));
		
		go(v, u);
		
		val[v] = mul(val[v], ifac[sz[v]-1]);
		sz[v] -= sz[u];
		val[v] = mul(val[v], fac[sz[v]-1]);
		val[v] = mul(val[v], mul(inv(val[u]), fac[sz[u]]));
		
		val[u] = mul(val[u], ifac[sz[u]-1]);
		sz[u] += sz[v];
		val[u] = mul(val[u], fac[sz[u]-1]);
		val[u] = mul(val[u], mul(val[v], ifac[sz[v]]));
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    init();
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    dfs(0, -1);
    go(0, -1);
    
    for(int i = 0; i < n; i++){
    	cout << ans[i] << endl;
    }
}
