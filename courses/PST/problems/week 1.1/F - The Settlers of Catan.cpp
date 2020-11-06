
// Problem : F - The Settlers of Catan
// Contest : Virtual Judge - Week # 1.1 [Complete search - Iterative&Recursive]- Easy~Medium
// URL : https://vjudge.net/contest/395176#problem/F
// Memory Limit : 1024 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

typedef long long int       lli;
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

const int MAX = 2e5 + 10;

int n, m;
array<vi, 30> edges;
bool vis[30][30];

int go(int nd){
	
	int mx = 0;
	
	for(int nxt : edges[nd]) if(!vis[nd][nxt]){
		vis[nd][nxt] = vis[nxt][nd] = true;
		mx = max(mx, go(nxt) +1);
		vis[nd][nxt] = vis[nxt][nd] = false;
	}	
	
	return mx;
}

int main(){

    fastIO;
	while(cin >> n >> m){
		
		if(!n && !m) break;
		
		edges.fill({});
		
		while(m--){
			int i, j;
			cin >> i >> j;
			
			edges[i].push_back(j);
			edges[j].push_back(i);
			
		}
		
		
		int mx = 0;
		for(int i = 0; i < n; i++)
			mx = max(mx, go(i));
			
		cout << mx << endl;
	}	
	
}
