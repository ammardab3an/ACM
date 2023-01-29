// Problem: F. Timofey and Black-White Tree
// Contest: Codeforces - Codeforces Round #847 (Div. 3)
// URL: https://codeforces.com/contest/1790/problem/F
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

int n, m, LOG;
set<int> adj[NMAX];
int depth[NMAX], sz[NMAX], par[NMAX][LOG_MAX], cpar[NMAX];
int ans[NMAX];

// init ----------------------------------  

void dfs0(int u, int p){
    
    for(auto nxt : adj[u]) if(nxt != p){
        
        depth[nxt] = depth[u]+1;
        
        par[nxt][0] = u;
        for(int i = 1; i < LOG; i++)
            par[nxt][i] = par[par[nxt][i-1]][i-1];
        
        dfs0(nxt, u);
    }    
}

void preprocess(){
    LOG = ceil(log2(double(n)));    
    dfs0(0, -1);
}

int lca(int u, int v){
    
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i = 0; i < LOG; i++) if(diff & (1<<i))
        u = par[u][i];
    if(u == v) return u;
    for(int i = LOG-1; i >= 0; i--) if(par[u][i] != par[v][i])
        u = par[u][i], v = par[v][i];
    return par[u][0];    
}

int dist(int u, int v){
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

// decompose -------------------------------

int nn;
void dfs1(int u, int p){
    
    nn++;
    sz[u] = 1;
    for(auto nxt : adj[u]) if(nxt != p){
        dfs1(nxt, u);
        sz[u] += sz[nxt];
    }
}

int dfs2(int u, int p){
    
    for(auto nxt : adj[u]) if(nxt != p) if(sz[nxt] > nn/2)
        return dfs2(nxt, u);
    
    return u;
}

void decompose(int u, int p){
    
    nn = 0;
    dfs1(u, u);
    
    int centroid = dfs2(u, u);
    if(p == -1) p = centroid;    
    cpar[centroid] = p;
    
    for(auto nxt : adj[centroid]){
        adj[nxt].erase(centroid);
        decompose(nxt, centroid);
    }
    
    adj[u].clear();
}

// queries ---------------------------------

void update(int u){
    
    int x = u;
    
    while(true){
    	
    	// cout << u+1 << ' ' << x+1 << ' ' << dist(x, u) << endl;
    	
        ans[x] = min(ans[x], dist(x, u));
    	
        if(x == cpar[x]) break;
        x = cpar[x];
    }    
}

int query(int u){
    
    int x = u;
    int ret = INF;
    
    while(true){
    	
    	if(u != x){		
	        ret = min(ret, dist(u, x) + ans[x]);
    	}
    	else{
    		ret = min(ret, ans[x]);
    	}
    	
    	// cout << ' ' << u+1 << ' ' << x+1 << ' ' << dist(u, x) << ' ' << ans[x] << endl;
    	
        if(x == cpar[x]) break;
        x = cpar[x];
    }
    
    return ret;
}

int32_t main(){
    
    int t; cin >> t; while(t--){
    	
	    cin >> n >> m;
	    m--;
	    
	    for(int i = 0; i <= n; i++){
	    	adj[i].clear();
	    	ans[i] = INF;
	    }
	    
	    vi tmp(n-1);
	    for(auto &i : tmp) cin >> i, i--;
	    
	    for(int i = 0; i < n-1; i++){
	        
	        int u, v;
	        cin >> u >> v;
	        u--, v--;
	        
	        adj[u].insert(v);
	        adj[v].insert(u);
	    }
	    
	    
	    preprocess();
	    decompose(0, -1);
	    
	    // for(int i = 0; i < n; i++){
	    	// cout << depth[i] << ' '; 
	    // } cout << endl;
	    // cout << endl;
	    
	    update(m);
	    
	    int mn = INF;
	    
	    for(auto i : tmp){
	    	
	        mn = min(mn, query(i));
	        update(i);
	        
	        cout << mn << ' ';
	        
	        // for(int i = 0; i < n; i++){
	        	// cout << ans[i] << ' ';
	        // }cout << endl;
	        // cout << endl;
	    }
	    
	    cout << endl;
    }
}
