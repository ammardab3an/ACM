// Problem: C - Caesar's Legions
// Contest: Virtual Judge - Dp 2
// URL: https://vjudge.net/contest/432549#problem/C
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
const int MOD = 1e8;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m, k0, k1;
int mem[110][110][2];

int add(int a, int b){
    return (1ll * a + b + MOD + MOD) % MOD;
}

int go(int n, int m, int b){
    
    if(!n && !m) return 1;
    
    int &ret = mem[n][m][b];
    if(ret + 1) return ret;
    
    int ans = 0;
    
    if(b == 0){
        
        for(int i = 1; i <= min(k0, n); i++){
            ans = add(ans, go(n-i, m, !b));
        }
    }
    else{
        
        for(int i = 1; i <= min(k1, m); i++){
            ans = add(ans, go(n, m-i, !b));
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

    
    cin >> n >> m >> k0 >> k1;
    memset(mem, -1, sizeof mem);
    cout << add(go(n, m, 0), go(n, m, 1)) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
