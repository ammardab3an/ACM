#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll int64_t

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
ll t , n , q ,a[MAX] , ans , cnt ;

int32_t main(){

    fastIO;

    freopen("sub.in", "r", stdin);

        cin >> t; while(t--){

            cin >> n >> q ;
            ans = 0 ;

            for ( int i = 0 ; i < n ; i ++ )
            cin >> a[i];
            sort ( a , a+n ) ;

            vector<int> sm(n);

            sm[0] = a[0];
            for(int i = 1; i < n; i++) sm[i] = sm[i-1] + a[i];

            for(int i = n-1; i >= 0; i--){

                int l = i;
                int r = i;

                ans = max(ans, a[i]);

                if(abs(q-a[i]) > a[i]){
                    r = 0;
                }
                else{
                    r = lower_bound(a, a+i+1, abs(q-a[i])) - a;
                    if(r == i+1) continue;
                }


                ll csm = sm[i];

                if(r) csm -= sm[r-1];

                ans = max(ans, csm);
            }

            cout << ans << '\n' ;
    }
}
