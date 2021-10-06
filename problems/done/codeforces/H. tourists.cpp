
// Problem : H. tourists
// Contest : Codeforces - 2015 Damascus Collegiate Programming Contest (DCPC 2015)
// URL : https://codeforces.com/gym/100883/problem/H
// Memory Limit : 24 MB
// Time Limit : 2000 ms
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

const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 10;


int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
	lli n; while(cin >> n){
		
		if(!n) break;
		
		lli c0, c1, n0, n1;
		cin >> c0 >> n0 >> c1 >> n1;
		
		lli ans = INT_MAX;
		int mni, mnj;
		
		for(lli i = 0; i * n0 <= n; i++){

			int nn = n - i * n0;	
			if(nn % n1) continue;
			
			lli nans = i * c0 + (nn/n1) * c1;
			
			if(ans > nans){
				ans = nans;
				mni = i;
				mnj = nn/n1;
			}
		}
		
		if(ans == INT_MAX) cout << "failed" << endl;
		else cout << mni << ' ' << mnj << endl;
	}
	
	
}
