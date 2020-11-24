// Problem: D. Circle Game
// Contest: Codeforces - Codeforces Round #685 (Div. 2)
// URL: https://codeforces.com/contest/1451/problem/D
// Memory Limit: 256 MB
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
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const double pi = acos(-1);

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

		lli r, k;
		cin >> r >> k; r*=r;
		
		lli i, j;
		i = j = 0;
		
		while(1){
			if(i <= j && pow(i+k, 2) + pow(j, 2) <= r)
				i += k;
			else if(i > j && pow(j+k, 2) + pow(i, 2) <= r)
				j += k;
			else break;
		}
		
		/*
		long double mv = sqrt(2*k*k);
		long double mx = r;
		
		long double kk = mv * floor(mx/mv) / sqrt(2);
		
		long double kkk = pow(kk+k, 2) + pow(kk, 2);
		*/
		cout << (i == j ? "Utkarsh" : "Ashish") << endl;
    }	
}
