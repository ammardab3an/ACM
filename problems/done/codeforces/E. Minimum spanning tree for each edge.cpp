// Problem: E. Minimum spanning tree for each edge
// Contest: Codeforces - Educational Codeforces Round 3
// URL: https://codeforces.com/problemset/problem/609/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG = ceil(log2(NMAX));

int n, m;
iii edges[NMAX];
vpii adj[NMAX];
int pos[NMAX];
int par_m[NMAX];
int par[NMAX][LOG];
int mx[NMAX][LOG];
int depth[NMAX];

int get_par(int n){
    return par_m[n] == n ? n : par_m[n] = get_par(par_m[n]);
}

bool merge(int u, int v){
    
    int par_u = get_par(u);
    int par_v = get_par(v);
    
    if(par_u == par_v) return false;
    
    if(rand()&1) swap(par_u, par_v);
    
    par_m[par_u] = par_v;
    
    return true;
}

void dfs(int nd, int p){
    
    for(auto [nxt_d, nxt_n] : adj[nd]) if(nxt_n != p){
            
        depth[nxt_n] = depth[nd] + 1;
        
        par[nxt_n][0] = nd;
        mx[nxt_n][0] = nxt_d;
        
        for(int i = 1; i < LOG; i++){
            par[nxt_n][i] = par[par[nxt_n][i-1]][i-1];
            mx[nxt_n][i] = max(mx[nxt_n][i-1], mx[par[nxt_n][i-1]][i-1]);
        }
        
        dfs(nxt_n, nd);
    }    
}

int lca(int u, int v){
    
    int dep_u = depth[u];
    int dep_v = depth[v];
    
    if(dep_u < dep_v){
        swap(u, v);
        swap(dep_u, dep_v);
    }
    
    int d = dep_u - dep_v;
    
    int mx_u = 0, mx_v = 0;
    
    for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
        mx_u = max(mx_u, mx[u][i]);
        u = par[u][i];
    }
    
    if(u == v) return mx_u;
    
    for(int i = LOG-1; i >= 0; i--){
        
        if(par[u][i] != par[v][i]){
            mx_u = max(mx_u, mx[u][i]);
            mx_v = max(mx_v, mx[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }
    
    return max({mx_u, mx_v, mx[u][0], mx[v][0]});
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, d;
        cin >> u >> v >> d;
        edges[i] = {d, {--u, --v}};
    }
    
    for(int i = 0; i < n; i++) par_m[i] = i;
    for(int i = 0; i < m; i++) pos[i] = i;
    sort(pos, pos+m, [&](int i, int j){return edges[i] < edges[j];});
    
    lli mst = 0;
    for(int i = 0; i < m; i++){
        
        int j = pos[i];
        int d = edges[j].first;
        int u = edges[j].second.first;
        int v = edges[j].second.second;
        
        if(merge(u, v)){
            adj[u].push_back({d, v});
            adj[v].push_back({d, u});
            mst += d;
        }
    }
    
    dfs(0, -1);
    
    for(int i = 0; i < m; i++){
        
        int d = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        
        cout << mst - lca(u, v) + d << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
