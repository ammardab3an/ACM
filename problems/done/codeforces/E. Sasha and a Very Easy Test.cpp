// Problem: E. Sasha and a Very Easy Test
// Contest: Codeforces - Codeforces Round 539 (Div. 1)
// URL: https://codeforces.com/contest/1109/problem/E
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

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
const double EPS = 1e-9;
const double  PI = acos(-1);

int MOD = 1e9 + 7;
int MOD_PHI = MOD-1;

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
	return pow_exp(x, MOD_PHI-1);
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

int phi(int n, vi &factors){
	
	{
		int m = n;
		
		for(int i = 2; i*i <= m; i++) if(m%i==0){
			factors.push_back(i);
			while(m%i==0) m /= i;
		}
		
		if(m > 1) factors.push_back(m);
	}
	
	int ans = 0;
	
	int sz = factors.size();
	for(int i = 0; i < (1<<sz); i++){
		
		int x = 1;
		for(int j = 0; j < sz; j++) if((i>>j)&1){
			x *= factors[j];
		}
		
		int l = __builtin_popcount(i);
		
		if(l&1){
			ans -= n/x;
		}
		else{
			ans += n/x;
		}
	}
	
	return ans;
}

struct seg_tree0{
	
	int n;
	vector<map<int, int>> tree;	
	
	seg_tree0(int n) : n(n) {
		tree.resize(n*4);
	}
	
	void merge(map<int, int> &a, const map<int, int> &b){
		for(auto [v, f] : b){
			a[v] += f;
		}	
	}
	
	void update(int nd, int l, int r, int q_l, int q_r, const map<int, int> &mp){
		
		if(r < q_l || q_r < l){
			return;
		}
		
		if(q_l <= l && r <= q_r){
			merge(tree[nd], mp);
			return;
		}
		
		int mid = (l+r)/2;
		update(nd*2, l, mid, q_l, q_r, mp);
		update(nd*2+1, mid+1, r, q_l, q_r, mp);
	}
	
	void update(int l, int r, map<int, int> mp){
		update(1, 0, n-1, l, r, mp);
	}
	
	void query(int nd, int l, int r, int p, map<int, int> &mp){
		
		merge(mp, tree[nd]);
		
		if(l==r){
			return;
		}
		
		int mid = (l+r)/2;
		
		if(p <= mid){
			query(nd*2, l, mid, p, mp);
		}
		else{
			query(nd*2+1, mid+1, r, p, mp);
		}
	}
	
	int query(int p){
		map<int, int> mp;
		query(1, 0, n-1, p, mp);
		int x = 1;
		for(auto [v, f] : mp){
			x = mul(x, pow_exp(v, f));
		}
		return x;
	}
};

struct seg_tree1{
	
	int n;
	vi tree;
	vi lazy[2];
	vi vals[2];
	
	seg_tree1(vi vals0, vi vals1){
		n = vals0.size();
		vals[0] = vals0;
		vals[1] = vals1;
		tree.resize(n*4);
		lazy[0].resize(n*4, 1);
		lazy[1].resize(n*4, 1);
		build(1, 0, n-1);
	}
	
	void build(int nd, int l, int r){
		
		if(l==r){
			tree[nd] = mul(vals[0][l], vals[1][l]);
			return;
		}	
		
		int mid = (l+r)/2;
		build(nd*2, l, mid);
		build(nd*2+1, mid+1, r);
		
		tree[nd] = add(tree[nd*2], tree[nd*2+1]);
	}
	
	void push(int nd, int l, int r){
		
		if(lazy[0][nd]==1 && lazy[1][nd]==1){
			return;
		}
		
		if(l==r){
			vals[0][l] = mul(vals[0][l], lazy[0][nd]);
			vals[1][l] = mul(vals[1][l], lazy[1][nd]);
			tree[nd] = mul(vals[0][l], vals[1][l]);
		}
		else{
			tree[nd] = mul(tree[nd], mul(lazy[0][nd], lazy[1][nd]));
		}
		
		if(l != r){
			for(auto k : {0, 1}){
				lazy[k][nd*2] = mul(lazy[k][nd*2], lazy[k][nd]);
				lazy[k][nd*2+1] = mul(lazy[k][nd*2+1], lazy[k][nd]);
			}
		}
		
		lazy[0][nd] = lazy[1][nd] = 1;
	}
	
