// Problem: E. Tree Painting
// Contest: Codeforces - Educational Codeforces Round 67 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1187/problem/E?fbclid=IwAR2EtKq_BiWXWdK8kTjYZPUTsZEFnHiU_y1SeC5iraRtL7p4N3a0RqpFFMU
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
vi adj[NMAX];
int sz[NMAX];
lli ans, dp[NMAX];

int calcSz(int nd, int par){
	sz[nd] = 1;
	for(auto nxt : adj[nd]) if(nxt != par){
		sz[nd] += calcSz(nxt, nd);
	}
	return sz[nd];
}

lli calcDp(int nd, int par){
	dp[nd] = sz[nd];
	for(auto nxt : adj[nd]) if(nxt != par){
		dp[nd] += calcDp(nxt, nd);
	}
	return dp[nd];
}

void dfs(int nd, int par){
	
	ans = max(ans, dp[nd]);
	for(auto nxt : adj[nd]) if(nxt != par){
		
		dp[nd] -= sz[nxt] + dp[nxt];
		sz[nd] -= sz[nxt];
		
		dp[nxt] += sz[nd] + dp[nd];
		sz[nxt] += sz[nd];
		
		dfs(nxt, nd);
		
		dp[nxt] -= sz[nd] + dp[nd];
		sz[nxt] -= sz[nd];
		
		dp[nd] += sz[nxt] + dp[nxt];
		sz[nd] += sz[nxt];
	}
}
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v; u--; v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    ans = 0;
    calcSz(0, -1);
    calcDp(0, -1);
    dfs(0, -1);
    
    cout << ans << endl;
}
