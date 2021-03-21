// Problem: C. Playlist
// Contest: Codeforces - Educational Codeforces Round 62 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1140/C
// Memory Limit: 256 MB
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

const int NMAX = 3e5 + 10;

pii arr[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n, k;
    cin >> n >> k;
 
    for(int i = 0; i < n; i++)
        cin >> arr[i].second >> arr[i].first;
 
    sort(arr, arr+n, greater<pii>());
 
    multiset<int> mst;
 
    lli ans = 0;
    lli sum = 0;
 
    for(int i = 0; i < n; i++){
 
        mst.insert(arr[i].second);
        sum += arr[i].second;
 
        while(mst.size() > k){
            auto it = mst.begin();
            sum -= *it;
            mst.erase(it);
        }
 
        ans = max(ans, sum * arr[i].first);
    }
 
    cout << ans;
}
