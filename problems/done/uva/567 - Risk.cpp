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
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

vector<pii> edges;

int floyd(int src, int des){

    int dist[22][22];
    memset(dist, INF, sizeof dist);

    for(auto ed : edges){
        dist[ed.first][ed.second] = 1;
        dist[ed.second][ed.first] = 1;
    }

    for(int k = 1; k <= 20; k++)
    for(int i = 1; i <= 20; i++)
    for(int j = 1; j <= 20; j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    return dist[src][des];
}
int bellman(int src, int des){

    int dist[22];
    memset(dist, INF, sizeof dist);

    dist[src] = 0;

    for(int i = 0; i < 20-1; i++){
        for(auto ed : edges){
            if(dist[ed.first] < INF){
                dist[ed.second] = min(dist[ed.second], dist[ed.first] + 1);
            }
            if(dist[ed.second] < INF){
                dist[ed.first] = min(dist[ed.first], dist[ed.second] + 1);
            }
        }
    }

    return dist[des];
}
int32_t main(){

    //fastIO;

#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif

    int fo, tt(1);
    while(cin >> fo){

        edges.clear();
        //adj[1].clear();
        while(fo--){
            int nd; cin >> nd; edges.push_back({1, nd}); //adj[1].push_back(nd);
        }

        for(int i = 2; i <= 19; i++){
            //adj[i].clear();
            int n; cin >> n; while(n--){
                int nd; cin >> nd; edges.push_back({i, nd}); //adj[i].push_back(nd);
            }
        }

//        for(auto ed : edges) cout << ed.first << ' ' << ed.second << endl;

        printf("Test Set #%d\n", tt++);

        int q; cin >> q; while(q--){

            int src, des; cin >> src >> des;
            printf("%2d to %2d: %d\n", src, des, bellman(src, des));

        }

        cout << endl;
    }
}
