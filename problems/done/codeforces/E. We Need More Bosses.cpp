// Problem: E. We Need More Bosses
// Contest: Codeforces - Educational Codeforces Round 46 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1000/E
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 3e5 + 10;
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

vi adj[NMAX];
int col[NMAX], sz;
vpii edges;
int tin[NMAX];
int low[NMAX];
bool visited[NMAX];
int tim;
vi adj2[NMAX];

void dfs(int u, int p){
	
	visited[u] = true;
	tin[u] = low[u] = tim++;
	
	for(auto &v : adj[u]) if(v != p){
		
		if(visited[v]){
			low[u] = min(low[u], low[v]);
		}
		else{
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > tin[u]){
				edges.push_back({u, v});
				v *= -1;
			}
		}
	}
}

void dfs2(int u, int p, int c){
	
	col[u] = c;
	
	for(auto v : adj[u]){
		if(v < 0){
			if(!col[-v]){			
				dfs2(-v, u, ++sz);
			}
		}
		else{
			if(!col[v]){			
				dfs2(v, u, c);
			}
		}
	}
}

int w, dw;
void go(int u, int p, int dist){
	
	if(dist > dw){
		w = u;
		dw = dist;
	}
	
	for(auto v : adj2[u]) if(v != p){
		go(v, u, dist+1);	
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
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(0, -1);
	
	sz = 1;
	dfs2(0, -1, 1);
	
	for(auto [u, v] : edges){
		u = col[u];
		v = col[v];
		adj2[u].push_back(v);
		adj2[v].push_back(u);
	}
	
	w = -1;
	dw = -1;
	go(1, -1, 0);
	
	dw = -1;
	go(w, -1, 0);
	
	cout << dw << endl;
}
