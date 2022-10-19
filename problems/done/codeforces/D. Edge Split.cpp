// Problem: D. Edge Split
// Contest: Codeforces - Codeforces Round #819 (Div. 1 + Div. 2) and Grimoire of Code Annual Contest 2022
// URL: https://codeforces.com/contest/1726/problem/D
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

int n, m;
vi adj[NMAX];
int par[NMAX];
int vis[NMAX], vid;
int head[NMAX];
int tin[NMAX], t;

int get_head(int u){
	return head[u] = (head[u]==u) ? u : get_head(head[u]);
}

bool merge(int u, int v){
	
	if((u=get_head(u)) == (v=get_head(v))){
		return false;
	}
	
	if(rand()&1) swap(u, v);
	
	head[u] = v;
	
	return true;
}

void dfs(int u, int p){
	
	tin[u] = t++;
	vis[u] = vid;
	
	for(auto v : adj[u]) if(vis[v] != vid){
		
		par[v] = u;
		
		dfs(v, u);
	}
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
		
		::t = 0;
		vid++;
		for(int i = 0; i < n; i++){
			adj[i].clear();
		}
		
		for(int i = 0; i < n; i++){
			head[i] = i;
		}
		
		vpii edges(m);
		for(auto &[u, v] : edges){
			cin >> u >> v;
			u--, v--;
			if(u > v) swap(u, v);
		}
		
		int used_cnt = 0;
		vector<bool> used(m);
		for(int i = 0; i < m; i++){
			auto [u, v] = edges[i];
			if(merge(u, v)){
				used_cnt++;
				used[i] = true;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
		
		dfs(0, -1);
		
		if(m-used_cnt == 3){
			
			for(int i = 0; i < n; i++){
				head[i] = i;
			}
			
			pii bad = {-1, -1};
			
			for(int i = 0; i < m; i++) if(!used[i]){
				auto [u, v] = edges[i];
				
				if(!merge(u, v)){
					int w = u;
					if(tin[u] < tin[v]) w = v;
					used[i] = true;
					bad = {w, par[w]};
					if(w > par[w]) bad = {par[w], w};
				}	
			}
			
			// cout << bad.first+1 << ' ' << bad.second+1 << endl;
			
			if(bad.first != -1){
				for(int i = 0; i < m; i++){
					if(bad == edges[i]){
						used[i] = false;
						break;
					}
				}
			}
		}
		
		for(auto b : used) cout << b;
		cout << endl;
    }	
}
