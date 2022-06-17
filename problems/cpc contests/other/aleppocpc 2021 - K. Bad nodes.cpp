
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

int n, m, k, q;
vpii adj[NMAX];
int dist[NMAX];
int par[NMAX];

int get_par(int u){
	return par[u] = par[u]==u ? u : get_par(par[u]);
}

bool merge(int u, int v){
	
	if((u=get_par(u)) == (v=get_par(v))){
		return false;
	}
	
	if(rand()&1) swap(u, v);
	
	par[u] = v;
	
	return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n >> m >> k >> q;
		
		for(int i = 0; i < n; i++){
			adj[i].clear();
		}
		
		for(int i = 0; i < m; i++){
			int u, v, w;
			cin >> u >> v >> w;
			u--, v--;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		
		vi bad(k);
		for(auto &i : bad) cin >> i, --i;
		
		vpii queries(q);
		for(auto &p : queries){
			cin >> p.first >> p.second;
			p.first--, p.second--;
		}
		
		
		{ // multi dij
		
			for(int i = 0; i < n; i++){
				dist[i] = INFLL;
			}
			
			priority_queue<pii> que;
			
			for(auto u : bad){
				dist[u] = 0;
				que.push({0, u});
			}
			
			while(!que.empty()){
				
				auto tp = que.top();
				que.pop();
				
				int cu = tp.second;
				int cd = -tp.first;
				
				if(dist[cu] < cd) continue;
				
				for(auto [v, w] : adj[cu]){
					if(dist[v] > dist[cu] + w){
						dist[v] = dist[cu] + w;
						que.push({-dist[v], v});
					}
				}
			}
		} // end multi dij
		
		vi ans(q, -1);
		
		{ // dsu
		
			vi pos(n);
			iota(pos.begin(), pos.end(), 0);
			sort(pos.begin(), pos.end(), [&](int i, int j){
				return dist[i] > dist[j];
			});
			
			iota(par, par+n, 0);
			
			vector<set<int>> sts(n);
			vi sts_id(n);
			iota(sts_id.begin(), sts_id.end(), 0);
			
			for(int i = 0; i < q; i++){
				int u = queries[i].first;
				int v = queries[i].second;	
				sts[u].insert(i);
				sts[v].insert(i);
			}
			
			vi vis(n);
			
			for(auto u : pos){
				
				vis[u] = true;
				
				for(auto [v, w] : adj[u]) if(vis[v]){
					
					int pu = get_par(u);
					int pv = get_par(v);
					
					if(pu==pv) continue;
					
					if(rand()&1) swap(pu, pv);
					
					if(sts[sts_id[pu]] < sts[sts_id[pv]]){
						swap(sts_id[pu], sts_id[pv]);
					}
					
					for(auto q_id : sts[sts_id[pv]]){
						if(sts[sts_id[pu]].count(q_id)){
							ans[q_id] = dist[u];
						}
						else{
							sts[sts_id[pu]].insert(q_id);
						}
					}
					
					par[pv] = pu;
				}
			}
			
		} // end dsu
		
		for(auto i : ans){
			cout << i << endl;
		}
    }	
}
