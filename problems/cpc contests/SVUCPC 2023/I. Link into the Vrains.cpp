// Problem: I. Link into the Vrains
// Contest: Codeforces - Tishreen + SVU CPC 2023
// URL: https://codeforces.com/gym/104487/problem/I
// Memory Limit: 128 MB
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
 
const int NMAX = 1E5 + 10;

struct seg_tree{
	
	int n;
	vpii tree;
	
	seg_tree(int n) : n(n){
		tree.resize(n*4, {-INFLL, NMAX});
	}
	
	pii merge(const pii &a, const pii &b){
		if(a.first != b.first){
			return max(a, b);
		}
		else{
			return min(a, b);
		}
	}	
	
	void update(int nd, int l, int r, int p, pii v){
		
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
		
		tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
	}
	
	void update(int p, pii v){
		update(1, 0, n-1, p, v);
	}
	
	pii query(int nd, int l, int r, int q_l, int q_r){
		
		if(r < q_l || q_r < l){
			return {-INFLL, NMAX};
		}
		
		if(q_l <= l && r <= q_r){
			return tree[nd];
		}
		
		int mid = (l+r)/2;
		pii st_path = query(nd*2, l, mid, q_l, q_r);
		pii nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
		
		return merge(st_path, nd_path);
	}
	
	pii query(int l, int r){
		return query(1, 0, n-1, l, r);
	}
};

int32_t main(){
    
    fastIO;
    
    int t; cin >> t; while(t--){

		int n, k, d;
		cin >> n >> k >> d;
		
		vpii vec(n);
		for(auto &[a, b] : vec) cin >> a;
		for(auto &[a, b] : vec) cin >> b;
		
		auto calc = [&](int x)->pii{
			
			seg_tree st(n);
			
			int j = n-1;
			for(int i = n-1; i >= 0; i--){
				
				while(vec[j].first - vec[i].first >= d){
					j--;
				}
				
				// cout << x << ' ' << i << ' ' << j << endl;
				
				int cval = vec[i].second;
				pii st_path = st.query(i+1, j);
				pii nd_path = st.query(j+1, n-1);
				pii rd_path = {cval - x, 1};
				
				st_path.first += cval;
				nd_path.first += cval - x;
				nd_path.second += 1;
				
				pii cans = st.merge(st_path, st.merge(nd_path, rd_path));
				st.update(i, cans);
			}
			
			pii ret = st.query(0, n-1);
			return ret;
		};
		
		int l = 0;
		int r = 1e11;
		
		int ans = 0;
		
		while(l <= r){
			
			int mid = (l+r)/2;
			
			pii q = calc(mid);
			
			if(q.second <= k){
				ans = q.first + k * mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		
		// for(int i = 0; i < 20; i++){
			// pii q = calc(i);
			// cout << i << ' ' << q.first+k*i << ' ' << q.first+q.second*i << ' ' << q.second << endl;
		// }
		
		ans = max(ans, int(0));
		cout << ans << endl;
    }	
}
