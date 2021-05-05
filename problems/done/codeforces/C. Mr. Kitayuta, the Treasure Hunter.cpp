// Problem: C. Mr. Kitayuta, the Treasure Hunter
// Contest: Codeforces - Codeforces Round #286 (Div. 2)
// URL: https://codeforces.com/problemset/problem/505/C
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

// #define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

int n, d;
int arr[30030];
int mem[30030][250*2];

int go(int i, int l){
    
    if(i <= 0 || i >= 30010) return 0;
    
    int &ret = mem[i][l-(d-250)];
    if(ret+1) return ret;
    
    int stPath = l-1 > 0 ? go(i+l-1, l-1) : 0;
    int ndPath =  l  > 0 ? go(i+l, l) : 0;
    int rdPath = l+1 > 0 ? go(i+l+1, l+1) : 0;
    
    return ret = arr[i] + max({stPath, ndPath, rdPath});
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> d;
    
    for(int i = 0; i < n; i++){
        int pi;
        cin >> pi;
        arr[pi]++;
    }
    
    memset(mem, -1, sizeof mem);
    
    cout << go(d, d) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
