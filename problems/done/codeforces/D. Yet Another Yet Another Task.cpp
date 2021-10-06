// Problem: D. Yet Another Yet Another Task
// Contest: Codeforces - Educational Codeforces Round 88 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1359/problem/D
// Memory Limit: 512 MB
// Time Limit: 1500 ms
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

    int n;
    cin >> n;
    
    vector<int> vec(n);
    for(int &i : vec) cin >> i;
    
    int ans = 0;
    
    for(int mx = 0; mx <= 30; mx++){
        
        int bst_sum = 0;
        int cur_sum = 0;
        
        for(int i = 0; i < n; i++){
            
            int ai = vec[i] > mx ? -INF : vec[i];
            
            cur_sum = max(0, cur_sum + ai);
            bst_sum = max(bst_sum, cur_sum);
        }
        
        ans = max(ans, bst_sum - mx);
    }
    
    cout << ans << endl;
}
