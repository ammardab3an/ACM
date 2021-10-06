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
int f[111], fo[111];
int dist[111][111];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; for(int tt = 1; tt <= t; tt++){

		cin >> n >> m >> k;
			
		memset(dist, INF, sizeof dist);
				
		for(int i = 0; i < m; i++){
			int u, v, c; 
			cin >> u >> v >> c; u--, v--;
			dist[u][v] = dist[v][u] = c;
		}
		
		for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			dist[k][k] = 0;
			if(dist[i][k] < INF && dist[k][j] < INF){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}	
		}
		
		
		vi fo(k);
		
		for(int i = 0; i < k; i++){
			cin >> fo[i]; fo[i]--;
		}
		
		sort(fo.begin(), fo.end());
		
		int ans = INF;
		
		do{
				
			int totDis = dist[0][fo[0]] + dist[fo[k-1]][n-1];
			
			for(int i = 0; i+1 < k; i++) totDis += dist[fo[i]][fo[i+1]];
			
			ans = min(ans, totDis);
			
		}while(next_permutation(fo.begin(), fo.end()));
		
		cout << "Case " << tt << ": ";
		cout << ans << endl;
    }	
}
