// Problem: C. Number Game
// Contest: Codeforces - Codeforces Round #651 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1370/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t

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

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

		int n; 
		cin >> n;
		
		int m = n;
		bool prime = n%2 == 0;
		
		if(prime){
			m /= 2;
			for(int i = 3; i*i <= n; i+=2) if(m%i==0){
				prime = false;
				break;
			}
		}
		
		cout << ((n == 1) || 
				 (n > 2 && n%2==0 && (n&(n-1))==0) || 
				 (n > 2 && n%2==0 && n%4!=0 && prime) ? "FastestFinger" : "Ashishgup" ) << endl;
		
    }	
}
