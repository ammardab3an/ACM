// Problem: A. The Fair Nut and the Best Path
// Contest: Codeforces - Codeforces Round #526 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1083/A
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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
const int NMAX = 3e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
int ans;
int w[NMAX];
vpii adj[NMAX];

int dfs(int u, int par){
	
	int mx_0 = 0;
	int mx_1 = 0;
	
	for(auto [v, d]: adj[u]) if(v != par){
		
		int tans = dfs(v, u) + w[u]-d;
		
		if(tans >= mx_0){
			mx_1 = mx_0;
			mx_0 = tans;
		}
		else if(tans >= mx_1){
			mx_1 = tans;
		}
	}
	
	ans = max({ans, mx_0, mx_1, mx_0+mx_1-w[u], w[u]});
	
	return max({mx_0, mx_1, w[u]});
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> w[i];
    }
    
    for(int i = 0; i < n-1; i++){
    	
    	int u, v, d;
    	cin >> u >> v >> d;
    	u--, v--;
    	
    	adj[u].push_back({v, d});
    	adj[v].push_back({u, d});
    }
    
    dfs(0, -1);
    
    cout << ans << endl;
}
