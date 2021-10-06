
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
int busy[NMAX];
lli dist[NMAX];
iii edges[MMAX];

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int tt = 1;

    while(cin >> n){

        for(int i = 1; i <= n; i++)
            cin >> busy[i];

        cin >> m;
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            edges[i] = {pow(busy[v]-busy[u], 3), {u, v}};
        }

        dist[1] = 0;
        for(int i = 2; i <= n; i++) dist[i] = INF;

        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < m; j++){

                int c = edges[j].first;
                int u = edges[j].second.first;
                int v = edges[j].second.second;

                if(dist[u] == INF) continue;

                if(dist[v] > dist[u] + c){
                    dist[v] = dist[u] + c;
                }
            }
        }

        for(int j = 0; j < m; j++){

            int c = edges[j].first;
            int u = edges[j].second.first;
            int v = edges[j].second.second;

            if(dist[u] == INF) continue;

            if(dist[v] > dist[u] + c){
                dist[v] = -INF;
            }
        }

        cout << "Set #" << tt++ << endl;

        int q; cin >> q; while(q--){

            int v;
            cin >> v;

            // cout << neg << ' ' << dist[v] << endl;

            if(dist[v] < 3 || dist[v] == INF)
                cout << "?" << endl;
            else
                cout << dist[v] << endl;
        }
    }
}
