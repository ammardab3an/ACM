// Problem: D. Catching Cheaters
// Contest: Codeforces - Codeforces Round #683 (Div. 2, by Meet IT)
// URL: https://codeforces.com/contest/1447/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int NMAX = 5000 + 10;

int n, m;
char str0[NMAX];
char str1[NMAX];

int dp[NMAX][NMAX];


int32_t main(){
    
    fastIO;

	cin >> n >> m;
	cin >> str0 >> str1;

	int ans = 0;

	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++){
		
		if(str0[i] == str1[j]){
			dp[i][j] = 2;
			if(i && j) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 2);
		}
		
		if(i) dp[i][j] = max(dp[i][j], dp[i-1][j] -1);
		if(j) dp[i][j] = max(dp[i][j], dp[i][j-1] -1);
		
		ans = max(ans, dp[i][j]);
	}
	
	cout << ans << endl;
}
