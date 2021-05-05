// Problem: C. Fools and Roads
// Contest: Codeforces - Codeforces Round #121 (Div. 1)
// URL: https://codeforces.com/contest/191/problem/C
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
vi idx[NMAX];
int par[NMAX][LOG];
int add[NMAX];
int ans[NMAX];
int depth[NMAX];
int par_idx[NMAX];

void dfs(int nd, int p){
    
    int i = 0;
    for(auto nxt : adj[nd]) {
        
        if(nxt != p){
            
            par_idx[nxt] = i;
            
            depth[nxt] = depth[nd] + 1;
            
            par[nxt][0] = nd;
            for(int i = 1; i < LOG; i++)
                par[nxt][i] = par[par[nxt][i-1]][i-1];
            
            dfs(nxt, nd);
        }
        
        i++;
    }
           
}

int dfs1(int nd, int p){
    
    int suf = add[nd];
    
    for(int i = 0; i < adj[nd].size(); i++) if(adj[nd][i] != p){
        suf += dfs1(adj[nd][i], nd);    
    }
    
    if(p != -1){
        ans[idx[par[nd][0]][par_idx[nd]]] += suf;
    }
    
    return suf;
}

void lca(int u, int v){
    
    int dep_u = depth[u];
    int dep_v = depth[v];
    
    if(dep_u < dep_v){
        swap(u, v), swap(dep_u, dep_v);
    }    
    
    int tmp_u = u;
    int tmp_v = v;
    
    int d = dep_u - dep_v;
    
    for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
        u = par[u][i];
    }
    
    if(u == v){
        add[tmp_v] -= 1;
        add[tmp_u] += 1;
        return;
    }
    
    for(int i = LOG-1; i >= 0; i--){
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    
    add[par[u][0]] -= 2;
    add[tmp_u] += 1;
    add[tmp_v] += 1;
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
        idx[u].push_back(i);
        idx[v].push_back(i);
    }
    
    dfs(0, -1);
    
    int m; cin >> m; while(m--){
        int u, v;
        cin >> u >> v; u--, v--;
        lca(u, v);
    }
    
    dfs1(0, -1);
    
    for(int i = 0; i < n-1; i++) cout << ans[i] << ' '; cout << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
