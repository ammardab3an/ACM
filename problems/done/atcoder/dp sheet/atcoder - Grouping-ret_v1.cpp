// Problem: U - Grouping
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_u
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
int arr[20][20];
int mem[1 << 16], cmem[1 << 16];

void fill_cmem(){
    for(int msk = 0; msk < 1 << n; msk++){
        int ans = 0;
        for(int i = 0; i < n; i++) if(msk & (1 << i))
        for(int j = i; j < n; j++) if(msk & (1 << j)) ans += arr[i][j];
        cmem[msk] = ans;
    }
}

int calc(int msk){
    return cmem[msk];
}

int go(int msk){
    
    if(!msk) return 0;
    
    int &ret = mem[msk];
    if(ret + 1) return ret;
    
    int ans = 0;
    for(int tmp = msk; tmp; tmp = (tmp-1) & msk){
        ans = max(ans, go(msk ^ tmp) + calc(tmp));
    }
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) cin >> arr[i][j];
    
    fill_cmem();
    
    memset(mem, -1, sizeof mem);
    
    cout << go((1 << n) -1);
}
