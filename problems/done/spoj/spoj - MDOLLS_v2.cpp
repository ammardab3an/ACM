// Problem: Nested Dolls
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/MDOLLS/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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

struct SegTree{
	
	vi tree;
	
	SegTree(){
		tree.resize(NMAX<<2, 0);
	}
	SegTree(int n){
		tree.resize(n<<2, 0);
	}
	
	void update(int nd, int l, int r, int p, int val){
		if(p < l || r < p) return;
		if(l == r){
			tree[nd] = val;
			return;
		}
		int mid = (l+r)/2;
		update(nd*2, l, mid, p, val);
		update(nd*2+1, mid+1, r, p, val);
		tree[nd] = max(tree[nd*2], tree[nd*2+1]);
	}	
	
	int query(int nd, int l, int r, int q_l, int q_r){
		if(r < q_l || q_r < l) return 0;
		if(q_l <= l && r <= q_r) return tree[nd];
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
		
		vpii vec(n);
		for(auto &p : vec){
			cin >> p.first >> p.second;
		}
		
		sort(vec.begin(), vec.end(), [](const pii &a, const pii &b){
			if(a.first != b.first){
				return a.first < b.first;
			}
			else{
				// if a.first==b.first then a and b cannot be in the same set, 
				// so here we give try to insert them all in the decreasing subsequence
				return a.second > b.second;
			}
		});
		
		int ans = 0;
		int sz = 10010;
		SegTree tree(sz);
		
		for(auto [a, b] : vec){
			int q = tree.query(1, 0, sz-1, b, sz-1);
			tree.update(1, 0, sz-1, b, q+1);
			ans = max(ans, q+1);
		}
		
		cout << ans << endl;
    }	
}
