
// Problem : F - 23 out of 5
// Contest : Virtual Judge - Week #2.0 [Backtracking - complete search] Medium ~ hard
// URL : https://vjudge.net/contest/396026#problem/F
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

vector<int> vec(5);

bool go(int pos, int cum){
	
	if(pos == 5) return cum == 23;
	
	if(go(pos+1, cum + vec[pos])) return true;
	if(go(pos+1, cum - vec[pos])) return true;
	if(go(pos+1, cum * vec[pos])) return true;
	
	return false;
}

int main(){

    fastIO;
	
	while(cin >> vec[0]){
		
		if(!vec[0]) break;
		
		for(int i = 1; i < 5; i++) cin >> vec[i];
		
		// notice that in order to use next_permutation you have to make sure that 
		// your array is sorted to be able to use do-while-nxtper method;
		
		sort(vec.begin(), vec.end());

		bool b = false;
		
		do{
			if(b = go(1, vec[0])) break;
		}while(next_permutation(vec.begin(), vec.end()));
		
		cout << (b ? "Possible" : "Impossible") << endl;
	}
}
