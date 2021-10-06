// Problem: B. Maximum Submatrix 2
// Contest: Codeforces - Codeforces Round #221 (Div. 1)
// URL: https://codeforces.com/contest/375/problem/B?outsideGroup=true
// Memory Limit: 512 MB
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

    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for(auto &str : grid) cin >> str;
    
    vector<vi> right(m, vi(n));
    
    for(int i = 0; i < n; i++){
        
        int lst = 0;
        for(int j = m-1; j >= 0; j--){
            
            if(grid[i][j] != '1'){
                lst = 0;
            }
            else{
                lst++;
            }
            
            right[j][i] = lst;
        }
    }
    
    int ans = 0;
    
    for(int j = 0; j < m; j++){
        
        sort(right[j].begin(), right[j].end());
        
        for(int i = 0; i < n; i++){
            ans = max(ans, right[j][i] * (n-i));
        }
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
