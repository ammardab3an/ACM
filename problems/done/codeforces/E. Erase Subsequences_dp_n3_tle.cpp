// Problem: E. Erase Subsequences
// Contest: Codeforces - Educational Codeforces Round 82 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1303/problem/E?outsideGroup=true
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

    int t; cin >> t; while(t--){
        
        string str0, str1;
        cin >> str0 >> str1;
        
        int n, m;
        n = str0.size(), m = str1.size();
        
        bool ans = false;
        
        for(int b = 0; b <= m; b++){
            
            vector<vi> dp(b+1, vi(m+1));
            dp[0][0] = 1;
            
            for(int i = 0; i < n; i++){
                
                vector<vi> new_dp(b+1, vi(m+1));
                  
                for(int j = 0; j <= b; j++)
                for(int k = 0; (j+k) <= m; k++){
                            
                    int stPath = 0, ndPath = 0, rdPath = 0;
                    
                    stPath = dp[j][k];
                    
                    if(j) if(str0[i] == str1[j-1])   ndPath = dp[j-1][k];
                    
                    if(k) if(str0[i] == str1[b+k-1]) rdPath = dp[j][k-1];
                    
                    new_dp[j][k] = stPath || ndPath || rdPath;
                }
                
                dp = new_dp;
            }
            
            bool cans = dp[b][m-b];
            
            if(cans){
                ans = true;
                break;
            }
        }
        
        cout << (ans ? "YES" : "NO") << endl;
    }	
}
