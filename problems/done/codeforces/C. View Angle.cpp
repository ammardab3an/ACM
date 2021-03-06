// Problem: C. View Angle
// Contest: Codeforces - Codeforces Round #159 (Div. 2)
// URL: https://codeforces.com/problemset/problem/257/C
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
const double EPS = 1e-8;
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
	
	int n;
	cin >> n;
	
	vector<pair<double, pii>> vec(n);
	
	for(auto & p : vec){
		cin >> p.second.first >> p.second.second;
		p.first = atan2(p.second.second, p.second.first);
		if(p.first < -EPS) p.first += 2*PI;
	}	
	
	sort(vec.begin(), vec.end());
	
	double ans = vec[n-1].first - vec[0].first;
	
	for(int i = 0; i+1 < n; i++){
		double ang = 2 * PI - (vec[(i+1)%n].first - vec[i].first);
		ans = min(ans, ang);
	}
	
	cout << fixed << setprecision(10) << ans/PI *180 << endl;
    
}
