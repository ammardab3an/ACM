
// Problem : C - 8 Queens Chess Problem
// Contest : Virtual Judge - Week #2.0 [Backtracking - complete search] Medium ~ hard
// URL : https://vjudge.net/contest/396026#problem/C
// Memory Limit : 1024 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

typedef long long int       lli;
typedef unsigned long long 	ull;
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

int sol_cnt = 0;

ull fill(int i, int j){

	ull vis = 0;

	for(int nj = 0; nj < 8; nj++) vis |= 1ULL << (i*8 + nj);
	for(int ni = 0; ni < 8; ni++) vis |= 1ULL << (ni*8 + j);
	
	for(int ni = i, nj = j; ni < 8 && nj < 8; ni++, nj++) vis |= 1ULL << (ni*8 + nj);
	for(int ni = i, nj = j; ni >=0 && nj >=0; ni--, nj--) vis |= 1ULL << (ni*8 + nj);
	for(int ni = i, nj = j; ni < 8 && nj >=0; ni++, nj--) vis |= 1ULL << (ni*8 + nj);
	for(int ni = i, nj = j; ni >=0 && nj < 8; ni--, nj++) vis |= 1ULL << (ni*8 + nj);		

	return vis;
}

void go(int lj, ull msk, ull vis){
	
	if(__builtin_popcountll(msk) == 8){
		printf("%2d     ", ++sol_cnt);
		for(int j = 0; j < 8; j++)
		for(int i = 0; i < 8; i++) if(msk & (1ULL << (i*8 + j)))
			printf(" %d", i+1);
		puts("");
		return;
	}
	
	for(int j = lj; j < 8; j++)
	for(int i = 0 ; i < 8; i++) 
		if(!(vis & (1ULL << (i*8 + j)))) 
			go(j, msk | (1ULL << (i*8 + j)), vis | fill(i, j));
}

int main(){
   
	fastIO;
	
    bool b = false;
	int t; scanf("%d", &t); while(t--){
		
		if(b++) puts("");
	    puts("SOLN       COLUMN");
	    puts(" #      1 2 3 4 5 6 7 8\n");
	    
		int i, j; sol_cnt = 0;
		scanf("%d%d", &i, &j); i--; j--;
		go(0, 1ULL << (i*8 + j), fill(i, j));
	}
	
}
