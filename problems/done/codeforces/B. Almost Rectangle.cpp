// Problem: B. Almost Rectangle
// Contest: Codeforces - Codeforces Round #713 (Div. 3)
// URL: https://codeforces.com/contest/1512/problem/B
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

char grid[444][444];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        int n;
        cin >> n;

        for(int i = 0; i < n; i++) cin >>grid[i];

        vpii vec;
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) if(grid[i][j] == '*') vec.push_back({i, j});

        if(vec.size() > 1){

           if(vec[0].first != vec[1].first){

              if(vec[0].second != vec[1].second){
                 grid[vec[0].first][vec[1].second] = grid[vec[1].first][vec[0].second] = '*';
              }
              else
              {
                 int j = vec[0].second ? 0 : 1;
                 grid[vec[0].first][j] = grid[vec[1].first][j] = '*';
              }
           } 
           else{

               int i = vec[0].first ? 0 : 1;
               grid[i][vec[0].second] = grid[i][vec[1].second] = '*';
           }
        }
        

        for(int i= 0; i < n; i++) cout << grid[i] << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
