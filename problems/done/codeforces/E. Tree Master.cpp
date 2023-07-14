#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// Problem: E. Tree Master
// Contest: Codeforces - Codeforces Round 858 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1806/E
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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
const int NMAX = 1e5 + 10;
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

int choose(int n, int c){
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

vi adj[NMAX];
int arr[NMAX];
int narr[NMAX];
int sub[NMAX];
int tin[NMAX], tim;
int par_hld[NMAX];
int depth[NMAX];
int par[NMAX];
int itin[NMAX];

void dfs0(int u, int p){
	
	sub[u] = 1;
	for(auto &v : adj[u]){
		
		dfs0(v, u);
		sub[u] += sub[v];
		
		if(sub[v] > sub[adj[u][0]]){
			swap(v, adj[u][0]);
		}
	}
}

void dfs1(int u, int p){
	
	if(p==-1 || adj[p][0]!=u){
		par_hld[u] = u;	
	}
	else{
		par_hld[u] = par_hld[p];
	}
	
	tin[u] = tim++;
	itin[tin[u]] = u;
	narr[tin[u]] = arr[u];
	par[u] = p;
	
	for(auto v : adj[u]){
		depth[v] = depth[u]+1;
		dfs1(v, u);
	}	
}

int64_t calc(int u, int v){
	
	int64_t ret = 0;
	int cnt = 0;
	
	while(u != -1){
		
		cnt++;
		assert(cnt < 17);
			
		int pu = par_hld[u];
		int pv = par_hld[v];
		
		if(depth[pu] < depth[pv]){
			swap(u, v);
			swap(pu, pv);
		}
		
		int dif = depth[pu] - depth[pv];
		int len = depth[u] - depth[pu] + 1;
		
		int i = tin[pu];
		int j = tin[pv] + dif;
		
		while(len--){
			ret += narr[i] *1ll* narr[j];
			i++, j++;
		}
		
		u = par[pu];
		v = par[itin[tin[pv]+dif]];
	}
	
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	for(int i = 1; i < n; i++){
		int pi;
		cin >> pi;
		adj[pi-1].push_back(i);
	}
	
	dfs0(0, -1);
	dfs1(0, -1);
	
	while(m--){
		
		int u, v;
		cin >> u >> v;
		u--, v--;
		
		cout << calc(u, v) << endl;
	}
}
