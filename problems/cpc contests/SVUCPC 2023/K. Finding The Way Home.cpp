// Problem: K. Finding The Way Home
// Contest: Codeforces - Tishreen + SVU CPC 2023
// URL: https://codeforces.com/gym/104487/problem/K
// Memory Limit: 256 MB
// Time Limit: 8000 ms
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
const int MOD = 998244353; // 1e9 + 7;
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

const int NMAX = 3e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

const int N = 3e5 + 5;
const int mod = 998244353;
const int root = 15311432;
const int root_1 = 469870224;
const int root_pw = 1 << 23;

void fft (vector<int> & a, bool invert) {
	
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		int wlen = invert ? root_1 : root;
		for (int i=len; i<root_pw; i<<=1)
			wlen = int (wlen * 1ll * wlen % mod);
		for (int i=0; i<n; i+=len) {
			int w = 1;
			for (int j=0; j<len/2; ++j) {
				int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
				a[i+j] = u+v < mod ? u+v : u+v-mod;
				a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
				w = int (w * 1ll * wlen % mod);
			}
		}
	}
	
	if (invert) {
		int nrev = pow_exp(n, mod-2);
		for (int i=0; i<n; ++i)
			a[i] = int (a[i] * 1ll * nrev % mod);
	}
}


int n;
vi adj[NMAX];
int arr_a[NMAX];
int arr_b[NMAX];
int depth[NMAX];
int par[NMAX][LOG_MAX];
int val[NMAX];

void dfs(int u, int p){
	for(auto v : adj[u]) if(v != p){
		depth[v] = depth[u] + 1;
		par[v][0] = u;
		for(int i = 1; i < LOG_MAX; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}
		dfs(v, u);
	}	
}

int lca(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	int dif = depth[u] - depth[v];
	for(int i = 0; i < LOG_MAX; i++) if((dif>>i)&1) u = par[u][i];
	if(u==v) return u;
	for(int i = LOG_MAX-1; i >= 0; i--) if(par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
	return par[u][0];
}

void go(int u){
	
	vi tmp;
	vi A, B;
	
	int w = u;
	while(true){
		tmp.push_back(w);
		A.push_back(arr_a[w]);
		if(w == 0) break;
		w = par[w][0];
	}
	
	reverse(A.begin(), A.end());
	reverse(tmp.begin(), tmp.end());
	
	B.resize(A.size(), 0);
	for(int i = 0; i < B.size(); i++){
		B[i] = arr_b[i];
	}
	
	// for(auto e : tmp) cout << e+1 << ' '; cout << endl;
	// for(auto e : A) cout << e << ' '; cout << endl;
	// for(auto e : B) cout << e << ' '; cout << endl;
	
	int sz = A.size()+B.size()-1;
	sz = 1 << int(ceil(log2(double(sz))));
	
	A.resize(sz, 0);
	B.resize(sz, 0);
	
	fft(A, false);
	fft(B, false);
	
	for(int i = 0; i < sz; i++){
		A[i] = mul(A[i], B[i]);
	}
	
	fft(A, true);
	
	// for(auto e : A) cout << e << ' '; cout << endl;
	
	for(int i = 0; i < tmp.size(); i++){
		if(val[tmp[i]]) assert(val[tmp[i]] == A[i]);
		val[tmp[i]] = A[i];
		// cout << tmp[i]+1 << ' ' << A[i] << endl;
	}
}

int32_t main(){
    
    fastIO;
	
    int t; cin >> t; while(t--){

		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> arr_b[i];
		}
		for(int i = 0; i < n; i++){
			cin >> arr_a[i];
		}
		
		for(int i = 0; i < n; i++){
			val[i] = 0;
			adj[i].clear();
		}
		
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		dfs(0, -1);
		
		vi tmp(n);
		iota(tmp.begin(), tmp.end(), 0);
		sort(tmp.begin(), tmp.end(), [&](int i, int j){
			return depth[i] > depth[j];
		});
		
		vi calc;
		for(auto u : tmp) if(!val[u]){
			
			bool found = false;
			
			for(auto v : calc){
				if(depth[u] - depth[lca(u, v)] <= BLOCK){
					found = true;
					int x = u;
					int y = v;
					int dif = depth[v] - depth[u];
					for(int i = 0; i < LOG_MAX; i++) if((dif>>i)&1) y = par[y][i];
					int j = 0;
					int cans = val[y];
					while(x != y){
						cans = add(cans, mul(arr_a[x] - arr_a[y], arr_b[j]));
						x = par[x][0];
						y = par[y][0];
						j++;
					}
					val[u] = cans;
					break;
				}
			}
			
			if(!found){
				calc.push_back(u);
				go(u);
			}
		}
		
		for(int i = 0; i < n; i++){
			cout << val[i] << endl;
		}
    }	
}
