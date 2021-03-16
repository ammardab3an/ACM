// Problem: 558 - Wormholes
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499
// Memory Limit: 32 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t

typedef unsigned int		uint;
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
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m;
iii edges[MMAX];
int dist[NMAX];

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int u, v, c;
            cin >> u >> v >> c;
            edges[i] = {c, {u, v}};
        }

        memset(dist, INF, sizeof dist);

        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < m; j++){

                int u = edges[j].second.first;
                int v = edges[j].second.second;
                int c = edges[j].first;

                if(dist[v] > dist[u] + c){
                    dist[v] = dist[u] + c;
                }
            }
        }

        bool neg = false;
        for(int j = 0; j < m; j++){

            int u = edges[j].second.first;
            int v = edges[j].second.second;
            int c = edges[j].first;

            if(dist[v] > dist[u] + c){
                neg = true;
                break;
            }
        }

        cout << ( neg ? "possible" : "not possible" ) << endl;

    }
}