// Problem: G - Rooks
// Contest: Virtual Judge - Dp 2
// URL: https://vjudge.net/contest/432549#problem/G
// Memory Limit: 65 MB
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, k;
lli fac[30];

lli factorial(int i){
    if(!i) return 1;
    if(fac[i]) return fac[i];
    return fac[i] = i * factorial(i-1);
}

lli choose(int n, int r){
    
    r = min ( r , n-r ) ;
    lli p = 1 , q = 1 , gcd ;
    while ( r ){
        p *= n ;
        q *= r ;
        lli gcd = __gcd  ( p , q ) ;
        p /= gcd ;
        q /= gcd ;
        --n ;
        --r ;
    }
    
    return p/q;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int tt = 1;
    int t; cin >> t; while(t--){
        
        int n, k;
        cin >> n >> k;
        
        cout << "Case " << tt++ << ": ";
        
        if(k > n){
            cout << 0 << endl;
        }
        else{        
            cout << choose(n, k) * choose(n, k) * factorial(k) << endl;
        }
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    