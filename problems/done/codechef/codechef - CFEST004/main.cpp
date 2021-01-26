
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

const int NMAX = 1e3 + 10;

int n, m;
int grid[NMAX][NMAX];
int dist[NMAX][NMAX];

pii mvArr[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool in(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m;
}

int dij(){

    memset(dist, INF, sizeof dist);
    dist[0][0] = 0;

    #define Pair pair<int, pii>
    priority_queue< Pair, vector<Pair>, greater<Pair> > que;
    que.push({0, {0, 0}});

    while(!que.empty()){

        auto tp = que.top(); que.pop();

        int cd = tp.first;
        int ci = tp.second.first;
        int cj = tp.second.second;

        if(dist[ci][cj] < cd) continue;

        if(ci == n-1 && cj == m-1) return cd;

        for(auto p : mvArr){

            int ni = ci + p.first;
            int nj = cj + p.second;

            if(!in(ni, nj)) continue;

            int nd = max(cd, grid[ni][nj]);

            if(dist[ni][nj] > nd){
                dist[ni][nj] = nd;
                que.push({nd, {ni, nj}});
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

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> grid[i][j];

    int ans = dij();

    cout << ans << endl;
}
