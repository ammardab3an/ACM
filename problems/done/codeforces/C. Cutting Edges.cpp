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
 
const int NMAX = 1e5 + 10;

struct seg_tree0{
	
	int n;
	vi tree;
	
	seg_tree0(int n) : n(n){
		tree = vi(n*4);
	}
	
	void update(int nd, int l, int r, int p, int v){
		
		if(l==r){
			tree[nd] = v;
			return;
		}
		
		int mid = (l+r)/2;
		if(p <= mid){
			update(nd*2, l, mid, p, v);
		}
		else{
			update(nd*2+1, mid+1, r, p, v);
		}
		
		tree[nd] = tree[nd*2] + tree[nd*2+1];
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
		
		return st_path + nd_path;
	}
	
	void update(int p, int v){
		update(1, 0, n-1, p, v);
	}
	
	int query(int l, int r){
		return query(1, 0, n-1, l, r);
	}
};

struct seg_tree1{
	
	int n;
	vector<vi> tree;
	
	seg_tree1(int n) : n(n){
		tree = vector<vi>(n*4);
	}
	
	void update(int nd, int l, int r, int q_l, int q_r, int v){
		
		if(r < q_l || q_r < l){
			return;
		}
		
		if(q_l <= l && r <= q_r){
			tree[nd].push_back(v);
			return;
		}
		
		int mid = (l+r)/2;
		update(nd*2, l, mid, q_l, q_r, v);
		update(nd*2+1, mid+1, r, q_l, q_r, v);
	}
	
	int query(int nd, int l, int r, int p, int x){
		
		auto it = upper_bound(tree[nd].begin(), tree[nd].end(), x);
		int ret = it!=tree[nd].begin() ? *(--it) : -1;
		
		if(l==r){
			return ret;
		}
		
		int mid = (l+r)/2;
		
		if(p <= mid){
			ret = max(ret, query(nd*2, l, mid, p, x));
		}
		else{
			ret = max(ret, query(nd*2+1, mid+1, r, p, x));
		}
		
		return ret;
	}
	
	void update(int l, int r, int v){
		update(1, 0, n-1, l, r, v);
	}
	
	int query(int p, int x){
		return query(1, 0, n-1, p, x);
	}
};

int pos[NMAX];
int par[NMAX];
pii rngs[NMAX];

int get_par(int u){
	return par[u] = (par[u]==u) ? u : get_par(par[u]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n, m;
	cin >> n >> m;
	
	vi vec(n);
	int sm_vals = 0;
	for(auto &i : vec) cin >> i, sm_vals += i;
	
	vector<iii> edges(m);
	for(int i = 0; i < m; i++){
		int u, v, d;
		cin >> u >> v >> d;
		u--, v--;
		edges[i] = {d, {u, v}};
	}
	
	sort(edges.begin(), edges.end());
	
	vector<vi> tmp_ord(n);
	vector<set<int>> tmp(n);
	
	for(int i = 0; i < n; i++){
		tmp_ord[i].push_back(i);
		pos[i] = 0;
		par[i] = i;
	}
	
	for(int i = 0; i < edges.size(); i++){
		
		auto [d, uv] = edges[i];
		auto [u, v] = uv;
		
		u = get_par(u);
		v = get_par(v);
		
		if(u==v) continue;
		
		if(tmp[u].size() < tmp[v].size()){
			swap(u, v);
		}
		
		int old_sz = tmp_ord[u].size();
		
		for(auto e : tmp_ord[v]){
			tmp_ord[u].push_back(e);	
			pos[e] += old_sz;
		}
		
		for(auto e : tmp[v]){
			
			if(e != -1){
				auto &[l, r] = rngs[e];
				l += old_sz;
				r += old_sz;
			}
			
			tmp[u].insert(e);
		}
		
		rngs[i] = {0, tmp_ord[u].size()-1};
		tmp[u].insert(i);
		
		par[v] = u;
		tmp[v].clear();
		tmp_ord[v].clear();
	}
	
	seg_tree0 seg0(n);
	seg_tree1 seg1(n);
	
	{
		int p = get_par(0);
		
		for(auto e : tmp[p]){
			auto [l, r] = rngs[e];
			seg1.update(l, r, e);
		}
		
		for(int i = 0; i < n; i++){
			seg0.update(pos[i], vec[i]);
		}
	}
	
	int q; cin >> q; while(q--){
		
		int k;
		cin >> k;
		
		if(k==1){
			
			int u, nval;
			cin >> u >> nval;
			u--;
			
			sm_vals += nval-vec[u];
			vec[u] = nval;
			
			seg0.update(pos[u], vec[u]);
		}
		else{
			
			int u, x;
			cin >> u >> x;
			u--;
			
			if(x > sm_vals){
				cout << -1 << endl;
				continue;
			}
			
			int l = 0;
			int r = edges.size();
			
			int ans = -1;
			
			while(l <= r){
				
				int mid = (l+r)/2;
				int mx_rng = seg1.query(pos[u], mid-1);
				int cur_sm  = mx_rng==-1 ? vec[u] : seg0.query(rngs[mx_rng].first, rngs[mx_rng].second);
				
				if(cur_sm <= x){
					ans = mid;
					l = mid+1;
				}
				else{
					r = mid-1;
				}
			}
			
			cout << (ans!=-1 ? edges[ans].first-1 : 0) << endl;
		}
	}
}
