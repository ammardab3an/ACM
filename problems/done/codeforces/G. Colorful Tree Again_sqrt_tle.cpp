// Problem: G. Colorful Tree Again
// Contest: Codeforces - TypeDB Forces 2023 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1787/problem/G
// Memory Limit: 512 MB
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
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

pii par[NMAX];
bool vis[NMAX];
bool good[NMAX];
int bg_node[NMAX];
int depth[NMAX];
vi col_nodes[NMAX];
int sm_weights[NMAX];
vector<array<int, 3>> adj[NMAX];
multiset<int> mst[NMAX], tot;
int cnt_bad[NMAX];
bool blocked[NMAX];
vi tmp[NMAX];

void dfs(int u, int p){
	
	for(auto [v, w, c] : adj[u]) if(v != p){
		
		par[v] = {u, c};
		depth[v] = depth[u] + 1;
		col_nodes[c].push_back(v);
		
		dfs(v, u);
	}
	
	for(auto [v, w, c] : adj[u]){
		if(bg_node[c]==-1 || adj[bg_node[c]].size() < adj[u].size()){
			bg_node[c] = u;
		}
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
	
	int n, q;
	cin >> n >> q;
	
	for(int i = 1; i < n; i++){
		
		int u, v, w, c;
		cin >> u >> v >> w >> c;
		u--, v--, c--;
		
		sm_weights[c] += w;
		adj[u].push_back({v, w, c});
		adj[v].push_back({u, w, c});
	}
	
	memset(bg_node, -1, sizeof bg_node);
	
	dfs(0, -1);
	
	for(int i = 0; i < n; i++) if(!col_nodes[i].empty()){
		
		bool bad = false;
		
		sort(col_nodes[i].begin(), col_nodes[i].end(), [&](int u, int v){
			return depth[u] > depth[v];
		});
		
		int cnt = 0;
		int cp = par[col_nodes[i].back()].first;
		
		for(auto u : col_nodes[i]) if(!vis[u]){
			
			cnt++;
			
			while(u != cp){
				vis[u] = true;
				if(par[u].first != cp && par[par[u].first].second != i){
					bad = true;
					break;
				}
				u = par[u].first;
			}
			
			if(bad) break;
		}
		
		if(cnt <= 2 && !bad){
			good[i] = true;
			mst[bg_node[i]].insert(sm_weights[i]);
		}
	}
	
	for(int i = 0; i < n; i++){
		
		for(auto [v, w, c] : adj[i]){
			if(good[c] && bg_node[c] != i){
				tmp[i].push_back(c);
			}
		}
		
		sort(tmp[i].begin(), tmp[i].end());
		tmp[i].erase(unique(tmp[i].begin(), tmp[i].end()), tmp[i].end());
		
		assert(tmp[i].size() < 500);
		
		mst[i].insert(0);
		tot.insert(*mst[i].rbegin());
	}
	
	tot.insert(0);
	
	while(q--){
		
		int k, u;
		cin >> k >> u;
		u--;
		
		if(k==0){
			
			blocked[u] = true;	
			tot.erase(tot.find(*mst[u].rbegin()));
			
			for(auto c : tmp[u]){
				
				int cp = bg_node[c];
				
				if(!blocked[cp]){
					tot.erase(tot.find(*mst[cp].rbegin()));
				}
				
				if(cnt_bad[c]++ == 0){
					mst[cp].erase(mst[cp].find(sm_weights[c]));
				}
				
				if(!blocked[cp]){
					tot.insert(*mst[cp].rbegin());
				}
			}
		}
		else{
			
			blocked[u] = false;	
			tot.insert(*mst[u].rbegin());
			
			for(auto c : tmp[u]){
				
				int cp = bg_node[c];
				
				if(!blocked[cp]){
					tot.erase(tot.find(*mst[cp].rbegin()));
				}
				
				if(--cnt_bad[c] == 0){
					mst[cp].insert(sm_weights[c]);
				}
				
				if(!blocked[cp]){
					tot.insert(*mst[cp].rbegin());
				}
			}
		}
		
		cout << (*tot.rbegin()) << endl;
	}
}
