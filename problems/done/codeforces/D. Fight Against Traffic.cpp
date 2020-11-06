
// Problem : D. Fight Against Traffic
// Contest : Codeforces - Educational Codeforces Round 40 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/954/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

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

//#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 10;

int n, m, t, s;
int cost[1010][1010];

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
	cin >> n >> m >> t >> s;
	
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++) if(i != j) cost[i][j] = INF;
	
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		cost[u][v] = cost[v][u] = 1;
	}
	
	for(int k = 1; k <= n; k++)
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
		cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
	
	int curCost = cost[t][s];
	
	int ans = 0;
	for(int i =  1 ; i <= n; i++)
	for(int j = i+1; j <= n; j++) if(cost[i][j] != 1){
			
		int xx = cost[t][i] + 1 + cost[j][s];
		int yy = cost[t][j] + 1 + cost[i][s];
		
		int newCost = min(xx, yy);

		if(newCost >= curCost) ans++;
	}
	
	cout << ans << endl;
}
