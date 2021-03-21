// Problem: C. Number of Segments with Small Sum
// Contest: Codeforces - ITMO Academy: pilot course - Two Pointers Method - Step 2
// URL: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/C
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    lli n, s;
    cin >> n >> s;
    
    vl vec(n);
    for(auto &i : vec) cin >> i;
    
    lli ans = 0;
    
    int j = 0;
    lli sum = 0;
    for(int i = 0; i < n; i++){
        sum += vec[i];
        while(sum > s) sum -= vec[j++];
        ans += (i-j+1);
    }
    
    cout << ans << endl;
}
