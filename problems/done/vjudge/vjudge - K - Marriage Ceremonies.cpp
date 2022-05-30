// Problem: K - Marriage Ceremonies
// Contest: Virtual Judge - Dp 2
// URL: https://vjudge.net/contest/432549#problem/K
// Memory Limit: 65 MB
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
int arr[20][20];
int mem[20][1 << 16];

int go(int i, int msk){
    
    if(i == n) return 0;
    
    int &ret = mem[i][msk];
    if(ret+1) return ret;
    
    int ans = 0;
    for(int j = 0; j < n; j++) if(!(msk & (1 << j))){
        ans = max(ans, arr[i][j] + go(i+1, msk | (1 << j)));
    }
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int tt = 1;
    int t; cin >> t; while(t--){
        
        cin >> n;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> arr[i][j];
        
        memset(mem, -1, sizeof mem);
        
        cout << "Case " << tt++ << ": ";
        cout << go(0, 0) << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
