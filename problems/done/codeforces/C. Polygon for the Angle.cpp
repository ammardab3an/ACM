// Problem: C. Polygon for the Angle
// Contest: Codeforces - Educational Codeforces Round 57 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1096/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
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
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
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
		
		int ang;
		cin >> ang;
		
		// ang = 180k/n  {1 <= k <= n-2}
		// ang * n = 180 * k
		// g = gcd(ang, 180)
		// ang/g * n = 180/g * k
		// => n = x * 180/g
		// => k = x * ang/g
		// because of we want n te be miminum => x = 1
		// but if k become larger than n-2 => x = 2
		
		int gcd = __gcd(180, ang);
		
		int x = 1;
		int k = x * ang/gcd;
		int n = x * 180/gcd;
		
		if(k > n-2){
			x++;
			k = x * ang/gcd;
			n = x * 180/gcd;
		}
		
		cout << n << endl;
    }	
}
