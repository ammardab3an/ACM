// Problem: D: Today is Gonna be a Great Day
// Contest: Meta Coding Competitions - Meta Hacker Cup 2023 Round 1
// URL: https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-1/problems/D
// Memory Limit: 1024 MB
// Time Limit: 360000 ms
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

struct s_data{
	
	pair<pair<int, int>, pair<int, int>> neg;	
	pair<pair<int, int>, pair<int, int>> pos;
	
	s_data(){
		neg = pos = {{INFLL, -1}, {-INFLL, -1}};
	}
};

pii merge_mn(const pii &a, const pii &b){
	return min(a, b);
}

pii merge_mx(const pii &a, const pii &b){
	if(a.first != b.first){
		return max(a, b);
	}	
	else{
		return min(a, b);
	}
}

s_data merge(const s_data &a, const s_data &b){
	
	s_data ret;
	ret.pos.first = merge_mn(a.pos.first, b.pos.first); 	
	ret.pos.second = merge_mx(a.pos.second, b.pos.second); 	
	ret.neg.first = merge_mn(a.neg.first, b.neg.first); 	
	ret.neg.second = merge_mx(a.neg.second, b.neg.second); 	
	
	return ret;
}

struct seg_tree{
	
	int n;
	vi vec;
	vector<s_data> tree;	
	vector<int> lazy;	
	
	const s_data init_val = s_data();
	
	seg_tree(const vi &v){
		vec = v;
		n = v.size();
		tree.resize(n*4, init_val);
		lazy.resize(n*4);
		build(1, 0, n-1);
	}
	
	void push(int nd, int l, int r){
		if(!lazy[nd]) return;
		swap(tree[nd].pos, tree[nd].neg);
		if(l != r){
			lazy[nd*2] ^= 1;
			lazy[nd*2+1] ^= 1;
		}
		lazy[nd] = 0;
	}
	
	void build(int nd, int l, int r){
		
		if(l==r){
			tree[nd].pos = {{vec[l], l}, {vec[l], l}};
			return;
		}	
		
		int mid = (l+r)/2;
		build(nd*2, l, mid);
		build(nd*2+1, mid+1, r);
		
		tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
	}
	
	void update(int nd, int l, int r, int q_l, int q_r){
		
		push(nd, l, r);
		
		if(r < q_l || q_r < l){
			return;
		}
		
		if(q_l <= l && r <= q_r){
			lazy[nd] = 1;
			push(nd, l, r);
			return;
		}
		
		int mid = (l+r)/2;
		update(nd*2, l, mid, q_l, q_r);
		update(nd*2+1, mid+1, r, q_l, q_r);
		
		tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
	}
	
	void update(int l, int r){
		update(1, 0, n-1, l, r);
	}
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif


    // freopen("D:/input.txt", "r", stdin);
    // freopen("D:/out_d.txt", "w", stdout);
	
	int tt = 1;
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &e : vec) cin >> e;
		
		seg_tree st(vec);
		
		auto calc = [&](){
			pii st_path = st.tree[1].pos.second;
			pii nd_path = st.tree[1].neg.first;
			nd_path.first = MOD-nd_path.first;
			pii ans = merge_mx(st_path, nd_path);
			return ans.second + 1;
		};
		
		int ans = 0;
		
		int m;
		cin >> m;
		while(m--){
			
			int l, r;
			cin >> l >> r;
			l--, r--;
			
			st.update(l, r);
			
			ans += calc();
		}
		
		cout << "Case #" << tt++ << ": " << ans << endl;
    }	
}
