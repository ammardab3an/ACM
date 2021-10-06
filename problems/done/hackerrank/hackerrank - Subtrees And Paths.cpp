// Problem: Subtrees And Paths
// Contest: HackerRank - Data Structures - Advanced
// URL: https://www.hackerrank.com/challenges/subtrees-and-paths/problem
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 1e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));

int n, log_n;
vi adj[NMAX];
int in[NMAX], out[NMAX], nxt[NMAX], t;
int sz[NMAX], depth[NMAX];
int par[NMAX][LOG_MAX];
int tree[NMAX << 2];
int lazy[NMAX << 2];

void push(int nd, int l, int r){
    
    if(!lazy[nd]) return;
    tree[nd] += lazy[nd];
    if(l != r){
        lazy[nd*2] += lazy[nd];
        lazy[nd*2+1] += lazy[nd];
    }    
    lazy[nd] = 0;
}

void update(int nd, int l, int r, int q_l, int q_r, int val){
    
    push(nd, l, r);
    
    if(r < q_l || q_r < l){
        return;
    }    
    
    if(q_l <= l && r <= q_r){
        lazy[nd] += val;
        push(nd, l, r);
        return;    
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, val);
    update(nd*2+1, mid+1, r, q_l, q_r, val);
    
    tree[nd] = max(tree[nd*2], tree[nd*2+1]);
}

int query(int nd, int l, int r, int q_l, int q_r){
    
    push(nd, l, r);
    
    if(r < q_l || q_r < l){
        return -INFLL;
    }
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    }
    
    int mid = (l+r)/2;
    int stPath = query(nd*2, l, mid, q_l, q_r);
    int ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return max(stPath, ndPath);
}

void dfs(int u, int p){
    
    sz[u] = 1;
    
    for(auto &v : adj[u]) if(v != p){
        
        depth[v] = depth[u] + 1;
        
        par[v][0] = u;
        for(int i = 1; i < log_n; i++){
            par[v][i] = par[par[v][i-1]][i-1];
        }
        
        dfs(v, u);
        sz[u] += sz[v];
        
        if(sz[v] > sz[adj[u][0]]){
            swap(adj[u][0], v);
        }
    }    
}

void hld(int u, int p){
    
    in[u] = t++;
    
    for(auto v : adj[u]) if(v != p){
        nxt[v] = (v == adj[u][0]) ? nxt[u] : v;
        hld(v, u);
    }
    
    out[u] = t;
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int dif = depth[u] - depth[v];
    for(int i = 0; i < log_n; i++) if(dif&(1<<i)) u = par[u][i];
    if(u == v) return u;
    for(int i = log_n-1; i >= 0; i--) if(par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
    return par[u][0];    
}

int query_up(int u, int p){
    
    int ans = -INFLL;
    
    while(true){
        
        if(nxt[u] == nxt[p]){
            int que = query(1, 0, n-1, in[p], in[u]);
            ans = max(ans, que);
            break;
        }
        
        int que = query(1, 0, n-1, in[nxt[u]], in[u]);
        ans = max(ans, que);
        u = par[nxt[u]][0];
    }    
    
    return ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    log_n = ceil(log2(double(n)));
    
    for(int i = 0; i < n-1; i++){
        
        int u, v;
        cin >> u >> v;
        u--, v--;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, -1);
    hld(0, -1);
    
    int m; cin >> m; while(m--){
        
        string com;
        cin >> com;
        
        if(com == "add"){
            
            int nd, val;
            cin >> nd >> val;
            nd--;
            
            update(1, 0, n-1, in[nd], out[nd]-1, val);
        }
        else if(com == "max"){
            
            int u, v;
            cin >> u >> v;
            u--, v--;
            
            int p = lca(u, v);
            
            int stPath = query_up(u, p);
            int ndPath = query_up(v, p);
            
            cout << max(stPath, ndPath) << endl;
        }
    }
}
