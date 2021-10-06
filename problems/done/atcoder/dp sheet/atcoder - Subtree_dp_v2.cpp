// Problem: V - Subtree
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_v
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

int n, mod;
vi adj[NMAX], children[NMAX];
vi pre[NMAX], suf[NMAX];
vi dp, ans;

int add(int a, int b){
    return (a + b) % mod;
}
int mul(int a, int b){
    return (1ll * a * b) % mod;
}

void dfs_init(int nd, int par = -1){
    for(auto nxt : adj[nd]) if(nxt != par){
        children[nd].push_back(nxt);
        dfs_init(nxt, nd);
    }
}

void dfs_one(int nd){
    dp[nd] = 1;
    for(auto nxt : children[nd]){
        dfs_one(nxt);
        dp[nd] = mul(dp[nd], add(dp[nxt], 1));
    }
}

void dfs_two(int nd, int prod_up = 1){
    
    ans[nd] = mul(dp[nd], prod_up);
    
    int sz = children[nd].size();
    
    vi pre(sz), suf(sz);
    
    for(int i = 0; i < sz; i++){
        pre[i] = add(dp[children[nd][i]], 1);
        if(i) pre[i] = mul(pre[i], pre[i-1]);
    }
    
    for(int i = sz-1; i >= 0; i--){
        suf[i] = add(dp[children[nd][i]], 1);
        if(i+1 < sz) suf[i] = mul(suf[i], suf[i+1]);
    }
    
    for(int i = 0; i < sz; i++){
        
        int new_prod = prod_up;
        if(i) new_prod = mul(new_prod, pre[i-1]);
        if(i+1 < sz) new_prod = mul(new_prod, suf[i+1]);
        
        new_prod = add(new_prod, 1);    
        dfs_two(children[nd][i], new_prod);
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> mod;
    
    dp.resize(n);
    ans.resize(n);
    
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs_init(0);
    dfs_one(0);
    dfs_two(0);
    
    for(auto i : ans) cout << i << endl;
}
