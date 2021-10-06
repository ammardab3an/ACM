
// Problem : D. Largest Group
// Contest : Codeforces - ACM International Collegiate Programming Contest, Tishreen Collegiate Programming Contest (2017)
// URL : https://codeforces.com/gym/101915/problem/D
// Memory Limit : 64 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

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

//#define int int64_t

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m;
int arr[22];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
	int t; cin >> t; while(t--){
		
		int n, m;
		cin >> n >> m;
		
		memset(arr, 0, sizeof arr);
		
		for(int i = 0; i < m; i++){
			int u, v; cin >> u >> v;
			arr[u] |= 1 << (v-1);
		}
				
		int ans = n;
		
		int mx = 1 << n;
		for(int msk = 1; msk < mx; msk++){
			
			int cnt = 0;
			for(int i = 1; i <= n; i++){
				if((arr[i] & msk) == msk) cnt++;
			}
			
			ans = max(ans, __builtin_popcount(msk) + cnt);
		}
		
		cout << ans << endl;
		
	}
	
	
}
