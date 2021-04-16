// Problem: D. Min Cost String
// Contest: Codeforces - Educational Codeforces Round 107 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1511/problem/D
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

int check(string str){

    int n = str.size();
    
    int cnt = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(str[i] == str[j]){
                if(str[i+1] == str[j+1]){
                    cnt++;
                }
            }
        }
    }
    
    return cnt;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n, k;
    cin >> n >> k;
    
    string ans;
    
    while(ans.size() != n){
        
        for(int i = 0; i < k; i++){
            
            ans += 'a' + i;
            if(ans.size() == n) break;
            
            for(int j = i+1; j < k; j++){
                
                ans += 'a' + i;
                if(ans.size() == n) break;
                
                ans += 'a' + j;
                if(ans.size() == n) break;
            }
            
            if(ans.size() == n) break;
        }
    }
    
    cout << ans << endl;
    // cout << check(ans) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
