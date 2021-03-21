// Problem: Easy Dijkstra Problem
// Contest: SPOJ - Tutorial
// URL: https://www.spoj.com/problems/EZDIJKST/
// Memory Limit: 1536 MB
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

int n, m;
vector<pii> adj[10100];
int dis[10100];

int dij(int u, int v){
    
     for(int i = 1; i <= n; i++) dis[i] = INF;
     
     dis[u] = 0;
     priority_queue<pii> que;
     que.push({0, u});
     
     while(!que.empty()){
         
         pii tp = que.top(); que.pop();
         
         int cnd = tp.second;
         int cw = -1 * tp.first;
         
         if(dis[cnd] < cw) continue;
         
         if(cnd == v) return cw;
         
         for(auto nxt : adj[cnd]){
             
             int nxt_nd = nxt.second;
             int nxt_dis = cw + nxt.first;
             
             if(dis[nxt_nd] > nxt_dis){
                 
                 dis[nxt_nd] = nxt_dis;
                 que.push({-1 * nxt_dis, nxt_nd});
             }
         }
     }
     
     return -1;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        cin >> n >> m;
        
        for(int i = 1; i <= n; i++) adj[i].clear();
        
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({w, v});
        }
        
        int u, v;
        cin >> u >> v;
        
        int dis = dij(u, v);
        
        if(dis == -1){
            cout << "NO" << endl;
        }
        else{
            cout << dis << endl;
        }
    }	
}
