// Problem: E. Cyclic Components
// Contest: Codeforces - Codeforces Round #479 (Div. 3)
// URL: https://codeforces.com/problemset/problem/977/E
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

int n, m;
vi adj[NMAX];
int deg[NMAX];
bool vis[NMAX];
vi vec;


void go(int nd){
    vec.push_back(nd);
    vis[nd] = true;
    for(auto nxt : adj[nd]) if(!vis[nxt]) go(nxt);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++) if(!vis[i]){
        
        vec.clear(); go(i);
        
        bool good = true;
        for(int nd : vec) good &= deg[nd] == 2;
        
        ans += good;
    }
    
    cout << ans << endl;
}
