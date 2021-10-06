// Problem: F. Best Edge Weight
// Contest: Codeforces - Codeforces Round #423 (Div. 2, rated, based on VK Cup Finals)
// URL: https://codeforces.com/problemset/problem/828/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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

struct edge{
    int u, v, c, i;
    bool operator < (const edge &other){
        return c < other.c;
    }
};

int n, m, log_n;
edge edges[NMAX];
vector<edge> adj[NMAX];
int idx[NMAX];

int dsu_par[NMAX], ans[NMAX];

int par[NMAX][LOG_MAX], par_mx[NMAX][LOG_MAX];
int sz[NMAX], depth[NMAX];

int link[NMAX];

int compress(int u, int p, int c){
    if(depth[u] <= depth[p]) return u; 
    ans[idx[u]] = min(ans[idx[u]], c);
    return link[u] = compress(link[par[u][0]], p, c);
}

int get_par(int u){
    return dsu_par[u] = dsu_par[u] == u ? u : get_par(dsu_par[u]);
}

bool merge(int u, int v){
    
    int par_u = get_par(u);
    int par_v = get_par(v);
    
    if(par_u == par_v) return false;
    
    if(rand()&1) swap(par_u, par_v);
    
    dsu_par[par_u] = par_v;
    
    return true;
}

int lca(int u, int v){
    
    if(depth[u] < depth[v]) swap(u, v);
    
    int dif = depth[u] - depth[v];
    for(int i = 0; i < log_n; i++) if(dif&(1<<i)){
        u = par[u][i];
    }
    
    if(u == v) return u;
    
    for(int i = log_n-1; i >= 0; i--) if(par[u][i] != par[v][i]){
        u = par[u][i], v = par[v][i];
    }
    
    return par[u][0];    
}

int lca_get_max(int u, int v){
    
    if(depth[u] < depth[v]) swap(u, v);
    
    int mx_u = 0, mx_v = 0;
    int dif = depth[u] - depth[v];
    
    for(int i = 0; i < log_n; i++) if(dif&(1<<i)){    
        mx_u = max(mx_u, par_mx[u][i]);
        u = par[u][i];
    }
    
    if(u == v) return mx_u;
    
    for(int i = log_n-1; i >= 0; i--) if(par[u][i] != par[v][i]){    
        mx_u = max(mx_u, par_mx[u][i]);
        mx_v = max(mx_v, par_mx[v][i]);
        u = par[u][i], v = par[v][i];
    }
    
    mx_u = max(mx_u, par_mx[u][0]);
    mx_v = max(mx_v, par_mx[v][0]);
    
    return max(mx_u, mx_v);           
}

void dfs(int u, int p){
    
    sz[u] = 1;
    
    for(auto e : adj[u]) if(e.v != p){
        
        int v = e.v;
        idx[v] = e.i;
        
        depth[v] = depth[u] + 1;
        
        par[v][0] = u;
        for(int i = 1; i < log_n; i++){
            par[v][i] = par[par[v][i-1]][i-1];
        }
        
        par_mx[v][0] = e.c;
        for(int i = 1; i < log_n; i++){
            par_mx[v][i] = max(par_mx[par[v][i-1]][i-1], par_mx[v][i-1]);
        }
        
        dfs(v, u);
        
        sz[u] += sz[v];
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
    
    // init
    log_n = ceil(log2(double(n)));
    iota(link, link+n, 0);
    iota(dsu_par, dsu_par+n, 0);
    memset(ans, INF, sizeof ans);
    vi non_mst;
    
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = (edge){u-1, v-1, w, i};
    }
    
    sort(edges, edges+m);
    
    for(int i = 0; i < m; i++){
        
        int u = edges[i].u;
        int v = edges[i].v;
        int idx = edges[i].i;
        int c = edges[i].c;
        
        if(merge(u, v)){    
            adj[u].push_back((edge){u, v, c, idx});
            adj[v].push_back((edge){v, u, c, idx});
        }
        else{
            non_mst.push_back(i);
        }
    }
    
    dfs(0, -1);
    
    for(auto i : non_mst){
        
        int u = edges[i].u;
        int v = edges[i].v;
        int c = edges[i].c;
        
        int p = lca(u, v);
        
        compress(u, p, c);
        compress(v, p, c);
        
        ans[edges[i].i] = lca_get_max(u, v);
    }
    
    for(int i = 0; i < m; i++){
        cout << (ans[i] < INF ? ans[i]-1 : -1) << ' ';
    }
}
