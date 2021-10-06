// Problem: Lowest Common Ancestor
// Contest: SPOJ - Tutorial
// URL: https://www.spoj.com/problems/LCASQ/
// Memory Limit: 1536 MB
// Time Limit: 12000 ms
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

const int LOG = 14;

vi adj[NMAX];
int depth[NMAX];
int par[NMAX][LOG];

void dfs(int nd){
    
    for(auto nxt : adj[nd]){
        
        depth[nxt] = depth[nd] + 1;
        
        par[nxt][0] = nd;
        for(int i = 1; i < LOG; i++){
            par[nxt][i] = par[par[nxt][i-1]][i-1];
        }
        dfs(nxt);
    }
}

int get_lca(int u, int v){
    
    if(depth[u] < depth[v])
        swap(u, v);
    
    int k = depth[u] - depth[v];
    
    for(int i = LOG-1; i >= 0; i--) if(k & (1 << i)){
        u = par[u][i];
    }
    
    if(u == v) return u;
    
    for(int i = LOG-1; i >= 0; i--){
        
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    
    return par[u][0];
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        
        int m; cin >> m; while(m--){
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }
    
    dfs(0);
    
    int q; cin >> q; while(q--){
        int u, v;
        cin >> u >> v;
        cout << get_lca(u, v) << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
