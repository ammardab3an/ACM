// Problem: F. MST Unification
// Contest: Codeforces - Codeforces Round #535 (Div. 3)
// URL: https://codeforces.com/contest/1108/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
iii edge[MMAX];
bool vis[MMAX];
int par[NMAX];
int depth[NMAX];
int up[NMAX][LOG];
int mx[NMAX][LOG];
vpii adj[NMAX];

int get_par(int u){
    return par[u] = par[u] == u ? u : par[u] = get_par(par[u]);
}

void dfs(int nd, int par){
    
    for(auto nxt : adj[nd]) if(nxt.second != par){
        
        depth[nxt.second] = depth[nd] + 1;
        
        up[nxt.second][0] = nd;
        mx[nxt.second][0] = nxt.first;
        
        for(int i = 1; i < LOG; i++){
            up[nxt.second][i] = up[up[nxt.second][i-1]][i-1];
            mx[nxt.second][i] = max(mx[nxt.second][i-1], mx[up[nxt.second][i-1]][i-1]);
        }
        
        dfs(nxt.second, nd);
    }    
}

int lca(int u, int v){
    
    if(depth[u] < depth[v])
        swap(u, v);
        
    int mxu = 0, mxv = 0;
    
    int d = depth[u] - depth[v];
    
    for(int i = LOG-1; i >= 0; i--){
        if(d & (1 << i)){
            mxu = max(mxu, mx[u][i]);
            u = up[u][i];
        }
    }    
    
    if(u == v) return mxu;
    
    for(int i = LOG-1; i >= 0; i--){
        
        if(up[u][i] != up[v][i]){
            
            mxu = max(mxu, mx[u][i]);
            mxv = max(mxv, mx[v][i]);
            
            u = up[u][i];
            v = up[v][i];
        }
    }
    
    mxu = max(mxu, mx[u][0]);
    mxv = max(mxv, mx[v][0]);
    
    return max(mxu, mxv);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = {w, {--u, --v}};
    }
    
    sort(edge, edge+m);
    
    for(int i = 0; i < n; i++) par[i] = i;
    
    for(int i = 0; i < m; i++){
        
        int w = edge[i].first;
        int u = edge[i].second.first;
        int v = edge[i].second.second;
        
        if(get_par(u) != get_par(v)){
            
            vis[i] = true;
            
            adj[u].emplace_back(w, v);
            adj[v].emplace_back(w, u);
            
            if(rand()&1){
                par[get_par(u)] = get_par(v);
            }
            else{
                par[get_par(v)] = get_par(u);
            }
        }
        
    }
    
    dfs(0, -1);
    
    int ans = 0;
    
    for(int i = 0; i < m; i++) if(!vis[i]){
        
        int w = edge[i].first;
        int u = edge[i].second.first;
        int v = edge[i].second.second;
        
        if(lca(u, v) == w){
            ans++;
        }
    }
    
    cout << ans << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    