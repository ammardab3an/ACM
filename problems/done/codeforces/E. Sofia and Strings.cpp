// Problem: E. Sofia and Strings
// Contest: Codeforces - Codeforces Round 910 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1898/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	
	int n;
	vi tree;
	
	segTree(){
		assert(false);
	}
	
	segTree(int n) : n(n){
		tree = vi(n<<2, -1);
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
	
	void update(int p, int v){
		update(1, 0, n-1, p, v);
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
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
    int t; cin >> t; while(t--){

		int n, m;
		cin >> n >> m;
		
		string str_n, str_m;
		cin >> str_n >> str_m;
		
		n = str_n.size();
		m = str_m.size();
		
		vector<vi> tmp_n(26);
		for(int i = 0; i < n; i++){
			tmp_n[str_n[i]-'a'].push_back(i);
		}
		
		vector<vi> tmp_m(26);
		for(int i = 0; i < m; i++){
			tmp_m[str_m[i]-'a'].push_back(i);
		}
		
		segTree st(n);
		bool ans = true;
		
		for(int c = 0; c < 26; c++) if(!tmp_m[c].empty()){
			
			while(!tmp_m[c].empty()){
				
				if(tmp_n[c].empty()){
					ans = false;
					break;
				}
				
				int i = tmp_n[c].back();
				int j = tmp_m[c].back();
				
				if(st.query(0, i) < j){
					st.update(i, j);
					tmp_n[c].pop_back();
					tmp_m[c].pop_back();
				}
				else{
					tmp_n[c].pop_back();
				}
			}
		}
		
		cout << (ans ? "YES" : "NO") << endl;
    }	
}
