// Problem: A. Learning Languages
// Contest: Codeforces - Codeforces Round #170 (Div. 1)
// URL: https://codeforces.com/contest/277/problem/A
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

int n, k;
vi adj[222];
bool vis[222];

void dfs(int nd){
    vis[nd] = true;
    for(auto nxt : adj[nd]) if(!vis[nxt]){
        dfs(nxt);
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> k;
    
    int ans = 0;
    int cnt = 0;
    
    for(int i = 1; i <= n; i++){
        
        int m;
        cin >> m;
        
        int u = i + k;
            
        if(!m) cnt++;    
        
        for(int j = 0; j < m; j++){

            int v;
            cin >> v;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    
    for(int i = 1; i <= k; i++){
        if(!vis[i] && !adj[i].empty()){
            ans++;
            dfs(i);
        }
    }
    
    ans += cnt;
    
    if(cnt != n){
        ans--;
    }
    
    cout << ans << endl;
}
