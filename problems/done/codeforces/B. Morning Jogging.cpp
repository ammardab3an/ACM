// Problem: B. Morning Jogging
// Contest: Codeforces - Contest 2050 and Codeforces Round #718 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1517/problem/B
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

int n, m;
int grid[111][111];
int vist[111][111];
int ans[111][111];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> grid[i][j];
        
        set<iii> st;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) st.insert({grid[i][j], {i, j}});
        
        memset(vist, 0, sizeof vist);
        memset(ans, -1, sizeof ans);
        
        for(int i = 0; i < m; i++){
            
            auto tp = *st.begin();
            st.erase(st.begin());
            
            int cv = tp.first;
            int ci = tp.second.first;
            int cj = tp.second.second;
            
            vist[ci][cj] = true;
            
            ans[ci][i] = cv;
        }
        
        for(int i = 0; i < n; i++){
            
            int k = 0;
            
            for(int j = 0; j < m; j++) if(ans[i][j] == -1){
                
                while(k < m && vist[i][k]) k++;
                
                ans[i][j] = grid[i][k];
                
                vist[i][k] = true;
                
                k++;
            }
            
        }
        
        for(int i= 0; i < n; i++){
            for(int j = 0; j < m; j++) cout << ans[i][j] << ' ' ; 
            cout << endl;
        }
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
