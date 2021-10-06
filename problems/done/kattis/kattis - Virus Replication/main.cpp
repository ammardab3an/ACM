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


    string str0, str1;
    cin >> str0 >> str1;

    int sz0(str0.size()), sz1(str1.size());

    int i = 0;
    int j0 = sz0-1;
    int j1 = sz1-1;

    while(j0 >= 0 && j1 >= 0){
        if(str0[j0] != str1[j1]) break;
        j0--, j1--;
    }

    while(i < sz0 && i < sz1){
        if(str0[i] != str1[i]) break;
        i++;
    }

    cout << j1-i+1 << endl;
}
