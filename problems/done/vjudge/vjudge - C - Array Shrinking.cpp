// Problem: C - Array Shrinking
// Contest: Virtual Judge - Contest 2
// URL: https://vjudge.net/contest/436948#problem/C
// Memory Limit: 262 MB
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
const int NMAX = 5e2 + 10;
const int MMAX = 2e5 + 10;

int n;
int arr[NMAX];
int mem[NMAX];
int mem0[NMAX][NMAX];

int can(int l, int r){
    
    if(l+1 == r) return arr[l];
    
    int &ret = mem0[l][r];
    if(ret+1) return ret;
    
    for(int i = l+1; i < r; i++){
        
        int pre = can(l, i);
        int suf = can(i, r);
        
        if(pre && (pre == suf)){
            return ret = pre+1;
        }
    }
    
    return ret = 0;
}

int go(int i){
    
    if(i == n) return 0;
    
    int &ret = mem[i];
    if(ret+1) return ret;
    
    int ans = n-i;
    
    for(int j = i+1; j < n+1; j++){
        if(can(i, j)){
            ans = min(ans, 1 + go(j));
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
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    memset(mem, -1, sizeof mem);
    memset(mem0, -1, sizeof mem0);
    
    cout << go(0);
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
