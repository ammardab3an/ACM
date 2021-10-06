// Problem: L. Subway Lines
// Contest: Codeforces - 2018-2019 ACM-ICPC Brazil Subregional Programming Contest
// URL: https://codeforces.com/gym/101908/problem/L
// Memory Limit: 1024 MB
// Time Limit: 500 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
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
int depth[NMAX];
int par[NMAX][LOG_MAX];
int sz[NMAX], in[NMAX], nxt[NMAX], t;
int tree[NMAX << 2];
int lazy[NMAX << 2];

void push(int nd, int l, int r){
    
    if(lazy[nd] == -1) return;
    
    tree[nd] = (r-l+1) * lazy[nd];
    
    if(l != r){
        lazy[nd*2] = lazy[nd];
        lazy[nd*2+1] = lazy[nd];
    }
    
    lazy[nd] = -1;
}

void update(int nd, int l, int r, int q_l, int q_r, int v){
    
    push(nd, l, r);
    
    if(r < q_l || q_r < l) return;
    
    if(q_l <= l && r <= q_r){
        lazy[nd] = v;
        push(nd, l, r);
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, v);
    update(nd*2+1, mid+1, r, q_l, q_r, v);
    
    tree[nd] = tree[nd*2] + tree[nd*2+1];
}

int query(int nd, int l, int r, int q_l, int q_r){
    
    push(nd, l, r);
    
    if(r < q_l || q_r < l) return 0;
    
    if(q_l <= l && r <= q_r) return tree[nd];
    
    int mid = (l+r)/2;
    int st_path = query(nd*2, l, mid, q_l, q_r);
    int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return st_path + nd_path;
}

void dfs(int u, int p){
    
    sz[u] = 1;
    
    for(auto &v : adj[u]) if(v != p){
        
        depth[v] = depth[u]+1;
        
        par[v][0] = u;
        for(int i = 1; i < log_n; i++){
            par[v][i] = par[par[v][i-1]][i-1];
        }
        
        dfs(v, u);
        sz[u] += sz[v];
        
        if((adj[u][0] == p) || (sz[adj[u][0]] < sz[v])){
            swap(adj[u][0], v);
        }
    }    
}

void dfs_hld(int u, int p){
    
    in[u] = t++;
    
    for(auto v : adj[u]) if(v != p){
        nxt[v] = (v==adj[u][0]) ? nxt[u] : v;
        dfs_hld(v, u);
    }    
}

void hld_update(int u, int v, int val){
    
    while(nxt[u] != nxt[v]){
        
        if(depth[nxt[u]] < depth[nxt[v]]){
            swap(u, v);
        }
        update(1, 0, n-1, in[nxt[u]], in[u], val);
        u = par[nxt[u]][0];
    }
    
    if(depth[u] < depth[v]) swap(u, v);
    update(1, 0, n-1, in[v], in[u], val);

}

int hld_query(int u, int v){
    
    int ans = 0;
    
    while(nxt[u] != nxt[v]){
        
        if(depth[nxt[u]] < depth[nxt[v]]){
            swap(u, v);
        }
        ans += query(1, 0, n-1, in[nxt[u]], in[u]);
        u = par[nxt[u]][0];
    }
    
    if(depth[u] < depth[v]) swap(u, v);
    ans += query(1, 0, n-1, in[v], in[u]);
    
    return ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int q;
    cin >> n >> q;
    
    log_n = ceil(log2(double(n)));
    
    for(int i = 0; i < n-1; i++){
        
        int u, v;
        cin >> u >> v;
        u--, v--;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, -1);
    dfs_hld(0, -1);
    memset(lazy, -1, sizeof lazy);
    
    while(q--){
        
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        a--, b--, x--, y--;
        
        hld_update(a, b, 1);
        
        int ans = hld_query(x, y);
        
        hld_update(a, b, 0);
        
        cout << ans << endl;
    }
}