// Problem: 108 - Maximum Sum
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=44
// Memory Limit: 32 MB
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
int arr[111][111];
int pre[111][111];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) cin >> arr[i][j];
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        pre[i][j] = arr[i][j];
        if(i) pre[i][j] += pre[i-1][j];
        if(j) pre[i][j] += pre[i][j-1];
        if(i && j) pre[i][j] -= pre[i-1][j-1];
    }

    int ans = pre[n-1][n-1];
    
    for(int x0 = 0; x0 < n; x0++)
    for(int y0 = 0; y0 < n; y0++)
    for(int x1 = x0; x1 < n; x1++)
    for(int y1 = y0; y1 < n; y1++){
        
        int csum = pre[x1][y1];
        if(x0) csum -= pre[x0-1][y1];
        if(y0) csum -= pre[x1][y0-1];
        if(x0 && y0) csum += pre[x0-1][y0-1];
        
        ans = max(ans, csum);
    }
    
    cout << ans << endl;
}
