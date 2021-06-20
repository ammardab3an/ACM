// Problem: Count on a tree
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/COT/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>      iii;
typedef pair<ll, pll>      lll;
typedef vector<int>         vi;
typedef vector<ll>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

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

int n, m, LOG;
int arr[NMAX];
vi adj[NMAX];
int comp[NMAX], comp_sz;
int par[NMAX][LOG_MAX];
int depth[NMAX];

struct node{
    
    int cnt;
    node *left, *right;
    
    node(int cnt, node *left, node *right): 
        cnt(cnt), left(left), right(right) {}
    
    node* insert(int l, int r, int w);
};

node *root[NMAX];
node *null = new node(0, nullptr, nullptr);

node *node::insert(int l, int r, int w){
    
    if(w < l || r < w){
        return this;
    }
    
    if(l == r){
        return new node(this->cnt+1, null, null);
    }
    
    int mid = (l+r)/2;
    node *left = this->left->insert(l, mid, w);
    node *right = this->right->insert(mid+1, r, w);
    return new node(this->cnt+1, left, right);
};

int query(node *a, node *b, node *c, node *d, int l, int r, int k){
    
    if(l == r){
        return l;
    }
    
    int cur_cnt = (a->left->cnt) + (b->left->cnt) - (c->left->cnt) - (d->left->cnt);
    
    int mid = (l+r)/2;
    
    if(cur_cnt >= k){
        return query(a->left, b->left, c->left, d->left, l, mid, k);
    }
    else{
        return query(a->right, b->right, c->right, d->right, mid+1, r, k-cur_cnt);
    }
}

void compress(){
    sort(comp, comp+comp_sz);
    comp_sz = unique(comp, comp+comp_sz) - comp;
    for(int i = 0; i < n; i++){
        arr[i] = lower_bound(comp, comp+comp_sz, arr[i]) - comp;
    }
}

int lca(int u, int v){
    
    if(depth[u] < depth[v]) 
        swap(u, v);
        
    int diff = depth[u] - depth[v];

    for(int i = 0; i < LOG; i++) 
        if((diff>>i)&1) 
            u = par[u][i];

    if(u == v) return u;

    for(int i = LOG-1; i >= 0; i--) 
        if(par[u][i] != par[v][i]) 
            u = par[u][i], v = par[v][i];

    return par[u][0];
}

void dfs(int u, int p){
    
    for(auto v : adj[u]) if(v != p){
        
        depth[v] = depth[u]+1;
        
        par[v][0] = u;
        for(int i = 1; i < LOG; i++) if(par[v][i-1] != -1)
            par[v][i] = par[par[v][i-1]][i-1];
        
        root[v] = root[u]->insert(0, comp_sz-1, arr[v]);
        
        dfs(v, u);        
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
    
    LOG = ceil(log2(double(n)));
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        comp[comp_sz++] = arr[i];
    }
    
    compress();
    
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    null->left = null->right = null;
    root[0] = null->insert(0, comp_sz-1, arr[0]);
    
    memset(par, -1, sizeof par);
    
    dfs(0, -1);
    
    while(m--){
        
        int u, v, k;
        cin >> u >> v >> k;
        u--, v--;
        
        int _lca = lca(u, v);
        int ans = query(root[u], root[v], root[_lca], (par[_lca][0]==-1) ? null : root[par[_lca][0]], 0, comp_sz-1, k);
        
        cout << comp[ans] << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  notes : 
  
  
*/    
