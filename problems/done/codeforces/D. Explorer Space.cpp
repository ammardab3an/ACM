// Problem: D. Explorer Space
// Contest: Codeforces - Contest 2050 and Codeforces Round #718 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1517/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int n, m, k;
int arr_j[555][555];
int arr_i[555][555];
int mem[555][555][22];

int go(int i, int j, int k){
    
    if(!k) return 0;
    
    int &ret = mem[i][j][k];
    if(ret+1) return ret;
    
    int ans = INF;
    
    {
        int ni = i;
        int nj = j+1;
        
        if(nj < m){
            ans = min(ans, go(i, j+1, k-1) + arr_j[i][j]);
        }
    }

    {
        int ni = i;
        int nj = j-1;
        
        if(nj >= 0){
            ans = min(ans, go(i, j-1, k-1) + arr_j[i][j-1]);
        }
    }
    
    {
        int ni = i+1;
        int nj = j;
        
        if(ni < n){
            ans = min(ans, go(i+1, j, k-1) + arr_i[i][j]);
        }
    }
    
    {
        int ni = i-1;
        int nj = j;
        
        if(ni >= 0){
            ans = min(ans, go(i-1, j, k-1) + arr_i[i-1][j]);
        }
    }
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m-1; j++) cin >> arr_j[i][j];
    
    for(int i = 0; i < n-1; i++)
    for(int j = 0; j < m; j++) cin >> arr_i[i][j];
    
    if(k%2==1){
        for(int i = 0; i < n; i++){
            for(int j = 0;j < m; j++) cout << -1 << ' ' ; 
            cout << endl;
        } 
        return 0;
    }
    
    memset(mem, -1, sizeof mem);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << 2*go(i, j, k/2) << ' ' ;
        }
        cout << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
