// Problem: E. Tree Queries
// Contest: Codeforces - Codeforces Round #629 (Div. 3)
// URL: https://codeforces.com/contest/1328/problem/E
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
vi adj[NMAX];
int depth[NMAX];
int par[NMAX][LOG];

void dfs(int nd, int p){
    
    for(auto nxt : adj[nd]) if(nxt != p){
        
        depth[nxt] = depth[nd] + 1;
        
        par[nxt][0] = nd;
        for(int i = 1; i < LOG; i++){
            par[nxt][i] = par[par[nxt][i-1]][i-1];
        }
        
        dfs(nxt, nd);
    }
}

int lca(int u, int v){
    
    int dep_u = depth[u];
    int dep_v = depth[v];
    
    if(dep_u < dep_v){
        swap(u, v), swap(dep_u, dep_v);
    }    
    
    int d = dep_u - dep_v;
    
    int dis_u = 0, dis_v = 0;
    
    for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
        dis_u += 1 << i;
        u = par[u][i];    
    }
    
    if(u == v) return 0;
    
    for(int i = LOG-1; i >= 0; i--){
        if(par[u][i] != par[v][i]){
            dis_u += 1 << i;
            dis_v += 1 << i;
            u = par[u][i];
            v = par[v][i];
        }
    }
    
    dis_u++, dis_v++;
    
    return min(dis_u, dis_v);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> m;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, -1);
    
    while(m--){
        
        int k;
        cin >> k;
        
        vi vec(k);
        for(auto &i : vec) cin >> i, i--;
        
        sort(vec.begin(), vec.end(), [&](int u, int v){return depth[u] < depth[v];});
        
        bool ans = true;
        
        for(auto i : vec){
            if(lca(i, vec.back()) > 1){
                ans = false;
                break;
            }
        }
        
        cout << (ans ? "YES" : "NO") << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
