// Problem: I. Imperial roads
// Contest: Codeforces - 2017-2018 ACM-ICPC Latin American Regional Programming Contest
// URL: https://codeforces.com/gym/101889/problem/I
// Memory Limit: 256 MB
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m, log_n, tot;
vpii adj[NMAX];
iii edge[NMAX];
int pp[NMAX];
map<pii, int> mp;
int par[NMAX][LOG_MAX];
int par_mx[NMAX][LOG_MAX];
int depth[NMAX];

int get_pp(int u){
	return pp[u] = (pp[u]==u) ? u : get_pp(pp[u]);
}

bool merge(int u, int v){
	
	u = get_pp(u);
	v = get_pp(v);
	
	if(u==v){
		return false;
	}
	
	if(rand()&1) swap(u, v);
	
	pp[u] = v;
	
	return true;
}

void dfs(int u, int p){
	
	for(auto [v, w] : adj[u]) if(v != p){
		
		depth[v] = depth[u]+1;
		
		par[v][0] = u;
		for(int i = 1; i < log_n; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}	
		
		par_mx[v][0] = w;
		for(int i = 1; i < log_n; i++){
			par_mx[v][i] = max(par_mx[par[v][i-1]][i-1], par_mx[v][i-1]);
		}
		
		dfs(v, u);
	}
}

pii lca(int u, int v){
	
	if(depth[u] < depth[v]){
		swap(u, v);
	}	
	
	int mx = 0;
	
	int dif = depth[u] - depth[v];
	for(int i = 0; i < log_n; i++) if((dif>>i)&1){
		mx = max(mx, par_mx[u][i]);
		u = par[u][i];
	}
	
	if(u==v) return {u, mx};
	
	for(int i = log_n-1; i >= 0; i--) if(par[u][i] != par[v][i]){
		mx = max(mx, par_mx[u][i]);
		mx = max(mx, par_mx[v][i]);
		u = par[u][i];
		v = par[v][i];
	}
	
	return {par[u][0], max(mx, max(par_mx[v][0], par_mx[u][0]))};
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    log_n = ceil(log2(double(n)));
    
    for(int i = 0; i < m; i++){
    	
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	if(u > v) swap(u, v);
    	
    	edge[i] = {w, {u, v}};
		mp[{u, v}] = w;
    }
    
    sort(edge, edge+m);
    iota(pp, pp+n, 0);
    
    for(int i = 0; i < m; i++){
    	
    	auto e = edge[i];
    	int w = e.first;
    	int u = e.second.first;
    	int v = e.second.second;
    	
    	if(merge(u, v)){
    		adj[u].push_back({v, w});
    		adj[v].push_back({u, w});
    		tot += w;
    	}
    }
    
    dfs(0, -1);
    
    int q; cin >> q; while(q--){
    	
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	if(u > v) swap(u, v);
    	
    	int ans = tot;
    	pii p = lca(u, v);
		ans += mp[{u, v}];	
	    ans -= p.second;    
    	
    	cout << ans << endl;
    }
}