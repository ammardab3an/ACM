// Problem: C. Cutting Edges
// Contest: Codeforces - ACPC 2022
// URL: https://codeforces.com/gym/417678/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
const int NMAX = 2e5 + 10;
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

struct FenwickTree {
	
    int n;
    vector<int> bit;  // binary indexed tree

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int n, m, nd_id;
int arr[NMAX];
int par[NMAX];
int sz[NMAX];
vi adj[NMAX];
int edge_w[NMAX];
int depth[NMAX];
int par_lca[NMAX][LOG_MAX];
int tin[NMAX], tout[NMAX], tim;
int pos[NMAX];

int get_par(int u){
	return par[u] = (par[u]==u) ? u : get_par(par[u]);
}

bool merge(int u, int v, int d){
	
	if((u=get_par(u)) == (v=get_par(v))){
		return false;
	}	
	
	int cid = nd_id++;
	
	par[cid] = cid;
	sz[cid] = sz[u] + sz[v];
	adj[cid].push_back(u);
	adj[cid].push_back(v);
	edge_w[cid] = d;
	
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
		
		depth[v] = depth[u] + 1;
		
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
	
    cin >> n >> m;
    
    int tot_sm = 0;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    	tot_sm += arr[i];
    }
    
    vector<iii> edges(m);
    for(auto &[d, uv] : edges){
    	auto &[u, v] = uv;
    	cin >> u >> v >> d;
    	u--, v--;
    }
    
    sort(edges.begin(), edges.end());
    
    nd_id = n;
    for(int i = 0; i < n; i++){
    	par[i] = i;
    	sz[i] = 1;
    }
    
    for(auto [d, uv] : edges){
    	auto [u, v] = uv;
    	merge(u, v, d);
    }
    
    dfs(get_par(0), true);
    
    // for(int i = 0; i < n; i++){
    	// cout << pos[i] << ' ';
    // }
    // cout << endl;
    
    FenwickTree tree(n);
    for(int i = 0; i < n; i++){
    	tree.add(pos[i], arr[i]);
    }
    
    int q; cin >> q; while(q--){
    	
    	int k;
    	cin >> k;
    	
    	if(k==1){
    		int u, nval;
    		cin >> u >> nval;
    		u--;
    		tree.add(pos[u], nval-arr[u]);
    		tot_sm += nval-arr[u];
    		arr[u] = nval;
    	}
    	else{
    		
    		int u, mx_sm;
    		cin >> u >> mx_sm;
    		u--;
    		
    		if(mx_sm >= tot_sm){
    			cout << -1 << endl;
    			continue;
    		}
    		
    		while(u != par_lca[u][0]){
    			
    			int p = par_lca[u][0];
    			int l = tin[p];
    			int r = tout[p]-1;
    			
    			if(tree.sum(l, r) <= mx_sm){
    				u = p;
    			}
    			else{
    				break;
    			}
    		}
    		
    		cout << edge_w[par_lca[u][0]]-1 << endl;
    	}
    }
}
