
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

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        int n, k;
        cin >> n >> k;

        vector<int> vec(n);
        for(auto &i : vec) cin >> i;

        vector<int> div_vec(1e6, 0);
        map<int, int> div_mp;

        int ans = -1;

        for(int i : vec){

            for(int j = 1; j*j <= i; j++) if(i%j==0){

                if(j < 1e6) {
                    div_vec[j]++;
                    if(div_vec[j] >= k) ans = max(ans, j);
                }
                else{
                    div_mp[j]++;
                    if(div_mp[j] >= k) ans = max(ans, j);
                }

                if(j != i/j){
                    int jj = i/j;
                    if(jj < 1e6) {
                        div_vec[jj]++;
                        if(div_vec[jj] >= k) ans = max(ans, jj);
                    }
                    else {
                        div_mp[jj]++;
                        if(div_mp[jj] >= k) ans = max(ans, jj);
                    }
                }
            }
        }

        cout << ans << endl;
    }
}

