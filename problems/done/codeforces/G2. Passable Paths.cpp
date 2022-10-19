// Problem: G2. Passable Paths (hard version)
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/G2
// Memory Limit: 256 MB
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, log_n;
vi adj[NMAX];
int par[NMAX][LOG_MAX];
int depth[NMAX];

void dfs(int u, int p){
	
	for(auto v : adj[u]) if(v != p){
		
		depth[v] = depth[u] + 1;
		
		par[v][0] = u;
		for(int i = 1; i < log_n; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}
		
		dfs(v, u);
	}
}

int lca(int u, int v){
	
	if(depth[u] < depth[v]) swap(u, v);
	int dif = depth[u] - depth[v];
	for(int i = 0; i < log_n; i++) if((dif>>i)&1){
		u = par[u][i];
	}
	
	if(u==v) return u;
	
	for(int i = log_n-1; i >= 0; i--) if(par[u][i] != par[v][i]){
		u = par[u][i];
		v = par[v][i];
	}
	
	return par[u][0];
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    log_n = ceil(log2(double(n)));
    dfs(0, -1);
    
    int q; cin >> q; while(q--){
    	
    	int m;
    	cin >> m;
    	
    	vpii tmp(m);
    	
    	for(int i = 0; i < m; i++){
    		int u;
    		cin >> u;
    		u--;
    		tmp[i] = {depth[u], u};
    	}
    	
    	sort(tmp.begin(), tmp.end());
    	
    	if(tmp.size() >= 3){
    		if((tmp[0].first==tmp[1].first) && (tmp[0].first==tmp[2].first)){
    			cout << "NO" << endl;
    			continue;
    		}
    	}
    	
    	bool ans = true;
    	
    	vi lf, ri;
    	int cur = tmp[0].second;
    	lf.push_back(cur);
    	
    	for(int i = 1; i < m; i++){
    		
    		int g = lca(cur, tmp[i].second);
    		
    		if(g == cur){
    			cur = tmp[i].second;
    			lf.push_back(tmp[i].second);
    		}
    		else{
    			ri.push_back(tmp[i].second);
    		}
    	}
    	
    	// for(auto i : lf) cout << i+1 << ' '; cout << endl;
    	// for(auto i : ri) cout << i+1 << ' '; cout << endl;
    	
    	if(!ri.empty()){
    		
    		if(depth[lf.front()] != depth[ri.front()]){
    			
    			if(lf.size() >= 2 && depth[lf.front()] < depth[ri.front()]){
    				
    				int x = lf[1];
    				int y = ri.front();
    				int g = lca(x, y);
    				
    				if(depth[g] > depth[lf.front()]){
    					ans = false;
    				} 
    			}
    			
    			if(ri.size() >= 2 && depth[ri.front()] < depth[lf.front()]){
    				
    				int x = ri[1];
    				int y = lf.front();
    				int g = lca(x, y);
    				
    				if(depth[g] > depth[ri.front()]){
    					ans = false;
    				} 
    			}
    		}
    		
    		if(!ans){
    			cout << "NO" << endl;
    			continue;
    		}
    		
    		int cur = ri[0];
    		for(auto nxt : ri){
    			
    			int g = lca(cur, nxt);
    			if(g != cur){
    				ans = false;
    				break;
    			}
    			else{
    				cur = nxt;
    			}
    		}
    	}
    	
    	cout << (ans ? "YES" : "NO") << endl;
    }
}
