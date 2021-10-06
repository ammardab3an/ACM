// Problem: V - Subtree
// Contest: AtCoder - Educational DP Contest
// URL: https://a...content-available-to-author-only...r.jp/contests/dp/tasks/dp_v
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://c...content-available-to-author-only...r.org)


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

int n, mod, phi_mod;
vi adj[NMAX];
int sz[NMAX], ans[NMAX];

int phi(int n)
{ 
    int result = n;  
    for(int p = 2; p * p <= n; ++p){ 
        if (n % p == 0){ 
            while (n % p == 0) 
                n /= p; 
            result -= result / p; 
        } 
    }
    if (n > 1) 
        result -= result / n;     
    return result; 
} 

int fast_pow(int n, int p){
    if(!p) return 1;
    if(p&1) return (n * fast_pow(n, p-1)) % mod;
    int tmp = fast_pow(n, p/2);
    return (tmp * tmp) % mod;
}

int add_mod(int a, int b){
    return (a + b + mod + mod) % mod;
}
int mul_mod(int a, int b){
    return ((a%mod) * (b%mod)) % mod;
}
int div_mod(int a, int b){
    return ((a%mod) * (fast_pow(b%mod, phi_mod-1)%mod)) % mod;
}

int init(int nd, int par = -1){
    
    int cur_sz = 1;
    
    for(auto nxt : adj[nd]) if(nxt != par){
        cur_sz = mul_mod(cur_sz, init(nxt, nd) + 1);
    }
    
    return sz[nd] = cur_sz;
}

void go(int nd, int par = 0){
    
    int cur_ans = add_mod(sz[par], 1); 
    
    for(auto nxt : adj[nd]) if(nxt != par){
        
        cur_ans = mul_mod(cur_ans, sz[nxt] + 1);
        
        sz[nd] = div_mod(sz[nd], sz[nxt] + 1);
        sz[nxt] = mul_mod(sz[nxt], sz[nd] + 1);
        
        go(nxt, nd);
        
        sz[nxt] = div_mod(sz[nxt], sz[nd] + 1);
        sz[nd] = mul_mod(sz[nd], sz[nxt] + 1);
    }
    
    ans[nd] = cur_ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    bool multi = false;
    
    int t = 1; if(multi) cin >> t; while(t--){
        
	    cin >> n >> mod;
	    phi_mod = phi(mod);
	    
	    if(multi) for(int i = 1; i <= n; i++) adj[i].clear();
	    
	    for(int i = 1; i < n; i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	        adj[v].push_back(u);
	    }
	    
	    init(1); go(1);
	    
	    for(int i : vi(ans+1, ans+n+1)) cout << i << endl;
	    
	    if(multi) cout << endl;
    }
}
