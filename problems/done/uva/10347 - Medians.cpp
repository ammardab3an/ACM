// Problem: F - Medians
// Contest: Virtual Judge - Basic Geometry
// URL: https://vjudge.net/contest/405410#problem/F
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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

	double a, b, c;
	while(cin >> a >> b >> c){

/*
		a *= 2.0/3.0;
		b *= 2.0/3.0;
		c *= 2.0/3.0;
*/	
		
		double s = (a + b + c) / 2.0;
		
		double area = 4.0/3.0 * sqrt( s * (s-a) * (s-b) * (s-c) );
		
		if(isnan(area) || area == 0) area = -1.0;
		
		cout << fixed << setprecision(3) << area << endl;
	}
}
