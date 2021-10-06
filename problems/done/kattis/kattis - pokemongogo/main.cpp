
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

//#define endl '\n'
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

int dist[22][1 << 22];

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n;
    cin >> n;

    vector<vi> vec;
    vector<pii> tranCor;
    map<string, int> tranName;

    int cntName(0), cntCor(1);
    tranCor.push_back({0, 0});

    for(int i = 0; i < n; i++){

        int x, y;
        string name;
        cin >> x >> y >> name;

        if(!tranName[name]){
            tranName[name] = ++cntName;
        }

        vec.resize(cntName);
        tranCor.resize(cntCor+1);

        tranCor[cntCor++] = {x, y};
        vec[tranName[name]-1].push_back(cntCor-1);
    }

    auto calcDist = [](pii p0, pii p1){
        return abs(p0.first - p1.first) + abs(p0.second - p1.second);
    };

    #define Pair iii
    priority_queue<Pair, vector<Pair>, greater<Pair> > que;
    memset(dist, INF, sizeof dist);
    dist[0][0] = 0;
    que.push({0, {0, 0}});

    int ans = -1;

    while(!que.empty()){

        auto tp = que.top(); que.pop();

        int cc = tp.first;
        int cnd = tp.second.first;
        int cmsk = tp.second.second;

        if(dist[cnd][cmsk] < cc) continue;

        if(cmsk == ((1 << cntName) -1)){
            ans = cc + calcDist({0, 0}, tranCor[cnd]);
            break;
        }

        for(int i = 0; i < cntName; i++) if(!(cmsk & (1 << i))){

            for(auto nxt : vec[i]){

                int nxtMsk = cmsk | (1 << i);
                int nxtDis = cc + calcDist(tranCor[cnd], tranCor[nxt]);

                if(dist[nxt][nxtMsk] > nxtDis){
                    dist[nxt][nxtMsk] = nxtDis;
                    que.push({nxtDis, {nxt, nxtMsk}});
                }
            }
        }
    }

    assert(~ans);

    cout << ans << endl;
}
