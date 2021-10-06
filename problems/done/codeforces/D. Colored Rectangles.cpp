// Problem: D. Colored Rectangles
// Contest: Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1398/problem/D
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int r, g, b;
int arr_r[222], arr_g[222], arr_b[222];

int mem[222][222][222];

int go(int i, int j, int k){
    
    int &ret = mem[i+1][j+1][k+1];
    if(ret+1) return ret;
    
    int ans = 0;
    
    if(i >= 0 && j >= 0){
        ans = max(ans, go(i-1, j-1, k) + arr_r[i] * arr_g[j]);    
    }
    
    if(i >= 0 && k >= 0){
        ans = max(ans, go(i-1, j, k-1) + arr_r[i] * arr_b[k]);
    }
    
    if(j >= 0 && k >= 0){
        ans = max(ans, go(i, j-1, k-1) + arr_g[j] * arr_b[k]);
    }
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> r >> g >> b;
    for(int i = 0; i < r; i++) cin >> arr_r[i];
    for(int i = 0; i < g; i++) cin >> arr_g[i];
    for(int i = 0; i < b; i++) cin >> arr_b[i];
    
    sort(arr_r, arr_r+r);
    sort(arr_g, arr_g+g);
    sort(arr_b, arr_b+b);
    
    memset(mem, -1, sizeof mem);
    
    cout << go(r-1, g-1, b-1) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
