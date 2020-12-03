// Problem: A. Prison Break
// Contest: Codeforces - Codeforces Round #687 (Div. 2, based on Technocup 2021 Elimination Round 2)
// URL: https://codeforces.com/contest/1457/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t


#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

		int n, m, r, c;
		cin >> n >> m >> r >> c;
		
		int ans = max({ r-1+c-1 , n-r+m-c , n-r+c-1 , r-1+m-c } );
		
		cout << ans << endl;
    }	
}
