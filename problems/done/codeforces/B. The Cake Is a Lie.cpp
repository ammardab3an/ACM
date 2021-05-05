// Problem: B. The Cake Is a Lie
// Contest: Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1519/problem/B
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m, k;
bool mem[101][101][10010];
bool vis[101][101][10010];

bool go(int i, int j, int k){
    
    if(k < 0) return 0;
    if(i == n && j == m) return !k;
    if(i > n || j > m) return 0;
    
    if(vis[i][j][k]) return mem[i][j][k];
    vis[i][j][k] = true;
    
    bool stPath = go(i+1, j, k-j);
    bool ndPath = go(i, j+1, k-i);
    
    return mem[i][j][k] = stPath || ndPath;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        cin >> n >> m >> k;
        memset(vis, 0, sizeof vis);
        cout << (go(1, 1, k) ? "YES" : "NO") << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
