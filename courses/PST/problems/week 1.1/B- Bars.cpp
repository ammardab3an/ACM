
// Problem : B - Bars
// Contest : Virtual Judge - Week # 1.1 [Complete search - Iterative&Recursive]- Easy~Medium
// URL : https://vjudge.net/contest/395176#problem/B
// Memory Limit : 1024 MB
// Time Limit : 1000 ms
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

int n, p;
int pars[1010];

bool canWe(){
	
	for(int i = 0; i < (1 << p); i++){
		int len = 0;
		for(int j = 0; j < p; j++)
			if(i & (1 << j)) len += pars[j];
		if(len == n) return true;
	}
	
	return false;
}

int main(){

    fastIO;
    
	int T; cin >> T; while(T--){

		cin >> n >> p;

		for(int i = 0; i < p; i++) cin >> pars[i];
		
		cout << (canWe() ? "YES" : "NO") << endl;
	}
	
}
