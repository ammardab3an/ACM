// Problem: G. Moving to the Capital
// Contest: Codeforces - Codeforces Round #693 (Div. 3)
// URL: https://codeforces.com/contest/1472/problem/G
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

int n, m;
vi adj[NMAX];
int mem[NMAX][2];
int dist[NMAX];
bool vist[NMAX];

int go(int nd, bool b){
	
	int & ret = mem[nd][b];
	if(~ret) return ret;
	
	int ans = dist[nd];
	
	for(auto nxt : adj[nd]) {
		
		if(dist[nxt] > dist[nd]){
			ans = min(ans, go(nxt, b));
		}
		if(!b){
			ans = min(ans, go(nxt, 1));
		}
	}		
	
	return ret = ans;
}

int bfs(){
	
	memset(dist, -1, sizeof dist);
	memset(vist, 0, sizeof vist);
	
	dist[1] = 0;
	vist[1] = true;
	
	queue<int> que;
	que.push(1);
	
	while(!que.empty()){
		
		int nd = que.front(); que.pop();
		for(auto nxt : adj[nd]) if(!vist[nxt]){
			vist[nxt] = true;
			dist[nxt] = dist[nd] + 1;
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

    int t; cin >> t; while(t--){
		
		cin >> n >> m;
		
		for(int i = 1; i <= n; i++) adj[i].clear();
		
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		
		bfs();
		//for(int i = 1; i <= n; i++) cout << dist[i] << ' ' ; cout << endl;

		memset(mem, -1, sizeof mem);
		for(int i = 1; i <= n; i++) cout << go(i, 0) << ' ' ; cout << endl;
    }	
}
