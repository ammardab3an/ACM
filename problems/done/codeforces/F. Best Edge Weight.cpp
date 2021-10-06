// Problem: F. Best Edge Weight
// Contest: Codeforces - Codeforces Round #423 (Div. 2, rated, based on VK Cup Finals)
// URL: https://codeforces.com/problemset/problem/828/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m, log_n;
iii edges[NMAX];
int idx[NMAX];
vi adj[NMAX];

int base_sz;
int chain_no, chain_head[NMAX], chain_idx[NMAX], pos_in_base[NMAX];

int par[NMAX][LOG_MAX], par_mx[NMAX][LOG_MAX];
int sz[NMAX], depth[NMAX], other_end[NMAX];

int tree[NMAX << 2];
int lazy[NMAX << 2];        

int dsu_par[NMAX];

int ans[NMAX];

int get_par(int u){
    return dsu_par[u] = dsu_par[u] == u ? u : get_par(dsu_par[u]);
}

bool merge(int u, int v){
    
    int par_u = get_par(u);
    int par_v = get_par(v);
    
    if(par_u == par_v) return false;
    
    if(rand()&1) swap(par_u, par_v);
    
    dsu_par[par_u] = par_v;
    
    return true;
}

void push(int nd, int l, int r){
    
    if(!lazy[nd]) return;
    
    tree[nd] = min(tree[nd], lazy[nd]);
    
    if(l != r){
        lazy[nd*2] = !lazy[nd*2] ? lazy[nd] : min(lazy[nd*2], lazy[nd]);
        lazy[nd*2+1] = !lazy[nd*2+1] ? lazy[nd] : min(lazy[nd*2+1], lazy[nd]);
    }    
    
    lazy[nd] = 0;
}

int query(int nd, int l, int r, int q_l, int q_r){
    
    push(nd, l, r);
    
    if(l > q_r || q_l > r) return INF;
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    }
    
    int mid = (l+r)/2;
    int stPath = query(nd*2, l, mid, q_l, q_r);
    int ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return min(stPath, ndPath);    
}

void update(int nd, int l, int r, int q_l, int q_r, int val){
    
    push(nd, l, r);
    
    if(l > q_r || q_l > r) return;
    
    if(q_l <= l && r <= q_r){
        lazy[nd] = val;
        push(nd, l, r);
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, val);
    update(nd*2+1, mid+1, r, q_l, q_r, val);
    
    tree[nd] =  min(tree[nd*2], tree[nd*2+1]);
}


int lca(int u, int v){
    
    if(depth[u] < depth[v]) swap(u, v);
    
    int dif = depth[u] - depth[v];
    for(int i = 0; i < log_n; i++) if(dif&(1<<i)){
        u = par[u][i];
    }
    
    if(u == v) return u;
    
    for(int i = log_n-1; i >= 0; i--) if(par[u][i] != par[v][i]){
        u = par[u][i], v = par[v][i];
    }
    
    return par[u][0];    
}

int lca_get_max(int u, int v){
    
    if(depth[u] < depth[v]) swap(u, v);
    
    int mx_u = 0, mx_v = 0;
    int dif = depth[u] - depth[v];
    
    for(int i = 0; i < log_n; i++) if(dif&(1<<i)){    
        mx_u = max(mx_u, par_mx[u][i]);
        u = par[u][i];
    }
    
    if(u == v) return mx_u;
    
    for(int i = log_n-1; i >= 0; i--) if(par[u][i] != par[v][i]){    
        mx_u = max(mx_u, par_mx[u][i]);
        mx_v = max(mx_v, par_mx[v][i]);
        u = par[u][i], v = par[v][i];
    }
    
    mx_u = max(mx_u, par_mx[u][0]);
    mx_v = max(mx_v, par_mx[v][0]);
    
    return max(mx_u, mx_v);           
}

void dfs(int u, int p_i){
    
    sz[u] = 1;
    
    for(auto i : adj[u]) if(i != p_i){
        
        auto &p = edges[i];
        
        if(p.second.first != u){
            swap(p.second.first, p.second.second);
        }
        
        int v = p.second.second;
        
        depth[v] = depth[u] + 1;
        
        par[v][0] = u;
        for(int i = 1; i < log_n; i++){
            par[v][i] = par[par[v][i-1]][i-1];
        }
        
        par_mx[v][0] = p.first;
        for(int i = 1; i < log_n; i++){
            par_mx[v][i] = max(par_mx[par[v][i-1]][i-1], par_mx[v][i-1]);
        }
        
        dfs(v, i);
        
        sz[u] += sz[v];
    }    
}

void hld(int u, int p_i){
    
    if(chain_head[chain_no] == -1){
        chain_head[chain_no] = u;
    }    
    
    chain_idx[u] = chain_no;
    pos_in_base[u] = base_sz++;
    
    int sc=-1, sc_par_i;
    
    for(auto i : adj[u]) if(i != p_i){
        if(sc == -1 || sz[sc] < sz[edges[i].second.second]){
            sc = edges[i].second.second;
            sc_par_i = i;
        }
    }
    
    if(sc != -1){
        hld(sc, sc_par_i);
    }
    
    for(auto i : adj[u]) if(i != p_i) if(i != sc_par_i){
        chain_no++;
        hld(edges[i].second.second, i);
    }
}

void update_up(int u, int v, int val){
    
    if(u == v) return;
    int uchain, vchain = chain_idx[v];
    
    while(true){
        
        uchain = chain_idx[u];
        
        if(uchain == vchain){
            if(u == v) break;
            update(1, 0, base_sz-1, pos_in_base[v]+1, pos_in_base[u], val);
            break;
        }
        
        update(1, 0, base_sz-1, pos_in_base[chain_head[uchain]], pos_in_base[u], val);
        u = par[chain_head[uchain]][0];
    }    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    log_n = ceil(log2(double(n)));
    
    // fill edges
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {w, {u, v}};
    }
    
    // init idx
    iota(idx, idx+m, 0);
    
    sort(idx, idx+m, [&](int a, int b){
        return edges[a].first < edges[b].first;
    });
    
    // init dsu
    iota(dsu_par, dsu_par+n, 0);
    
    // not included in the mst
    vi tmp;
    
    // build mst
    for(int _i = 0; _i < m; _i++){
        
        int i = idx[_i];
        
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;
        
        if(merge(u, v)){    
            adj[u].push_back(i);
            adj[v].push_back(i);
        }
        else{
            tmp.push_back(i);
        }
    }
    
    // init seg tree
    memset(tree, INF, sizeof tree);
    
    // init chain_head arrary
    memset(chain_head, -1, sizeof chain_head);
    
    // init hld
    dfs(0, -1);
    hld(0, -1);
    
    // process non mst edges
    for(auto i : tmp){
        
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;
        
        int p = lca(u, v);
        
        update_up(u, p, w);
        update_up(v, p, w);
        
        ans[i] = lca_get_max(u, v);
    }
    
    
    for(int _i = 0; _i < m; _i++){
        int i = idx[_i];
        if(ans[i]) continue;
        int u = edges[i].second.second;
        int que = query(1, 0, base_sz-1, pos_in_base[u], pos_in_base[u]);
        ans[i] = que;
    }
    
    for(int i = 0; i < m; i++){
        cout << (ans[i] < INF ? ans[i]-1 : -1) << ' ';
    }
}