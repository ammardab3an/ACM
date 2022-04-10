// Problem: Counting Paths
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1136
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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

int n, m, log_n;
vi adj[NMAX];
int depth[NMAX];
int par[NMAX][LOG_MAX];
int tmp[NMAX];
int ans[NMAX];

void dfs(int u, int p){
	
	for(auto v : adj[u]) if(v != p){
		
		depth[v] = depth[u]+1;
		
		par[v][0] = u;
		for(int i = 1; i < log_n; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}
		
		dfs(v, u);
	}
}

int lca(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	int dif = depth[u] - depth[v];
	for(int i = 0; i < log_n; i++) if((dif>>i)&1) u = par[u][i];
	if(u==v) return u;
	for(int i = log_n-1; i >= 0; i--) if(par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
	return par[u][0];	
}

void dfs2(int u, int p){
	
	ans[u] = tmp[u];
	
	for(auto v : adj[u]) if(v != p){
		dfs2(v, u);
		ans[u] += ans[v];	
	}	
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    log_n = ceil(log2(double(n)));
    dfs(0, -1);
    
    while(m--){
    	
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	
    	tmp[u]++;
    	tmp[v]++;
    	
    	int g = lca(u, v);
    	
    	tmp[g]--;
    	
    	if(g != 0){
    		tmp[par[g][0]]--;			
    	}
    }
    
    dfs2(0, -1);
    
    for(int i = 0; i < n; i++){
    	cout << ans[i] << ' ';
    }
}
