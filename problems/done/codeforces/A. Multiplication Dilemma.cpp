#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second

#define endl '\n'

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
ll a,b , ans ;

void pri ( ll x , ll y ){
    cout << x << " x " << y;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL


    int t; cin >> t; while(t--){
        int a, b;
        cin >> a >> b;
        if (a < 0 && b < 0)
            a = -a, b = -b;
        bool ok = 0;
        if (1ll * a * b < 0 ) ok =1;
        a = abs(a);
        b = abs(b);
        if (a % 10 == 0) swap(a, b);
        int x = 1;
        while (a) {
            if (x == 1 && ok == 1) cout << '-';
            cout << (a % 10) * x << " x " << b;
            a /= 10;
            if (a)
                cout << (ok == 0 ? " + " : " - ");
            x *= 10;
        }
        cout << endl;
    }

}