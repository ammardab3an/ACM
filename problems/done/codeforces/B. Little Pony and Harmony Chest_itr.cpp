// Problem: B. Little Pony and Harmony Chest
// Contest: Codeforces - Codeforces Round #259 (Div. 1)
// URL: https://codeforces.com/contest/453/problem/B?outsideGroup=true
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
    
    vi fact(60);    
    vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    
    for(int i = 1; i < 60; i++){
        for(int j = 0; j < 17; j++){
            if(i % primes[j] == 0) fact[i] |= 1 << j;
        }
    }
    
    vector<vi> dp(n+1, vi(1 << 17, INF));
    fill(dp[0].begin(), dp[0].end(), 1);
    
    vector<vi> bac(n+1, vi(1 << 17));
    
    for(int i = 0; i < n; i++){
        
        for(int k = 1; k < 60; k++){
            
            int msk = (~fact[k]) & ((1 << 17) -1);
            for(int nmsk = msk; ; nmsk = (nmsk-1) & msk){
                
                if(dp[i+1][nmsk | fact[k]] > dp[i][nmsk] + abs(vec[i] - k)){
                    dp[i+1][nmsk | fact[k]] = dp[i][nmsk] + abs(vec[i] - k);
                    bac[i+1][nmsk | fact[k]] = k;
                }
                
                if(nmsk == 0) break;
            }
        }
    }
    
    vi out;
    
    int cmsk = min_element(dp[n].begin(), dp[n].end()) - dp[n].begin();
    
    for(int i = n; i > 0; i--){
        out.push_back(bac[i][cmsk]);
        cmsk = cmsk ^ fact[bac[i][cmsk]];
    }
    
    reverse(out.begin(), out.end());
    for(auto i : out) cout << i << ' '; cout << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
