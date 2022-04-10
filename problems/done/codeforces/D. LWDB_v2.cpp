// Problem: D. LWDB
// Contest: Codeforces - 2015 ICL, Finals, Div. 1
// URL: https://codeforces.com/gym/100633/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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

int n, nn;
vpii adj[NMAX];
bool used[NMAX];
int depth[NMAX];
int _dist[NMAX][LOG_MAX];
int cpar[NMAX];
int cpar_dist[NMAX];
int sz[NMAX];
vector<iii> colors[NMAX];
int t;

int lca(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	while(depth[u] > depth[v]) u = cpar[u];
	while(u != v) u = cpar[u], v = cpar[v];
	return u;	
}

int dist(int u, int v){
	int g = lca(u, v);
	return _dist[u][depth[g]] + _dist[v][depth[g]];
}

void dfs1(int u, int p){
	
	nn++;
	sz[u] = 1;
	
	for(auto [v, w] : adj[u]) if(v != p) if(!used[v]){
		dfs1(v, u);
		sz[u] += sz[v];
	}
}

int dfs2(int u, int p){
	
	for(auto [v, w] : adj[u]) if(v != p) if(!used[v]) if(sz[v] > nn/2){
		return dfs2(v, u);
	}	
	
	return u;
}

void dfs3(int u, int p, int d){
	for(auto [v, w] : adj[u]) if(v != p) if(!used[v]){
		_dist[v][d] = _dist[u][d] + w;
		dfs3(v, u, d);
	}	
}

void decompose(int u, int p){
	
	nn = 0;
	dfs1(u, u);
	int c = dfs2(u, u);
	
	cpar[c] = p==-1 ? c : p;
	depth[c] = p==-1 ? 0 : depth[p]+1;
	
	_dist[c][depth[c]] = 0;
	dfs3(c, -1, depth[c]);
	
	used[c] = true;
	
	for(auto [v, w] : adj[c]) if(!used[v]){
		decompose(v, c);
	}
}

void update(int u, int d, int c){
	
	t++;
	int p = u;
	
	while(true){
		
		int tmp_d = dist(u, p);
		
		if(tmp_d <= d){
			while(!colors[p].empty() && (colors[p].back().second.first <= d-tmp_d)){
				colors[p].pop_back();
			}
			colors[p].push_back({t, {d-tmp_d, c}});
		}
		
		if(cpar[p]==p) break;
		p = cpar[p];
	}
}

int query(int u){
	
	iii ans;
	int p = u;
	
	while(true){
		
		int dd = dist(u, p);
		
		for(auto it = colors[p].rbegin(); it != colors[p].rend(); it++){
			
			if(it->first > ans.first)
			if(it->second.first >= dd){
				ans = *it;
				break;
			}
		}
		
		if(cpar[p]==p) break;
		p = cpar[p];
	}
	
	return ans.second.second;
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
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
    }
    
    decompose(0, -1);
    
    int q; cin >> q; while(q--){
    	
    	int k;
    	cin >> k;
    	
    	if(k==1){
    		int u, d, c;
    		cin >> u >> d >> c;
    		u--;
    		update(u, d, c);
    	}
    	else{
    		int u;
    		cin >> u;
    		u--;
    		cout << query(u) << endl;
    	}
    }
}
