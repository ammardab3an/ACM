// Problem: G. Tree Queries
// Contest: Codeforces - Educational Codeforces Round 25
// URL: https://codeforces.com/contest/825/problem/G
// Memory Limit: 256 MB
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
 
const int NMAX = 1e6 + 10;

int n;
vi adj[NMAX];
int par[NMAX];
bool col[NMAX];
int val[NMAX];
int nxt[NMAX];
bool bad[NMAX];
int dist[NMAX];

int get_par(int u){
	return par[u] = (par[u]==u) ? u : get_par(par[u]);
}

bool merge(int u, int v){
	
	if((u=get_par(u)) == (v=get_par(v))){
		return false;
	}	
	
	if(rand()&1){
		swap(u, v);
	}
	
	par[u] = v;
	col[v] |= col[u];
	val[v] = min(val[v], val[u]);
	
	return true;
}

void go(int u, int p){
	for(auto v : adj[u]) if(v != p) if(dist[v]==-1){
		dist[v] = dist[u]+1;
		go(v, u);
	}
}

void go2(int u, int p, int w){
	merge(u, w);
	for(auto v : adj[u]) if(v != p) if(!bad[v]){
		go2(v, u, w);
	}
}

void build(int u){
	
	memset(dist, -1, sizeof dist);
	dist[u] = 0;
	go(u, -1);	
	
	for(int i = 0; i < n; i++){
		par[i] = i;
		col[i] = 0;
		val[i] = i;
		nxt[i] = -1;
	}
	
	col[u] = 1;
	
	for(int i = 0; i < n; i++){
		
		int w = i;
		w = get_par(w);
		w = val[w];
		if(w < i) continue;
		
		if(u==w){
			go2(u, -1, w);	
			continue;
		}
		
		assert(adj[w].size() > 0);
		
		int v = adj[w][0];
		
		for(auto x : adj[w]){
			if(dist[x] < dist[v]){
				v = x;
			}
		}
		
		nxt[w] = v;
		bad[v] = true;
		go2(w, -1, w);
		bad[v] = false;
		bad[w] = true;
	}
}

void update(int u){
	
	u = get_par(u);
	
	if(!col[u]){
		
		u = val[u];
		int v = nxt[u];
		nxt[u] = -1;
		
		while(v != -1){
			v = val[get_par(v)];
			merge(u, v);
			int t = v;
			v = nxt[v];
			nxt[t] = -1;
		}	
	}
}

int query(int u){
	u = get_par(u);
	return val[u];
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int q;
    cin >> n >> q;
    
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    {
    	int k, u;
    	cin >> k >> u;
    	u %= n;
    	
		build(u);
		q--;
    }
    
    int lst = 0;
    
    while(q--){
    	
    	int k, u;
    	cin >> k >> u;
    	
    	u = (u+lst)%n;
    	
    	if(k==1){
    		update(u);
    	}
    	else{
    		lst = query(u)+1;
    		cout << lst << endl;
    	}
    }
}
