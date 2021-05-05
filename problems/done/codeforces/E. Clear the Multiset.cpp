// Problem: E. Clear the Multiset
// Contest: Codeforces - Educational Codeforces Round 94 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1400/problem/E
// Memory Limit: 256 MB
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

const int  MAX = 2e5 + 10;
const int NMAX = 5e3 + 10;
const int MMAX = 2e5 + 10;

int n;
int arr[NMAX];
int mem[NMAX][NMAX];

int go(int i, int k){
    
    if(i == n) return 0;
    
    int &ret = mem[i][k];
    if(ret+1) return ret;
    
    int ans = INF;
    
    if(k >= arr[i]){
        ans = go(i+1, arr[i]);
    }
    else{
        ans = go(i+1, k) + 1;
        if(k+1 < n) ans = min(ans, go(i, k+1) + 1);
    }
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    memset(mem, -1, sizeof mem);
    
    cout << go(0, 0) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
