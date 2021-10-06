// Problem: F. Maximum White Subtree
// Contest: Codeforces - Codeforces Round #627 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1324/F
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
int col[NMAX];
int ans[NMAX];
int mem[NMAX];
vi adj[NMAX];

int dfs0(int nd, int par=-1){
    
    mem[nd] = col[nd];
    
    for(auto nxt : adj[nd]) if(nxt != par){
        int tmp = dfs0(nxt, nd);
        if(tmp > 0) mem[nd] += tmp;
    }
    
    return mem[nd];
}

void dfs1(int nd, int par=-1){
    
    ans[nd] = mem[nd];
    
    for(auto nxt : adj[nd]) if(nxt != par){
        
        if(mem[nxt] > 0) mem[nd] -= mem[nxt];
        if(mem[nd] > 0) mem[nxt] += mem[nd];
        
        dfs1(nxt, nd);
        
        if(mem[nd] > 0) mem[nxt] -= mem[nd];
        if(mem[nxt] > 0) mem[nd] += mem[nxt];
    }    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    for(int i = 0; i < n; i++){
        int ci; cin >> ci; col[i] = ci ? 1 : -1;
    }
    
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs0(0);
    dfs1(0);
    
    for(int i = 0; i < n; i++) cout << ans[i] << ' '; cout << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
