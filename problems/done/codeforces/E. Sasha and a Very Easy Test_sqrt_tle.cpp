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
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b, int MOD){
	int ret = (1ll * a * b) % MOD;
	return ret;
}
 
int add(int a, int b, int MOD){
	int ret = (1ll * a + b) % MOD;
	return ret;
}
 
int pow_exp(int n, int p, int MOD){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1, MOD), MOD);
	int tmp = pow_exp(n, p/2, MOD);
	return mul(tmp, tmp, MOD);
}

// int inv(int x, int MOD){
	// return pow_exp(x, MOD-2, MOD);
// }
 
const int NMAX = 1e5 + 10;
const int BLOCK = 500; // ceil(sqrt(double(NMAX)));

vi primes;
vpii factors[NMAX];

void init(){
	
	for(int i = 1; i < NMAX; i++){
		
		auto &cur = factors[i];
		
		int x = i;
		for(int j = 2; j*j <= x; j++){
			
			int cnt = 0;
			while(x%j==0){
				cnt++;
				x /= j;
			}
			
			if(cnt){
				cur.push_back({j, cnt});
			}
		}
		
		if(x > 1){
			cur.push_back({x, 1});
		}
		
		if(cur.size()==1){
			primes.push_back(i);
		}
		
		for(auto &[v, f] : cur){
			v = lower_bound(primes.begin(), primes.end(), v)-primes.begin();
		}
	}
}

struct ds{
	
	vi tree;
	vi vals;
	int mod;
	
	ds(){
		
	}
	
	ds(int mod) : mod(mod){
		tree.resize(primes.size()*4, 1);
		vals.resize(primes.size());
	}
	
	void update(int nd, int l, int r, int p, int v){
		
		if(l==r){
			vals[p] += v;
			assert(vals[p] >= 0);
			tree[nd] = pow_exp(primes[p], vals[p], mod);
			return;
		}
		
		int mid = (l+r)/2;
		if(p <= mid){
			update(nd*2, l, mid, p, v);
		}
		else{
			update(nd*2+1, mid+1, r, p, v);
		}
		
		tree[nd] = mul(tree[nd*2], tree[nd*2+1], mod);
	}
	
	void update(int p, int v){
		update(1, 0, primes.size()-1, p, v);
	}
	
	int query(){
		return tree[1];
	}
};

struct seg_tree{
	
	int n;
	vi tree;
	vi lazy;
	vi vals;
	int mod;
	
	seg_tree(){
		
	}
	
	seg_tree(const vi &vals, int mod) : vals(vals), mod(mod){
		n = vals.size();
		tree.resize(n*4);
		lazy.resize(n*4, 1);
		build(1, 0, n-1);
	}
	
	void build(int nd, int l, int r){
		
		if(l==r){
			tree[nd] = vals[l];
			return;
		}
		
		int mid = (l+r)/2;
		build(nd*2, l, mid);
		build(nd*2+1, mid+1, r);
		
		tree[nd] = add(tree[nd*2], tree[nd*2+1], mod);
	}
	
	void update(int nd, int l, int r, int q_l, int q_r, int x){
		
		push(nd, l, r);
		
		if(r < q_l || q_r < l){
			return;
		}
		
		if(q_l <= l && r <= q_r){
			lazy[nd] = mul(lazy[nd], x, mod);
			push(nd, l, r);
			return;
		}
		
		int mid = (l+r)/2;
		update(nd*2, l, mid, q_l, q_r, x);
		update(nd*2+1, mid+1, r, q_l, q_r, x);
		
		tree[nd] = add(tree[nd*2], tree[nd*2+1], mod);
	}
	
	void update(int l, int r, int x){
		update(1, 0, n-1, l, r, x);
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
		
		return add(st_path, nd_path, mod);
	}
	
	int query(int l, int r){
		return query(1, 0, n-1, l, r);
	}
	
