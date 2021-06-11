// Problem: B. Anany in the Army
// Contest: Codeforces - ECPC 2019 Kickoff
// URL: https://codeforces.com/gym/102881/problem/B
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second

using namespace std;

typedef unsigned long long  ull;
typedef long long int       ll;
typedef long double         ld;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<ll, ll>        pll;
typedef pair<ll, pll>       lll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<pii>         vpii;

const int OO = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int pi = acos(-1);
const ld EPS = 1e-9;

const int MAX = 2e5 + 10;
ld a[5] , k ;

ld triangleArea3sides(ld a, ld b, ld c) {
	if ( max({a,b,c})*2 > a+b+c )
        return 0 ;
	ld s=((a + b + c) / 2);
	return sqrt(s) * sqrt(s - a) * sqrt(s - b) * sqrt(s - c) ;
}

ld ts(ld x, ld y, ld z)
{
        ld lo = z, hi = min(z + k, x + y);
        for (int i = 0; i < 100; i++ )
        {
                ld mid = (hi - lo) / 3.0;
                if (triangleArea3sides(x, y, lo + mid) > triangleArea3sides(x, y, hi - mid))
                        hi -= mid;
                else
                        lo += mid;
        }
        return triangleArea3sides(x, y, lo);
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("sticks.in", "r", stdin);

    int t; cin >> t; while(t--){
        for ( int i = 0 ; i < 3 ; i++ )
            cin >> a[i] ;
        cin >> k ;
        sort ( a , a+3 ) ;
        ld ans = 0 ;
        ans = max ( ans , ts(a[2] , a[1] , a[0] ) ) ;
        ans = max ( ans , ts(a[2] , a[0] , a[1] ) ) ;
        ans = max ( ans , ts(a[0] , a[1] , a[2] ) ) ;

        cout << fixed << setprecision(12) << ans << "\n" ;
    }

}