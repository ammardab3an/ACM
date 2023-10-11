// Problem: D. Cleaning
// Contest: Codeforces - Codeforces Round 696 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1474/D
// Memory Limit: 256 MB
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

struct seg_tree{
	
	int n;
	vi vec;
	vi tree;
	vi lazy;
	
	seg_tree(const vi &v) : vec(v){
		n = v.size();
		tree.resize(n*4);
		lazy.resize(n*4);
		build(1, 0, n-1);
	}
	
	void push(int nd, int l, int r){
		if(!lazy[nd]) return;
		tree[nd] += lazy[nd];
		if(l != r){
			lazy[nd*2] += lazy[nd];
			lazy[nd*2+1] += lazy[nd];
		}
		lazy[nd] = 0;
	}
	
	void build(int nd, int l, int r){
		
		if(l==r){
			tree[nd] = vec[l];
			return;
		}
		
		int mid = (l+r)/2;
		build(nd*2, l, mid);
		build(nd*2+1, mid+1, r);
		
		tree[nd] = min(tree[nd*2], tree[nd*2+1]);
	}
	
	void update(int nd, int l, int r, int q_l, int q_r, int d){
		
		push(nd, l, r);
		
		if(r < q_l || q_r < l){
			return;
		}	
		
		if(q_l <= l && r <= q_r){
			lazy[nd] += d;
			push(nd, l, r);
			return;
		}
		
		int mid = (l+r)/2;
		update(nd*2, l, mid, q_l, q_r, d);
		update(nd*2+1, mid+1, r, q_l, q_r, d);
		
		tree[nd] = min(tree[nd*2], tree[nd*2+1]);
	}
	
	void update(int l, int r, int d){
		update(1, 0, n-1, l, r, d);
	}
	
	int query(int nd, int l, int r, int q_l, int q_r){
		
		push(nd, l, r);
		
		if(r < q_l || q_r < l){
			return INF;
		}
		
		if(q_l <= l && r <= q_r){
			return tree[nd];
		}
		
		int mid = (l+r)/2;
		int st_path = query(nd*2, l, mid, q_l, q_r);
		int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
		
		return min(st_path, nd_path);
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

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		int sm = 0;
		vi vec_0, vec_1;
		for(int i = 0; i < n; i++){
			sm = vec[i] - sm;
			if(i&1){
				vec_1.push_back(sm);
			}
			else{
				vec_0.push_back(sm);
			}
		}
		
		seg_tree st0(vec_0);
		seg_tree st1(vec_1);
		
		bool ans = false;
		
		bool b0 = st0.tree[1] >= 0;
		bool b1 = (n%2==0) || st0.query(st0.n-1, st0.n-1) == 0;
		bool b2 = st1.tree[1] >= 0;
		bool b3 = (n%2==1) || st1.query(st1.n-1, st1.n-1) == 0;
		
		if(b0 && b1 && b2 && b3){
			cout << "YES" << endl;
			continue;
		}
		
		for(int i = 0; i+1 < n; i++){
			
			int x = vec[i];
			int y = vec[i+1];
			int dif = y-x;
			
			// i -> y-x
			// i+2k -> -(x-y) + (y-x) -> -2*x + 2*y -> +2*(y-x)
			// i+2k-1 -> -2*y + 2*x -> +2(x-y)
			
			// 0 1 2 3 4 5 6 7 8 9 10
			// 0 0 1 1 2 2 3 3 4 4 5
			
			if(i&1){
				st1.update(i/2, i/2, dif);
				st1.update(i/2+1, INF, 2*dif);
				st0.update((i+1)/2, INF, -2*dif);
			}
			else{
				st0.update(i/2, i/2, dif);
				st0.update(i/2+1, INF, 2*dif);
				st1.update((i+1)/2, INF, -2*dif);
			}
			
			bool b0 = st0.tree[1] >= 0;
			bool b1 = (n%2==0) || st0.query(st0.n-1, st0.n-1) == 0;
			bool b2 = st1.tree[1] >= 0;
			bool b3 = (n%2==1) || st1.query(st1.n-1, st1.n-1) == 0;
			
			if(b0 && b1 && b2 && b3){
				ans = true;
				break;
			}
			
			if(i&1){
				st1.update(i/2, i/2, -dif);
				st1.update(i/2+1, INF, -2*dif);
				st0.update((i+1)/2, INF, 2*dif);
			}
			else{
				st0.update(i/2, i/2, -dif);
				st0.update(i/2+1, INF, -2*dif);
				st1.update((i+1)/2, INF, 2*dif);
			}
		}
		
		cout << (ans ? "YES" : "NO") << endl;
    }	
}
