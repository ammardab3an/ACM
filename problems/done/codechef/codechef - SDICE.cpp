// Problem: Chef and Dice
// Contest: CodeChef - April Challenge 2021 Division 3
// URL: https://www.codechef.com/APRIL21C/problems/SDICE
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

        lli n;
        cin >> n;
        
        lli ans = 0;
        
        lli cnt = n / 4;
        
        ans += cnt * 2 * (6 + 5 + 5 + 6);
        
        lli left = n % 4;
        
        if(left == 0){
            ans += bool(cnt) * (4 + 4 + 4 + 4);
        }
        else if(left == 1){
            ans += bool(cnt) * (4 + 4 + 4) + (21 - 1);
        }
        else if(left == 2){
            ans += bool(cnt) * (4 + 4) + (21 - 1 - 2) + (21 - 1 - 2);
        }
        else{
            ans += bool(cnt) * (4) + (21 -1 - 2) + (21 - 1 - 2 - 3) + (21 - 1 - 2);
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
