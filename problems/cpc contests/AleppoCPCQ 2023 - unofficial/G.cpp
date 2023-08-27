
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

struct seg_tree{
	
	int n;
	vi tree;
	vi lazy;
	
	seg_tree(int n) : n(n){
		tree = vi(n*4);
		lazy = vi(n*4);
	}	
	
	void push(int nd, int l, int r){
		if(!lazy[nd]) return;
		tree[nd] += (r-l+1) * lazy[nd];;
		if(l != r){
			lazy[nd*2] += lazy[nd];
			lazy[nd*2+1] += lazy[nd];
		}
		lazy[nd] = 0;
	}
	
	void update(int nd, int l, int r, int q_l, int q_r, int v){
		
		push(nd, l, r);
		
		if(r < q_l || q_r < l){
			return;
		}
		
		if(q_l <= l && r <= q_r){
			lazy[nd] += v;
			push(nd, l, r);
			return;
		}
		
		int mid = (l+r)/2;
		update(nd*2, l, mid, q_l, q_r, v);
		update(nd*2+1, mid+1, r, q_l, q_r, v);
		
		tree[nd] = tree[nd*2] + tree[nd*2+1];
	}
	
	void update(int l, int r, int v){
		update(1, 0, n-1, l, r, v);
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
		
		return st_path + nd_path;
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
	
    int t; cin >> t; while(t--){

		int n, k;
		cin >> n >> k;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		vi tmp(n);
		int cnt_zero = 0;
		for(int i = 0; i < n; i++){
			if(vec[i] != 0){
				tmp[i] = i-cnt_zero;
				cnt_zero = 0;
			}
			else{
				tmp[i] = i-cnt_zero;
				cnt_zero++;
			}
		}
		
		vi pre = vec;
		for(int i = 1; i < n; i++){
			pre[i] += pre[i-1];
		}
		
		auto calc = [&](int l, int r){
			return pre[r]-pre[l]+vec[l];	
		};
		
		int m;
		cin >> m;
		vpii queries(m);
		vector<vpii> tmp_queries(n);
		
		for(int i = 0; i < m; i++){
			auto [l, r] = queries[i];
			cin >> l >> r;
			l--, r--;
			tmp_queries[r].push_back({l, i});
		}
		
		vi ans(m);
		seg_tree st(n);
		
		for(int i = 0; i < n; i++){
			
			int l = 0;
			int r = i;
			
			int bs_ans = -1;
			
			while(l <= r){
				
				int mid = (l+r)/2;
				int sm = calc(mid, i);
				
				if(sm >= k){
					bs_ans = mid;
					l = mid+1;
				}
				else{
					r = mid-1;
				}
			}
			
			if(calc(bs_ans, i) == k){
				st.update(tmp[bs_ans], bs_ans, +1);
			}
			
			for(auto [l, q_i] : tmp_queries[i]){
				ans[q_i] += st.query(l, i);
			}
			
			// for(int i = 0; i < n; i++){
				// cout << st.query(i,i) << ' ';
			// } cout << endl;
		}
		
		for(auto e : ans) cout << e << endl;
    }	
}
