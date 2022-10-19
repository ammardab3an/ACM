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
 
const int NMAX = 500 + 10;

int n, m, q;
vpii adj[NMAX];
int dist[NMAX];

int dij(int u, int v, int x){
	
	memset(dist, INF, sizeof dist);
	
	dist[u] = x;
	priority_queue<pii> que;
	que.push({-x, u});
	
	while(!que.empty()){
		
		pii tp = que.top();
		que.pop();
		
		int cu = tp.second;
		int cd = -tp.first;
		
		if(cd > dist[cu]) continue;
		
		if(cu == v){
			return cd;
		}
		
		cd += x;
		
		for(auto [v, w] : adj[cu]){
			if(dist[v] > cd+w){
				dist[v] = cd+w;
				que.push({-(cd+w), v});
			}
		}
	}
	
	return -1;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m >> q;
    
    for(int i = 0; i < m; i++){
    	
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	
    	adj[u].push_back({v, w});
    }
    
    
    while(q--){
    	
    	int u, v, x;
    	cin >> u >> v >> x;
    	u--, v--;
    	
    	cout << dij(u, v, x) << endl;
    }
}