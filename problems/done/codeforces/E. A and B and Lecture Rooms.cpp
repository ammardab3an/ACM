// Problem: E. A and B and Lecture Rooms
// Contest: Codeforces - Codeforces Round #294 (Div. 2)
// URL: https://codeforces.com/contest/519/problem/E
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

const int NMAX = 1e5 + 10;
const int LOG = ceil(log2(NMAX));

int n;
vi adj[NMAX];
int par[NMAX][LOG];
int sz[NMAX];
int depth[NMAX];

int dfs(int nd, int p){
    
    int sm = 1;
    
    for(auto nxt : adj[nd]) if(nxt != p){
        
        depth[nxt] = depth[nd] + 1;
        
        par[nxt][0] = nd;
        for(int i = 1; i < LOG; i++)
            par[nxt][i] = par[par[nxt][i-1]][i-1];
            
        sm += dfs(nxt, nd);
    }    
    
    return sz[nd] = sm;
}

int lca(int u, int v){
    
    if(u == v) return sz[0];
    
    int dep_u = depth[u];
    int dep_v = depth[v];
    
    if(dep_u < dep_v){
        swap(u, v), swap(dep_u, dep_v);
    }
    
    int tmp_u = u;
    int tmp_v = v;
    
    int d = dep_u - dep_v;
    int dis_u = 0, dis_v = 0;
    
    for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
        u = par[u][i];
        dis_u += 1 << i;
    }
    
    if(u == v){
        
        if(d%2==1) return 0;
        
        d = d/2 -1;
        u = tmp_u;
        
        for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
            u = par[u][i];    
        }
        
        return sz[par[u][0]] - sz[u];
    }
    
    for(int i = LOG-1; i >= 0; i--){
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
            dis_u += 1 << i;
            dis_v += 1 << i;
        }
    }
    
    dis_u++, dis_v++;
    
    if(dis_u == dis_v) return sz[0] - sz[u] - sz[v];
    
    if((dis_u + dis_v)%2==1) return 0;
    
    d = (dis_u + dis_v)/2 -1;
    u = tmp_u;
    
    for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
        u = par[u][i];    
    }
    
    return sz[par[u][0]] - sz[u];
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, -1);
    
    int m; cin >> m; while(m--){
        
        int u, v;
        cin >> u >> v; u--, v--;
        
        cout << lca(u, v) << endl;    
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
