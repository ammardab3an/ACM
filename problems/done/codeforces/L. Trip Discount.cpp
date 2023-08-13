// Problem: L. Trip Discount
// Contest: Codeforces - 2023 ICPC HIAST Collegiate Programming Contest
// URL: https://codeforces.com/gym/104493/problem/L
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
 
const int NMAX = 1e4 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));

vpii adj[NMAX];
int pre[NMAX];
int par[NMAX][LOG_MAX];
int depth[NMAX];
int val[NMAX];
int sub[NMAX];
vi suf[NMAX];
int pre_val[NMAX];

int mem0[NMAX][1010];
int mem1[NMAX][1010];
int mem2[3][NMAX][1010];

int go0(int u, int rm);

int go2(int u, int p, int rm, int cnt){
	
	if(!rm || p==adj[u].size()){
		return cnt==2 ? 0 : -INFLL;
	}
	
	int v = adj[u][p].first;
	int &ret = mem2[cnt][v][rm];
	if(ret+1) return ret;
	
	int ans = 0;
	int l = max((int)0, rm-suf[u][p]+sub[v]);
	int r = min(rm, sub[v]);
	l = min(l, r);
	
	for(int i = l; i <= r; i++){
		int cans = go0(v, i) + go2(u, p+1, rm-i, min((int)2, cnt + (i!=0)));
		ans = max(ans, cans);
	}
	
	return ret = ans;
}

int go1(int u, int p, int rm){
	
	if(!rm || p==adj[u].size()){
		return 0;
	}	
	
	int v = adj[u][p].first;
	int &ret = mem1[v][rm];
	if(ret+1) return ret;
	
	int ans = 0;
	int l = max((int)0, rm-(suf[u][p]-sub[v]));
	int r = min(rm, sub[v]);
	l = min(l, r);
	
	for(int i = l; i <= r; i++){
		int cans = go0(v, i) + go1(u, p+1, rm-i);
		ans = max(ans, cans);
	}
	
	return ret = ans;
}

int go0(int u, int rm){
	
	if(!rm){
		return 0;
	}
	
	int &ret = mem0[u][rm];
	if(ret+1) return ret;
	
	int ans = val[u] + go1(u, 0, rm);
	return ret = ans;
}

void dfs0(int u, int p){
	
	sub[u] = 1;
	suf[u].clear();
	
	if(p != -1){
		auto it = adj[u].begin();
		while(it->first != p) it++;
		adj[u].erase(it);
	}
	
	for(auto [v, w] : adj[u]){
		
		depth[v] = depth[u] + 1;
		
		par[v][0] = u;
		for(int i = 1; i < LOG_MAX; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}
		
		dfs0(v, u);
		
		sub[u] += sub[v];
		suf[u].push_back(sub[v]);
	}
	
	int sz = adj[u].size();
	for(int i = sz-2; i >= 0; i--){
		suf[u][i] += suf[u][i+1];
	}
}

int lca(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	int dif = depth[u]-depth[v];
	for(int i = 0; i < LOG_MAX; i++) if((dif>>i)&1) u = par[u][i];
	if(u==v) return u;
	for(int i = LOG_MAX-1; i >= 0; i--) if(par[u][i] != par[v][i]){
		u = par[u][i], v = par[v][i];
	}	
	return par[u][0];
}

void dfs1(int u){
	for(auto [v, w] : adj[u]){
		dfs1(v);
		pre[u] += pre[v];
	}	
}
void dfs2(int u){
	for(auto [v, w] : adj[u]){
		val[v] = pre[v] * w;
		pre_val[v] = pre_val[u] + val[v];
		dfs2(v);
	}
}

int32_t main(){
    
    fastIO;
    
    int t; cin >> t; while(t--){

		int n, k, m;
		cin >> n >> k >> m;
		
		for(int i = 0; i < n; i++){
			pre[i] = 0;
			adj[i].clear();
		}
		
		for(int i = 0; i < n-1; i++){
			int u, v, w;
			cin >> u >> v >> w;
			u--, v--;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		
		dfs0(0, -1);
		
		while(m--){
			int u, v;
			cin >> u >> v;
			u--, v--;
			pre[u]++;
			pre[v]++;
			pre[lca(u, v)] -= 2;
		}
		
		dfs1(0);
		dfs2(0);
		
		memset(mem0, -1, sizeof mem0);
		memset(mem1, -1, sizeof mem1);
		memset(mem2, -1, sizeof mem2);
		
		int tot = 0;
		for(int i = 0; i < n; i++){
			tot += val[i];
		}
		
		int ans = tot;
		
		if(k >= 2) for(int i = 0; i < n; i++){
			int st_path = tot - max(int(0), go2(i, 0, k, 0));
			int nd_path = tot - max(int(0), go2(i, 0, k-1, 0)) - pre_val[i];
			ans = min(ans, min(st_path, nd_path));
		}
		
		cout << ans << endl;
    }	
}
