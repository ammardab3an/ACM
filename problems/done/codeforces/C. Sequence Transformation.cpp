// Problem: C. Sequence Transformation
// Contest: Codeforces - Codeforces Round #686 (Div. 3)
// URL: https://codeforces.com/contest/1454/problem/C
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
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int arr[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

		int n;
		cin >> n; 
		
		int lst = -1;
		
		for(int i = 0; i < n; i++){
		
			int x; cin >> x;
		
			if(x != lst){
				arr[i] = lst = x;
			}
			else{
				n--;
				i--;
			}
		}
		
		map<int, array<int, 3> > cnt;
		
		
		cnt[arr[0]] = {1, 1, 0};
		
		if(n != 1)
			cnt[arr[n-1]] = {1, 0, 1};
		else
			cnt[arr[n-1]] = {1, 1, 1};
			
			
		for(int i = 1; i < n-1; i++){
			cnt[arr[i]];
			cnt[arr[i]][0]++;
		}
		
		int ans = n;
		for(auto p : cnt){
			
			ans = min(ans, p.second[0] - p.second[1] - p.second[2] +1);
		}
//		for(int i = 0; i < n; i++) cout << arr[i] << ' '; cout << endl;
		
		cout << ans << endl;
    }	
}
