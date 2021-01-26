
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
const int NMAX = 1e6 + 10;
const int MMAX = 2e5 + 10;

bool primes[NMAX];
int ans[NMAX];

void go(){
    memset(primes, 1, sizeof primes);
    primes[0] = primes[1] = 0;
    for(lli i = 2; i < NMAX; i++) if(primes[i]){
        for(lli j = i*i; j < NMAX; j += i) {
            primes[j] = false;
        }
    }
}

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    go();

    for(int i = 2; i < NMAX; i++) {
        ans[i] = ans[i-1] + (primes[i] && primes[i-2]);
    }

    int t; cin >> t; while(t--){

     int n;
     cin >> n;

     cout << ans[n] << endl;
    }
}
