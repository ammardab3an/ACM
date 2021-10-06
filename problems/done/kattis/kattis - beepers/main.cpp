
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

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        int n, m, bi, bj, k;
        cin >> n >> m >> bi >> bj >> k;

        vpii vec(k);
        for(auto &p : vec)
            cin >> p.first >> p.second;

        vi tmp(k);
        for(int i = 0; i < k; i++) tmp[i] = i;

        auto dist = [](pii p0, pii p1){
            return abs(p0.first - p1.first) + abs(p0.second - p1.second);
        };

        int ans = INF;

        do{
            int cans = 0;

            cans += dist({bi, bj}, vec[tmp[0]]);
            for(int i = 0; i+1 < k; i++)
                cans += dist(vec[tmp[i]], vec[tmp[i+1]]);
            cans += dist(vec[tmp[k-1]], {bi, bj});

            ans = min(ans, cans);

        } while(next_permutation(tmp.begin(), tmp.end()));

        cout << ans << endl;
    }
}
