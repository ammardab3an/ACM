// Problem: C. Three Friends
// Contest: Codeforces - bld.ai Summer22 Internship Contest [Practice]
// URL: https://codeforces.com/group/tKWnzvWA4V/contest/387337/problem/C
// Memory Limit: 512 MB
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

int n, m;
int nd[3];
vpii adj0[NMAX];
vpii adj1[NMAX];
int dist0[NMAX];
int dist1[NMAX];
int dist2[NMAX];

void dij(int nd, vpii *adj, int *dist){
	
	memset(dist, INF, (n+10) * sizeof(dist[0]));
	
	priority_queue<pii> que;
	que.push({0, nd});
	dist[nd] = 0;
	
	while(!que.empty()){
		
		auto tp = que.top();
		que.pop();
		
		int u = tp.second;
		int d = -tp.first;
		
		if(dist[u] < d) continue;
		
		for(auto [w, v] : adj[u]){
			if(dist[v] > d + w){
				dist[v] = d + w;
				que.push({-dist[v], v});
			}
		}
		
	}	
	
	// for(int i = 0; i < n; i++){
		// cout << dist[i] << endl;
	// }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	adj0[u].push_back({w, v});
    	adj1[v].push_back({w, u});
    }
    for(int i = 0; i < 3; i++){
    	cin >> nd[i];
    	nd[i]--;
    }
    
    int ans = INFLL;
    int ans_nd = -1;
    
    for(int i = 0; i < 3; i++){
    	
    	dij(nd[(i+0)%3], adj1, dist0);
    	dij(nd[(i+1)%3], adj0, dist1);
    	dij(nd[(i+2)%3], adj0, dist2);
    	
    	int mn_cans = INFLL;
    	
    	for(int i = 0; i < n; i++) {
    		
	    	if(dist0[i] < INFLL) 
	    	if(dist1[i] < INFLL) 
	    	if(dist2[i] < INFLL) 
	    	{
	    		int cans = dist0[i] + dist1[i] + dist2[i];
	    		mn_cans = min(mn_cans, cans);
	    	}
    	}
    	
    	if(ans > mn_cans){
    		ans = mn_cans;
    		ans_nd = nd[i];
    	}
    	else if(ans == mn_cans){
    		ans_nd = min(ans_nd, nd[i]);
    	}
    	
		// cout << nd[i]+1 << ' ' << mn_cans << endl;
    }
    
    if(ans_nd==-1){
    	cout << -1 << endl;
    }
    else{
		cout << ans_nd+1 << ' ' << ans << endl;	
    }
}
