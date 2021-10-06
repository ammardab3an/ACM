// Problem: Count on a tree II
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/COT2/
// Memory Limit: 1536 MB
// t Limit: 1207 ms
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

const int NMAX = 4e4 + 10;
const int MMAX = 1e5 + 10;
const int LOG = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt((double)NMAX));

int n, m;
int arr[NMAX];
vi adj[NMAX];
int narr[NMAX*2], t = -1;
int in[NMAX], out[NMAX];
int par[NMAX][LOG];
int lvl[NMAX];
int ans[MMAX];
int freq[NMAX];
int vis[NMAX];
int cans = 0;

#define debug false

struct query{
    
    int lo, hi, idx, add;
    
    bool operator < (const query &other){
        
        if(lo/BLOCK != other.lo/BLOCK) return lo < other.lo;
        return lo/BLOCK % 2 ? hi > other.hi : hi < other.hi;
    }
    
} que[MMAX];

void add(int nd){
    
    if(vis[nd]==0){
        vis[nd]++;
        freq[arr[nd]]++;
        if(freq[arr[nd]]==1) cans++;    
    }
    else {
        vis[nd]++;
        freq[arr[nd]]--;
        if(freq[arr[nd]]==0) cans--;
    }
    
    if(debug) cout << "add " << nd << ' ' << cans << endl;
}

void rem(int nd){
    
    if(vis[nd]==1){
        vis[nd]--;
        freq[arr[nd]]--;
        if(freq[arr[nd]]==0) cans--;
    }
    else{
        vis[nd]--;
        freq[arr[nd]]++;
        if(freq[arr[nd]]==1) cans++;
    }
    
    if(debug) cout << "rem " << nd << ' ' << cans << endl;
}

void dfs(int nd, int p){
    
    in[nd] = ++t;
    narr[t] = nd;
    
    for(auto nxt : adj[nd]) if(nxt != p){
        
        lvl[nxt] = lvl[nd]+1;
        
        par[nxt][0] = nd;
        for(int i = 1; i < LOG; i++){
            par[nxt][i] = par[par[nxt][i-1]][i-1];
        }
        
        dfs(nxt, nd);
    }
    
    out[nd] = ++t;
    narr[t] = nd;
}

int lca(int u, int v){
    
    int depth_u = lvl[u];
    int depth_v = lvl[v];
    
    if(depth_u < depth_v){
        swap(u, v), swap(depth_u, depth_v);
    }
    
    int dist = depth_u - depth_v;
    
    for(int i = LOG-1; i >= 0; i--) if(dist&(1 << i)){
        u = par[u][i];
    }
    
    if(u == v) return v;
    
    for(int i = LOG-1; i >= 0; i--){
        
        int nu = par[u][i];
        int nv = par[v][i];
        
        if(nu != nv){
            u = nu;
            v = nv;
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

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    {
        set<int> st;
        map<int, int> mp;
        int cur = 0;
        
        for(int i = 0; i < n; i++) st.insert(arr[i]);
        
        for(auto i : st) mp[i] = cur++;
        
        for(int i = 0; i < n; i++) arr[i] = mp[arr[i]];
        
        if(debug) for(int i = 0; i < n; i++) cout << arr[i] << ' ', cout << endl;
    }
    
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, -1);
    if(debug) for(int i = 0; i <= t; i++) cout << narr[i]+1 << ' ', cout << endl;
    
    for(int i = 0; i < m; i++){
        
        int u, v;
        cin >> u >> v; u--, v--;
        
        if(in[u] > in[v]) swap(u, v);
        
        int p = lca(u, v);
        
        if(p == u){
            que[i].lo = in[u];
            que[i].hi = in[v];
            que[i].add = -1;
            que[i].idx = i;
        }
        else{
            que[i].lo = out[u];
            que[i].hi = in[v];
            que[i].add = arr[p];
            que[i].idx = i;
        }
    }
    
    sort(que, que+m);
    
    int l = 1;
    int r = 0;
    
    for(int i = 0; i < m; i++){
        
        int cl = que[i].lo;
        int cr = que[i].hi;
        int ca = que[i].add;
        int ci = que[i].idx;
        
        if(debug) cout << ci << ' ' << cl << ' ' << cr << endl;
        
        while(r < cr) add(narr[++r]);
        while(cl < l) add(narr[--l]);
        while(cr < r) rem(narr[r--]);
        while(l < cl) rem(narr[l++]);
        
        ans[ci] = cans;
        if(ca != -1) ans[ci] += (freq[ca]==0);
        
        if(debug) cout << endl;
    }
    
    for(int i = 0; i < m; i++) cout << ans[i] << endl;
    
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
