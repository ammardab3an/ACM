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
const double EPS = 1e-9;

const int MAX = 2e5 + 10;


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int t; cin >> t; while(t--){

        long double a, b, c, x;
        cin >> a >> b >> c >> x;

        long double ans = sqrt((b+c+c) * (b+c+c) + (a*a));
        long double ans2 = sqrt(a*a + b*b) * x / 100.0;
        long double z1 = (1.0 - x / 100.0) * a;
        long double z2 = (c+c) +(1.0-x/100.0) *b;
        long double ans3 = sqrt(z1*z1 + z2*z2);

        long double anss = ans + ans2 + ans3;

//        cout << ans << ' ' << ans2 << ' ' << z1 << ' ' << z2 << ' ' << ans3 << endl;

        cout << fixed << setprecision(9) << anss << '\n';
    }

}