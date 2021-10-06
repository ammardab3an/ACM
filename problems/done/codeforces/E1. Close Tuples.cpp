// Problem: E2. Close Tuples (hard version)
// Contest: Codeforces - Codeforces Round #690 (Div. 3)
// URL: http://codeforces.com/contest/1462/problem/E2
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

int n, m, k;
int arr[NMAX];
int fact[NMAX];

int fast_pow(int n, int p){
	
	if(!p) return 1;
	
	if(p&1) return (n * fast_pow(n, p-1)) % MOD;
	
	int tmp = fast_pow(n, p/2);
	
	return (tmp * tmp) % MOD;
}

int get_fact(int n){
	if(n < 1) return 1;
	if(fact[n]) return fact[n];
	return fact[n] = (n * get_fact(n-1)) % MOD;
}

int choose(int n, int r){
	
	return (
		
				(
					(get_fact(n) * fast_pow(get_fact(r), MOD-2)) % MOD
				) 
				
					* fast_pow(get_fact(n-r), MOD-2)
				
			) % MOD;
			
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
	m = 3;
	k = 2;
	
    int t; cin >> t; while(t--){

		cin >> n;// >> m >> k;
		
		for(int i = 0; i < n; i++) cin >> arr[i];
		
		sort(arr, arr+n);
		
		int ans = 0;
		
		int j = 0;
				
		for(int i = 0; i < n; i++){
			
			while(j < n && arr[i] + k >= arr[j]){
				j++;
			}
			
			int cnt = j-i-1;
			
			if(cnt < m-1) continue;
			
			int cans = cnt*(cnt-1)/2;
			ans += cans;
			
			//ans = (ans + choose(cnt, m-1))%MOD;
			
		}
		
		cout << ans << endl;
    }	
}
