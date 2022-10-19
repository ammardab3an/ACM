// Problem: A. Artistic Swimming
// Contest: Codeforces - 2021 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/103577/problem/A
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<iii> edges(m);
    
    for(int i = 0; i < m; i++){
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	edges[i] = {w, {u, v}};
    }
    
    vi ans(q, INFLL);
    vector<iii> queries(q);
    
    for(int i = 0; i < q; i++){
    	int u, v, x;
    	cin >> u >> v >> x;
    	u--, v--;
    	queries[i] = {x, {u, v}};
    	if(u==v) ans[i] = x;
    }
    
    vector<vi> dist[2];
    
    dist[0] = dist[1] = vector<vi>(n, vi(n, INFLL));
    
    for(int i = 0; i < n; i++){
    	dist[0][i][i] = 0;
    	dist[1][i][i] = 0;
    }
    
    for(int k = 1; k <= n; k++){
    	
    	for(auto p : edges){
    		int d = p.first;
    		auto [u, v] = p.second;
    		for(int w = 0; w < n; w++){
    			dist[k&1][w][v] = min(dist[k&1][w][v], dist[(k+1)&1][w][u] + d);
    		}
    	}
		
    	for(int i = 0; i < q; i++){
    		int x = queries[i].first;
    		auto [u, v] = queries[i].second;
    		ans[i] = min(ans[i], dist[k&1][u][v] + x*(k+1));
    	}
    }
    
    for(auto i : ans){
    	if(i>=INF) i = -1;
    	cout << i << endl;
    }
}
