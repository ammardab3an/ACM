// Problem: G. Colorful Tree Again
// Contest: Codeforces - TypeDB Forces 2023 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/problemset/problem/1787/G
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

vector<array<int, 3>> adj[NMAX];	
pii par[NMAX];
int depth[NMAX];

vi paths[NMAX];
int paths_sum[NMAX];
int paths_lca[NMAX];

void dfs(int u, int p){
	
	for(auto [v, w, c] : adj[u]) if(v != p){
		
		par[v] = {u, c};
		depth[v] = depth[u]+1;
		
		paths_sum[c] += w;
		paths[c].push_back(v);
		
		if(paths_lca[c]==-1){
			paths_lca[c] = u;
		}
		
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
    
	// init();
	
	int n, q;
	cin >> n >> q;
	
	for(int i = 0; i < n-1; i++){
		
		int u, v, w, c;
		cin >> u >> v >> w >> c;
		u--, v--, c--;
		
		adj[u].push_back({v, w, c});
		adj[v].push_back({u, w, c});
	}
	
	memset(paths_lca, -1, sizeof paths_lca);
	
	dfs(0, -1);
	
	multiset<int> mst_tot;
	vector<multiset<int>> mst(n);
	vector<bool> vis(n);
	vi blocked(n);
	vi cnt_bad(n);
	
	mst_tot.insert(0);
	
	for(int i = 0; i < n; i++) if(paths_lca[i] != -1){
		
		bool good = true;
		for(auto u : paths[i]){
			if((par[u].first != paths_lca[i]) && (par[par[u].first].second != i)){
				good = false;
				break;
			}
		}
		
		if(good){
			
			sort(paths[i].begin(), paths[i].end(), [&](int u, int v){
				return depth[u] > depth[v];
			});
			
			int cnt = 0;
			for(auto u : paths[i]) if(!vis[u]){
				
				if(cnt==2){
					good = false;
					break;
				}
				
				cnt++;
				
				int w = u;
				while(w != paths_lca[i]){
					vis[w] = true;
					w = par[w].first;
				}
			}
		}
		
		if(good){
			mst[paths_lca[i]].insert(paths_sum[i]);
		}
		else{
			cnt_bad[i] = INF;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(!mst[i].empty()){
			mst_tot.insert(*mst[i].rbegin());
		}
	}
	
	while(q--){
		
		int k, u;
		cin >> k >> u;
		u--;
		
		if(k==0){
			
			blocked[u] = true;
			
			if(!mst[u].empty()){
				mst_tot.erase(mst_tot.find(*mst[u].rbegin()));
			}
			
			if(u != 0){
				
				int c = par[u].second;
				int cp = paths_lca[c];
				int cs = paths_sum[c];
				
				if(cnt_bad[c]++ == 0){
					
					if(!blocked[cp]) if(!mst[cp].empty()){
						mst_tot.erase(mst_tot.find(*mst[cp].rbegin()));
					}
					
					mst[cp].erase(mst[cp].find(cs));
					
					if(!blocked[cp]) if(!mst[cp].empty()){
						mst_tot.insert(*mst[cp].rbegin());
					}
				}
			}
		}
		else{
			
			blocked[u] = false;
			
			if(!mst[u].empty()){
				mst_tot.insert(*mst[u].rbegin());
			}
			
			if(u != 0){
				
				int c = par[u].second;
				int cp = paths_lca[c];
				int cs = paths_sum[c];
				
				if(--cnt_bad[c] == 0){
					
					if(!blocked[cp]) if(!mst[cp].empty()){
						mst_tot.erase(mst_tot.find(*mst[cp].rbegin()));
					}
					
					mst[cp].insert(cs);
					
					if(!blocked[cp]) if(!mst[cp].empty()){
						mst_tot.insert(*mst[cp].rbegin());
					}
				}
			}
		}
		
		cout << (*mst_tot.rbegin()) << endl;
	}
}
