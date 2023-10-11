// Problem: G. wxhtzdy ORO Tree
// Contest: Codeforces - Codeforces Round 900 (Div. 3)
// URL: https://codeforces.com/contest/1878/problem/G
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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

// const int INF = 0x3f3f3f3f;
// const ll INFLL = 0x3f3f3f3f3f3f3f3f;
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

int n;
int arr[NMAX];
vi adj[NMAX];
int par[NMAX][LOG_MAX];
int par_or[NMAX][LOG_MAX];
int depth[NMAX];

void dfs(int u, int p){
	
	if(u==0){
		for(int i = 0; i < LOG_MAX; i++){
			par_or[0][i] = arr[0];
		}
	}
	
	for(auto v : adj[u]) if(v != p){
		
		depth[v] = depth[u]+1;
		
		par[v][0] = u;
		for(int i = 1; i < LOG_MAX; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}
		
		par_or[v][0] = arr[v];
		for(int i = 1; i < LOG_MAX; i++){
			par_or[v][i] = par_or[v][i-1] | par_or[par[v][i-1]][i-1];
		}
		
		dfs(v, u);
	}	
}

int lca(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	int dif = depth[u]-depth[v];
	for(int i = 0; i < LOG_MAX; i++) if((dif>>i)&1) u = par[u][i];
	if(u==v) return u;
	for(int i = LOG_MAX-1; i >= 0; i--) if(par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
	return par[u][0];
}

int dist(int u, int v){
	return depth[u] + depth[v] - 2*depth[lca(u, v)];
}

int calc(int u, int v, int k){
		
	// assert(k <= dist(u, v)+1);
	
	int ret = 0;
	int g = lca(u, v);
	
	{
		int mn = min(k, depth[u]-depth[g]+1);
		k -= mn;
		for(int i = 0; i < LOG_MAX; i++) if((mn>>i)&1){
			ret |= par_or[u][i];
			u = par[u][i];
		}
	}
	
	if(k){
		
		int dif = (depth[v]-depth[g]) - k;
		assert(dif >= 0);
		
		for(int i = 0; i < LOG_MAX; i++) if((dif>>i)&1) v = par[v][i];
		
		for(int i = 0; i < LOG_MAX; i++) if((k>>i)&1){
			ret |= par_or[v][i];
			v = par[v][i];
		}
	}
	
	return ret;
}

int32_t main(){
    
    fastIO;
    
    // freopen("d:\\test.txt", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		for(int i = 0; i < n; i++){
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
		
		int m;
		cin >> m;
		vpii queries(m);
		for(auto &[u, v] : queries){
			cin >> u >> v;
			u--, v--;
		}
		
		// cout << n << endl;
		// continue;
		
		for(auto [u, v] : queries){
			
			// cout << u << ' ' << v << endl << flush;
			
			int ans = 0;
			
			int g = lca(u, v);
			int d = dist(u, v) + 1;
			
			for(auto _ : {0, 1}){
				
				int w = u;
				int val = arr[u];
				
				while(depth[w] >= depth[g]){
					
					// cout << u << ' ' << v << ' ' << w << ' ' << d << ' ' << d - (depth[u]-depth[w]) << ' ' << val << ' ' << calc(v, u, d - (depth[u]-depth[w])) << endl << flush;
					
					int st_path = __builtin_popcount(val);
					int nd_path = __builtin_popcount(calc(v, u, d - (depth[u]-depth[w])));
					ans = max(ans, st_path + nd_path);
					
					if(!w) break;
					
					for(int i = LOG_MAX-1; i >= 0; i--){
						if(depth[w]-(1<<i) < depth[g]) continue;
						if((val | par_or[w][i] | arr[par[w][i]]) == val){
							w = par[w][i];
						}
					}
					
					w = par[w][0];
					val |= arr[w];
				}
				
				swap(u, v);
			}
			
			cout << ans << ' ';
		}
		
		cout << endl;
    }	
}
