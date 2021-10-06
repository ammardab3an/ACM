// Problem: E. Two Platforms
// Contest: Codeforces - Codeforces Round #667 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1409/E
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
        
        int n, k;
        cin >> n >> k;
        
        vi x(n), y(n);
        for(auto &i : x) cin >> i;
        for(auto &i : y) cin >> i;
        
        sort(x.begin(), x.end());
        
        int ans = 0;
        
        queue<pii> que;
        
        int j = 0;
        int sum = 0;
        int last = 0;
        
        for(int i = 0; i < n; i++){
                
            while(!que.empty()){
                
                if(x[i] - que.front().first > k){
                    last = max(last, que.front().second);
                    que.pop();
                }
                else{
                    break;
                }
            }
            
            while((j < n) && ((x[j] - x[i]) <= k)) sum++, j++;
            
            ans = max(ans, last + sum);
            
            que.push({x[i], sum});
            
            sum--;
        }
        
        cout << ans << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
