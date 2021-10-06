// Problem: Ivan Pesic and His World Tour
// Contest: CodeChef - Practice(Medium)
// URL: https://www.codechef.com/problems/QRYLAND
// Memory Limit: 256 MB
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

int mul(int a, int b, int MOD){
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret + MOD) % MOD;
}
 
int add(int a, int b, int MOD){
	int ret = (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
	return (ret + MOD) % MOD;
}

const int NMAX = 250000 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));

int n, m, log_n;
int val[NMAX];
vi adj[NMAX];
int par[NMAX][LOG_MAX], depth[NMAX], in[NMAX], out[NMAX], t;
array<int, 2> base[NMAX], tree[NMAX << 2];
array<int, 2> p, b, fst_pow[NMAX], ans_len[NMAX];

array<int, 2> add(array<int, 2> arr_0, array<int, 2> arr_1){
    return {add(arr_0[0], arr_1[0], p[0]), add(arr_0[1], arr_1[1], p[1])};    
}

array<int, 2> mul(array<int, 2> arr_0, array<int, 2> arr_1){
    return {mul(arr_0[0], arr_1[0], p[0]), mul(arr_0[1], arr_1[1], p[1])};    
}

void build(int nd, int l, int r){
    
    if(l==r){
        tree[nd] = base[l];
        return;
    }
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
}

void update(int nd, int l, int r, int q_l, int q_r, array<int, 2> val){
    
    if(r < q_l || q_r < l){
        return;
    }    
    
    if(q_l <= l && r <= q_r){
        tree[nd] = add(tree[nd], val);
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, val);
    update(nd*2+1, mid+1, r, q_l, q_r, val);
}

array<int, 2> query(int nd, int l, int r, int p){
    
    if(l == r){
        return tree[nd];
    }
    
    int mid = (l+r)/2;
    
    array<int, 2> ret;
    
    if(p <= mid) 
        ret = query(nd*2, l, mid, p);
    else
        ret = query(nd*2+1, mid+1, r, p);
    
    return add(ret, tree[nd]);
}

int lca(int u, int v){
    
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i = 0; i < log_n; i++) if(diff&(1<<i)) u = par[u][i];      
    if(u==v) return u;
    for(int i = log_n-1; i >= 0; i--) if(par[u][i] != par[v][i]){
        u = par[u][i], v = par[v][i];
    }  
    return par[u][0];
}

void dfs(int u, int pa){
    
    in[u] = t++;
    base[in[u]] = (pa==-1) ? fst_pow[val[u]] : add(fst_pow[val[u]], base[in[pa]]); 
    
    for(auto v : adj[u]) if(v != pa){
        
        depth[v] = depth[u] + 1;
        
        par[v][0] = u;
        for(int i = 1; i < log_n; i++){
            par[v][i] = par[par[v][i-1]][i-1];
        }
        
        dfs(v, u);
    }    
    
    out[u] = t-1;
}

int next_prime(int i){
    
    while(true){
        
        bool is_prime = true;
        for(int j = 2; j*j <= i; j++) if(i%j==0){
            is_prime = false;
            break;
        }
        
        if(is_prime) return i;
        i++;
    }    
}

void init(){
    
    p[0] = 1e9+7;
    p[1] = 1e9+9;
    b[0] = next_prime(NMAX);
    b[1] = next_prime(b[0]+1);
    
    fst_pow[0] = ans_len[0] = {1, 1};
    
    for(int i = 1; i < NMAX; i++){
        fst_pow[i] = mul(fst_pow[i-1], b);
        ans_len[i] = add(ans_len[i-1], fst_pow[i]);
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    init();
        
    int t; cin >> t; while(t--){

        cin >> n >> m;
        
        init:{
            ::t = 0;
            log_n = ceil(log2(double(n)));
            memset(tree, 0, sizeof tree);
            for(int i = 0; i < n; i++) adj[i].clear();
        }
        
        for(int i = 0; i < n; i++){
            cin >> val[i];
            val[i]--;
        }
        
        for(int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
            
        dfs(0, -1);
        build(1, 0, n-1);
        
        while(m--){
            
            int x;
            cin >> x;
            
            if(x==1){
                
                int u, v;
                cin >> u >> v;
                u--, v--;
                
                int g = lca(u, v);
                
                auto que_0 = query(1, 0, n-1, in[u]);
                auto que_1 = query(1, 0, n-1, in[v]);
                auto que_2 = query(1, 0, n-1, in[g]);
                
                que_2 = mul(que_2, {-2, -2});
                que_2 = add(que_2, fst_pow[val[g]]);
                
                auto que = add(que_0, add(que_1, que_2));
                
                int dist = depth[u] + depth[v] -2 * depth[g];
                
                cout << (que==ans_len[dist] ? "Yes" : "No") << endl;
            }
            else{
                
                int u, nval;
                cin >> u >> nval;
                u--, nval--;
                
                auto old_val = fst_pow[val[u]];
                auto new_val = fst_pow[nval];
                
                auto tmp_upd = add(new_val, mul(old_val, {-1, -1}));
                
                update(1, 0, n-1, in[u], out[u], tmp_upd);
                
                val[u] = nval;
            }
        }
    }	
}
