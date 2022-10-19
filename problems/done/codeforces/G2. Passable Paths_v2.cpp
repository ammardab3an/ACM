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
    	
    	vi tmp(m);
    	for(auto &i : tmp) cin >> i, --i;
    	
    	sort(tmp.begin(), tmp.end(), [&](int u, int v){
    		return depth[u] > depth[v];
    	});
    	
    	vi lf, ri;
    	bool ans = true;
    	
    	for(auto u : tmp){
    		if(lf.empty() || lca(lf.back(), u)==u){
    			lf.push_back(u);
    		}
    		else if(ri.empty() || lca(ri.back(), u)==u){
    			ri.push_back(u);
    		}
    		else{
    			ans = false;
    			break;
    		}
    	}
    	
    	if(lf.size()==1) lf.push_back(lf.back());
    	if(ri.size()==1) ri.push_back(ri.back());
    	
    	if(lf.size()>=2 && ri.size()>=2){
    		ans &= lca(lf.back(), ri.back())==lca(lf[lf.size()-2], ri[ri.size()-2]);
    	}
    	
    	cout << (ans ? "YES" : "NO") << endl;
    }
}
