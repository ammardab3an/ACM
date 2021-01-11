// Problem: B. Suffix Operations
// Contest: Codeforces - Codeforces Round #688 (Div. 2)
// URL: https://codeforces.com/contest/1453/problem/B
// Memory Limit: 512 MB
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
int arr[NMAX];
int dp_l[NMAX];
int dp_r[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
	int t; cin >> t; while(t--){
		
		cin >> n;
		for(int i = 0; i < n; i++) cin >> arr[i];
		
		if(n <= 2){
			cout << 0 << endl;
			continue;
		}
		
		dp_l[0] = dp_r[n-1] = 0;
		
		for(int i = 1; i < n; i++){
			dp_l[i] = dp_l[i-1] + abs(arr[i-1] - arr[i]);
		}
		
		for(int i = n-2; i >= 0; i--){
			dp_r[i] = dp_r[i+1] + abs(arr[i+1] - arr[i]);
		}
		
		int ans = min(dp_l[n-2], dp_r[1]);

		for(int i = 1; i < n-1; i++){
			ans = min(ans, dp_l[i-1] + abs(arr[i-1] - arr[i+1]) + dp_r[i+1]);
		}
		
		cout << ans << endl;
	}
	
	
}
