// Problem: A - 1
// Contest: Virtual Judge - Level 3 - Graduation Contest
// URL: https://vjudge.net/contest/414878#problem/A
// Memory Limit: 262 MB
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

int n, m;
int arr[NMAX], dis[NMAX], sm[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    {

		cin >> m;
		for(int i = 0; i < m; i++) cin >> dis[i];
		sort(dis, dis+m);
		
		cin >> n;
		for(int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr+n);
		
		sm[0] = arr[0];
		for(int i = 1; i < n; i++) sm[i] = sm[i-1] + arr[i];
		
		int ans = 0;
		
		int j = 0;
		for(int i = n-1; i >= 0; i--){
			
			int cnt = i+1;
			while(j < m && cnt < dis[j]) j++;
			
			if(j >= m){
				ans += arr[i];
				continue;
			}
						
			ans += sm[i];
			if(i-dis[j] >= 0) ans -= sm[i-dis[j]];
			
			if(i-1 >= 0) i--;
			if(i-1 >= 0) i--;
			
			i -= dis[j];
			i++;
		}
		
		cout << ans << endl;
    }	
}
