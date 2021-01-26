
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
int vist[NMAX][NMAX];

pii mvArr[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool in(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m;
}

bool go(int i, int j, int mx){

    if(i == n-1 && j == m-1){
        return true;
    }

    vist[i][j] = true;

    for(auto p : mvArr){

        int ni = i + p.first;
        int nj = j + p.second;

        if(in(ni, nj) && !vist[ni][nj] && grid[ni][nj] <= mx){

            if(go(ni, nj, mx)){
                vist[i][j] = false;
                return true;
            }
        }
    }

    vist[i][j] = false;

    return false;
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

    int l = 0;
    int r = 1e9 + 10;

    int ans = INF;

    while(l <= r){

        int m = (l+r)/2;

        if(go(0, 0, m)){
            ans = m;
            r = m-1;
        }
        else{
            l = m+1;
        }
    }

    cout << ans << endl;
}
