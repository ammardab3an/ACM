// Problem: C - 3
// Contest: Virtual Judge - Level 3 - Graduation Contest
// URL: https://vjudge.net/contest/414878#problem/C
// Memory Limit: 1572 MB
// Time Limit: 2000 ms
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

int n, c;
int arr[NMAX];

bool can(int m){
	
	int i = 1;
	int cnt = c-1;
	int pst = arr[0];
	
	while(cnt && i < n){
		
		int cdist = arr[i] - pst;
		
		if(cdist >= m){
			pst = arr[i];
			cnt--;
		}
		
		i++;
	}
	
	return cnt <= 0;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
		
		cin >> n >> c;
		for(int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr+n);
		
		int dist = 2e9;
		
		int l = 0;
		int r = dist;
		
		int ans = dist;
		
		while(l <= r){
			
			int m = (l+r)/2;
			
			if(can(m)){
				ans = m;
				l = m+1;
			}
			else{
				r = m-1;
			}
		}
		
		cout << ans << endl;
    }	
}
