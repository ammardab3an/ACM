
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

int n;
char str[NMAX];
int one[NMAX], zero[NMAX];

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        cin >> n >> str;

        one[0] = str[0] == '1';
        for(int i = 1; i < n; i++){
            one[i] = one[i-1] + (str[i] == '1');
        }

        zero[n-1] = str[n-1] == '0';
        for(int i = n-2; i >= 0; i--){
            zero[i] = zero[i+1] + (str[i] == '0');
        }

        int ans = min(one[n-1], zero[0]);

        for(int i = 0; i+1 < n; i++){
            int cans = one[i] + zero[i+1];
            ans = min(ans, cans);
        }

        cout << ans << endl;
    }
}
