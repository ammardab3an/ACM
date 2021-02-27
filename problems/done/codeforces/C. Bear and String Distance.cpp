// Problem: C. Bear and String Distance
// Contest: Codeforces - Educational Codeforces Round 8
// URL: https://codeforces.com/problemset/problem/628/C
// Memory Limit: 256 MB
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

    int n, k;
    cin >> n >> k;
    
    string str;
    cin >> str;
    
    int rem = k;
    
    string ans = str;
    
    for(int i = 0; i < n; i++) {
        
        int cmx = max(str[i] - 'a', 'z' - str[i]);
        int dir = (vi){+1, -1}[str[i] - 'a' > 'z' - str[i]];
        
        ans[i] += dir * min(cmx, rem);
        
        rem = max(0, rem - cmx);
    }
    
    cout << (rem ? "-1" : ans) << endl;

}
