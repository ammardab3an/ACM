// different vs deferent

// Problem: H. Weekend
// Contest: Codeforces - Training Contest 3
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/310125/problem/H
// Memory Limit: 250 MB
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
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m, k;
vpii adj[111];
int dist[111][1 << 9];
int foo[111];

int dij(){
	
	memset(dist, INF, sizeof dist);
	dist[0][0] = 0;
	priority_queue< iii, vector<iii>, greater<iii> > que;
	que.push({0, {0, 0}});
	
	while(!que.empty()){
		
		auto tp = que.top(); que.pop();
		
		int c = tp.first;
		int nd = tp.second.first;
		int msk = tp.second.second;
		
		if(dist[nd][msk] < c) continue;
		
		if(nd == n-1 && msk == ((1 << k) -1)) return c;
		
		for(auto nxt : adj[nd]){
			
			int nxtC = c + nxt.first;
			int nxtNd = nxt.second;
			int nxtMsk = msk | foo[nxtNd];
			
			if(dist[nxtNd][nxtMsk] > nxtC){
				dist[nxtNd][nxtMsk] = nxtC;			
				que.push({nxtC, {nxtNd, nxtMsk}});
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

	int t, tt(1); cin >> t; while(t--){

		cin >> n >> m >> k;

		for(int i = 0; i < n; i++) adj[i].clear();

		for(int i = 0; i < m; i++){
			int u, v, c;
			cin >> u >> v >> c; u--, v--;
			adj[u].push_back({c, v});
			adj[v].push_back({c, u});
		}
		
		memset(foo, false, sizeof foo);
		
		vi vec_k(k);
		for(int &nd : vec_k) cin >> nd;
		
		k = 0;
		for(auto nd : set<int>(vec_k.begin(), vec_k.end())) foo[nd-1] = 1 << k++;
		
		cout << "Case " << tt++ << ": ";
		cout << dij() << endl;
		
    }	
}
