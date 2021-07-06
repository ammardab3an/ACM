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

    //int t; cin >> t; while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int Ans = 0;
        int zng = 0, nig = 0;
        char vowels[] = {'a', 'i', 'o', 'u', 'e', 'y'};
        for (char c : s) {
            int con = 0;
            for (char vowel : vowels) {
                if (c == vowel) {
                    zng = 1;
                    con = 1;
                }
            }
            if (!con) nig = 1;
            if (zng && nig) {
                zng = 0, nig = 0;
                Ans++;
            }
        }
        cout << Ans << endl;

    //}

}