// Problem: S - Digit Sum
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_s
// Memory Limit: 1024 MB
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
    
    string k;
    cin >> k;
    
    int d;
    cin >> d;
    
    vector<vi> dp(d, vi(2));
    
    dp[0][0] = 1;
    
    for(int i = 0; i < k.size(); i++){
        
        vector<vi> new_dp(d, vi(2));
        
        for(int s = 0; s < d; s++){
            
            for(bool smaller : {false, true}){
                
                int mx = smaller ? 9 : k[i] - '0';
                
                for(int dig = 0; dig <= mx; dig++){
                    ((new_dp[(s+dig)%d][smaller || (dig < k[i] - '0')] += dp[s][smaller])) %= MOD;
                }
            }
        }
        
        dp = new_dp;
    }
    
    cout << (dp[0][0] + dp[0][1] -1 + MOD) % MOD;
}