	void update(int nd, int l, int r, int q_l, int q_r, int b, int x){
		
		push(nd, l, r);
		
		if(r < q_l || q_r < l){
			return;
		}
		
		if(q_l <= l && r <= q_r){
			lazy[b][nd] = mul(lazy[b][nd], x);
			push(nd, l, r);
			return;
		}
		
		int mid = (l+r)/2;
		update(nd*2, l, mid, q_l, q_r, b, x);
		update(nd*2+1, mid+1, r, q_l, q_r, b, x);
		
		tree[nd] = add(tree[nd*2], tree[nd*2+1]);
	}
	
	void update(int l, int r, int b, int x){
		update(1, 0, n-1, l, r, b, x);
	}
	
	void update_pnt(int nd, int l, int r, int p, int x){
		
		push(nd, l, r);
		
		if(l==r){
			vals[0][l] = x;
			tree[nd] = mul(vals[0][l], vals[1][l]);
			return;
		}
		
		int mid = (l+r)/2;
		
		if(p <= mid){
			update_pnt(nd*2, l, mid, p, x);
		}
		else{
			update_pnt(nd*2+1, mid+1, r, p, x);
		}
		
		tree[nd] = add(tree[nd*2], tree[nd*2+1]);
	}
	
	void update_pnt(int p, int x){
		update_pnt(1, 0, n-1, p, x);
	}
	
	int query(int nd, int l, int r, int q_l, int q_r){
		
		push(nd, l, r);
		
		if(r < q_l || q_r < l){
			return 0;
		}
		
		if(q_l <= l && r <= q_r){
			return tree[nd];
		}
		
		int mid = (l+r)/2;
		int st_path = query(nd*2, l, mid, q_l, q_r);
		int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
		
		return add(st_path, nd_path);
	}
	
	int query(int l, int r){
		return query(1, 0, n-1, l, r);
	}
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	
	int n, mod;
	cin >> n >> mod;
	
	vi mod_factors;
	
	::MOD = mod;
	::MOD_PHI = phi(mod, mod_factors);
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	auto calc = [&](int x)->pair<int, map<int, int>>{
			
		map<int, int> mp;
		for(auto f : mod_factors){
			
			int cnt = 0;
			while(x%f==0){
				cnt++;
				x /= f;
			}
			
			if(cnt){
				mp[f] = cnt;
			}
		}
		
		return {x, mp};
	};
	
	seg_tree0 st0(n);
	vi vals0(n), vals1(n);
	
	for(int i = 0; i < n; i++){
		
		auto [y, mp] = calc(vec[i]);
		
		vals1[i] = y;
		vals0[i] = vec[i]/y;
		
		if(!mp.empty()){
			st0.update(i, i, mp);	
		}
	}
	
	seg_tree1 st1(vals0, vals1);
	
	int q; cin >> q; while(q--){
		
		int k;
		cin >> k;
		
		if(k==1){
			
			int l, r, x;
			cin >> l >> r >> x;
			l--, r--;
			
			auto [y, mp] = calc(x);
			
			st1.update(l, r, 0, x/y);
			st1.update(l, r, 1, y);
			st0.update(l, r, mp);
		}
		else if(k==2){
			
			int p, x;
			cin >> p >> x;
			p--;
			
			auto [y, mp] = calc(x);
			
			for(auto &[v, f] : mp){
				f = -f;
			}
			
			st1.update(p, p, 1, inv(y));
			st0.update(p, p, mp);
			st1.update_pnt(p, st0.query(p));
		}
		else{
			
			int l, r;
			cin >> l >> r;
			l--, r--;
			
			int ans = st1.query(l, r);
			cout << ans << endl;
		}
	}
}
