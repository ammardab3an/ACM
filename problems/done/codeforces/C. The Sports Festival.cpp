// Problem: C. The Sports Festival
// Contest: Codeforces - Codeforces Round #715 (Div. 2)
// URL: https://codeforces.com/contest/1509/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int NMAX = 3000 + 10;
const int MMAX = 2e5 + 10;

int n;
int arr[NMAX];
int mem[NMAX][NMAX];

int go(int i, int j){
    
    if(i > j) return 0;
    
    int &ret = mem[i][j];
    if(ret+1) return ret;
    
    int stPath = go(i+1, j);
    int ndPath = go(i, j-1);
    
    return ret = min(stPath, ndPath) + arr[j] - arr[i];
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr, arr+n);
    
    memset(mem, -1, sizeof mem);
    
    cout << go(0, n-1) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
