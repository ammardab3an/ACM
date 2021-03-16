// Problem: C - Vacation
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_c
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

int n;
int arr[NMAX][3];
int mem[NMAX][4];

int go(int pos, int lst){
    
    if(pos == n) return 0;
    
    int &ret = mem[pos][lst+1];
    if(ret+1) return ret;
    
    int stPath = 0, ndPath = 0, rdPath = 0;
    
    if(lst != 0) stPath = go(pos+1, 0) + arr[pos][0];
    if(lst != 1) ndPath = go(pos+1, 1) + arr[pos][1];
    if(lst != 2) rdPath = go(pos+1, 2) + arr[pos][2];
    
    return ret = max({stPath, ndPath, rdPath});
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < 3; j++) cin >> arr[i][j];
    
    memset(mem, -1, sizeof mem);
    
    cout << go(0, -1);
}
