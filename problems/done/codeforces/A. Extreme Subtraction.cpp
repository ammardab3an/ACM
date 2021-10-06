// Problem: A. Extreme Subtraction
// Contest: Codeforces - Training Contest 3
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/310125/problem/A
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
		
		vi arr(n), dif(n);
		for(int i = 0; i < n; i++) cin >> arr[i];
		

		dif[0] = arr[0];
		for(int i = 1; i < n; i++) dif[i] = min(arr[i] - arr[i-1], 0);
		
		bool b = true;
		
		lli sm = 0;
		for(int i = 0; i < n && b; i++){
			sm += dif[i];
			if(sm < 0) b = 0;
		}
		
		cout << (b ? "YES" : "NO") << endl;
    }	
}
