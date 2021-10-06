// Problem: F. Useful Edges
// Contest: Codeforces - Codeforces Round #709 (Div. 2, based on Technocup 2021 Final Round)
// URL: https://codeforces.com/contest/1484/problem/F
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n, m;
    cin >> n >> m;
    
    vector<vi> dist(n, vi(n, INFLL)), mdist(n, vi(n));
    for(int i = 0; i < n; i++) dist[i][i] = 0;
    
    vector<vector<iii> > adj(n);
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c; u--, v--;
        adj[u].emplace_back(i, (pii){v, c});
        adj[v].emplace_back(i, (pii){u, c});
        dist[u][v] = dist[v][u] = c;
    }
    
    int q; cin >> q; while(q--){
        int u, v, l;
        cin >> u >> v >> l; u--, v--;
        mdist[u][v] = mdist[v][u] = l;
    }
    
    for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    
    for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        mdist[i][j] = max(mdist[i][j], mdist[i][k] - dist[k][j]);
    }
       
    vi ans(m);
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        
        for(auto edge : adj[j]){
            if(dist[i][j] + edge.second.second <= mdist[i][edge.second.first])
                ans[edge.first] = true;
        }
    }
    
    cout << accumulate(ans.begin(), ans.end(), 0);
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
