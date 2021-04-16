// Problem: E. Maximum Sum
// Contest: Codeforces - ACM International Collegiate Programming Contest, JUST Collegiate Programming Contest (2018)
// URL: https://codeforces.com/gym/101853/problem/E?outsideGroup=true
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

// #define endl '\n'
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
int grid[20][20];
int mem[20][20][1 << 16];

int go(int i, int j, int msk){
    
    int nmsk = msk;
    if(j) nmsk = nmsk & (~(1 << (j-1)));
    
    if(i == n) return 0;
    if(j >= n) return go(i+1, 0, nmsk);
    
    int &ret = mem[i][j][msk];
    if(ret + 1) return ret;
    
    //stPath
    int stPath = go(i, j+1, nmsk);
    
    //ndPath
    int ndPath = 0;
    if(!(j && (msk & (1 << (j-1)))) && !(msk & (1 << j)) && (!(msk & (1 << (j+1))))){
            
        ndPath = grid[i][j] + go(i, j+2, nmsk | (1 << j));
    }
    
    return ret = max(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        cin >> n;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> grid[i][j];
        
        memset(mem, -1, sizeof mem);
        
        cout << go(0, 0, 0) << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
