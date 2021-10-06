// Problem: J. Negative effect
// Contest: Codeforces - Training Contest
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/309757/problem/J
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
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m;
int arr[NMAX];
int sm[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	sm[0] = arr[0];
	for(int i = 1; i < n; i++) sm[i] = sm[i-1] + arr[i];
	
	for(int i = 0; i < n; i++){
		int ans = sm[n-1]-min(arr[i]-m, i != n-1 ? sm[i] : INF);
		if(i) ans = max(ans, sm[i-1]);
		cout << ans << ' ';
	}	
}
