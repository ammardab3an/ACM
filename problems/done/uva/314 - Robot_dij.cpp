// Problem: A - Robot
// Contest: Virtual Judge - Week #8.1 [Dijkstra- BFS] Harder
// URL: https://vjudge.net/contest/406926#problem/A
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m;
bool grid[55][55];

map<string, int> di_mp;
vpii mvArr;
		
bool can(int i, int j){
	return 0 <= i && i < n &&
		   0 <= j && j < m;
}

bool clear(int i, int j){
	
	for(int ii = 0; ii < 2; ii++)
	for(int jj = 0; jj < 2; jj++){
		if(!can(i - ii, j - jj) || grid[i - ii][j - jj]) return false;
	}
	
	return true;
}

int dij(int i0, int j0, int i1, int j1, int d0){
	
	int dist[55][55][4];
	
	memset(dist, 0x3f, sizeof dist);
	
	priority_queue< pair<int, array<int, 3> > , vector<pair<int, array<int, 3> > >, greater<pair<int, array<int, 3> > > > que;
	
	dist[i0][j0][d0] = 0;
	que.push({0, {i0, j0, d0}});
	
	while(!que.empty()){
		
		auto tp = que.top(); que.pop();
		
		int cc = tp.first;
		int ci = tp.second[0];
		int cj = tp.second[1];
		int cd = tp.second[2];
		
		if(dist[ci][cj][cd] < cc) continue;
		
		if(ci == i1 && cj == j1) return cc;
		
		for(int k = 1; k <= 3; k++){
			
			int ni = ci + k*mvArr[cd].first;
			int nj = cj + k*mvArr[cd].second;
			
			if(!clear(ni, nj)) break;
			
			if(cc+1 < dist[ni][nj][cd]){
				dist[ni][nj][cd] = cc+1;
				que.push({cc+1, {ni, nj, cd}});
			}
		}
		
		for(int nd : {(cd+1)%4, (cd+3)%4}){
			
			if(cc+1 < dist[ci][cj][nd]){
				dist[ci][cj][nd] = cc+1;
				que.push({cc+1, {ci, cj, nd}});
			}
		}
	}
	
	return -1;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
	
	
	di_mp["north"] = 0;
	di_mp["west"] = 1;
	di_mp["south"] = 2;
	di_mp["east"] = 3;
	
	mvArr = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	
	while(true){
		
		cin >> n >> m;
		
		if(!n && !m) break;
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) cin >> grid[i][j];
		
		int i0, j0, i1, j1;
		cin >> i0 >> j0 >> i1 >> j1;
		
		string di_str;
		cin >> di_str;
		
		cout << dij(i0, j0, i1, j1, di_mp[di_str]) << endl;	
		
	}
}
