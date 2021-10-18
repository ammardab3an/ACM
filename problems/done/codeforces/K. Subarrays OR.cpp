// Problem: K. Subarrays OR
// Contest: Codeforces - 2019 JUST Programming Contest
// URL: https://codeforces.com/gym/102152/problem/K
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


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


int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
	int t; cin >> t; while(t--){
		
		int n;
		cin >> n;
		
		set<int> ans, pst;
		
		for(int i = 0; i < n; i++){
			
			int x; 
			cin >> x;
			
			set<int> tmp;		
			pst.insert(0);
			for(int j : pst) tmp.insert(j | x), ans.insert(j | x);
			
			pst = tmp;
		}
		
//		for(int i : ans) cout << i << ' '; cout << endl;

		cout << ans.size() << endl;
	}
	
	
}