// Problem: Ada and Travelling Salesman
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/ADASALES/
// Memory Limit: 1536 MB
// Time Limit: 3000 ms
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
 
const int NMAX = 5e5 + 10;

int n, m;
int val[NMAX];
vi adj[NMAX];
int mx[NMAX];
int ans[NMAX];

void dfs(int u, int p){
	for(auto v : adj[u]) if(v != p){
		dfs(v, u);
		int cans = max(int(0), val[v]-val[u]) + mx[v];
		mx[u] = max(mx[u], cans);
	}	
}

void go(int u, int p){
	
	ans[u] = mx[u];
	
	multiset<int> mst;
	for(auto v : adj[u]){
		int cans = max(int(0), val[v]-val[u]) + mx[v];
		mst.insert(cans);
	}
	
	for(auto v : adj[u]) if(v != p){
			
		int cans = max(int(0), val[v]-val[u])  + mx[v];
		mst.erase(mst.find(cans));
		mx[u] = mst.empty() ? 0 : *mst.rbegin();
		
		int old_mx_v = mx[v];
		int old_mx_u = mx[u];
		
		int cans_u = max(int(0), val[u]-val[v]) + mx[u];
		mx[v] = max(mx[v], cans_u);
		
		go(v, u);
		
		mx[v] = old_mx_v;
		mx[u] = old_mx_u;
		mst.insert(cans);
	}	
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
    	cin >> val[i];
    }
    
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    dfs(0, -1);
	
    go(0, -1);
    
    while(m--){
    	int u;
    	cin >> u;
    	cout << ans[u] << endl;
    }
}
