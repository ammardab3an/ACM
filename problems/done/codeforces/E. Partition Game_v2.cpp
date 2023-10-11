// Problem: E. Partition Game
// Contest: Codeforces - Codeforces Round 721 (Div. 2)
// URL: https://codeforces.com/contest/1527/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

struct seg_tree{
	
	int n;
	vpii tree;
	vi lazy;
	
	seg_tree(int n) : n(n){
		tree.resize(n*4, {INFLL, INFLL});
		lazy.resize(n*4);
	}
	
	void push(int nd, int l, int r){
		if(!lazy[nd]) return;
		tree[nd].first += lazy[nd];
		if(l != r){
			lazy[nd*2] += lazy[nd];
			lazy[nd*2+1] += lazy[nd];
		}
		lazy[nd] = 0;
	}
	
	void update(int nd, int l, int r, int q_l, int q_r, int x){
		
		push(nd, l, r);
		
		if(r < q_l || q_r < l){
			return;
		}
		
		if(q_l <= l && r <= q_r){
			lazy[nd] += x;
			push(nd, l, r);
			return;
		}
		
		int mid = (l+r)/2;
		update(nd*2, l, mid, q_l, q_r, x);
		update(nd*2+1, mid+1, r, q_l, q_r, x);
		
		tree[nd] = min(tree[nd*2], tree[nd*2+1]);
	}
	
	void update(int nd, int l, int r, int p, pii x){
		
		push(nd, l, r);
		
		if(l==r){
			tree[nd] = x;
			return;
		}	
		
		int mid = (l+r)/2;
		
		if(p <= mid){
			update(nd*2, l, mid, p, x);
		}
		else{
			update(nd*2+1, mid+1, r, p, x);
		}
		
		tree[nd] = min(tree[nd*2], tree[nd*2+1]);
	}
	
	pii query(int nd, int l, int r, int q_l, int q_r){
		
		push(nd, l, r);
		
		if(r < q_l || q_r < l){
			return {INFLL, INFLL};
		}
		
		if(q_l <= l && r <= q_r){
			return tree[nd];
		}
		
		int mid = (l+r)/2;
		pii st_path = query(nd*2, l, mid, q_l, q_r);
		pii nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
		
		return min(st_path, nd_path);
	}
	
	void update(int l, int r, int x){
		update(1, 0, n-1, l, r, x);
	}
	
	void update(int p, pii x){
		update(1, 0, n-1, p, x);
	}
	
	pii query(int l, int r){
		return query(1, 0, n-1, l, r);
	}
};

int32_t main(){
    
    fastIO;
	
    int n, k;
    cin >> n >> k;
    
    vi vec(n);
    for(auto &i : vec) cin >> i, --i;
    
	if(n==0){
		rng = mt19937(123);
		n = 35000;
		k = 100;
		vec = vi(n);
		for(auto &i : vec) i = rand(0, n-1);
	}
	
	auto calc = [&](int x_factor){
		
		vpii dp(n);
		
		vi lst(n, -1);
		seg_tree tree(n+1);
		tree.update(0, {0, 0});
		
		for(int i = 0; i < n; i++){
			
			if(lst[vec[i]] != -1){
				tree.update(0, lst[vec[i]], i-lst[vec[i]]);
			}	
						
			lst[vec[i]] = i;
			
			pii cans = tree.query(0, i);
			cans.first += x_factor;
			cans.second += 1;
			
			dp[i] = cans;
			tree.update(i+1, cans);
			
			// for(int j = 0; j <= i+1; j++){
				// cout << tree.query(j, j).first << ' ';
			// }
			// cout << endl;
		}
	
		// cout << x_factor << endl;
		// for(auto e : dp) cout << e.first << ' '; cout << endl;
		// for(auto e : dp) cout << e.second << ' '; cout << endl;
		
		return dp.back();
	};
	
	int l = 0;
	int r = INFLL;
	
	pii bs_ans = {-1, -1};
	
	while(l <= r){
		
		int mid = (l+r)/2;
		
		pii cans = calc(mid);
		
		if(cans.second <= k){
			bs_ans = {cans.first, mid};
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
		
	cout << bs_ans.first - bs_ans.second*k << endl;
}
