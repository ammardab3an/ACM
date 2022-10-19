// Problem: F. Multi-Colored Segments
// Contest: Codeforces - Codeforces Round #826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/F
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

multiset<int> arr[2*NMAX];

int tree[(2*NMAX) << 2];

void build(int nd, int l, int r){
	
	if(l==r){
		tree[nd] = *arr[l].rbegin();	
		return;
	}
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
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

void update(int nd, int l, int r, int p, int x, bool b){
	
	if(p < l || r < p){
		return;
	}	
	
	if(l==r){
		if(!b){
			arr[l].erase(arr[l].find(x));
		}
		else{
			arr[l].insert(x);
		}
		
		tree[nd] = *arr[l].rbegin();
		
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, p, x, b);
	update(nd*2+1, mid+1, r, p, x, b);
	
	tree[nd] = max(tree[nd*2], tree[nd*2+1]);
}

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
		
		vector<array<int, 3>> vec(n);
		
		for(auto &v : vec)
		for(auto &i : v) cin >> i;
		
		vi comp;
		
		vector<vi> col(n);
		for(int i = 0; i < n; i++){
			auto &[l, r, c] = vec[i];
			c--;
			col[c].push_back(i);
			comp.push_back(l);
			comp.push_back(r);
		}
		
		sort(comp.begin(), comp.end());
		comp.resize(unique(comp.begin(), comp.end())-comp.begin());
		
		for(auto &[l, r, c] : vec){
			l = lower_bound(comp.begin(), comp.end(), l)-comp.begin();
			r = lower_bound(comp.begin(), comp.end(), r)-comp.begin();
		}
		
		int m = comp.size();
		
		for(int i = 0; i < m; i++){
			arr[i].clear();
			arr[i].insert(-INFLL);
		}
		
		multiset<int> mst;
		
		for(auto [l, r, c] : vec){
			arr[l].insert(r);
			mst.insert(l);
		}
		
		build(1, 0, m-1);
		
		vi ans(n, INFLL);
		
		for(auto v : col){
			
			for(auto i : v){
				auto [l, r, c] = vec[i];
				update(1, 0, m-1, l, r, 0);
				mst.erase(mst.find(l));
			}
			
			for(auto i : v){
				
				auto [l, r, c] = vec[i];
				
				int br = query(1, 0, m-1, 0, l);
				
				if(l <= br){
					ans[i] = 0;
				}
				else if(br >= 0){
					ans[i] = min(ans[i], comp[l]-comp[br]);
				}
				
				int mr = query(1, 0, m-1, l, r);
				if(l <= mr){
					ans[i] = 0;
				}
				
				auto it = mst.lower_bound(r);
				if(it != mst.end()){
					int al = *it;
					ans[i] = min(ans[i], comp[al]-comp[r]);
				}
				
			}
			
			for(auto i : v){
				auto [l, r, c] = vec[i];
				update(1, 0, m-1, l, r, 1);
				mst.insert(l);
			}
		}
		
		for(auto i : ans) cout << i << ' '; cout << endl;
    }	
}
