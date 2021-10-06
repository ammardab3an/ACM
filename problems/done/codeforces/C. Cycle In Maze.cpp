
// Problem : C. Cycle In Maze
// Contest : Codeforces - VK Cup 2017 - Qualification 1
// URL : https://codeforces.com/problemset/problem/769/C
// Memory Limit : 256 MB
// Time Limit : 15000 ms
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

int n, m, k;
char grid[1010][1010];

pii mvArr[] = {{+1, 0}, {0, -1}, {0, +1}, {-1, 0}};
char pathArr[] = "DLRU";

int dist[1010][1010];
int vist[1010][1010];

bool can(int i, int j){
	return 0 <= i && i < n &&
		   0 <= j && j < m;
}

string path;
bool go(int i, int j, int k){
	
	if(!k){
		cout << path << endl;
		return true;
	}
	
	for(int l = 0; l < 4; l++){
		
		int ni = i + mvArr[l].first;
		int nj = j + mvArr[l].second;
		
		if(!can(ni, nj) || grid[ni][nj] == '*' || (dist[ni][nj] > k-1)) continue;
		
		path.push_back(pathArr[l]);
		
		if(go(ni, nj, k-1)) return true;
		
		break;
		
	}
		
	return false;
}

void bfs(int i, int j){
	
	queue<pii> que;
	que.push({i, j});
	
	vist[i][j] = 1;
	
	while(!que.empty()){
		
		pii fr = que.front(); que.pop();
		
		int ci = fr.first;
		int cj = fr.second;
		
		for(int k = 0; k < 4; k++){
			
			int ni = ci + mvArr[k].first;
			int nj = cj + mvArr[k].second;
			
			if(!can(ni, nj) || vist[ni][nj] || grid[ni][nj] == '*') continue;
			
			dist[ni][nj] = dist[ci][cj] + 1;
			vist[ni][nj] = 1;
			
			que.push({ni, nj});
		}
	}	
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) cin >> grid[i];
	
	if(k % 2){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++) if(grid[i][j] == 'X'){
		
		bfs(i, j);
		
		if(!go(i, j, k)) 
			cout << "IMPOSSIBLE" << endl;
		
		break;
	}
}
