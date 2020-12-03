// Problem: B. Repainting Street
// Contest: Codeforces - Codeforces Round #687 (Div. 2, based on Technocup 2021 Elimination Round 2)
// URL: https://codeforces.com/contest/1457/problem/B
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
int c[111];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
		
		int n, k;
		cin >> n >> k;
		
		for(int i = 0; i < n; i++) cin >>  arr[i];
		
		int ans = INF;
		
		for(int i = 1; i <= 100; i++){
		
			int cans = 0;
			
			for(int j = 0; j < n; j++){
				if(arr[j] != i){
					cans++;
					j += k-1;	
				}
			}
			
			ans = min(ans, cans);
		}
		
		cout << ans << endl;
    }	
}
