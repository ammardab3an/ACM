
// Problem : K - Back to the 8-Queens
// Contest : Virtual Judge - Week #2.0 [Backtracking - complete search] Medium ~ hard
// URL : https://vjudge.net/contest/396026#problem/K
// Memory Limit : 1024 MB
// Time Limit : 3000 ms
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

const int MAX = 2e5 + 10;

ull oMsk;

int go(int i, ull msk, ull vis){
	
	if(i == 8){
		return __builtin_popcountll(msk ^ oMsk)/2;
	}	
	
	int mn = 10;
	for(int j = 0; j < 8; j++) if(!(vis & (1ULL << (i*8 + j)))){
		
		ull nVis = vis;
		int ni, nj;
		for(ni = i; ni < 8; ni++) nVis |= 1ULL << (ni*8 + j);
		for(ni = i, nj = j; ni < 8 && nj < 8; ni++, nj++) nVis |= 1ULL << (ni*8 + nj);
		for(ni = i, nj = j; ni < 8 && nj >=0; ni++, nj--) nVis |= 1ULL << (ni*8 + nj);
		mn = min(mn, go(i+1, msk | 1ULL << (i*8 + j), nVis));
	}
	
	return mn;
}

int main(){

    fastIO;
    
	int i, t = 1; 
	while(cin >> i){
		
		oMsk = 1ULL << (i-1)*8;
		
		for(int j = 1; j < 8; j++){
			cin >> i; oMsk |= 1ULL << ((i-1)*8 + j);
		}
		
		cout << "Case " << t++ << ": " << go(0, 0, 0) << endl;
	}
	
}
