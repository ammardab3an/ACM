// Problem: E. By Elevator or Stairs?
// Contest: Codeforces - Codeforces Round #595 (Div. 3)
// URL: https://codeforces.com/contest/1249/problem/E?outsideGroup=true
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

// #define endl '\n'
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

    int n, c;
    cin >> n >> c;
    
    vi a(n-1), b(n-1);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    
    vector<vi> dp(n+1, vi(2, INF));
    
    dp[0][0] = 0;
    dp[0][1] = INF;
    
    cout << 0 << ' ';
    
    for(int i = 1; i < n; i++){
        
        dp[i][0] = min(dp[i-1][0] + a[i-1], dp[i-1][1] + a[i-1]);
        dp[i][1] = min(dp[i-1][1] + b[i-1], dp[i-1][0] + b[i-1] + c);
        
        cout << min(dp[i][0], dp[i][1]) << ' ';
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
