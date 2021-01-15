
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


        freopen("check.in", "r", stdin);

    int t; cin >> t; while(t--){

        int n; cin >> n;

        int p[2] = {0, 0};

        int foo = 7  * int(n/30);
        int tot = 14 * int(n/30);

        for(int i = 1; i <= (n%30); i++){

            p[i&1] += (i%3 == 0) | (i%5 ==0) | (i%15 == 0);
        }

        double dans = double(foo + p[1]) / double(tot + p[0]+p[1]);

     //   cout << p[1] << ' ' << p[0] << endl;
        cout << fixed << setprecision(2) << dans << endl;
    }

}
