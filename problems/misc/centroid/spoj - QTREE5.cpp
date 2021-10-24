// Problem: Query on a tree V
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/QTREE5/
// Memory Limit: 1536 MB
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

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 1e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));

int n, q, LOG;
set<int> adj[NMAX];
int depth[NMAX], sub[NMAX], par[NMAX][LOG_MAX];
int cpar[NMAX];
multiset<pii> ans[NMAX];
bool white[NMAX];

void dfs0(int u, int p){
    
    for(auto v: adj[u]) if(v != p){
        
        depth[v] = depth[u] + 1;
        
        par[v][0] = u;
        for(int i = 1; i < LOG; i++)
            par[v][i] = par[par[v][i-1]][i-1];
        
        dfs0(v, u);
    }
}

int lca(int u, int v){
    
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i = 0; i < LOG; i++) if(diff & (1<<i)) u = par[u][i];
    if(u == v) return u;
    for(int i = LOG-1; i >= 0; i--) if(par[u][i] != par[v][i])
        u = par[u][i], v = par[v][i];
    return par[u][0];    
}

int dist(int u, int v){
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int nn;
void dfs1(int u, int p){
    
    nn++;
    sub[u] = 1;
    
    for(auto v : adj[u]) if(v != p){
        dfs1(v, u);
        sub[u] += sub[v];
    }    
}

int dfs2(int u, int p){
    
    for(auto v : adj[u]) if(v != p) if(sub[v] > nn/2){
        return dfs2(v, u);
    }    
    
    return u;
}

void decompose(int u, int p){
    
    nn = 0;
    dfs1(u, u);
    int centroid = dfs2(u, u);
    if(p == -1) p = centroid;
    cpar[centroid] = p;
    
    for(auto v : adj[centroid]){
        adj[v].erase(centroid);
        decompose(v, centroid);
    }    
    
    adj[centroid].clear();
}

int solve(int u){
    
    auto &mst = ans[u];
    
    while(!mst.empty()){
        
        pii tp = *mst.begin();
        
        if(white[tp.second] == 0){
            mst.erase(mst.begin());
        }
        else{
            return tp.first;
        }
    }    
    
    return INF;
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
        cin >> u >> v;
        u--, v--;
        
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    LOG = ceil(log2(double(n)));
    dfs0(0, -1);
    
    decompose(0, -1);
    
    cin >> q; while(q--){
        
        int x, u;
        cin >> x >> u;
        u--;
        
        if(x == 0){
            
            white[u] = !white[u];
            
            int p = u;
            while(true){
                
                ans[p].insert({dist(u, p), u});
                
                if(cpar[p] == p) break;
                p = cpar[p];
            }
        }
        else{
            
            int ans = INF;
            
            int p = u;
            while(true){
                
                ans = min(ans, dist(u, p) + solve(p));
                
                if(cpar[p] == p) break;
                p = cpar[p];
            }
            
            cout << (ans < INF ? ans : -1) << endl;
        }
    }
}

/*
  arrays sizes 
  INFLL & 1ll]
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
