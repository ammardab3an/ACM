
// Problem : A. Box is Pull
// Contest : Codeforces - Codeforces Raif Round 1 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1428/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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


int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	
	int t; cin >> t; while(t--){
		
		int x0, y0, x1, y1;
		cin >> x0 >> y0 >> x1 >> y1;
		
		int ans = abs(x1-x0) + abs(y1-y0);
		
		if(x0 != x1 && y0 != y1) ans += 2;

		cout << ans << endl;
	}
	
}
