// Problem: D. Add to Neighbour and Remove
// Contest: Codeforces - Codeforces Round #690 (Div. 3)
// URL: http://codeforces.com/contest/1462/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

int n;
int arr[3333];
lli sm[3333];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
		
		cin >> n;
		for(int i = 0; i < n; i++) cin >> arr[i];
		
		sm[0] = arr[0];
		for(int i = 1; i < n; i++) sm[i] = sm[i-1] + arr[i];
		
		int ans = 1;
		
		for(int i = 0; i < n; i++){
			
			lli fsm = sm[i];
			
			int cnt = 1;
			
			int j = i;
			
			while(j != n-1){
				
				int nxt = lower_bound(sm, sm+n, sm[j] + fsm) - sm;
				
				if(nxt >= n || sm[nxt] != sm[j] + fsm){
					cnt = 0;
					break;
				}
				
				j = nxt;
				cnt++;
			}
			
			ans = max(ans, cnt);
		}
		
		cout << n - ans << endl;
    }	
}
