// Problem: J. ABS MEX
// Contest: Codeforces - SCPC 23
// URL: https://codeforces.com/gym/470283/problem/J
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct seg_tree{
	
	int n;
	vi tree;	
	
	seg_tree(int n) : n(n){
		tree.resize(n*4);
	}
	
	void update(int nd, int l, int r, int p, int val){
		
		tree[nd] = max(tree[nd], val);
	
		if(l==r){
			return;
		}
		
		int mid = (l+r)/2;
		if(p <= mid){
			update(nd*2, l, mid, p, val);
		}
		else{
			update(nd*2+1, mid+1, r, p, val);
		}
	}
	
	int query(int nd, int l, int r, int q_l, int q_r){
		
		if(r < q_l || q_r < l){
			return 0;
		}
		
		if(q_l <= l && r <= q_r){
			return tree[nd];
		}
		
		int mid = (l+r)/2;
		int st_path = query(nd*2, l, mid, q_l, q_r);
		int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
		
		return max(st_path, nd_path);
	}
	
	void update(int p, int val){
		update(1, 0, n-1, p, val);
	}
	
	int query(int l, int r){
		return query(1, 0, n-1, l, r);
	}
};

int32_t main(){
    
    fastIO;
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec_a(n);
		for(auto &i : vec_a) cin >> i;
		
		vi vec_b(n);
		for(auto &i : vec_b) cin >> i;
		
		int m;
		cin >> m;
		
		vpii queries(m);
		for(auto &[l, r] : queries){
			cin >> l >> r;
			l--, r--;
		}
		
		vector<vpii> tmp(n);
		
		for(auto k : {0, 1}){
			
			vi pos(n+1);
			pos[n] = -1;
			for(int i = 0; i < n; i++){
				pos[vec_a[i]] = i;
			}
			
			set<int> st;
			for(int i = 0; i <= n; i++){
				st.insert(i);
			}
			
			int l = pos[0];
			int r = pos[0];
			st.erase(vec_b[pos[0]]);
			
			for(int i = 1; i <= n; i++){
				
				int p = pos[i];
				
				if(p < l || r < p){
					int mex_a = i;
					int mex_b = *st.begin();
					if(mex_a >= mex_b){
						tmp[r].push_back({l, mex_a-mex_b});
					}
				}
				
				if(p != -1){
					
					while(p < l){
						st.erase(vec_b[--l]);
					}
					
					while(r < p){
						st.erase(vec_b[++r]);
					}
				}
			}
			
			swap(vec_a, vec_b);
		}
		
		vi ans(m);
		seg_tree st(n);
		
		vector<vpii> tmp_q(n);
		for(int i = 0; i < m; i++){
			auto [l, r] = queries[i];
			tmp_q[r].push_back({i, l});
		}
		
		for(int i = 0; i < n; i++){
			
			for(auto [l, val] : tmp[i]){
				st.update(l, val);
			}
			
			for(auto [q_i, q_l] : tmp_q[i]){
				ans[q_i] = st.query(q_l, i);
			}
		}
		
		for(auto e : ans) cout << e << endl;
    }	
}
