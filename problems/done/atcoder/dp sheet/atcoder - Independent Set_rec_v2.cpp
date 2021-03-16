// Problem: P - Independent Set
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_p
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

int n;
vi adj[NMAX];

// returns : {nd_is_black, nd_is_white}

pii go(int nd, int par){
    
    int all_white = 1;
    int sth_black = 0;
    
    for(auto nxt : adj[nd]) if(nxt != par){
        
        pii tmp = go(nxt, nd);
        
        int n_all_white = (1ll * all_white * tmp.second) % MOD;
        int n_sth_black = ((1ll * all_white * tmp.first) % MOD + (1ll * sth_black * (tmp.first + tmp.second) % MOD) % MOD) % MOD;
        
        all_white = n_all_white;
        sth_black = n_sth_black;
    }
    
    return {all_white, (all_white + sth_black) % MOD};
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    pii tmp = go(0, -1);
    cout << (tmp.first + tmp.second) % MOD;
}
