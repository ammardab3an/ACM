// Problem: E. Graph Coloring
// Contest: Codeforces - Educational Codeforces Round 87 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1354/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 5e3 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m;
int n1, n2, n3;
vi adj[NMAX];
int col[NMAX];
vector<vector<vi>> tmp;
vector<pii> tmp_sz;
int mem[NMAX][NMAX];
int ans[NMAX];

int go(int i, int rst){
    
    if(rst < 0) return false;
    if(i == tmp_sz.size()) return rst==0;
    
    int &ret = mem[i][rst];
    if(ret+1) return ret;
    
    int st_path = go(i+1, rst-tmp_sz[i].first);
    int nd_path = go(i+1, rst-tmp_sz[i].second);
    
    return ret = st_path || nd_path;    
}

void calc(int i, int rst){
    
    if(i == tmp_sz.size()) return;
    
    if(go(i+1, rst-tmp_sz[i].first)){
        
        for(auto u : tmp[i][0]){
            ans[u] = 2;
        }
        
        for(auto u : tmp[i][1]){
            if(n1) ans[u] = 1, n1--;
            else   ans[u] = 3, n3--;
        }
        
        calc(i+1, rst-tmp_sz[i].first);
    }
    else{
        
        for(auto u : tmp[i][1]){
            ans[u] = 2;
        }
        
        for(auto u : tmp[i][0]){
            if(n1) ans[u] = 1, n1--;
            else   ans[u] = 3, n3--;
        }
        
        calc(i+1, rst-tmp_sz[i].second);
    }
}

bool dfs(int u, bool b){
    
    col[u] = b;
    tmp.back()[b].push_back(u);
    
    for(auto v : adj[u]) {
        
        if(col[v] == -1){
            if(!dfs(v, !b)) 
                return false;
        }
        else if(col[v] == !b){
            continue;
        }
        else{
            return false;
        }
    }    
    
    return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    cin >> n1 >> n2 >> n3;
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    memset(col, -1, sizeof col);
    
    bool bad = false;
    
    for(int i = 0; i < n; i++) if(col[i] == -1){
        
        tmp.push_back({{}, {}});
        
        if(!dfs(i, 0)){
            bad = true;
            break;        
        }    
        
        tmp_sz.push_back({tmp.back()[0].size(), tmp.back()[1].size()});
    }
    
    if(bad){
        cout << "NO" << endl;
        return 0;
    }
    
    memset(mem, -1, sizeof mem);
    
    if(!go(0, n2)){
        cout << "NO" << endl;
        return 0;
    }
    
    calc(0, n2);
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) cout << ans[i];
}
