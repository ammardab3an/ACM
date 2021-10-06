// Problem: F - LCS
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_f
// Memory Limit: 1024 MB
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

int n, m;
char str_a[3030], str_b[3030];
int mem[3030][3030];

int go(int i, int j){
    
    if(i == n || j == m) return 0;    
    
    int &ret = mem[i][j];
    if(ret+1) return ret;
    
    if(str_a[i] == str_b[j]) 
        return ret = go(i+1, j+1) + 1;
    
    int stPath = 0, ndPath = 0;
    
    stPath = go(i+1, j);
    ndPath = go(i, j+1);    
    
    return ret = max(stPath, ndPath);
}

void calc(int i, int j){
    
    if(i == n || j == m) return;
    
    if(str_a[i] == str_b[j]){
        cout << str_a[i];
        calc(i+1, j+1);
        return;
    }
    
    if(go(i, j) == go(i+1, j)) 
        calc(i+1, j);
    else 
        calc(i, j+1);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> str_a >> str_b;
    
    n = strlen(str_a);
    m = strlen(str_b);
    
    memset(mem, -1, sizeof mem);
    
    calc(0, 0);
}
