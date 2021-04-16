// Problem: F - Queries for Number of Palindromes
// Contest: Virtual Judge - Dp 2
// URL: https://vjudge.net/contest/432549#problem/F
// Memory Limit: 262 MB
// Time Limit: 5000 ms
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
const int NMAX = 5e3 + 10;
const int MMAX = 2e5 + 10;

int n;
char str[NMAX];
bool good[NMAX][NMAX];
int mem[NMAX][NMAX];

int go(int l, int r){
    
    if(l > r) return 0;
    
    int &ret = mem[l][r];
    if(ret + 1) return ret;
    
    return ret = go(l+1, r) + go(l, r-1) - go(l+1, r-1) + good[l][r];
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> str;
    n = strlen(str);
    
    memset(mem, -1, sizeof mem);
    
    for(int i = 0; i < n; i++){
        
        int l = i;
        int r = i;
        
        while(l >= 0 && r < n && (str[l] == str[r])){
            good[l][r] = 1;
            l--, r++;
        } 
        
        l = i;
        r = i+1;
        while(l >= 0 && r < n && (str[l] == str[r])){
            good[l][r] = 1;
            l--, r++;
        } 
    }
    
    int q; cin >> q; while(q--){
        int l, r;
        cin >> l >> r;
        cout << go(l-1, r-1) << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
