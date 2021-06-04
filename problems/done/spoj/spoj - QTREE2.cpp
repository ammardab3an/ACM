// Problem: B - Query on a tree II
// Contest: Virtual Judge - Contest 1
// URL: https://vjudge.net/contest/436651#problem/B
// Memory Limit: 1572 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
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

const int NMAX = 1e4 + 10;
const int LOG = ceil(log2(NMAX));

int n;
vpii adj[NMAX];
int par[NMAX][LOG];
int len[NMAX][LOG];
int depth[NMAX];

void dfs(int nd, int pa){
    
    for(auto p : adj[nd]){
        
        int nxt_n = p.second;
        int nxt_d = p.first;
        
        if(nxt_n != pa){
            
            depth[nxt_n] = depth[nd] + 1;
            
            par[nxt_n][0] = nd;
            len[nxt_n][0] = nxt_d;
            
            for(int i = 1; i < LOG; i++){
                par[nxt_n][i] = par[par[nxt_n][i-1]][i-1];
                len[nxt_n][i] = len[nxt_n][i-1] + len[par[nxt_n][i-1]][i-1];
            }
            
            dfs(nxt_n, nd);
        }
    }
}

int lca_dist(int u, int v){
    
    int dep_u = depth[u];
    int dep_v = depth[v];
    
    if(dep_u < dep_v){
        swap(u, v), swap(dep_u, dep_v);
    }
    
    int d = dep_u - dep_v;
    int len_u = 0, len_v = 0;
    
    for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
        len_u += len[u][i];
        u = par[u][i];
    }    
    
    if(u == v) return len_u;
    
    for(int i = LOG-1; i >= 0; i--){
        if(par[u][i] != par[v][i]){
            len_u += len[u][i];
            len_v += len[v][i];
            u = par[u][i];
            v = par[v][i];
        }
    }
    
    len_u += len[u][0];
    len_v += len[v][0];
    
    return len_u + len_v;
}

int lca_kth(int u, int v, int k){
    
    int dep_u = depth[u];
    int dep_v = depth[v];
    
    int tmp_u = u;
    int tmp_v = v;
    bool b = false;
    
    if(dep_u < dep_v){
        swap(u, v), swap(dep_u, dep_v);
        b = true;
    }
    
    int dis = lca_dist(u, v);
    
    int d = dep_u - dep_v;
    int len_u = 0, len_v = 0;
    
    for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
        len_u += 1 << i;
        u = par[u][i];
    }    
    
    if(u == v){
        
        if(b){
            swap(u, v), swap(depth[u], depth[v]), swap(len_u, len_v);
        }
        
        u = tmp_u;
        v = tmp_v;
        k--;
        
        int d = k;
        
        if(b){
            d = len_v - k;
            swap(u, v);
        }
        
        for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
            u = par[u][i];
        }
        
        return u;
    }
    
    for(int i = LOG-1; i >= 0; i--){
        if(par[u][i] != par[v][i]){
            len_u += 1 << i;
            len_v += 1 << i;
            u = par[u][i];
            v = par[v][i];
        }
    }
    
    len_u++;
    len_v++;
    
    if(b){
        swap(u, v), swap(depth[u], depth[v]), swap(len_u, len_v);
    }
    
    u = tmp_u;
    v = tmp_v;
    k--;
    
    if(len_u >= k){
        
        int d = k;
        for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
            u = par[u][i];
        }
        
        return u;
    }
    
    else{
        
        int d = len_v - (k-len_u);
        for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
            v = par[v][i];
        }
        
        return v;
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        cin >> n;
        
        for(int i = 0; i < n; i++) adj[i].clear();
        memset(par, 0, sizeof par);
        memset(len, 0, sizeof len);
        memset(depth, 0, sizeof depth);
        
        for(int i = 0; i < n-1; i++){
            int u, v, d;
            cin >> u >> v >> d, u--, v--;
            adj[u].push_back({d, v});
            adj[v].push_back({d, u});
        }
        
        dfs(0, -1);
        
        string str;
        while(cin >> str){
            
            if(str == "DIST"){
                int u, v;
                cin >> u >> v, u--, v--;
                cout << lca_dist(u, v) << endl;
            }
            
            else if(str == "KTH"){
                int u, v, k;
                cin >> u >> v >> k, u--, v--;
                cout << lca_kth(u, v, k)+1 << endl;
            }
            
            else if(str == "DONE"){
                cout << endl;
                break;
            }
        }
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
