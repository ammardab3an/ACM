// Problem: E. Distinctive Roots in a Tree
// Contest: Codeforces - Codeforces Round #695 (Div. 2)
// URL: https://codeforces.com/contest/1467/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
#define freopenO fre		open("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, c, ans;
int arr[NMAX];
vi adj[NMAX];
int parNd[NMAX], dp[NMAX];
int tin[NMAX], tout[NMAX], euler[NMAX<<1];
map<int, vi> mp, times;
set<pii> edges;

void dfs(int nd, int par){
	
	parNd[nd] = par;
		
	tin[nd] = c;
	euler[c++] = nd;
	
	for(auto nxt : adj[nd]) if(nxt != par){
		dfs(nxt, nd);
		euler[c++] = nd;
	}
	
	tout[nd] = c-1;
}

void examine(int nd, int col){
	
	int sm = 0;
	
	for(auto nxt : adj[nd]) if(nxt != parNd[nd]){
		
		int cnt = upper_bound(times[col].begin(), times[col].end(), tout[nxt]) - 
				  lower_bound(times[col].begin(), times[col].end(), tin[nxt]);
		
		if(cnt > 0)
			edges.insert({nd, nxt});

		sm += cnt;
	}
	
	sm = mp[col].size() - sm -1;
	
	if(sm) 
		edges.insert({nd, parNd[nd]});
}

int setup(int nd, int par){
	
	dp[nd] = 0;
	
	for(auto nxt : adj[nd]) if(nxt != par){
		dp[nd] += setup(nxt, nd);
	}
	
	return dp[nd] + edges.count({nd, par});
}

void reroot(int nd, int par){
	
	if(dp[nd] == edges.size()) ans++;
	
	for(auto nxt : adj[nd]) if(nxt != par){
		
		dp[nd] -= dp[nxt] + edges.count({nxt, nd});
		dp[nxt] += dp[nd] + edges.count({nd, nxt});
		
		reroot(nxt, nd);
		
		dp[nxt] -= dp[nd] + edges.count({nd, nxt});
		dp[nd] += dp[nxt] + edges.count({nxt, nd});
	}	
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		mp[arr[i]].push_back(i);
	}
	
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(0, -1);
	
	for(auto p : mp) if(p.second.size() > 1){
		
		for(auto nd : p.second){
			times[p.first].push_back(tin[nd]);
		}
		
		sort(times[p.first].begin(), times[p.first].end());
		
		for(auto nd : p.second) 
			examine(nd, p.first);
	}
	
	setup(0, -1);
	reroot(0, -1);
	
	cout << ans << endl;
}
