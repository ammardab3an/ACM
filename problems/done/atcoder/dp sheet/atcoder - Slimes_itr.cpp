// Problem: N - Slimes
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_n
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
int arr[440];
int pre[440];
int mem[440][440];
    
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    pre[0] = arr[0];
    for(int i = 1; i < n; i++) pre[i] = pre[i-1] + arr[i];
    
    memset(mem, INFLL, sizeof mem);
    for(int i = 0; i < n; i++) mem[i][i] = 0;
    
    for(int i = n-1; i >= 0; i--)
    for(int j = i ; j < n; j++){
        
        for(int k = i; k < j; k++){
            
            mem[i][j] = min(mem[i][j], mem[i][k] + mem[k+1][j] + pre[j] - pre[i] + arr[i]);    
        }    
    }
    
    cout << mem[0][n-1];
}
