// Problem: Path Queries II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2134
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define ll  int64_t

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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, q, log_n;
vi adj[NMAX];
int val[NMAX];
int arr[NMAX];
int t, tin[NMAX], tout[NMAX];
int tree[NMAX << 2];
int nxt[NMAX];
int sz[NMAX];
int par[NMAX][LOG_MAX];
int depth[NMAX];

void build(int nd, int l, int r){
	if(l == r){
		tree[nd] = arr[l];
		return;
	}
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	tree[nd] = max(tree[nd*2], tree[nd*2+1]);
}
void update(int nd, int l, int r, int p, int val){
	if(p < l || r < p){
		return;
	}
	if(l == r){
		arr[l] = tree[nd] = val;
		return;
	}
	int mid = (l+r)/2;
	update(nd*2, l, mid, p, val);
	update(nd*2+1, mid+1, r, p, val);
	tree[nd] = max(tree[nd*2], tree[nd*2+1]);
}
int query(int nd, int l, int r, int q_l, int q_r){
	if(r < q_l || q_r < l){
		return 0;
	}
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	int mid = (l+r)/2;
	int st_path = query(nd*2, l, mid, q_l, q_r);
	int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	return max(st_path, nd_path);
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

		if((sz[v] > sz[adj[u][0]]) || (adj[u][0]==p)){
			swap(adj[u][0], v);
		}
	}
}


int lca(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	int dif = depth[u] - depth[v];
	for(int i = 0; i < log_n; i++) if((dif>>i)&1) u = par[u][i];
	if(u==v) return u;
	for(int i = log_n-1; i >= 0; i--) if(par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
	return par[u][0];
}

void hld(int u, int p){

	tin[u] = t++;
	arr[tin[u]] = val[u];

	for(auto v : adj[u]) if(v != p){
		nxt[v] = (v==adj[u][0]) ? nxt[u] : v;
		hld(v, u);
	}

	tout[u] = t-1;
}

int query_up(int u, int p){

	int ret = 0;

	while(true){

		if(nxt[u] == nxt[p]){
			int que = query(1, 0, n-1, tin[p], tin[u]);
			ret = max(ret, que);
			break;
		}

		int que = query(1, 0, n-1, tin[nxt[u]], tin[u]);
		ret = max(ret, que);
		u = par[nxt[u]][0];
	}

	return ret;
}

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);

    cin >> n >> q;
    for(int i = 0; i < n; i++){
    	cin >> val[i];
    }
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    log_n = ceil(log2(double(n)));

    dfs(0, -1);
    hld(0, -1);
    assert(t==n);
    build(1, 0, n-1);

    while(q--){
    	int k;
    	cin >> k;
    	if(k==1){
    		int u, x;
    		cin >> u >> x;
    		u--;
    		update(1, 0, n-1, tin[u], x);
    	}
    	else{
    		int u, v;
    		cin >> u >> v;
    		u--, v--;
    		int g = lca(u, v);
    		int ans = max(query_up(u, g), query_up(v, g));
    		cout << ans << ' ';
    	}
    }
}
