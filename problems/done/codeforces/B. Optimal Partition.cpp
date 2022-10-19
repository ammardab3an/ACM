// Problem: B. Optimal Partition
// Contest: Codeforces - Codeforces Round #783 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1667/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));


struct segTree{
	
	vi tree;
	
	segTree(){
		// tree = vi(NMAX<<2, -INFLL);
	}
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
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		vi pre(n);
		pre[0] = vec[0];
		for(int i = 1; i < n; i++){
			pre[i] = pre[i-1] + vec[i];
		}
		
		vi comp = pre;
		comp.push_back(0);
		sort(comp.begin(), comp.end());
		comp.resize(unique(comp.begin(), comp.end())-comp.begin());
		for(auto &i : pre){
			i = lower_bound(comp.begin(), comp.end(), i)-comp.begin();
		}
		
		int m = comp.size();
		
		auto calc = [&](int sm)->int{
			return sm>0 ? 1 : (sm<0 ? -1 : 0);
		};
		
		// for(auto i : pre) cout << i << ' '; cout << endl;
		
		int p0 = lower_bound(comp.begin(), comp.end(), 0)-comp.begin();
		
		vi dp(n);
		segTree st(m);
		
		dp[n-1] = calc(vec[n-1]);
		st.update(1, 0, m-1, pre[n-1], 0+n);
		
		for(int i = n-2; i >= 0; i--){
			
			/*
				pj-pi > 0
				pj > pi
			*/
			
			int st_path = calc(vec[i]) + dp[i+1];
			int nd_path = st.query(1, 0, m-1, i ? pre[i-1]+1 : p0+1, m-1) - i;
			dp[i] = max(st_path, nd_path);
			
			st.update(1, 0, m-1, pre[i], dp[i+1]+i+1);
		}
		
		// for(auto i : dp){
			// cout << i << ' ';
		// } cout << endl;
		
		int ans = dp[0];
		cout << ans << endl;
    }	
}
