// Problem: C. Fillomino 2
// Contest: Codeforces - Contest 2050 and Codeforces Round #718 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1517/problem/C
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

int n, m, bad;
int grid[555][555];

void dfs(int i, int j, int v, int k){
    
    if(!k) return;
    
    if(j-1 >= 0 && !grid[i][j-1]){
        grid[i][j-1] = v;
        dfs(i, j-1, v, k-1);
    }
    else{
        
        if(i+1 >= n || grid[i+1][j]){
            bad = true;
            return;
        }
        else{
            grid[i+1][j] = v;
            dfs(i+1, j, v, k-1);
        }
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;
    for(int i = 0; i < n; i++) cin >> grid[i][i];
    
    for(int i = 0; i < n; i++) dfs(i, i, grid[i][i], grid[i][i]-1);
    
    if(bad){
        cout << -1 << endl;
    }
    else{
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++) cout << grid[i][j] << ' ' ;
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
