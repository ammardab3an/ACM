// just trying a n(m^2) solution

// Problem: N. Zbazi in Zeydabad
// Contest: Codeforces - Training Contest 2
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/309949/problem/N
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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

int n, m;
char grid[3030][3030];
int sm[3030][3030];
int di[3030][3030];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		cin >> grid[i];
		for(int j = 0; j < m; j++) 
			grid[i][j] = grid[i][j] == 'z';	
	}
	
	for(int i = 0; i < n; i++){
		sm[i][0] = grid[i][0];
		for(int j = 1; j < m; j++)
			sm[i][j] = sm[i][j-1] + grid[i][j];
	}
	
	
	for(int i = n-1; i >= 0; i--){
		di[i][0] = grid[i][0];	
		for(int j = 1; j < m; j++){
			if(grid[i][j])
				di[i][j] = di[i+1][j-1] + grid[i][j];
			else
				di[i][j] = 0;
		} 
	}
	
	int cnt = 0;
	
	for(int i = 0; i < n; i++)	
	for(int j = 0; j < m; j++){
		
		int cnt2 = di[i][j];

		for(int k = 1; k <= j+1; k++){
			
			int l = j-k+1;
			int r = j;
			
			int cnt0 = sm[i][r];
			if(l) cnt0 -= sm[i][l-1];
			
			int cnt1 = sm[i+k-1][r];
			if(l) cnt1 -= sm[i+k-1][l-1];			
			
			bool b0 = cnt0 == k;
			bool b1 = cnt1 == k;
			bool b2 = cnt2 >= k;
			
			if(b0 && b1 && b2) cnt++;
			else if(!b0 || !b2) break;
		}
		
	}
	
	cout << cnt << endl;
}
