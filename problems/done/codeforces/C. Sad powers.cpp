// Problem: C. Sad powers
// Contest: Codeforces - Codeforces Round #471 (Div. 2)
// URL: https://codeforces.com/problemset/problem/955/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int root(int n, int i){
	int t = powl(n, 1.0/i) - 0.5;
	return t + (powl(t+1, i) - 0.5 <= n);
}

vi mob(70);

int calc(int n){
	
	int ans = 1;
	
	for(int i = 2; i <= 60; i++){
		int tmp = root(n, i);
		if(!tmp) break;
		ans += -1 * mob[i] * (tmp -1);
	}
	
	return ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	for(int i = 2; i < 70; i++){
		mob[i] = -1 -mob[i];
		for(int j = i+i; j < 70; j += i){
			mob[j] += mob[i];
		}
	}
	
    int t; cin >> t; while(t--){

		int l, r;
		cin >> l >> r;
		
		int cans = calc(r);
		if(l > 1) cans -= calc(l-1);
		
		cout << cans << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
