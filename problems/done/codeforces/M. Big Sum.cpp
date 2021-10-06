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
ll power(long long x, unsigned int y, int p = 1e9 + 7) {
    ll res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
                // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

const int OO = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int pi = acos(-1);
const double EPS = 1e-9;

const int MAX = 2e5 + 10;

int modInverse(int a, int m)
{
    int g = __gcd(a, m);
    if (g != 1)
        return -1;
    else
    {
        // If a and m are relatively prime, then modulo
        // inverse is a^(m-2) mode m
        return power(a, m - 2, m);
    }
}


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int t; cin >> t; while(t--){

        int i1, i2, j1, j2;
        cin >> i1 >> i2 >> j1 >> j2;

        if (i1 > i2)swap(i1, i2);
        if (j1 > j2)swap(j1, j2);

        ll x = power(2 , i1);
        ll y = power(2, i2 - i1 + 1);

        int MOD = 1e9 + 7;

        x *= (y - 1);
        x %= MOD;
        x *= power(3, j1);
        x %= MOD;

        int tmp = power(3, j2-j1+1)-1;
        x = (((x*tmp)%MOD ) * modInverse(2, MOD))%MOD;

        cout << x << endl;

    }

}