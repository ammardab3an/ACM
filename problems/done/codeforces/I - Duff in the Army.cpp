// Problem: I - Duff in the Army
// Contest: Virtual Judge - Contest 1
// URL: https://vjudge.net/contest/436651#problem/I
// Memory Limit: 524 MB
// Time Limit: 4000 ms
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

int n, m, q;
vi adj[NMAX];
int par[NMAX][LOG];
vi mn[NMAX][LOG];
int depth[NMAX];
vi city[NMAX];

void dfs(int nd, int p){
    
    for(auto nxt : adj[nd]) if(nxt != p){
        
        depth[nxt] = depth[nd] + 1;
        
        par[nxt][0] = nd;
        for(int i = 1; i < LOG; i++){
            par[nxt][i] = par[par[nxt][i-1]][i-1];
        }
        
        mn[nxt][0] = city[nd];
        
        for(int i = 1; i < LOG; i++){
            
            vi &res = mn[nxt][i];
            vi &tmp_0 = mn[nxt][i-1];
            vi &tmp_1 = mn[par[nxt][i-1]][i-1];
            
            res = vi(tmp_0.size() + tmp_1.size());
            merge(tmp_0.begin(), tmp_0.end(), tmp_1.begin(), tmp_1.end(), res.begin());
            if(res.size() > 10) res.resize(10);
        }
        
        dfs(nxt, nd);
    }
}

vi lca(int u, int v){
    
    int dep_u = depth[u];
    int dep_v = depth[v];
    
    if(dep_u < dep_v){
        swap(u, v), swap(dep_u, dep_v);
    }
    
    int d = dep_u - dep_v;
    
    vi mn_u  = city[u], mn_v = city[v];
    
    for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
        
        vi &tmp_u = mn[u][i];
        
        vi res_u(tmp_u.size() + mn_u.size());
        merge(tmp_u.begin(), tmp_u.end(), mn_u.begin(), mn_u.end(), res_u.begin());
        
        if(res_u.size() > 10) res_u.resize(10);
        
        mn_u = res_u;
        u = par[u][i];
    }
    
    if(u == v) return mn_u;
    
    for(int i = LOG-1; i >= 0; i--){
        
        if(par[u][i] != par[v][i]){
            
            vi &tmp_u = mn[u][i];
            vi &tmp_v = mn[v][i];
            
            vi res_u(tmp_u.size() + mn_u.size()), res_v(tmp_v.size() + mn_v.size());
            merge(tmp_u.begin(), tmp_u.end(), mn_u.begin(), mn_u.end(), res_u.begin());    
            merge(tmp_v.begin(), tmp_v.end(), mn_v.begin(), mn_v.end(), res_v.begin());
            
            if(res_u.size() > 10) res_u.resize(10);
            if(res_v.size() > 10) res_v.resize(10);
            
            mn_u = res_u;
            mn_v = res_v;
            
            u = par[u][i];
            v = par[v][i];
        }
    }
    
    {
        vi &tmp_u = mn[u][0];
        vi res_u(mn_u.size() + tmp_u.size());
        merge(tmp_u.begin(), tmp_u.end(), mn_u.begin(), mn_u.end(), res_u.begin());
        if(res_u.size() > 10) res_u.resize(10);
        mn_u = res_u;
    }
    
    vi res(mn_v.size() + mn_u.size());
    merge(mn_v.begin(), mn_v.end(), mn_u.begin(), mn_u.end(), res.begin());    
    if(res.size() > 10) res.resize(10);
    
    return res;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> m >> q;
    
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 0; i < m; i++){
        int ci;
        cin >> ci, ci--;
        city[ci].push_back(i);
        if(city[ci].size() > 10) city[ci].resize(10);
    }
    
    dfs(0, -1);
    
    while(q--){
        int u, v, k;
        cin >> u >> v >> k, u--, v--;
        vi tmp = lca(u, v);
        if(tmp.size() > k) tmp.resize(k);
        cout << tmp.size() << ' ' ;
        for(auto i : tmp) cout << i+1 << ' '; cout << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
