
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
int clk, cnt;
bool vist[NMAX];
int tin[NMAX], low[NMAX];

void dfs(int nd, int par){

    vist[nd] = true;
    tin[nd] = low[nd] = clk++;

    int children = 0;

    for(auto nxt : adj[nd]) if(nxt != par){
        if(vist[nxt]){
            low[nd] = min(low[nd], tin[nxt]);
        }
        else{
            dfs(nxt, nd);
            low[nd] = min(low[nd], low[nxt]);
            if(low[nxt] >= tin[nd] && par != -1){
                cnt++;
            }
            children++;
        }
    }

    if(par == -1 && children > 1) cnt++;
}
int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    while(cin >> n >> m, n, m){

        for(int i = 0; i < n; i++) adj[i].clear();

        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v; u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        clk = 0;
        cnt = 0;

        memset(vist, 0, sizeof vist);

        dfs(0, -1);

        cout << cnt << endl;
    }
}
