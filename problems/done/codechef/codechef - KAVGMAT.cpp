// Problem: Worthy Matrix
// Contest: CodeChef - April Challenge 2021 Division 3
// URL: https://www.codechef.com/APRIL21C/problems/KAVGMAT
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<vi> grid(n, vi(m));
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> grid[i][j];
        
        vector<vi> pre(n, vi(m));
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            pre[i][j] = grid[i][j];
            if(i) pre[i][j] += pre[i-1][j];
            if(j) pre[i][j] += pre[i][j-1];
            if(i&&j) pre[i][j] -= pre[i-1][j-1];
        }
        
        int ans = 0;
        
        int mn = min(n, m);
        
        for(int l = 1; l <= mn; l++){
            
            for(int i = 0; i <= n-l; i++){
                
                int ll = 0;
                int rr = m-l;
                
                int mm = -1;
                
                while(ll <= rr){
                    
                    int j = (ll+rr)/2;
                    
                    int sm = pre[i+l-1][j+l-1];
                    if(i) sm -= pre[i-1][j+l-1];
                    if(j) sm -= pre[i+l-1][j-1];
                    if(i&&j) sm += pre[i-1][j-1];
                    
                    if(sm / (l*l) >= k){
                        mm = j;
                        rr = j-1;
                    }
                    else{
                        ll = j+1;
                    }
                }
                
                if(mm != -1){
                    ans += ((m-l) - mm + 1);
                }
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
