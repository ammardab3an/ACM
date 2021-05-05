// Problem: F. Subsequences of Length Two
// Contest: Codeforces - Codeforces Round #667 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1409/F
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, k;
char s[222], t[2];
int mem[222][222][222];

int go(int i, int num, int k){
    
    if(i == n) return 0;
    
    int &ret = mem[i][num][k];
    if(ret+1) return ret;
    
    int ans = 0;

    ans = go(i+1, num + (s[i] == t[0]), k) + (s[i] == t[1]) * num;
    
    if(k){
        
        int stPath = go(i+1, num+1, k-1) + (t[0] == t[1]) * num;
        int ndPath = go(i+1, num, k-1) + num;
        
        ans = max(ans, max(stPath, ndPath));
    }
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> k;
    cin >> s >> t;
    
    memset(mem, -1, sizeof mem);
    
    cout << go(0, 0, k) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
