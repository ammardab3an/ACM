// Problem: F2. Omsk Metro (hard version)
// Contest: Codeforces - Codeforces Round 881 (Div. 3)
// URL: https://codeforces.com/contest/1843/problem/F2
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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

struct node{
	
	int sum;
	int mx_pre, mx_suf, mx_ans;
	int mn_pre, mn_suf, mn_ans;	
	
	node(){}
	
	node(int val){
		sum = val;
		mx_pre=mx_suf=mx_ans = max(val, int(0));
		mn_pre=mn_suf=mn_ans = min(val, int(0));
	}
};

node merge(const node &a, const node &b){
	
	node ret;
	ret.sum = a.sum + b.sum;
	
	ret.mx_pre = max(a.mx_pre, a.sum + b.mx_pre);
	ret.mx_suf = max(b.mx_suf, b.sum + a.mx_suf);
	ret.mx_ans = max({a.mx_ans, b.mx_ans, a.mx_suf + b.mx_pre});
	
	ret.mn_pre = min(a.mn_pre, a.sum + b.mn_pre);
	ret.mn_suf = min(b.mn_suf, b.sum + a.mn_suf);
	ret.mn_ans = min({a.mn_ans, b.mn_ans, a.mn_suf + b.mn_pre});
	
	return ret;
}

int n;
vi adj[NMAX];
int val[NMAX];
int depth[NMAX];
int par[NMAX][LOG_MAX];
node par_calc[2][NMAX][LOG_MAX];

void dfs(int u, int p){
	
	for(auto v : adj[u]) if(v != p){
		
		depth[v] = depth[u] + 1;
		
		par[v][0] = u;
		for(int i = 1; i < LOG_MAX; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}
		
		par_calc[0][v][0] = node(val[v]);
		for(int i = 1; i < LOG_MAX; i++){
			par_calc[0][v][i] = merge(par_calc[0][v][i-1], par_calc[0][par[v][i-1]][i-1]);
		}
		
		par_calc[1][v][0] = node(val[v]);
		for(int i = 1; i < LOG_MAX; i++){
			par_calc[1][v][i] = merge(par_calc[1][par[v][i-1]][i-1], par_calc[1][v][i-1]);
		}
		
		dfs(v, u);
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

node calc(int u, int p, bool b){
	
	// assert(lca(u, p) == p);
	
	node ret(0);
	
	int dif = depth[u] - depth[p];
	
	for(int i = 0; i < LOG_MAX; i++) if((dif>>i)&1){
		
		if(!b){
			ret = merge(ret, par_calc[0][u][i]);		
		}
		else{
			ret = merge(par_calc[1][u][i], ret);		
		}
		
		u = par[u][i];
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
    
	// init();

    int t; cin >> t; while(t--){

		int q;
		cin >> q;
		
		{
			n = 1;
			val[0] = 1;
			
			for(int i = 0; i < q; i++){
				adj[i].clear();
			}
		}
		
		vector<array<int, 3>> queries;
		
		for(int i = 0; i < q; i++){
			
			char c;
			cin >> c;
			
			if(c=='+'){
				int p, v;
				cin >> p >> v;
				p--;
				adj[p].push_back(n);
				val[n] = v;
				n++;
			}	
			else{
				int u, v, k;
				cin >> u >> v >> k;
				u--, v--;
				queries.push_back({u, v, k});
			}
		}
		
		dfs(0, -1);
		
		for(auto [u, v, k] : queries){
			
			int p = lca(u, v);
			
			node st_path = calc(u, p, 0);
			node nd_path = node(val[p]);
			node rd_path = calc(v, p, 1);
			
			node cur = merge(st_path, merge(nd_path, rd_path));
			
			bool ans = cur.mn_ans <= k && k <= cur.mx_ans;
			
			cout << (ans ? "YES" : "NO") << endl;
		}
    }	
}
