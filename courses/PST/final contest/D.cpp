// Problem: D - 4
// Contest: Virtual Judge - Level 3 - Graduation Contest
// URL: https://vjudge.net/contest/414878#problem/D
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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

int n;
int arr[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	sort(arr, arr+n); // just in case
	
	int q; cin >> q; while(q--){
		
		int x; 
		cin >> x;
		
		int s = -1;
		int t = -1;
		
		{
			int l = 0;
			int r = n-1;
			
			while(l <= r){
				
				int m = (l+r)/2;
				
				if(arr[m] < x){
					s = m;
					l = m+1;
				}
				else{
					r = m-1;
				}
			}
		}
		
		{
			int l = 0;
			int r = n-1;
			
			while(l <= r){
				
				int m = (l+r)/2;
				
				if(arr[m] > x){
					t = m;
					r = m-1;
				}
				else{
					l = m+1;
				}
			}
		}	
		
		
		// int s = lower_bound(arr, arr+n, x) -arr -1;
		// int t = upper_bound(arr, arr+n, x) -arr;
		
		if(s+1){
			cout << arr[s];
		}
		else{
			cout << 'X';
		}
		
		cout << ' ';
		
		if(t+1){
			cout << arr[t];
		}
		else{
			cout << 'X';
		}
		
		cout << endl;
	}
}
