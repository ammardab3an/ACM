// Problem: B. Han Solo and Lazer Gun
// Contest: Codeforces - Codeforces Round #291 (Div. 2)
// URL: https://codeforces.com/problemset/problem/514/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int sgn(int i){
	return (0 <= i);// - (i < 0);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	int n, x0, y0;
	cin >> n >> x0 >> y0;
	
	vpii points(n);
	for(int i = 0; i < n; i++) cin >> points[i].first >> points[i].second;
	
	set<pii> st;
	
	for(int i = 0; i < n; i++) {
		
		int x = points[i].first-x0;
		int y = points[i].second-y0;
		
		if(sgn(x) != sgn(y))
			y = -abs(y), x = abs(x);
		else
			y = abs(y), x = abs(x);
			
		int gcd = __gcd(x, y);
		x /= gcd;
		y /= gcd;
		
		st.insert({y, x});
	}
	
	cout << st.size() << endl;
}
