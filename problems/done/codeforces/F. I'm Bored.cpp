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
        int a[26];
        for (int i=0;i<26;i++)
            cin >> a[i];
        sort (a, a + 26);
        reverse(a, a + 26);
        int mn = 1e9;
        if (a[0] == 0) mn = 0;
        int mx = 0;
        for (int i=0;i<26;i++){
            if (a[i] >= 2){
                mx += 2;
                mn = min(mn, a[i] / 2);
            }
            else if (a[i] == 1) {
                mx += 1;
                int cnt = 0;
                for (int j =i; j<26;j++)
                    cnt += (a[j] == 1);
                mn = min(cnt, mn);
                break;
            }
        }
        cout << mx << " " << mn << endl;

    }

}