
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

/*
 Password must contain at least one lower case letter [a−z];

2) Password must contain at least one upper case letter [A−Z] strictly inside, i.e. not as the first or the last character;

3) Password must contain at least one digit [0−9] strictly inside;

4) Password must contain at least one special character from the set { '@', '#', '%', '&', '?' } strictly inside;

10
*/

int32_t main() {

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t;
    cin >> t;
    while(t--) {
        string pass;
        cin >> pass;

        int cnt = 0;

        if(pass.size() >= 10) {
            cnt++;
        }

        for(auto c : pass) if(c >= 'a' && c <= 'z') {
            cnt++;
            break;
        }

        for(int i = 1; i+1 < pass.size(); i++) {
            char c = pass[i];
            if(c >= 'A' && c <= 'Z') {
                cnt++;
                break;
            }
        }

        for(int i = 1; i+1 < pass.size(); i++) {
            char c = pass[i];
            if(c >= '0' && c <= '9') {
                cnt++;
                break;
            }
        }

        // { '@', '#', '%', '&', '?' }

        map<char, bool> mp;
        for(auto c : {
                    '@', '#', '%', '&', '?'
                }) mp[c] = 1;

        for(int i = 1; i+1 < pass.size(); i++) {
            char c = pass[i];
            if(mp[c]) {
                cnt++;
                break;
            }
        }

        cout << (cnt == 5 ? "YES" : "NO") << endl;
    }

}