	void push(int nd, int l, int r){
		
		if(lazy[nd] == 1){
			return;
		}
		
		tree[nd] = mul(tree[nd], lazy[nd], mod);
		
		if(l != r){
			lazy[nd*2] = mul(lazy[nd*2], lazy[nd], mod);
			lazy[nd*2+1] = mul(lazy[nd*2+1], lazy[nd], mod);
		}
		
		lazy[nd] = 1;
	}
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	init();
	
	int n, mod;
	cin >> n >> mod;
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	int q;
	cin >> q;
	
	vector<array<int, 4>> queries(q);
	
	for(auto &v : queries){
		
		int k;
		cin >> k;
		
		if(k==1){
			int l, r, x;
			cin >> l >> r >> x;
			l--, r--;
			v = {1, l, r, x};
		}
		else if(k==2){
			int p, x;
			cin >> p >> x;
			p--;
			v = {2, p, x, 0};
		}
		else{
			int l, r;
			cin >> l >> r;
			l--, r--;
			v = {3, l, r, 0};
		}
	}
	
	seg_tree st;
	map<int, ds> mp;
	
	auto build = [&](int i){
		
		mp.clear();
		
		vi nxt;
		for(int j = 0; (i+j < q) && (j < BLOCK); j++){
			int p = i+j;
			if(queries[p][0]==2){
				nxt.push_back(queries[p][1]);
			}
		}
		
		sort(nxt.begin(), nxt.end());
		nxt.erase(unique(nxt.begin(), nxt.end()), nxt.end());
		reverse(nxt.begin(), nxt.end());
		
		vector<vpii> tmp(n+1);
		
		for(int j = 0; j < n; j++){
			for(auto [v, f] : factors[vec[j]]){
				tmp[j].push_back({v, f});
				tmp[j+1].push_back({v, -f});
			}
		}
		
		for(int j = 0; j < i; j++){
			
			auto cur = queries[j];
			
			if(cur[0] == 1){
				auto [k, l, r, x] = cur;
				for(auto [v, f] : factors[x]){
					tmp[l].push_back({v, f});
					tmp[r+1].push_back({v, -f});
				}
			}
			else if(cur[0] == 2){
				auto [k, p, x, z] = cur;
				for(auto [v, f] : factors[x]){
					tmp[p].push_back({v, -f});
					tmp[p+1].push_back({v, f});
				}
			}
		}
		
		vi vals(n);
		ds cur_ds(mod);
		
		for(int i = 0; i < n; i++){
			
			for(auto [v, f] : tmp[i]) if(f > 0){
				cur_ds.update(v, f);
			}
			for(auto [v, f] : tmp[i]) if(f <= 0){
				cur_ds.update(v, f);
			}
			
			if(!nxt.empty() && nxt.back()==i){
				nxt.pop_back();
				mp[i] = cur_ds;
			}
			else{			
				vals[i] = cur_ds.query();
			}
		}
		
		st = seg_tree(vals, mod);
	};
	
	
	for(int i = 0; i < q; i++){
		
		if(i%BLOCK == 0){
			build(i);
		}	
		
		auto cur = queries[i];
		
		if(cur[0]==1){
			
			auto [k, l, r, x] = cur;
			st.update(l, r, x);
			
			for(auto &[p, pds] : mp){
				if(l <= p && p <= r){
					for(auto [v, f] : factors[x]){
						pds.update(v, f);
					}
				}
			}
		}
		else if(cur[0]==2){
			
			auto [k, p, x, z] = cur;
			
			auto it = mp.find(p);
			assert(it != mp.end());
			
			for(auto [v, f] : factors[x]){
				it->second.update(v, -f);
			}
		}
		else{
			
			auto [k, l, r, z] = cur;
			int ans = st.query(l, r);
			for(auto &[p, pds] : mp){
				if(l <= p && p <= r){
					int cans = pds.query();
					ans = add(ans, cans, mod);
				}
			}
			
			cout << ans << endl;
		}
	}
}
