// Problem: E. Monkeys
// Contest: Codeforces - ITMO Academy: pilot course - Disjoint Sets Union - Step 1
// URL: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/E
// Memory Limit: 256 MB
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
 
const int NMAX = 2e5 + 10;
const int MMAX = 4e5 + 10;

int par[NMAX];
vi child[NMAX];
int mon[NMAX][2], que[MMAX][2];
bool vis[NMAX][2];
int ans[NMAX];

int get_par(int u){
    return par[u] = par[u] == u ? u : get_par(par[u]);
}

void merge(int u, int v){
    
    if((u = get_par(u)) == (v = get_par(v))) return;    
    
    if(child[u].size() < child[v].size()) swap(u, v);
    
    child[u].insert(child[u].end(), child[v].begin(), child[v].end());
    child[v].clear();
    
    par[v] = u;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> mon[i][0] >> mon[i][1];
        mon[i][0]--, mon[i][1]--;
    }
    
    for(int i = 0; i < m; i++){
        cin >> que[i][0] >> que[i][1];
        que[i][0]--, que[i][1]--;
        vis[que[i][0]][que[i][1]] = true;
    }
    
    for(int i = 0; i < n; i++) par[i] = i, child[i].push_back(i);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            if(!vis[i][j] && mon[i][j] != -2){
                merge(i, mon[i][j]);
            }   
        }
    }
    
    memset(ans, -1, sizeof ans);
    
    for(int i = m-1; i >= 0; i--){
        
        int u = que[i][0];
        int v = mon[u][que[i][1]];
        
        if(v == -2) continue;
        
        get_par(u), get_par(v), get_par(0);
        
        if(par[u] == par[v]) continue;
        
        if(par[u] == par[0] || par[v] == par[0]){
            for(auto e : child[par[u]==par[0] ? par[v] : par[u]]) 
                ans[e] = i;  
        }
        
        merge(u, v);
    }
    
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
}
