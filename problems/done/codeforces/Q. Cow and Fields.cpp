// Problem: Q. Cow and Fields
// Contest: Codeforces - Training Contest 2
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/309949/problem/Q
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

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m, k;
vi adj[NMAX];
int dist[2][NMAX];
vi spe;

void bfs(int nd, int * dist){
	
	queue<int> que;
	que.push(nd);
	
	for(int i = 1; i <= n; i++) dist[i] = INF;
	dist[nd] = 0;
	
	while(!que.empty()){
		
		int fr = que.front(); que.pop();
		
		for(auto nxt : adj[fr]) if(dist[nxt] == INF){
			dist[nxt] = dist[fr] + 1;
			que.push(nxt);
		}
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	cin >> n >> m >> k;

	spe.resize(k);
	for(int i = 0; i < k; i++) cin >> spe[i];

	for(int u, v, i = 0; i < m; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	bfs(1, dist[0]);
	bfs(n, dist[1]);
	
	vpii res(k);
	
	for(int i = 0; i < k; i++){
		int nd = spe[i];
		res[i] = {dist[0][nd] - dist[1][nd], nd};
	}	
	
	sort(res.begin(), res.end());
	
	int bst = 0;
	int mx = -INF;
	
	for(int i = 0; i < k; i++){
		int nd = res[i].second;
		bst = max(bst, mx +	dist[1][nd]);
		mx = max(mx, dist[0][nd]);	
	}
	
	cout << min(dist[0][n], bst+1) << endl;
}
