// Problem: E. Vowels
// Contest: Codeforces - Codeforces Round #225 (Div. 1)
// URL: https://codeforces.com/contest/383/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

const int NMAX = 1e4 + 10;
const int LOG = 24;

int n;
int dp[1 << LOG];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    for(int i = 0; i < n; i++){
        
        string str;
        cin >> str;
        
        int ai = (1 << (str[0] - 'a')) | (1 << (str[1] - 'a')) | (1 << (str[2] - 'a'));
        
        for(int msk = ai; msk; msk = (msk-1) & ai){
            dp[msk] += __builtin_popcount(msk)%2 ? +1 : -1;
        }
    }
    
    for(int i = 0; i < LOG; i++) for(int msk = 0; msk < (1 << LOG); msk++){
        if(msk & (1 << i))
            dp[msk] += dp[msk^(1 << i)];
    }
    
    lli ans = 0;
    for(int i = 0; i < (1 << LOG); i++){
        ans ^= 1ll*dp[i]*dp[i];
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
