// Problem: K. Another Shortest Path Problem
// Contest: Codeforces - ACM International Collegiate Programming Contest, Damascus University Collegiate Programming Contest(2018)
// URL: https://codeforces.com/gym/101808/problem/K
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
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
vpii adj[NMAX];
int par[NMAX][LOG_MAX], par_sm[NMAX][LOG_MAX];
int depth[NMAX], vis[NMAX], vid;
int su, sv, sw;

void dfs(int u, int p){
    
    vis[u] = vid;
    
    for(auto pp : adj[u]) {
        
        int v = pp.first;
        int w = pp.second;
        
        if(v == p) continue;
         
        if(vis[v] == vid){
            su = u;
            sv = v;
            sw = w;
            continue;
        }
        
        depth[v] = depth[u] + 1;
        
        par[v][0] = u;
        for(int i = 1; i < log_n; i++){
            par[v][i] = par[par[v][i-1]][i-1];
        }
        
        par_sm[v][0] = w;
        for(int i = 1; i < log_n; i++){
            par_sm[v][i] = par_sm[par[v][i-1]][i-1] + par_sm[v][i-1];
        }
        
        dfs(v, u);
    }
}

int lca(int u, int v){
    
    if(depth[u] < depth[v]) swap(u, v);
    
    int sm_u = 0, sm_v = 0;
    
    int dif = depth[u] - depth[v];
    for(int i = 0; i < log_n; i++) if(dif&(1<<i)){
        sm_u += par_sm[u][i];
        u = par[u][i];
    }    
    
    if(u == v) return sm_u;
    
    for(int i = log_n-1; i >= 0; i--) if(par[u][i] != par[v][i]){
        sm_u += par_sm[u][i];
        sm_v += par_sm[v][i];
        u = par[u][i];
        v = par[v][i];
    }
    
    return sm_u + sm_v + par_sm[u][0] + par_sm[v][0];
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        cin >> n >> m;
        
        log_n = ceil(log2(double(n)));
        
        for(int i = 0; i < n; i++){
            adj[i].clear();
        }
        
        for(int i = 0; i < n; i++){
            
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vid++;
        dfs(0, -1);
        
        while(m--){
            
            int u, v;
            cin >> u >> v;
            u--, v--;
            
            int stPath = lca(u, v);
            int ndPath = lca(u, su) + lca(v, sv) + sw;
            int rdPath = lca(u, sv) + lca(v, su) + sw;
            
            cout << min({stPath, ndPath, rdPath}) << endl;
        }
    }	
}
