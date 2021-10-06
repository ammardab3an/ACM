// Problem: B. Jzzhu and Cities
// Contest: Codeforces - Codeforces Round #257 (Div. 1)
// URL: https://codeforces.com/problemset/problem/449/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t

typedef unsigned int		uint;
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

const lli INF = 0x3f3f3f3f3f3f3f3f;

const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 1e5 + 10;
const int MMAX = 2e5 + 10;

vpll adj[NMAX];
bool vis[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCALtmp
    freopenI;
    freopenO;
#endif
	
	int n, m, k;
	cin >> n >> m >> k;
	
	for(int i = 0; i < m; i++){
		
		lli u, v, c;
		cin >> u >> v >> c;

		adj[u].push_back({c, v});
		adj[v].push_back({c, u});
	}
	
	
	priority_queue< pll, vpll, greater<pll> > que;
	
	que.push({0, -1});
	
	for(int i = 0; i < k; i++){
		lli v, c;
		cin >> v >> c;
		que.push({c, v});
	}
	
	int ans = 0;
	
	while(!que.empty()){
		
		pll tp = que.top(); que.pop();
		
		lli cc = tp.first;
		lli cn = -tp.second;
		
		if(cn < 0){
			cn *= -1;
			ans += vis[cn];
		}
		
		if(vis[cn]) continue;
		vis[cn] = true;
		
		for(pll nxt : adj[cn]){
			
			lli nc = nxt.first;
			lli nn = nxt.second;
			
			que.push({cc + nc, -nn});
					
		}
	}
	
	cout << ans << endl;
}