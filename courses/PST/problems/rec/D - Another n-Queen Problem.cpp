
// Problem : D - Another n-Queen Problem
// Contest : Virtual Judge - Week #2.0 [Backtracking - complete search] Medium ~ hard
// URL : https://vjudge.net/contest/396026#problem/D
// Memory Limit : 1024 MB
// Time Limit : 5000 ms
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

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int MAX = 2e5 + 10;

int n; 
int grid[20];
char _grid[20][20];

int go(int i){
	
	if(i == n) return 1;
	
	int sm = 0;
	for(int j = 0; j < n; j++) if(!(grid[i] & (1 << j))){
			
		int ni, nj, tmp[20];
		
		for(ni = i; ni < n; ni++) tmp[ni] = grid[ni];

		for(ni = i; ni < n; ni++) grid[ni] |= 1 << j;
		
		for(ni = i, nj = j; ni < n && nj < n; ni++, nj++) grid[ni] |= 1 << nj;
		for(ni = i, nj = j; ni < n && nj >=0; ni++, nj--) grid[ni] |= 1 << nj;
		
		sm += go(i+1);

		for(ni = i; ni < n; ni++) grid[ni] = tmp[ni];
	}
	
	return sm;
}

int main(){
	
	fastIO;
	
	int t = 1;
	while(cin >> n){
		
		if(!n) break;
		
		memset(grid, 0, sizeof grid);
		
		for(int i = 0; i < n; i++) cin >> _grid[i];
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) if(_grid[i][j] == '*') grid[i] |= 1 << j;
		
		cout << "Case " << t++ << ": " << go(0) << endl;
	}
	
}
