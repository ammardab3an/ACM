// Problem: Q - Flowers
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_q
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
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

int n;
int arr[2][NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[0][i];
    for(int i = 0; i < n; i++) cin >> arr[1][i];
    
    int sz = 1;
    while(sz <= n) sz <<= 1;

    vi seg(2 * sz);
    
    // here instead of using an array for memoization, we are going to use a segment tree, so we can do fast nlogn queries on it.
    
    for(int i = 0; i < n; i++){
        
        int mx = 0;
        
        // quering from the segment tree
        int l = sz + 0;
        int r = sz + arr[0][i];
        for(;l < r; l /= 2, r /= 2){
            if(l&1) mx = max(mx, seg[l++]);
            if(r&1) mx = max(mx, seg[--r]);
        }
        
        // update segment tree
        int p = arr[0][i];
        for(seg[p += sz] = mx + arr[1][i]; p > 1; p /= 2) 
            seg[p/2] = max(seg[p], seg[p^1]);
            
    } 
    
    int ans = 0;
    
    int l = sz + 0;
    int r = sz + sz;
    for(;l < r; l /= 2, r /= 2){
        if(l&1) ans = max(ans, seg[l++]);
        if(r&1) ans = max(ans, seg[--r]);
    }
    
    cout << ans << endl;
}
