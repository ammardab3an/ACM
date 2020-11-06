
// Problem : E - The Hamming Distance Problem
// Contest : Virtual Judge - Week #2.0 [Backtracking - complete search] Medium ~ hard
// URL : https://vjudge.net/contest/396026#problem/E
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

int n, h;

void go(int pos, int cnt, string str){
	
	if(pos == n){
		if(cnt == h) cout << str << endl;
		return;
	}
	
	go(pos+1, cnt, str + "0");
	if(cnt < h) go(pos+1, cnt+1, str + "1");
}

int main(){

    fastIO;
    
    int t; cin >> t; while(t--){
    	
    	cin >> n >> h;
    	
    	go(0, 0, "");
    	
    	if(t) cout << endl;
    }
	
	
}
