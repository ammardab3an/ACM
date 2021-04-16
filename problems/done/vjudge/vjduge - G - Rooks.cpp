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
int fac[33];
int mem[33][33];

void go(){
    
    for (int i = 0; i <= 30; i++)
    for (int j = 0; j <= min(i, int(30)); j++) {

        if (j == 0 || j == i)
            mem[i][j] = 1;
    
        else
            mem[i][j] = mem[i-1][j-1] + mem[i-1][j];
    }
}

int factorial(int i){
    if(!i) return 1;
    if(fac[i]) return fac[i];
    return fac[i] = i * factorial(i-1);
}

int choose(int n, int c){
    return mem[n][c];
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    go();
    
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
