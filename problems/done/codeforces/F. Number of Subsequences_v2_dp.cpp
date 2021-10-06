// Problem: F. Number of Subsequences
// Contest: Codeforces - Codeforces Round #674 (Div. 3)
// URL: https://codeforces.com/contest/1426/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
char str[NMAX];
int mem[NMAX][4];

int add(int a, int b){
    return (1ll * a + b + MOD + MOD) % MOD;
}
 
int mul(int a, int b){
    return (1ll * a * b) % MOD;
}

int go(int pos, int k){
    
    if(pos == n) return k == 3;
    
    int &ret = mem[pos][k];
    if(ret+1) return ret;
    
    int stPath = go(pos+1, k);
    if(str[pos] == '?') stPath = mul(stPath, 3);
    
    int ndPath = 0;
    
    if(k == 0){
        if(str[pos] == 'a') ndPath += go(pos+1, k+1);
    }
    else if(k == 1){
        if(str[pos] == 'b') ndPath += go(pos+1, k+1);
    }
    else if(k == 2){
        if(str[pos] == 'c') ndPath += go(pos+1, k+1);
    }
    
    if(k < 3 && str[pos] == '?') ndPath += go(pos+1, k+1);
    
    return ret = add(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> str;
    
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
