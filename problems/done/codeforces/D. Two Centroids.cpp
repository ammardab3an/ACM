// Problem: D. Two Centroids
// Contest: Codeforces - Codeforces Round 873 (Div. 1)
// URL: https://codeforces.com/contest/1827/problem/D
// Memory Limit: 1024 MB
// Time Limit: 1500 ms
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
const int NMAX = 5e5 + 10;
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
	vector<int> tree;
	
	seg_tree(int n) : n(n){
		tree = vi(n<<2);
	}	
	
	void update(int nd, int l, int r, int p, int val){
		
		if(l==r){
			tree[nd] = val;
			return;
		}
		
		int mid = (l+r)/2;
		if(p <= mid){
			update(nd*2, l, mid, p, val);
		}
		else{
			update(nd*2+1, mid+1, r, p, val);
		}
		
		tree[nd] = tree[nd*2] + tree[nd*2+1];
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
		
		return st_path + nd_path;
	}
};

int n;
vi adj[NMAX];
int sz[NMAX];
int nxt[NMAX];
int tin[NMAX], tout[NMAX], tt;
int par[NMAX][LOG_MAX];
int depth[NMAX];

void dfs0(int u){
	sz[u] = 1;
	for(auto &v : adj[u]){
		
		depth[v] = depth[u]+1;
		
		par[v][0] = u;
		for(int i = 1; i < LOG_MAX; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}
		
		dfs0(v);
		sz[u] += sz[v];
		if(sz[v] > sz[adj[u][0]]){
			swap(adj[u][0], v);
		}
	}
}

void dfs1(int u){
	tin[u] = tt++;
	for(auto v : adj[u]){
		nxt[v] = (u==adj[u][0]) ? nxt[u] : v;
		dfs1(v);
	}
	tout[u] = tt;
}

int go_up(int u, int k){
	
	for(int i = 0; i < LOG_MAX; i++) if((k>>i)&1){
		u = par[u][i];
	}
	
	return u;
}

bool check(int u, int v){
	
	if(depth[v] < depth[u]){
		return false;
	}
	
	return go_up(v, depth[v]-depth[u])==u;
}

int get_son(int u, int v){
	
	assert(depth[v] > depth[u]);
	
	return go_up(v, depth[v]-depth[u]-1);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
    int t; cin >> t; while(t--){

		cin >> n;
		for(int i = 0; i < n; i++){
			adj[i].clear();
		}
		
		vi queries(n-1);
		for(int i = 1; i < n; i++){
			int pi;
			cin >> pi;
			pi--;
			queries[i-1] = pi;
			adj[pi].push_back(i);
		}
		
		tt = 0;
		dfs0(0);
		dfs1(0);
		
		seg_tree st(n);
		st.update(1, 0, n-1, tin[0], 1);
		
		int cen_0 = 0;
		int cen_1 = 0;
		int ssize = 0;
		
		for(int i = 1; i < n; i++){
			
			int u = i;
			int p = queries[i-1];
			
			st.update(1, 0, n-1, tin[u], 1);
			
			int m = i+1;
			
			if(cen_0==cen_1){
				
				int s, sz;
				
				if(check(cen_0, u)){
					s = get_son(cen_0, u);
					sz = st.query(1, 0, n-1, tin[s], tout[s]-1);
				}
				else{
					s = par[cen_0][0];
					sz = m-st.query(1, 0, n-1, tin[cen_0], tout[cen_0]-1);
				}
				
				if(m%2==0 && sz==m/2){
					cen_1 = s;
					ssize = m/2;
				}
				else{
					ssize = max(ssize, sz);
				}
			}
			else{
				
				if(depth[cen_0] < depth[cen_1]){
					swap(cen_0, cen_1);
				}
				
				if(check(cen_0, u)){
					cen_1 = cen_0;
				}
				else{
					cen_0 = cen_1;
				}
			}
			
			if(cen_0 != cen_1){
				cout << 0 << ' ';
			}
			else{
				
				// int l = 0;
				// int r = 1e9;
// 				
				// int i = -1;
// 				
				// while(l <= r){
// 					
					// int mid = (l+r)/2;
// 					
					// if(ssize+mid >= ((m+mid+1)/2)){
						// i = mid;
						// r = mid-1;
					// }
					// else{
						// l = mid+1;
					// }
				// }
// 				
				// cout << (m+i+1)/2-ssize << ' ';
				
				cout << m-2*ssize << ' ';
			}
		}
		
		cout << endl;
    }	
}
