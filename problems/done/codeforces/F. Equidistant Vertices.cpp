// Problem: F. Equidistant Vertices
// Contest: Codeforces - Codeforces Round #734 (Div. 3)
// URL: https://codeforces.com/contest/1551/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 200 + 10;        

int n, k;
vi adj[NMAX];
int cnt[NMAX][NMAX];

vi tmp;
int sz;
int mem[NMAX][NMAX];

void dfs(int u, int p){
    
    cnt[u][0] = 1;
    
    for(auto v : adj[u]) if(v != p){
        
        dfs(v, u);
        
        for(int l = 1; l <= n; l++){
            cnt[u][l] += cnt[v][l-1];
        }
    }
}

int calc(int pos, int rem){
    
    if(!rem) return 1;
    if(pos == sz) return 0;
    
    int &ret = mem[pos][rem];
    if(ret+1) return ret;
    
    int stPath = calc(pos+1, rem);
    int ndPath = mul(tmp[pos], calc(pos+1, rem-1));
    
    return ret = add(stPath, ndPath);
}

int go(int u, int p){
    
    int nans = 0;
    
    for(int l = 0; l <= n; l++){
        
        tmp.clear();
        
        for(auto v : adj[u]){
            if(cnt[v][l]) tmp.push_back(cnt[v][l]);
        }
        
        sz = tmp.size();
        memset(mem, -1, sizeof mem);
        
        nans = add(nans, calc(0, k));
    }
    
    for(auto v : adj[u]) if(v != p){
        
        for(int l = 1; l <= n; l++){
            cnt[u][l] -= cnt[v][l-1];
        }    
        for(int l = 1; l <= n; l++){
            cnt[v][l] += cnt[u][l-1];
        }
        
        nans = add(nans, go(v, u));
        
        for(int l = 1; l <= n; l++){
            cnt[v][l] -= cnt[u][l-1];
        }
        for(int l = 1; l <= n; l++){
            cnt[u][l] += cnt[v][l-1];
        }
    }    
    
    
    return nans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        cin >> n >> k;
        
        for(int i = 0; i < n; i++) adj[i].clear();
        
        for(int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        if(k==2){
            cout << n*(n-1)/2 << endl;
            continue;
        }
        
        memset(cnt, 0, sizeof cnt);
        
        dfs(0, -1);
        int ans = go(0, -1);
        
        cout << ans << endl;
    }	
}
