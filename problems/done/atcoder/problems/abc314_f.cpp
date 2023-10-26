// Problem: F - A Certain Game
// Contest: AtCoder - AtCoder Beginner Contest 314
// URL: https://atcoder.jp/contests/abc314/tasks/abc314_f
// Memory Limit: 1024 MB
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

int m;
int par[2*NMAX];
int sz[2*NMAX];
vi adj[2*NMAX];
int ans[2*NMAX];

int get_par(int u){
	return par[u] = (par[u] == u) ? u : get_par(par[u]);
	// return (par[u] == u) ? u : get_par(par[u]);
}

int merge(int u, int v){
	
	u = get_par(u);
	v = get_par(v);
	
	assert(u != v);
	
	int nd = m++;
	par[nd] = nd;
	sz[nd] = sz[u] + sz[v];
	par[u] = nd;
	par[v] = nd;
	
	adj[nd].push_back(u);
	adj[nd].push_back(v);
	
	return nd;	
}

void dfs(int u, int p){
	
	if(p != -1){
		ans[u] = add(ans[u], ans[p]);
	}
	
	assert(adj[u].size()==0 || adj[u].size()==2);
	
	if(!adj[u].empty()){
		
		int a = adj[u][0];
		int b = adj[u][1];
		
		int sz_a = sz[a];
		int sz_b = sz[b];
		
		// cout << u << ' ' << a << ' ' << sz_a << ' ' << b << ' ' << sz_b << endl;
		
		int _ab = inv(sz_a + sz_b);
		ans[a] = mul(sz_a, _ab);
		ans[b] = mul(sz_b, _ab);
		
		dfs(a, u);
		dfs(b, u);
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n;
	cin >> n;
	
	m = n;
	
	vpii vec(n-1);
	for(auto &[a, b] : vec){
		cin >> a >> b;
		a--, b--;
	}
	
	for(int i = 0; i < n; i++){
		par[i] = i;
		sz[i] = 1;
	}
	
	int p = -1;
	for(auto [a, b] : vec){
		p = merge(a, b);
	}
	
	assert(p != -1);
	
	dfs(p, -1);
	
	for(int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
}
