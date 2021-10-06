// Problem: B. Cat Cycle
// Contest: Codeforces - Educational Codeforces Round 104 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1487/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
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
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

		int n, k;
		cin >> n >> k;
		
		k--;
		
		if(n%2 == 0){
			cout << k%n +1 << endl;
			continue;
		}
		
		int a = 0, b = n-1, ck = 0;
		
		int lsta = a;
		int lstb = b;
		int lstk = 0;
		
		
		if(false) while(ck < k){
			
			lsta = a;
			lstb = b;
			lstk = ck;
			
			b = b - n/2;
			b = (b+n)%n;
			
			ck += n/2;
		}
		
		lstk = (n/2) *(k/(n/2));
		lstb = b - (n/2) * (k/(n/2));
		lstb += (n/2) * (k/(n/2)) * n;
		lstb %= n;
		lsta = lstb+1;
		lsta %= n;
		
		ck = (n/2) * (k/(n/2) +1);
		
		b = b - (n/2) * (k/(n/2) + 1);
		b += (n/2) * (k/(n/2) + 1) * n;
		b %= n;
		
		a = b+1;
		a %= n;
		
		// cout << a << ' ' << b << ' ' << ck << endl;
		// cout << lsta << ' ' << lstb << ' ' << lstk << endl;
		
		if(ck != k)
		{
			
			int a = lsta;
			int b = lstb;
			int ck = lstk;
			
			if(ck < k){
				b = (b-1+n)%n;
				a = (a+1)%n;
				if(a == b) a = (a+1)%n;
				ck++;
			}
			
			a = (a + (k-ck) + n) % n;
			
			cout << a+1 << endl;
		}
		
		else{
			
			cout << a+1 << endl;
		}
		
    }	
}
