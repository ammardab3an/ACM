// Problem: C. Apple Shops
// Contest: Codeforces - Training Contest
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/309757/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int a[NMAX], q[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n, k, x;
    cin >> n >> k >> x;
   	for(int i = 0; i < n; i++) cin >> a[i];
   	
   	int l = 0;
   	int r = 2e18;
   	
   	// binary search on the avg price of a box
   	// avg_b = a+m*x
   	while(l+1 < r){
   		
   		int p = (l+r)/2;
   		int s = 0;
   		for(int i = 0; i < n && s < k; i++)
   			s += p >= a[i] ? (p-a[i]) / x + 1LL : 0;
   		
   		if(s >= k)
   			r = p;
   		else
   			l = p;
   	}
   	
   	
   	for(int i = 0; i < n; i++){
   		q[i] = l >= a[i] ? (l-a[i]) / x + 1LL : 0;
   		k -= q[i];
   	}
   	
   	//if(k)
   	for(int i = 0; i < n && k; i++)
   		if(r >= a[i] && (r-a[i])%x == 0)
   			q[i]++, k--;
   			
   	for(int i = 0; i < n; i++) cout << q[i] << ' ';
}