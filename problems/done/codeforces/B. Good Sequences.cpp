// Problem: B. Good Sequences
// Contest: Codeforces - Codeforces Round #162 (Div. 1)
// URL: https://codeforces.com/contest/264/problem/B?outsideGroup=true
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

    int n;
    cin >> n;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    vi dp(1e5+10), d(1e5+10);
    
    int Ans = 0;
    
    for(int i = 0; i < n; i++){
        
        int x = vec[i];
        
        int ans = 0;
        
        for(int j = 2; j*j <= x; j++) if(x%j==0){
            
            ans = max(ans, d[j]);
            ans = max(ans, d[x/j]);    
        }
        
        dp[x] = max(dp[x], ans+1);
        
        for(int j = 1; j*j <= x; j++) if(x%j==0){
            
            d[j] = max(d[j], dp[x]);
            d[x/j] = max(d[x/j], dp[x]);  
        }
        
        Ans = max(Ans, dp[x]);
    }
    
    // cout << Ans << endl;
    cout << d[1] << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
