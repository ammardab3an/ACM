
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
char val[NMAX];
vi adj[NMAX];
int par[NMAX][LOG_MAX];
int par_val[2][NMAX][LOG_MAX];
int depth[NMAX];

const int pp = 543921331;
const int mm = 31;

int pow_mm[NMAX];

void init_hash(){
	pow_mm[0] = 1;
	for(int i = 1; i < NMAX; i++){
		pow_mm[i] = (pow_mm[i-1] * mm) % pp; 
	}	
}

int calc(int a, int b, int len_a){
	int ret = (a + ((b*pow_mm[len_a])%pp)) % pp;
	return ret;
}

void dfs(int u, int p){
	
	for(auto v : adj[u]) if(v != p){
		
		depth[v] = depth[u] + 1;
		
		par[v][0] = u;
		for(int i = 1; i < LOG_MAX; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}
		
		par_val[0][v][0] = val[v]-'a'+1;
		for(int i = 1; i < LOG_MAX; i++){
			par_val[0][v][i] = calc(par_val[0][v][i-1], par_val[0][par[v][i-1]][i-1], 1<<(i-1));
		}
		
		par_val[1][v][0] = val[v]-'a'+1;
		for(int i = 1; i < LOG_MAX; i++){
			par_val[1][v][i] = calc(par_val[1][par[v][i-1]][i-1], par_val[1][v][i-1], 1<<(i-1));
		}
		
		dfs(v, u);
	}	
}

int lca(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	int dif = depth[u] - depth[v];
	for(int i = 0; i < LOG_MAX; i++) if((dif>>i)&1) u = par[u][i];
	if(u==v) return u;
	for(int i = LOG_MAX-1; i >= 0; i--) if(par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
	return par[u][0];	
}

int foo(string str){
	
	reverse(str.begin(), str.end());
	
	int ret = 0;
	for(auto c : str){
		ret = (ret * mm + (c-'a'+1)) % pp;
	}
	
	return ret;
}

int go(int u, int v, bool debug=false){
	
	int p = lca(u, v);
	
	int st_path = 0;
	int nd_path = 0;
	int len_st_path = 0;
	int len_nd_path = 0;
	
	{
		int dif = depth[u] - depth[p];
		for(int i = 0; i < LOG_MAX; i++) if((dif>>i)&1){
			st_path = calc(st_path, par_val[0][u][i], len_st_path);
			len_st_path += 1<<i;
			u = par[u][i];
		}
	}	
	{
		int dif = depth[v] - depth[p];
		for(int i = 0; i < LOG_MAX; i++) if((dif>>i)&1){
			nd_path = calc(par_val[1][v][i], nd_path, 1<<i);
			len_nd_path += 1<<i;
			v = par[v][i];
		}
	}
	
	int ret = calc(st_path, (val[p]-'a'+1), len_st_path);
	ret = calc(ret, nd_path, len_st_path+1);
	
	return ret;
}

int32_t main(){
    
    fastIO;
	
	init_hash();
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> val[i];
	}
	
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(0, -1);
	
	int q; cin >> q; while(q--){
		
		int u, v;
		cin >> u >> v;
		u--, v--;
		
		int g0 = go(u, v);
		int g1 = go(v, u);
		
		cout << (g0==g1) << endl;
	}
}
