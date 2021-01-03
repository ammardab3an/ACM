// Problem: I. March Rain
// Contest: Codeforces - Training Contest 2
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/309949/problem/I
// Memory Limit: 64 MB
// Time Limit: 2000 ms
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

int n, k;
int arr[NMAX];

bool can(int m){
	
	int cnt = 0;
	
	int i = 0;
	while(i < n){

		cnt++;
		
		int l = arr[i];
		i++;
		while(i < n && (arr[i] - l +1 <= m)) i++;		
	}
	return cnt <= k;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
		
		cin >> n >> k;
		for(int i = 0; i < n; i++) cin >> arr[i];
		
		sort(arr, arr+n);
		
		int ans = INF;
		
		int l = 0;
		int r = 1e9 + 10;
		
		while(l <= r){
			
			int m = (l + r)/2;

			if(can(m)){
				ans = m;
				r = m-1;
			} else{
				l = m+1;
			}
		}
		
		cout << ans << endl;
    }	
}
