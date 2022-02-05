// Problem: Jealous Numbers
// Contest: CodeChef - Practice(Extcontest)
// URL: https://www.codechef.com/problems/NUMSET
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
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

int n;
int arr[1010];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int32_t main(){
      
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int t; cin >> t; while(t--){

        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        map<int, vi> mp;
        
        for(int i = 0; i < n; i++){
            
            int msk = 0;
            int ai = arr[i];
            
            for(int j = 0; j < 11; j++) if(ai%primes[j]==0){
                msk |= 1 << j;
                while(ai%primes[j]==0) ai/=primes[j];
            }
            
            if(ai == 1) ai = -i;
            mp[ai].push_back(msk);
        }
        
        vector<vi> vec;
        for(auto p : mp) vec.emplace_back(p.second);
        n = vec.size();
        
        vector<vi> dp(n+1, vi(1 << 11));
        
        for(int i = n-1; i >= 0; i--){
            
            for(int msk = 0; msk < (1 << 11); msk++){
                
                dp[i][msk] = dp[i+1][msk];
                
                for(auto x : vec[i]){
                    
                    if((msk&x)==0) dp[i][msk] = max(dp[i][msk], dp[i+1][msk|x]+1);
                }
            }
        }
        
        cout << dp[0][0] << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
