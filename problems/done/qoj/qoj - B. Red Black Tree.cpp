
// B. Red Black Tree
// https://qoj.ac/contest/1339/submissions

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

vpii adj[NMAX];
int par[NMAX][LOG_MAX];
int dist[NMAX][LOG_MAX];
int depth[NMAX];
int val[NMAX];

void dfs(int u, int p){
	
	for(auto [v, w] : adj[u]) if(v != p){
		
		depth[v] = depth[u] + 1;
		
		par[v][0] = u;
		for(int i = 1; i < LOG_MAX; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}
		
		dist[v][0] = w;
		for(int i = 1; i < LOG_MAX; i++){
			dist[v][i] = dist[v][i-1] + dist[par[v][i-1]][i-1];
		}
		
		val[v] = min(val[v], val[u] + w);
		
		dfs(v, u);
	}
}

pii lca(int u, int v){
	
	if(u==-1){
		return {v, 0};
	}
	
	if(depth[u] < depth[v]) swap(u, v);
	
	int sm_dist = 0;
	int dif = depth[u] - depth[v];
	for(int i = 0; i < LOG_MAX; i++) if((dif>>i)&1){
		sm_dist += dist[u][i];
		u = par[u][i];
	}
	
	if(u==v){
		return {u, sm_dist};
	}
	
	for(int i = LOG_MAX-1; i >= 0; i--) if(par[u][i] != par[v][i]){
		sm_dist += dist[u][i] + dist[v][i];
		u = par[u][i];
		v = par[v][i];
	}
	
	return {par[u][0], sm_dist + dist[u][0] + dist[v][0]};
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

		int n, m, q;
		cin >> n >> m >> q;
		
		for(int i = 0; i < n; i++){
			adj[i].clear();
			val[i] = INFLL;
		}
		
		for(int i = 0; i < m; i++){
			int u;
			cin >> u;
			u--;
			val[u] = 0;
		}
		
		for(int i = 1; i < n; i++){
			int u, v, w;
			cin >> u >> v >> w;
			u--, v--;
			adj[u].emplace_back(v, w);
			adj[v].emplace_back(u, w);
		}
		
		dfs(0, -1);
		
		while(q--){
			
			int k;
			cin >> k;
			
			vi tmp(k);
			for(auto &e : tmp) cin >> e, --e;
			
			sort(tmp.begin(), tmp.end(), [&](int u, int v){
				return val[u] > val[v];
			});
			
			// cout << ' ';
			// for(auto e : tmp) cout << e << ' '; cout << endl << flush;
			
			int mx = 0;
			int u = -1;
			int ans = INFLL;
			
			for(int i = 0; i < k; i++){
				
				int v = tmp[i];
				pii g = lca(u, v);
				int d0 = lca(u, g.first).second;
				int d1 = lca(v, g.first).second;
				
				mx = max(mx+d0, d1);
				u = g.first;
				
				int cans = mx;
				if(i+1 < k) cans = max(cans, val[tmp[i+1]]);
				ans = min(ans, cans);
			}
			
			cout << ans << endl;
		}
    }	
}
