// Problem: A. Bovine Dilemma
// Contest: Codeforces - Good Bye 2020
// URL: https://codeforces.com/contest/1466/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int EPS = 1e-9;
const int  PI = acos(-1);

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
		
		int n;
		cin >> n;
		vi vec(n);
		for(int i = 0; i < n; i++) cin >> vec[i];
		
		set<int> st;
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			
			int mn = min(vec[i], vec[j]);
			int mx = max(vec[i], vec[j]);
			
			int area = (mx-mn);
			st.insert(area);
		}
		
		cout << st.size()-1 << endl;
    }	
}
