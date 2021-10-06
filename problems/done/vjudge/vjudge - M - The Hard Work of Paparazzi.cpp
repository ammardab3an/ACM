// Problem: M - The Hard Work of Paparazzi
// Contest: Virtual Judge - Dp 2
// URL: https://vjudge.net/contest/432549#problem/M
// Memory Limit: 262 MB
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int r, n;
    cin >> r >> n;
    
    n++;
    vector<vi> vec(n, vi(3));
    
    vec[0] = {0, 1, 1};
    for(int i = 1; i < n; i++)
    for(int j = 0; j < 3; j++) cin >> vec[i][j];
    
    vi dp(n, -INF), mx(n);
    dp[0] = 0;
    
    for(int i = 1; i < n; i++){
        
        int ct = vec[i][0];
        int cx = vec[i][1];
        int cy = vec[i][2];
        
        // for(int j = 0; j < max(0, i - 2*r); j++){
            // dp[i] = max(dp[i], dp[j] + 1);    
        // }
        
        if(i-2*r >= 0) dp[i] = max(dp[i], mx[i-2*r] + 1);
        
        for(int j = max(0, i-2*r); j < i; j++){
            
            int nt = vec[j][0];
            int nx = vec[j][1];
            int ny = vec[j][2];
            
            if(abs(nx - cx) + abs(ny - cy) <= ct - nt){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
        mx[i] = max(mx[i-1], dp[i]);
    }
    
    cout << mx[n-1] << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
