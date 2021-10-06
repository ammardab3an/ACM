// Problem: D. Imbalanced Array
// Contest: Codeforces - Educational Codeforces Round 23
// URL: https://codeforces.com/problemset/problem/817/D
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
const int NMAX = 1e6 + 10;
const int MMAX = 2e5 + 10;

int n;
int arr[NMAX];
int par_l[NMAX], par_r[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    lli ans = 0;
    
    // stPath
    
    par_l[0] = -1;
    for(int i = 1; i < n; i++){
        par_l[i] = i-1;
        while(par_l[i] >= 0 && arr[i] >= arr[par_l[i]]) par_l[i] = par_l[par_l[i]];
    }
    
    for(int i = n-1; i >= 0; i--){
        par_r[i] = i+1;
        while(par_r[i] < n && arr[i] > arr[par_r[i]]) par_r[i] = par_r[par_r[i]];
    }
    
    for(int i = 0; i < n; i++){
        
        int r = par_r[i];
        int l = par_l[i];
        
        ans += 1ll * arr[i] * (r-i) * (i-l);
    }
    
    // ndPath 
    
    par_l[0] = -1;
    for(int i = 1; i < n; i++){
        par_l[i] = i-1;
        while(par_l[i] >= 0 && arr[i] <= arr[par_l[i]]) par_l[i] = par_l[par_l[i]];
    }
    
    par_r[n-1] = n;
    for(int i = n-2; i >= 0; i--){
        par_r[i] = i+1;
        while(par_r[i] < n && arr[i] < arr[par_r[i]]) par_r[i] = par_r[par_r[i]];
    }
    
    for(int i = 0; i < n; i++){
        
        int r = par_r[i];
        int l = par_l[i];
        
        ans -= 1ll * arr[i] * (r-i) * (i-l);
    }
    
    cout << ans << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
