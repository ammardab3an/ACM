// Problem: F. Points
// Contest: Codeforces - Educational Codeforces Round 131 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1701/problem/F
// Memory Limit: 512 MB
// Time Limit: 6500 ms
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

struct FenwickTree {
	
    int n;
    vector<int> bit;  // binary indexed tree

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

struct SegmentTree{
	
	struct node{
		int val;
		int cnt;
		int lazy;
		node(){
			val=cnt=lazy=0;
		}
	};
	
	static const int n = NMAX;
	vector<node> tree;
	
	SegmentTree(int _n){
		assert(n==_n);
		tree = vector<node>(n*4);
	}
	
	void push(int nd, int l, int r){
		
		if(!tree[nd].lazy) return;
		
		tree[nd].val += tree[nd].cnt * tree[nd].lazy;
		
		if(l != r){
			tree[nd*2].lazy += tree[nd].lazy;
			tree[nd*2+1].lazy += tree[nd].lazy;
		}
		
		tree[nd].lazy = 0;
	}
	
	node merge(const node &a, const node &b){
		
		assert(a.lazy==b.lazy && a.lazy==0);
		
		node ret;
		ret.val = a.val + b.val;
		ret.cnt = a.cnt + b.cnt;
		ret.lazy = 0;
		
		return ret;
	}
	
	void update_p(int p, int val, bool b, int nd=1, int l=0, int r=n-1){
		
		push(nd, l, r);
		
		if(p < l || r < p){
			return;
		}
		
		if(l==r){
			tree[nd].val = val;
			tree[nd].cnt = b;
			return;
		}
		
		int mid = (l+r)/2;
		update_p(p, val, b, nd*2, l, mid);
		update_p(p, val, b, nd*2+1, mid+1, r);
		
		tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
	}
	
	void update_rng(int q_l, int q_r, int val, int nd=1, int l=0, int r=n-1){
		
		push(nd, l, r);
		
		if(r < q_l || q_r < l){
			return;
		}	
		
		if(q_l <= l && r <= q_r){
			tree[nd].lazy += val;
			push(nd, l, r);
			return;
		}
		
		int mid = (l+r)/2;
		update_rng(q_l, q_r, val, nd*2, l, mid);
		update_rng(q_l, q_r, val, nd*2+1, mid+1, r);
		
		tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
	}
	
	int query(int q_l, int q_r, int nd=1, int l=0, int r=n-1){
		
		push(nd, l, r);
		
		if(r < q_l || q_r < l){
			return 0;
		}
		
		if(q_l <= l && r <= q_r){
			return tree[nd].val;
		}
		
		int mid = (l+r)/2;
		int st_path = query(q_l, q_r, nd*2, l, mid);
		int nd_path = query(q_l, q_r, nd*2+1, mid+1, r);
		
		return st_path + nd_path;
	}
};

FenwickTree bit(NMAX);
SegmentTree seg(NMAX);
vector<bool> vec(NMAX);

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n = NMAX;
    
    int q, d;
    cin >> q >> d;
    
    int ans = 0;
    
    while(q--){
    	
    	int ai;
    	cin >> ai;
    	ai--;
    	
    	int cans = 0;
    	
    	if(ai > 0){
	    	int st_cnt = bit.sum(max(int(0), ai-d), ai-1);
    		int st_path = (st_cnt*(st_cnt-1))/2;
    		cans += st_path;
    	}
    	
    	if(ai < n-1){		
	    	int nd_cnt = bit.sum(ai+1, min(n-1, ai+d));
	    	int nd_path = (nd_cnt*(nd_cnt-1))/2;
	    	cans += nd_path;
    	}
    	
    	if(0 < ai && ai < n-1){	
    		int tot = seg.query(ai+1, min(n-1, ai+d));
    		int cnt = bit.sum(ai+1, min(n-1, ai+d));
    		int rd_path = tot - ((cnt*(cnt-1))/2);
    		if(vec[ai]) rd_path -= cnt;
    		cans += rd_path;
    	}
    	
    	if(!vec[ai]){
    		ans += cans;
    		bit.add(ai, 1);
    		if(0 < ai){
	    		seg.update_p(ai, bit.sum(max(int(0), ai-d), ai-1), 1);
    		}
    		if(ai < n-1){
    			seg.update_rng(ai+1, min(n-1, ai+d), 1);
    		}
    		vec[ai] = 1;
    	}
    	else{
    		ans -= cans;
    		bit.add(ai, -1);
    		seg.update_p(ai, 0, 0);
    		if(ai < n-1){
    			seg.update_rng(ai+1, min(n-1, ai+d), -1);
    		}
    		vec[ai] = 0;
    	}
    	
    	cout << ans << endl;
    }
}
