
// Problem : C - 8 Queens Chess Problem _2
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

int que[8], mj;
int sol_cnt = 0;

bool check(int i, int j){
	for(int k = 0; k < j; k++){
		if(que[k] == i || (abs(k - j) == abs(que[k] - i)))
			return false;
	}
	return true;
}

void go(int j){
	
	if(j == 8){
		printf("%2d     ", ++sol_cnt);
		for(int k = 0; k < 8; k++)
			printf(" %d", que[k]+1);
		puts("");
	}
	
	if(j == mj){
		if(check(que[mj], mj))
			go(j+1);
		return ;
	}
	
	for(int i = 0; i < 8; i++){
		if(check(i, j)){
			que[j] = i;
			go(j+1);
		}
	}
}

int main(){
   
	fastIO;
	
	int t; scanf("%d", &t); while(t--){
	
	    puts("SOLN       COLUMN");
	    puts(" #      1 2 3 4 5 6 7 8\n");
	    
		int i, j; sol_cnt = 0;
		scanf("%d%d", &i, &j); i--; j--;
		
		mj = j; 
		que[mj] = i;
		go(0);
		
		if(t) puts("");
	}
	
}
