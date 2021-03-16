// Problem: L - Deque
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_l
// Memory Limit: 1024 MB
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

int n;
int arr[3030];
int mem[2][3030][3030];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    // for(int i = 0; i < n; i++)
    // for(int j = n-1; j >= i; j--)
    
    for(int i = n-1; i >= 0; i--)
    for(int j = i; j < n; j++)
    for(int t = 0; t < 2; t++)
    {
        
        int stPath = !t * arr[i] - t * arr[i];
        if(i+1 < n) stPath += mem[!t][i+1][j];
        
        int ndPath = !t * arr[j] - t * arr[j];
        if(j) ndPath += mem[!t][i][j-1];
        
        mem[t][i][j] = !t ? max(stPath, ndPath) : min(stPath, ndPath);
    }
    
    cout << mem[0][0][n-1] << endl;
}
