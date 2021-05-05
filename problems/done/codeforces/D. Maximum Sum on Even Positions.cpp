// Problem: D. Maximum Sum on Even Positions
// Contest: Codeforces - Educational Codeforces Round 90 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1373/D
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

int n;
int arr[NMAX];
int mem[NMAX][3][2];
int vis[NMAX][3][2], vid;

int go(int i, int k, int p){
    
    if(!p) if((i == n-1) && (k == 1)) return -INF;
    if(p) if((i >= n) && (k == 1)) return -INF;
    
    if(i >= n) return 0;
    
    if(vis[i][k][p] == vid) return mem[i][k][p];
    vis[i][k][p] = vid;
    
    int ans = 0;
    
    if(k == 0){
        int stPath = arr[i] + go(i+2, 0, 0);
        int ndPath = arr[i] + go(i+1, 1, 0);
        int rdPath = arr[i] + go(i+3, 1, 1);
        ans = max(stPath, max(ndPath, rdPath));
    }
    
    else if(k == 1){
        int stPath = arr[i] + go(i+2, 1, p);
        int ndPath = arr[i] + go(i+1 + (!p * 2), 2, 0);
        ans = max(stPath, ndPath);
    }
    
    else {
        int stPath = arr[i] + go(i+2, 2, 0);
        ans = stPath;
    }
    
    return mem[i][k][p] = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        vid++;
        cout << max(go(0, 0, 0), go(1, 1, 1)) << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
