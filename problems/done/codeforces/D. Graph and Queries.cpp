// Problem: D. Graph and Queries
// Contest: Codeforces - Codeforces Round 673 (Div. 1)
// URL: https://codeforces.com/contest/1416/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 5e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int fac[NMAX], ifac[NMAX];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

struct seg_tree{
	
	int n;
	vi vals;
	vpii tree;
	
	seg_tree(const vi &vals){
		this->n = vals.size();
		this->vals = vals;
		this->tree = vpii(n*4);
		build(1, 0, n-1);
	}
	
	void build(int nd, int l, int r){
		
		if(l==r){
			tree[nd] = {vals[l], l};
			return;
		}
		
		int mid = (l+r)/2;
		build(nd*2, l, mid);
		build(nd*2+1, mid+1, r);
		
		tree[nd] = max(tree[nd*2], tree[nd*2+1]);
	}
	
	void update(int nd, int l, int r, int p, int v){
		
		if(l==r){
			vals[l] = v;
			tree[nd] = {v, l};
			return;
		}
		
		int mid = (l+r)/2;
		
		if(p <= mid){
			update(nd*2, l, mid, p, v);
		}
		else{
			update(nd*2+1, mid+1, r, p, v);
		}
		
		tree[nd] = max(tree[nd*2], tree[nd*2+1]);
	}
	
	void update(int p, int v){
		update(1, 0, n-1, p, v);
	}
	
	pii query(int nd, int l, int r, int q_l, int q_r){
		
		if(r < q_l || q_r < l){
			return {-1, -1};
		}
		
		if(q_l <= l && r <= q_r){
			return tree[nd];
		}
		
		int mid = (l+r)/2;
		pii st_path = query(nd*2, l, mid, q_l, q_r);
		pii nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
		
		return max(st_path, nd_path);
	}
	
	pii query(int l, int r){
		return query(1, 0, n-1, l, r);
	}
};

int n, m, q, nd_id;
int arr[NMAX];
vi adj[NMAX];
int node_id[NMAX];
int par[NMAX];
int par_lca[NMAX][LOG_MAX];
int tin[NMAX], tout[NMAX], tim;
bool vis[NMAX];
bool dfs_vis[NMAX];
int pos[NMAX];

int get_par(int u){
	return par[u] = (par[u]==u) ? u : get_par(par[u]);
}

bool merge(int u, int v, int t){
	
	if((u=get_par(u)) == (v=get_par(v))){
		return false;
	}	
	
	int cid = nd_id++;
	
	par[cid] = cid;
	adj[cid].push_back(u);
	adj[cid].push_back(v);
	if(t) node_id[t] = cid;
	
	par[u] = cid;
	par[v] = cid;
	
	return true;
}

void dfs(int u, bool is_root=false){
	
	tin[u] = tim;
	
	if(is_root){
		for(int i = 0; i < LOG_MAX; i++){
			par_lca[u][i] = u;
		}
	}	
	
	if(adj[u].empty()){
		pos[u] = tim++;
	}
	
	for(auto v : adj[u]){
		
		par_lca[v][0] = u;
		for(int i = 1; i < LOG_MAX; i++){
			par_lca[v][i] = par_lca[par_lca[v][i-1]][i-1];
		}
		
		dfs(v);
	}
	
	tout[u] = tim;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	vpii edges(m);
	vector<bool> edges_vis(m);
	
	for(auto &[u, v] : edges){
		cin >> u >> v;
		u--, v--;
	}
	
	vpii queries(q);
	for(auto &[a, b] : queries){
		cin >> a >> b;
		b--;
		if(a==2){
			edges_vis[b] = true;
		}
	}
	
	nd_id = n;
	for(int i = 0; i < n; i++){
		par[i] = i;
	}
	
	for(int i = 0; i < m; i++) if(!edges_vis[i]){
		auto [u, v] = edges[i];
		merge(u, v, 0);
	}
	
	int tt = 1;
	for(int i = q-1; i >= 0; i--) if(queries[i].first==2){
		
		auto [u, v] = edges[queries[i].second];
		
		if(merge(u, v, tt)){
			tt++;
		}
		else{
			queries[i].first = -1;
		}
	}
	
	for(int i = 0; i < n; i++){
		int p = get_par(i);
		if(!dfs_vis[p]){
			dfs_vis[p] = true;
			dfs(p, true);
		}
	}
	
	vi tmp(n);
	for(int i = 0; i < n; i++){
		tmp[pos[i]] = arr[i];
	}
	
	// for(auto i : tmp) cout << i << ' '; cout << endl;
	
	seg_tree tree(tmp);
	
	for(auto [a, b] : queries){
		
		if(a==1){
			
			int u = b;
			
			for(int i = LOG_MAX-1; i >= 0; i--) if(!vis[par_lca[u][i]]){
				u = par_lca[u][i];
			}
			
			int l = tin[u];
			int r = tout[u]-1;
			
			pii qq = tree.query(l, r);
			
			if(qq.first != 0){
				tree.update(qq.second, 0);
			}
			
			cout << qq.first << endl;
		}
		else if(a==2){
			vis[node_id[--tt]] = true;
		}
	}
}
