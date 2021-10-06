// Problem: D. Dima and Hares
// Contest: Codeforces - Codeforces Round #208 (Div. 2)
// URL: https://codeforces.com/problemset/problem/358/D
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

const int NMAX = 3e3 + 10;

int n;
int a[NMAX];
int b[NMAX];
int c[NMAX];

int mem[NMAX][2];

int go(int i, int p){
    
    if(i == n-1){
        return p ? b[i] : a[i];
    }
    
    int &ret = mem[i][p];
    if(ret+1) return ret;
    
    int ans = 0;
    
    if(p){
        
        int stPath = b[i] + go(i+1, 1);
        int ndPath = c[i] + go(i+1, 0);
        
        ans = max(stPath, ndPath);
    }
    else{
        
        int stPath = a[i] + go(i+1, 1);
        int ndPath = b[i] + go(i+1, 0);
        
        ans = max(stPath, ndPath);
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
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    
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
