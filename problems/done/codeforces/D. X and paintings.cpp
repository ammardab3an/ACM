// Problem: D. X and paintings
// Contest: Codeforces - Training Contest 2
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/309949/problem/D
// Memory Limit: 64 MB
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
const int NMAX = 1e3 + 10;
const int MMAX = 2e5 + 10;

int n, m, k;
char grid[NMAX][NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

		cin >> n >> m >> k;
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) grid[i][j] = '.';
		
		while(k--){
			int x0, y0, x1, y1; char c;
			cin >> x0 >> y0 >> x1 >> y1 >> c;
			for(int i = x0-1; i <= x1-1; i++)
			for(int j = y0-1; j <= y1-1; j++) grid[i][j] = c;
		}
		
		for(int i = 0; i < n; i++) cout << grid[i] << endl;
		
    }	
}
