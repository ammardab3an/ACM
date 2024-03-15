// Problem: E. Sum Over Zero
// Contest: Codeforces - Codeforces Round 851 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1788/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include <bits/stdc++.h>

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

// int fac[NMAX], ifac[NMAX];
// 
// void init(){
// 	
	// fac[0] = 1;
	// for(int i = 1; i < NMAX; i++){
		// fac[i] = mul(fac[i-1], i);
	// }
// 	
	// ifac[NMAX-1] = inv(fac[NMAX-1]);
	// for(int i = NMAX-2; i >= 0; i--){
		// ifac[i] = mul(ifac[i+1], i+1);
	// }
// }
// 
// int choose(int n, int c){
	// assert(n >= c);
	// return mul(fac[n], mul(ifac[c], ifac[n-c]));
// }

struct segTree{
	
	vi tree;
	
	segTree(){}
	
	segTree(int n){
		tree = vi(n<<2, -INFLL);
	}
	 
	void update(int nd, int l, int r, int p, int v){
		
		if(p < l || r < p){
			return;
		}
		
		if(l==r){
			tree[nd] = max(tree[nd], v);
			return;
		}
		
		int mid = (l+r)/2;
		update(nd*2, l, mid, p, v);
		update(nd*2+1, mid+1, r, p, v);
		
		tree[nd] = max(tree[nd*2], tree[nd*2+1]);
	}
	
	int query(int nd, int l, int r, int q_l, int q_r){
		
		if(r < q_l || q_r < l){
			return -INFLL;
		}
		
		if(q_l <= l && r <= q_r){
			return tree[nd];
		}
		
		int mid = (l+r)/2;
		int st_path = query(nd*2, l, mid, q_l, q_r);
		int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
		
		return max(st_path, nd_path);
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
	
	int n;
	cin >> n;
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	vi pre = vec;
	for(int i = 1; i < n; i++){
		pre[i] += pre[i-1];
	}
	
	vi tmp = pre;
	tmp.push_back(0);
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	
	for(auto &e : pre){
		e = lower_bound(tmp.begin(), tmp.end(), e)-tmp.begin();
	}
	
	int sz = tmp.size();
	segTree st0(sz), st1(sz);
	
	int zero = lower_bound(tmp.begin(), tmp.end(), 0)-tmp.begin();
	st0.update(1, 0, sz-1, zero, -(-1));
	st1.update(1, 0, sz-1, zero, 0);
	
	// for(auto e : pre){
		// cout << e << ' ';
	// } cout << endl;
	
	for(int i = 0; i < n; i++){
		
		int e = pre[i];
		
		int st_path = i+st0.query(1, 0, sz-1, 0, e);
		int nd_path = st1.query(1, 0, sz-1, e+1, sz-1);
		int cans = max(st_path, nd_path);
		
		// cout << i << ' ' << st_path << ' ' << nd_path << endl;
		
		st0.update(1, 0, sz-1, e, cans-i);
		st1.update(1, 0, sz-1, e, cans);
	}
	
	int ans = st1.query(1, 0, sz-1, 0, sz-1);
	cout << ans << endl;
}
