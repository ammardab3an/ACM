// Problem: E - Knapsack 2
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_e
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

int n, w;
int arr[110][2];
lli mem[110][100010];
int vis[110][100010], vid;

lli go(int pos, int left){
    
    if(left <= 0) return 0;
    if(pos == n) return INFLL;
    
    lli &ret = mem[pos][left];
    
    if(vis[pos][left] == vid)
        return ret;
    else
        vis[pos][left] = vid;
        
    int stPath = go(pos+1, left);    
    int ndPath = go(pos+1, left - arr[pos][1]) + arr[pos][0];
    
    return ret = min(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> w;
    for(int i = 0; i < n; i++) 
        cin >> arr[i][0] >> arr[i][1];
    
    int ans = 0;
    
    int l = 0;
    int r = 1e5 + 10;
    
    while(l <= r){
        
        int mid = (l+r)/2;
        
        vid++;
        if(go(0, mid) <= lli(w)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    
    cout << ans;
}
