
// Problem : G - The Sultan's Successors
// Contest : Virtual Judge - Week #2.0 [Backtracking - complete search] Medium ~ hard
// URL : https://vjudge.net/contest/396026#problem/G
// Memory Limit : 1024 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

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

const int MAX = 2e5 + 10;

int grid[8][8];

int go(int i, int sm, ull msk){
	
	if(i == 8){
		return sm;
	}
	
	int mx = 0;
	for(int j = 0; j < 8; j++) if(!(msk & (1ULL << (i*8 + j)))){
		
		ull nmsk = msk;
		
		int ni, nj;
		for(ni = i; ni < 8; ni++) nmsk |= 1ULL << (ni*8 + j);
		for(ni = i, nj = j; ni < 8 && nj < 8; ni++, nj++) nmsk |= 1ULL << (ni*8 + nj);
		for(ni = i, nj = j; ni < 8 && nj >=0; ni++, nj--) nmsk |= 1ULL << (ni*8 + nj);
		
		mx = max(mx, go(i+1, sm + grid[i][j], nmsk));
	}
	
	return mx;
}
int main(){

    fastIO;
	
	int t; scanf("%d", &t); while(t--){
		
		for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++) scanf("%d", &grid[i][j]);
		
		printf("%5d\n", go(0,0,0));
	}	
}
