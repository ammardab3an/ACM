// Problem: C - Comma
// Contest: AtCoder - Panasonic Programming Contest (AtCoder Beginner Contest 195)
// URL: https://atcoder.jp/contests/abc195/tasks/abc195_c
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    lli num;
    cin >> num;
    
    
    lli ans = 0;
    
    lli low = 0, high = 999;
    
    int i = 1;
    
    while(true){
        
        low = high;
        high = 1ll * (low+1) * 1000 - 1;
        
        if(high > num) break;
        
        ans += (high - low) * i++;
    }
    
    if(low < num){
        ans += (num - low) * i++;
    }
    
    cout << ans << endl;
}
