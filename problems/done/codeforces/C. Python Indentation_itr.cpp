// Problem: C. Python Indentation
// Contest: Codeforces - Codeforces Round #455 (Div. 2)
// URL: https://codeforces.com/contest/909/problem/C?outsideGroup=true
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

const int NMAX = 5e3 + 10;

int add(int a, int b){
    return (lli(a) + b + MOD + MOD) % MOD;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n;
    cin >> n;
    
    vector<string> vec(n);
    for(auto &str : vec) cin >> str;
    
    vi dp(n+1);
    dp[0] = 1;
    
    for(int i = 0; i < n; i++){
        
        if(i && vec[i-1] == "f"){
            
            for(int lvl = n; lvl > 0; lvl--){
                dp[lvl] = dp[lvl-1];
            }
            dp[0] = 0;
        }
        else{
            
            for(int lvl = n-1; lvl >= 0; lvl--){
                (dp[lvl] += dp[lvl+1]) %= MOD;
            }    
        }
    }
    
    int ans = 0;
    for(int i = 0; i <= n; i++) (ans += dp[i]) %= MOD;
    
    cout << ans;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
