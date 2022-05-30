// Problem: D - Stamp Rally
// Contest: AtCoder - AtCoder Grand Contest 002
// URL: https://atcoder.jp/contests/agc002/tasks/agc002_d
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

vi adj[NMAX];
int par[NMAX];
int sz[NMAX];

int get_par(int u){
	return par[u] = (par[u]==u) ? u : get_par(par[u]);
}

void merge(int u, int v){
	
	u = get_par(u);
	v = get_par(v);
	
	if(u==v) return;
	
	if(sz[u] > sz[v]) swap(u, v);
	
	par[u] = v;
	sz[v] += sz[u];
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    vector<array<int, 2>> edges(m);
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	edges[i] = {u, v};
    }
    
    int q;
    cin >> q;
	
	vi ans(q);
    vector<array<int, 3>> queries(q);
    
    for(int i = 0; i < q; i++){
    	int u, v, x;
    	cin >> u >> v >> x;
    	u--, v--;
    	queries[i] = {u, v, x};
    }
    
    queue<pair<pii, vi>> que;
    que.push({{0, m}, vi(q)});
    for(int i = 0; i < q; i++) que.front().second[i] = i;
    
    int cur = INF;
    
    while(!que.empty()){
    	
    	auto fr = que.front();
    	que.pop();
    	
    	int l = fr.first.first;
    	int r = fr.first.second;
    	vi &v = fr.second;
    	
    	if(l==r){
    		for(auto i : v) ans[i] = l;
    		continue;
    	}
    	
    	int mid = (l+r)/2;
    	
    	if(cur <= mid){
    		for(int i = cur; i < mid; i++){
    			merge(edges[i][0], edges[i][1]);
    		}
    	}
    	else{
    		for(int i = 0; i < n; i++){
    			par[i] = i;
    			sz[i] = 1;
    		}
    		for(int i = 0; i < mid; i++){
    			merge(edges[i][0], edges[i][1]);
    		}
    	}
    	
    	cur = mid;
    	
    	vi lf, ri;
    	for(auto i : v){
    		
    		int u = queries[i][0];
    		int v = queries[i][1];
    		int x = queries[i][2];
    		
    		u = get_par(u);
    		v = get_par(v);
    		
    		int tot = (u==v) ? sz[u] : (sz[u]+sz[v]);
    		
    		if(x <= tot){
    			lf.push_back(i);
    		}
    		else{
    			ri.push_back(i);
    		}
    	}
    	
    	if(!lf.empty()) que.push({{l, mid}, lf});
    	if(!ri.empty()) que.push({{mid+1, r}, ri});
    }
    
    for(auto i : ans) cout << i << endl;
}
