// Problem: F. Yet Another Substring Reverse
// Contest: Codeforces - Codeforces Round #590 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1234/F
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
    
    string str;
    cin >> str;
    
    int n = str.size();
    
    vi dp(1 << 20);
    
    for(int i = 0; i < n; i++){
        
        int msk = 0;
        int pop_cnt = 0;
        
        for(int j = i; j < n; j++){
            
            if(msk & (1 << (str[j] - 'a'))) break;
            
            msk |= 1 << (str[j] - 'a');
            
            dp[msk] = ++pop_cnt;
        }    
    }
    
    for(int msk = 0; msk < (1 << 20); msk++){
        
        for(int i = 0; i < 20; i++) if(msk & (1 << i)){
            
            dp[msk] = max(dp[msk], dp[msk ^ (1 << i)]);
        }
    }
    
    int ans = 0;
    
    for(int msk = 0; msk < (1 << 20); msk++){
        
        if(dp[msk] == __builtin_popcount(msk)){
            
            int comp = ((1 << 20)-1) & (~msk);
            
            ans = max(ans, dp[msk] + dp[comp]);
        }
    }
    
    cout << ans << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
*/    
