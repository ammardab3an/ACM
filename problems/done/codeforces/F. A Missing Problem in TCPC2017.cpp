
// Problem : F. A Missing Problem in TCPC2017
// Contest : Codeforces - ACM International Collegiate Programming Contest, Tishreen Collegiate Programming Contest (2017)
// URL : https://codeforces.com/gym/101915/problem/F
// Memory Limit : 64 MB
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

//#define int int64_t

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;


int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
	
	int t; cin >> t; while(t--){
		
		int n; cin >> n;
		vi vec(n-1);
		for(int i = 0; i < n-1; i++) cin >> vec[i];
		
		int ans = n;
		for(int i = 0; i < n-1; i++) if(vec[i] != i+1){
			ans = i+1;
			break;
		}
		
		cout << ans << endl;
	}
	
}
