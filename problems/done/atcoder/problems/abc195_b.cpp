// Problem: B - Many Oranges
// Contest: AtCoder - Panasonic Programming Contest (AtCoder Beginner Contest 195)
// URL: https://atcoder.jp/contests/abc195/tasks/abc195_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


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


inline pii merge(pii a, pii b){
    return {min(a.first, b.first), max(a.second, b.second)};
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int a, b, w;
    cin >> a >> b >> w;
    w *= 1000;
    
    pii ans = {INF, -INF};
    
    for(int i = 1; i <= 1e6; i++){
        if(i*a <= w && w <= i*b){
            ans = merge(ans, {i, i});
        }
    }
    
    if(ans.first == INF)
        cout << "UNSATISFIABLE" << endl;
    else
        cout << ans.first << ' ' << ans.second << endl;
}
