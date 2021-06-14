// Problem: C. Qualification Rounds
// Contest: Codeforces - Codeforces Round #438 by Sberbank and Barcelona Bootcamp (Div. 1 + Div. 2 combined)
// URL: https://codeforces.com/problemset/problem/868/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
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
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

const int NMAX = 1e5 + 10;

int n, k;
int arr[NMAX];
set<int> st;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		
		for(int j = 0; j < k; j++){
			
			int aij;
			cin >> aij;
			
			arr[i] |= aij << j;	
		}
		
		st.insert(arr[i]);
	}
	
	
	if(n == 1){
		cout << (!arr[0] ? "YES" : "NO") << endl;
		return 0;	
	}
		
	bool ans = false;
	
	for(auto i : st)
	for(auto j : st) ans |= (i&j)==0;
	
	cout << (ans ? "YES" : "NO") << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
