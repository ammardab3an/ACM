// Problem: D - Shipping Center
// Contest: AtCoder - Panasonic Programming Contest (AtCoder Beginner Contest 195)
// URL: https://atcoder.jp/contests/abc195/tasks/abc195_d
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

// #define endl '\n'
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

int n, m, q;
vi vec;
pii bag[55];
int mem[55][55];

int go(int i, int j){
    
    if(i == m || j == n) return 0;
    
    int &ret = mem[i][j];
    if(ret + 1) return ret;
    
    int ans = max(go(i+1, j), go(i, j+1));
    
    if(bag[j].first <= vec[i]) 
        ans = max(ans, go(i+1, j+1) + bag[j].second);
        
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> m >> q;
    
    vi orig_vec(m);
    
    for(int i = 0; i < n; i++) cin >> bag[i].first >> bag[i].second;
    for(int i = 0; i < m; i++) cin >> orig_vec[i];
    
    sort(bag, bag+n);
    
    while(q--){
        
        int l, r;
        cin >> l >> r; l--, r--;
        
        vec = vi();
        for(int i = 0; i < orig_vec.size(); i++) if(i < l || r < i) 
            vec.push_back(orig_vec[i]);
        
        sort(vec.begin(), vec.end());
        
        m = vec.size();
        
        memset(mem, -1, sizeof mem);
        cout << go(0, 0) << endl;
    }
}
