// Problem: B. Replace and Keep Sorted
// Contest: Codeforces - Codeforces Round #701 (Div. 2)
// URL: https://codeforces.com/contest/1485/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
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

int n, m, k;
int arr[NMAX];
lli pre[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	cin >> n >> m >> k;
	for(int i =  0; i < n; i++) cin >> arr[i];
	
	for(int i = 1; i < n-1; i++){
		pre[i] = pre[i-1];
		pre[i] += (arr[i] - arr[i-1] - 1) + (arr[i+1] - arr[i] - 1);
	}
	
	while(m--){
		
		int l, r;
		cin >> l >> r; l--, r--;
		
		if(l == r){
			cout << k-1 << endl;
			continue;
		}
		
		lli ans = 0;
		
		ans += (arr[l] - 1) + (arr[l+1] - arr[l] -1);
		ans += (arr[r] - arr[r-1] -1) + (k - arr[r]);
		
		ans += pre[r-1];
		ans -= pre[l];
		
		cout << ans << endl;
	}
}
