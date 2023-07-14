// Problem: E. The Tree Has Fallen!
// Contest: Codeforces - Codeforces Round #848 (Div. 2)
// URL: https://codeforces.com/contest/1778/problem/e
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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

struct sys{
	
	vi base = vi(31);
	
	sys(){}
	
	sys(int x){
		add(x);
	}
	
	void add(int x){
		
		for(int i = 30; i >= 0; i--) if((x>>i)&1){
			if(!base[i]){
				base[i] = x;
				return;			
			}
			x ^= base[i];
		}
	}	
	
	int get_max(){
		
		int ret = 0;
		for(int i = 30; i >= 0; i--) if(base[i]){
			if(!((ret>>i)&1)){
				ret ^= base[i];
			}
		}
		
		return ret;
	}
	
	void merge(const sys &other){
		for(auto x : other.base){
			add(x);
		}
	}
};

vi adj[NMAX];
int val[NMAX];
int depth[NMAX];
int par[NMAX][LOG_MAX];
int tin[NMAX], tout[NMAX], tim;
sys pre[NMAX], suf[NMAX];
sys sub[NMAX];

void dfs(int u, int p){
	
	tin[u] = tim++;
	sub[u] = sys(val[u]);
	
	for(auto v : adj[u]) if(v != p){
		
		depth[v] = depth[u]+1;
		
		par[v][0] = u;
		for(int i = 1; i < LOG_MAX; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}
		
		dfs(v, u);
		sub[u].merge(sub[v]);
	}
	
	tout[u] = tim;
}

int lca(int u, int v){
	
	if(depth[u] < depth[v]) swap(u, v);
	int dif = depth[u]-depth[v];
	for(int i = 0; i < LOG_MAX; i++) if((dif>>i)&1){
		u = par[u][i];
	}
	if(u==v) return u;
	for(int i = LOG_MAX-1; i >= 0; i--) if(par[u][i] != par[v][i]){
		u = par[u][i];
		v = par[v][i];
	}
	return par[u][0];
}

int go_up(int u, int k){
	
	for(int i = 0; i < LOG_MAX; i++) if((k>>i)&1){
		u = par[u][i];
	}	
	
	return u;
}

int dist(int u, int v, int p=-1){
	if(p==-1) p = lca(u, v);
	return depth[u] + depth[v] - 2*depth[p];
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){
    	
		int n;
		cin >> n;
		
		for(int i = 0; i < n; i++){
			cin >> val[i];
		}
		
		for(int i = 0; i <= n; i++){
			adj[i].clear();
		}
		
		for(int i = 0; i < n-1; i++){
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		tim = 0;
		dfs(0, -1);
		
		for(int i = 0; i < n; i++){
			pre[tin[i]] = sys(val[i]);
		}
		for(int i = 0; i < n; i++){
			suf[i] = pre[i];
		}
		for(int i = 1; i < n; i++){
			pre[i].merge(pre[i-1]);
		}
		for(int i = n-2; i >= 0; i--){
			suf[i].merge(suf[i+1]);
		}
		
		int m;
		cin >> m;
		while(m--){
			
			int r, v;
			cin >> r >> v;
			r--, v--;
			
			if(r==v){
				cout << suf[0].get_max() << endl;
				continue;
			}
			
			int p = lca(r, v);
			
			if(p != v){
				sys tmp = sub[v];
				cout << tmp.get_max() << endl;
			}
			else{
				int ch = go_up(r, dist(r, v, p)-1);
				sys tmp = tin[ch] ? pre[tin[ch]-1] : sys();
				if(tout[ch] != n) tmp.merge(suf[tout[ch]]);
				cout << tmp.get_max() << endl;
			}
		}
    }	
}
