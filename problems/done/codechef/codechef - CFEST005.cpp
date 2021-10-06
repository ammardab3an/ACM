
// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

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

int n;
int arr[2][NMAX];
int mem[2][NMAX];

int go(int pos, int k){

    if(pos == n)
        return 0;

    int &ret = mem[k][pos];
    if(~ret) return ret;

    int stPath = go(pos+1, 0);
    int ndPath = go(pos+1, 1);
    int rdPath = go(pos+1, !k) + arr[k][pos];

    return ret = max({stPath, ndPath, rdPath});
}

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    while(cin >> n){

        for(int k = 0; k < 2; k++)
        for(int i = 0; i < n; i++) cin >> arr[k][i];

        memset(mem, -1, sizeof mem);

        int stPath = go(0, 0);
        int ndPath = go(0, 1);

        cout << max(stPath, ndPath) << endl;
    }
}
