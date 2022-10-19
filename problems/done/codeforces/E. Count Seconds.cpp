// Problem: E. Count Seconds
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/problemset/problem/1704/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int MOD = 998244353; //1e9 + 7;
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

int n, m;
vi adj[NMAX];
vi inv_adj[NMAX];
int mem[NMAX];
bool vis[NMAX];
vi nds;

void dfs(int u){
	vis[u] = true;
	nds.push_back(u);
	for(auto v : inv_adj[u]) if(!vis[v]){
		dfs(v);
	}	
}

int go(int u){
	
	int &ret = mem[u];
	if(ret+1) return ret;
	
	int ans = 0;
	for(auto v : adj[u]){
		ans = add(ans, go(v));
	}	
	
	if(!ans){
		ans = 1;
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n >> m;
		
		nds.clear();
		for(int i = 0; i < n; i++){
			adj[i].clear();
			inv_adj[i].clear();
		}
		
		vi val(n);
		for(int i = 0; i < n; i++){
			cin >> val[i];
		}
		while(m--){
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			inv_adj[v].push_back(u);
		}
		
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < n; i++) if(!vis[i]){
			dfs(i);
		}
		reverse(nds.begin(), nds.end());
		
		// for(auto i : nds) cout << i << ' '; cout << endl;
		
		int ans = 0;
		
		while(true){
			
			// for(auto i : val) cout << i << ' '; cout << endl;
			// cout << flush;
			
			bool found = false;
			
			for(int i = 0; i < n && !found; i++){
				int u = nds[i];
				if(val[u]){
					for(auto v : adj[u]){
						if(!val[v]){
							found = true;
							break;
						}
					}
				}
			}
			
			if(!found){
				break;
			}
			
			vi tmp;
			for(int i = 0; i < n; i++){
				if(val[i]){
					tmp.push_back(i);
				}
			}
			
			for(auto u : tmp){
				val[u]--;
				for(auto v : adj[u]){
					val[v]++;
				}
			}
			
			ans = add(ans, 1);
		}
		
		memset(mem, -1, sizeof mem);
		
		for(int i = 0; i < n; i++){
			if(val[i]){
				int cans = mul(val[i], go(i));
				ans = add(ans, cans);
			}
		}
		
		cout << ans << endl;
    }	
}
