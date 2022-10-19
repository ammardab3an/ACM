// Problem: C. Circuit Board Design
// Contest: Codeforces - 2018-2019 ICPC Northwestern European Regional Programming Contest (NWERC 2018)
// URL: https://codeforces.com/gym/102483/problem/C
// Memory Limit: 256 MB
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
 
const int NMAX = 1e3 + 10;

int n;
vi adj[NMAX];
vi nadj[NMAX];
int par[NMAX];
vi vd[NMAX];
pair<double, double> ans[NMAX];

void dfs(int u, int p, int d){
	
	vd[d].push_back(u);
	
	for(auto v : adj[u]) if(v != p){
		par[v] = u;
		nadj[u].push_back(v);
		dfs(v, u, d+1);
	}	
}

double calc(double x, double y, double nx){
	
	// (x-nx)^2 + (y-ny)^2 = 1	
	// (y-ny)^2 = 1-(x-nx)^2 = C
	// ny = y-sqrt(C)
	
	return y - sqrt(1.0-(x-nx)*(x-nx));
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
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    dfs(0, -1, 0);
    
    ans[0] = {0, 0};
    
    for(int i = 1; i < n; i++){
    		
	    double lst = 0;
    	for(auto u : vd[i]){
	    	lst = max(lst, ans[par[u]].first);	
    		
    		double x = lst + 1e-3;
    		double y = calc(ans[par[u]].first, ans[par[u]].second, x);
    		
    		lst = x;
    		
    		ans[u] = {x, y};
    	}
    }
    
    cout << fixed << setprecision(6);
    
    for(int i = 0; i < n; i++){
    	cout << ans[i].first << ' ' << ans[i].second << endl;
    	// cout << "(" << ans[i].first << ", " << ans[i].second << ")" << endl;
    }
}
