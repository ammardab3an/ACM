// Problem: C. Bouncing Ball
// Contest: Codeforces - Codeforces Round #687 (Div. 2, based on Technocup 2021 Elimination Round 2)
// URL: https://codeforces.com/contest/1457/problem/C
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

char arr[NMAX];
int sm[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

		int n, p, k;
		cin >> n >> p >> k;
		
		cin >> arr;
		
		int x, y;
		cin >> x >> y;
		
		for(int i = n-1; i >= 0; i--){
			sm[i] = '1' - arr[i];
			if(i+k < n) sm[i] += sm[i+k];
		}
		
				
		int ans = INF;
		
		for(int i = 0; i+p-1 < n; i++){
			
			int tmp = y*i + x*sm[i+p-1];
			
			ans = min(ans, tmp);
		}
		
		cout << ans << endl;
    }	
}
