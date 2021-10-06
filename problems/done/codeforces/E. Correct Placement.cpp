// Problem: E. Correct Placement
// Contest: Codeforces - Codeforces Round #693 (Div. 3)
// URL: https://codeforces.com/contest/1472/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

int n;
pii arr[NMAX];
pii pre[NMAX];
pair<pii, int> sorted[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
		
		cin >> n;
		for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
		
		for(int i = 0; i < n; i++) sorted[i] = {arr[i], i};
		sort(sorted, sorted+n);

		pre[0] = {sorted[0].first.second, sorted[0].second};
		for(int i = 1; i < n; i++) pre[i] = min(pre[i-1], {sorted[i].first.second, sorted[i].second});

		vi ans(n, -1);
	
		for(int i = 0; i < n; i++){
			int r = lower_bound(sorted, sorted+n, (pair<pii, int>){{arr[i].first, 0}, -1}) - sorted;
			if(r){
				int idx = pre[r-1].second;
				if(arr[idx].first < arr[i].first && arr[idx].second < arr[i].second) ans[i] = idx+1;
			}
		}

		for(int i = 0; i < n; i++) if(ans[i] == -1){
			int r = lower_bound(sorted, sorted+n, (pair<pii, int>){{arr[i].second, 0}, -1}) - sorted;
			if(r){
				int idx = pre[r-1].second;
				if(arr[idx].second < arr[i].first && arr[idx].first < arr[i].second) ans[i] = idx+1;
			}
		}

		for(int i = 0; i < n; i++) cout << ans[i] << ' '; cout << endl;
    }	
}
