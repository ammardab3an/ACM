// Problem: E. Minimum Path
// Contest: Codeforces - Educational Codeforces Round 102 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1473/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

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

int n, m;
vector< pair<int, int> > adj[NMAX];
int dist[NMAX][2][2];
int vist[NMAX][2][2];

void dij(){
	
	memset(dist, INF, sizeof dist);
	
	priority_queue< array<int, 4>, vector< array<int, 4> >, greater< array<int, 4> > > que;
	
	que.push({0, 0, 0, 0});

	while(!que.empty()){
		
		auto tp = que.top(); que.pop();
		
		int curC = tp[0];
		int curNd = tp[1];
		int curMn = tp[2];
		int curMx = tp[3];
		
		if(vist[curNd][curMn][curMx]) continue;
		
		vist[curNd][curMn][curMx] = true;
		dist[curNd][curMn][curMx] = curC;
		
		for(auto [nxtC, nxtNd] : adj[curNd]){
			
			que.push({curC + nxtC, nxtNd, curMn, curMx});
			
			if(!curMn && !curMx){
				que.push({curC + nxtC, nxtNd, 1, 1});
			}
			
			if(!curMn){
				que.push({curC + 2*nxtC, nxtNd, 1, curMx});
			}
			
			if(!curMx){
				que.push({curC, nxtNd, curMn, 1});
			}
		}		
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int u, v, c; 
		cin >> u >> v >> c; u--, v--;
		adj[u].push_back({c, v});
		adj[v].push_back({c, u});
	}
	
	dij();
	
	for(int i = 1; i < n; i++) cout << dist[i][1][1] << ' ' ; cout << endl;

}
