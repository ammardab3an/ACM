// Problem: D. Potion Brewing Class
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/contest/1654/problem/D
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
const int MOD = 998244353; // 1e9 + 7;
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

int nxt[NMAX];
vi factors[NMAX];
int cnt[NMAX], mn[NMAX];
int vis[NMAX], vid;
vi tmp_factors;
vector<iii> adj[NMAX];

void init(){
	
	for(int i = NMAX-1; i > 1; i--){
		for(int j = i; j < NMAX; j+=i){
			nxt[j] = i;
		}
	}    
	
	for(int i = 1; i < NMAX; i++){
		int x = i;
		while(x != 1){
			factors[i].push_back(nxt[x]);
			x /= nxt[x];
		}	
	}
}

void update(int x, int val){
	
	if(vis[x]!=vid){
		vis[x] = vid;
		cnt[x] = mn[x] = 0;
		tmp_factors.push_back(x);
	}	
	
	cnt[x] += val;
}

void dfs0(int u, int p){
	for(auto [v, xy] : adj[u]) if(v != p){
		auto [x, y] = xy;
		for(auto f : factors[x]) update(f, +1);
		// important to do the minimization here so it acts like gcd
		for(auto f : factors[y]) update(f, -1), mn[f] = min(mn[f], cnt[f]); 
		dfs0(v, u);
		for(auto f : factors[x]) update(f, -1);
		for(auto f : factors[y]) update(f, +1);
	}	
}

int dfs1(int u, int p, int val){
	
	int ret = val;
	
	for(auto [v, xy] : adj[u]) if(v != p){
		auto [x, y] = xy;
		int nval = val;
		for(auto f : factors[x]) nval = mul(nval, f);
		for(auto f : factors[y]) nval = mul(nval, pow_exp(f, MOD-2));
		int nxt = dfs1(v, u, nval);
		ret = add(ret, nxt);
	}
	
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
	
	init();
	
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		tmp_factors.clear();
		for(int i = 0; i < n; i++){
			adj[i].clear();
		}
		
		for(int i = 0; i < n-1; i++){
			int u, v, x, y;
			cin >> u >> v >> x >> y;
			u--, v--;
			adj[u].push_back({v, {y, x}});
			adj[v].push_back({u, {x, y}});
		}
		
		vid++;
		
		dfs0(0, -1);
		
		int p = 1;
		for(auto f : tmp_factors){
			p = mul(p, pow_exp(f, -mn[f]));
		}
		
		int ans = dfs1(0, -1, p);
		cout << ans << endl;
    }	
}
