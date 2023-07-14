// Problem: D. Design Tutorial: Inverse the Problem
// Contest: Codeforces - Codeforces Round 270
// URL: https://codeforces.com/contest/472/problem/D
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
const int NMAX = 2e3 + 10;
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

vpii adj[NMAX];
int par[NMAX][LOG_MAX];
int depth[NMAX];
int depth_sm[NMAX];

void dfs(int u){
	
	for(auto [v, d] : adj[u]){
		
		depth[v] = depth[u]+1;
		depth_sm[v] = depth_sm[u]+d;
		
		par[v][0] = u;
		for(int i = 1; i < LOG_MAX; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}
		
		dfs(v);
	}
}

int lca(int u, int v){
	
	if(depth[u] < depth[v]){
		swap(u, v);
	}	
	
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

int dist(int u, int v){
	return depth_sm[u] + depth_sm[v] - 2*depth_sm[lca(u, v)];
}

bool check(int n, const vector<vi>&grid){
	
	dfs(0);
	vector<vi> ngrid(n, vi(n));
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < i; j++){
		ngrid[i][j] = ngrid[j][i] = dist(i, j);
	}
	
	// for(auto v : ngrid){
		// for(auto i : v){
			// cout << i << ' ';
		// }
		// cout << endl;
	// }
	
	return grid==ngrid;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n;
	cin >> n;
	
	vector<vi> grid(n, vi(n));
	
	for(auto &v : grid)
	for(auto &i : v) cin >> i;
	
	bool good = true;
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++){
		if((grid[i][j]==0 && i!=j) || (grid[i][j]!=0 && i==j)){
			good = false;
		}
	}
	
	if(!good){
		cout << "NO" << endl;
		return 0;
	}
	
	queue<int> que;
	vector<bool> vis(n);
	que.push(0);
	par[0][0] = -1;
	
	while(!que.empty()){
		
		int u = que.front();
		que.pop();
		
		if(vis[u]){
			good = false;
			break;
		}
		else{
			vis[u] = true;
		}
		
		vi pos(n);
		iota(pos.begin(), pos.end(), 0);
		sort(pos.begin(), pos.end(), [&](int a, int b){
			return grid[u][a] < grid[u][b];
		});
		
		vi ch;
		if(par[u][0] != -1){
			ch.push_back(par[u][0]);
		}
		
		for(auto v : pos) if(v != u) if(v != par[u][0]){
			
			bool good = true;
			for(auto c : ch) if(grid[u][v]==grid[u][c]+grid[c][v]){
				good = false;
				break;
			}
			
			if(good || ch.empty()){
				ch.push_back(v);
			}
		}
		
		for(auto c : ch) if(c != par[u][0]){
			que.push(c);
			par[c][0] = u;
			adj[u].push_back({c, grid[u][c]});
			// cout << u << ' ' << c << ' ' << grid[u][c] << endl;
		}
	}
	
	// cout << dist(0, 1) << endl;
	// cout << depth[0] << ' ' << depth[1] << endl;
	
	cout << (good && check(n, grid) ? "YES" : "NO") << endl;
}
