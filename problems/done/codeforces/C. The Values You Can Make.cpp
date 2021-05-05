// Problem: C. The Values You Can Make
// Contest: Codeforces - Codeforces Round #360 (Div. 1)
// URL: https://codeforces.com/problemset/problem/687/C
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n, k;
    cin >> n >> k;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    vector<vi> dp(555, vi(555));
    
    dp[0][0] = 1;
    
    for(int i = 0; i < n; i++){
        
        for(int rem_k = k; rem_k >= 1; rem_k--)
        for(int rem_n = k; rem_n >= 0; rem_n--){
            
            if(dp[rem_k][rem_n]) continue;
            
            if(rem_k >= vec[i]) {
                
                dp[rem_k][rem_n] |= dp[rem_k-vec[i]][rem_n];
                
                if(rem_n >= vec[i]) 
                
                    dp[rem_k][rem_n] |= dp[rem_k-vec[i]][rem_n-vec[i]];
            }
        }
        
    }
    
    vi ans;
    for(int i = 0; i <= k; i++){
        if(dp[k][i]){
            ans.push_back(i);
        }
    }
    
    cout << ans.size() << endl;
    for(auto i : ans) cout << i << ' ' ; cout << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
