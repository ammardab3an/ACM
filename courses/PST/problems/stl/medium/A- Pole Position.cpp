
// Problem : A - Pole Position
// Contest : Virtual Judge - Week #1[STLs - Medium]
// URL : https://vjudge.net/contest/394527#problem/A
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

int pre[1010101];

int main(){

    fastIO;
	
	int n, c, p;
	
	while(cin >> n){
		
		if(!n) break;

		bool valid = true;
		
		memset(pre, -1, sizeof pre);
		
		for(int i = 0; i < n; i++){
		
			cin >> c >> p;
			
			if(i+p < 0 || i+p >= n || pre[i+p] != -1)
				valid = false;
			else
				pre[i+p] = c;	
		}	
		
		if(valid){
			for(int i = 0; i < n; i++)
				cout << pre[i] << (i == n-1 ? "" : " ");
		}
		else{
			cout << -1;
		}
		
		cout << endl;
	}
	
}

















