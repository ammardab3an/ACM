// Problem: C. New Year and Curling
// Contest: Codeforces - Good Bye 2017
// URL: https://codeforces.com/problemset/problem/908/C
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

	int n, r;
	cin >> n >> r;
	
	vi vec(n);
	for(int &i : vec) cin >> i;
	
	
	vector<double> ans;
	ans.push_back(r);
	
	for(int i = 1; i < n; i++){
			
		double bsty = r;
		
		for(int j = 0; j < i; j++){
			
			if(abs(vec[i] - vec[j]) <= 2*r){
				
				double th = acos((double)abs(vec[i] - vec[j]) / double(2*r));
				double ny = ans[j] + (sin(th) * double(2*r));
				
				bsty = max(bsty, ny);
			}
		}
		
		ans.push_back(bsty);
	}
	
	for(double y : ans) cout << fixed << setprecision(10) << y << ' ';
}
