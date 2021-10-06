// Problem: E. Duff in the Army
// Contest: Codeforces - Codeforces Round #326 (Div. 2)
// URL: https://codeforces.com/problemset/problem/588/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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
 
const int NMAX = 1e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));

int LOG;
vi adj[NMAX];
vi vec[NMAX];
int par[NMAX][LOG_MAX];
vi mn[NMAX][LOG_MAX];
int depth[NMAX];

void dfs(int u, int p){
    
    for(auto v : adj[u]) if(v != p){
        
        depth[v] = depth[u]+1;
        
        par[v][0] = u;
        for(int i = 1; i < LOG; i++){
            par[v][i] = par[par[v][i-1]][i-1];
        }
        
        for(auto i : vec[u]) mn[v][0].push_back(i);
        
        for(int i = 1; i < LOG; i++){    
            for(auto j : mn[v][i-1]) mn[v][i].push_back(j);
            for(auto j : mn[par[v][i-1]][i-1]) mn[v][i].push_back(j);
            sort(mn[v][i].begin(), mn[v][i].end());
            if(mn[v][i].size() > 10) mn[v][i].resize(10);
        }
        
        dfs(v, u);
    }    
}

vi lca(int u, int v, int s){
    
    vi vec_u, vec_v;
    
    if(depth[u] < depth[v]) swap(u, v);
    
    int diff = depth[u] - depth[v];
    
    for(auto i : vec[u]) vec_u.push_back(i);
    sort(vec_u.begin(), vec_u.end());
    if(vec_u.size() > 10) vec_u.resize(10);
    
    for(int i = 0; i < LOG; i++) if(diff&(1<<i)){
        for(auto i : mn[u][i]) vec_u.push_back(i);
        sort(vec_u.begin(), vec_u.end());
        if(vec_u.size() > 10) vec_u.resize(10);
        u = par[u][i];
    }
    
    if(v==u){
        if(vec_u.size() > s) vec_u.resize(s);
        return vec_u;
    }
    
    for(auto i : vec[v]) vec_v.push_back(i);
    sort(vec_v.begin(), vec_v.end());
    if(vec_v.size() > 10) vec_v.resize(10);
    
    for(int i = LOG-1; i >= 0; i--) if(par[u][i] != par[v][i]){
        for(auto i : mn[u][i]) vec_u.push_back(i);
        for(auto i : mn[v][i]) vec_v.push_back(i);
        sort(vec_u.begin(), vec_u.end());
        sort(vec_v.begin(), vec_v.end());
        if(vec_u.size() > 10) vec_u.resize(10);
        if(vec_v.size() > 10) vec_v.resize(10);
        u = par[u][i];
        v = par[v][i];
    }
    
    for(auto i : vec[par[u][0]]) vec_u.push_back(i);
    
    vi ret;
    for(auto i : vec_u) ret.push_back(i);
    for(auto i : vec_v) ret.push_back(i);
    sort(ret.begin(), ret.end());
    if(ret.size() > s) ret.resize(s);
    return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    LOG = ceil(log2(double(n)));
    
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 0; i < m; i++){
        
        int ci;
        cin >> ci;
        ci--;
        
        vec[ci].push_back(i);    
    }
    
    for(int i = 0; i < n; i++){
        sort(vec[i].begin(), vec[i].end());
        if(vec[i].size() > 10) vec[i].resize(10);
    }
    
    dfs(0, -1);
    
    while(q--){
        
        int u, v, s;
        cin >> u >> v >> s;
        u--, v--;
        
        vi que = lca(u, v, s);
        
        cout << que.size() << ' ';
        for(auto i : que) cout << i+1 << ' ' ;
        cout << endl;
    }
}
