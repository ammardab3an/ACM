// Problem: F. Exotic Queries
// Contest: Codeforces - Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1864/problem/F
// Memory Limit: 1024 MB
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

int inv(int x){
	return pow_exp(x, MOD-2);
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

struct seg_tree{
	
	int n;
	vi tree;
	
	seg_tree(int n) : n(n){
		tree.resize(n*4, -1);
	}	
	
	void update(int nd, int l, int r, int p, int v){
		
		if(l==r){
			tree[nd] = v;
			return;
		}
		
		int mid = (l+r)/2;
		if(p <= mid){
			update(nd*2, l, mid, p, v);
		}
		else{
			update(nd*2+1, mid+1, r, p, v);
		}
		
		tree[nd] = max(tree[nd*2], tree[nd*2+1]);
	}
	
	void update(int i, int v){
		update(1, 0, n-1, i, v);
	}
	
	int query(int nd, int l, int r, int q_l, int q_r){
		
		if(r < q_l || q_r < l){
			return -1;
		}
		if(q_l <= l && r <= q_r){
			return tree[nd];
		}
		
		int mid = (l+r)/2;
		int st_path = query(nd*2, l, mid, q_l, q_r);
		int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
		
		return max(st_path, nd_path);
	}
	
	int query(int l, int r){
		return query(1, 0, n-1, l, r);
	}
};

int32_t main(){
    
    fastIO;
	
	int n, m;
	cin >> n >> m;
	
	int sz = n;
	
	vi vec(n);
	for(auto &i : vec) cin >> i, --i;
	
	vpii queries(m);
	vector<vpii> tmp(sz);
	
	for(int i = 0; i < m; i++){
		auto &[l, r] = queries[i];
		cin >> l >> r;
		l--, r--;
		tmp[r].push_back({i, l});
	}
	
	vector<vi> pos(sz);
	for(int i = 0; i < n; i++){
		pos[vec[i]].push_back(i);
	}
	
	seg_tree st(n);
	vector<vi> calc(sz);
	
	for(int i = 0; i < sz; i++){
		
		for(int j = 1; j < pos[i].size(); j++){
			int q = st.query(pos[i][j-1], pos[i][j]);
			if(q != -1) calc[i].push_back(q);
		}
		
		sort(calc[i].begin(), calc[i].end());
		
		for(auto p : pos[i]){
			st.update(p, i);
		}
	}
	
	vi ans(m);
	FenwickTree bit(sz);
	FenwickTree bit2(sz);
	
	for(int i = 0; i < sz; i++){
		
		for(auto e : calc[i]){
			bit.add(e, +1);
		}	
		
		if(pos[i].size()){
			bit2.add(i, 1);
		}
		
		for(auto [q_id, l] : tmp[i]){
			ans[q_id] = bit.sum(l, i) + bit2.sum(l, i);
		}
	}
	
	for(auto e : ans) cout << e << endl;
}
