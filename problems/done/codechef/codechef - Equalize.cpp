// Problem: Equalize
// Contest: CodeChef - Practice(Easy)
// URL: https://www.codechef.com/problems/EQUALIZE
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m, q;
int grid[1010][1010];
int pre[1010][1010];

bool can(int h, int w, int v){
    
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < m; j++){
            
            pre[i][j] = grid[i][j] >= v ? +1 : -1;
            
            if(i) pre[i][j] += pre[i-1][j];
            if(j) pre[i][j] += pre[i][j-1];
            if(i&&j) pre[i][j] -= pre[i-1][j-1];
            
            if(i >= h-1 && j >= w-1){
                
                int csum = pre[i][j];
                if(i-h >= 0) csum -= pre[i-h][j];
                if(j-w >= 0) csum -= pre[i][j-w];
                if(i-h >= 0 && j-w >= 0) csum += pre[i-h][j-w];
                
                if(csum > 0) return true;
            }
        }
    }
    
    return false;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> grid[i][j];
    
    while(q--){
        
        int h, w;
        cin >> h >> w;
        
        int l = 0;
        int r = 1e7 + 10;
        
        int ans = -1;
        
        while(l <= r){
            
            int m = (l+r)/2;
            
            if(can(h, w, m)){
                ans = m;
                l = m+1;
            }
            else{
                r = m-1;
            }
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
