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

#define all_white first
#define sth_black second

int n, mod;
vi adj[NMAX], children[NMAX];
pii down[NMAX], up[NMAX];
vpii downs[NMAX], pre[NMAX], suf[NMAX];

int add(int a, int b){
    return (a + b) % mod;
}
int mul(int a, int b){
    return (1ll * a * b) % mod;
}

pii merge(pii a, pii b){
    pii p;
    p.all_white = mul(a.all_white, b.all_white);
    p.sth_black = add(
        mul(a.sth_black, add(b.all_white, b.sth_black)),
        mul(a.all_white, b.sth_black)
    );
    return p;
}

pii process(pii p){
    return {p.all_white, add(p.all_white, p.sth_black)};
}

void dfs_init(int nd, int par = -1){
    for(auto nxt : adj[nd]) if(nxt != par){
        children[nd].push_back(nxt);
        dfs_init(nxt, nd);
    }
}

pii dfs_one(int nd){
    
    pii p = {1, 0};
    
    for(auto nxt : children[nd]){
        p = merge(p, dfs_one(nxt));
        downs[nd].push_back(down[nxt]);
    }
    
    return down[nd] = process(p);
}

void dfs_two(int nd){
    
    for(int i = 0; i < children[nd].size(); i++){
        
        pii p = {1, 0};
        
        if(i != 0)
            p = merge(p, pre[nd][i-1]);
        if(i != children[nd].size()-1)
            p = merge(p, suf[nd][i+1]);
        if(nd != 1)
            p = merge(p, up[nd]);
        
        int nxt = children[nd][i];
        up[nxt] = process(p);
        dfs_two(nxt);
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> mod;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs_init(1);
    dfs_one(1);
    
    for(int i = 1; i <= n; i++){
            
        pii p = {1, 0};
        for(int j = 0; j < downs[i].size(); j++){
            p = merge(p, downs[i][j]);
            pre[i].push_back(p);
        }
        
        p = {1, 0};
        for(int j = downs[i].size()-1; j >= 0; j--){
            p = merge(p, downs[i][j]);
            suf[i].push_back(p);
        }
        
        reverse(suf[i].begin(), suf[i].end());
    }
    
    dfs_two(1);
    
    for(int i = 1; i <= n; i++){
        
        pii p = {1, 0};
        
        if(i != 1){
            p = merge(p, up[i]);
        }
        
        if(!children[i].empty()){
            p = merge(p, pre[i].back());
        }
        
        cout << process(p).sth_black << endl;
    }
}
