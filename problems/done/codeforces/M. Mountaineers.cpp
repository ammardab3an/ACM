
// https://codeforces.com/gym/102021/problem/M

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

// #define endl '\n'
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

vector<int> par;
int get_par(int u){
    return par[u] = par[u] == u ? u : get_par(par[u]);
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
    
    vector<pii> cells;
    vector<vi> grid(n, vi(m));
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        cin >> grid[i][j];
        cells.push_back({grid[i][j], i*m+j});
    }
    
    int sz = cells.size();
    sort(cells.begin(), cells.end());
    
    par.resize(sz);
    iota(par.begin(), par.end(), 0);
    
    vector<int> ans(q, -1);
    vector<vpii> queries(sz);
    
    for(int i = 0; i < q; i++){
        int x, y, _x, _y;
        cin >> x >> y >> _x >> _y;
        x--, y--, _x--, _y--;
        if(x==_x && y==_y){
            ans[i] = grid[x][y];
        }
        else{
            queries[x*m+y].push_back({_x*m+_y, i});
            queries[_x*m+_y].push_back({x*m+y, i});
        }
    }
    
    for(auto cell : cells){
        
        int hi = cell.first;
        int i = cell.second/m;
        int j = cell.second%m;
        
        for(auto [ni, nj] : (vpii){{i, j+1}, {i+1, j}, {i, j-1}, {i-1, j}}){
            
            if(!(ni >= 0 && nj >= 0 && ni < n && nj < m)) continue;
            if(grid[ni][nj] > hi) continue;
            
            int par_a = get_par(cell.second);
            int par_b = get_par(ni*m+nj);
            
            if(par_a == par_b) continue;
            
            if(queries[par_a].size() > queries[par_b].size()) swap(par_a, par_b);
            
            for(auto [g_id, q_id] : queries[par_a]){
                
                if(get_par(g_id) == par_b){
                    if(ans[q_id] == -1) ans[q_id] = hi;
                }
                else{
                    queries[par_b].push_back({g_id, q_id});
                }
            }
            
            par[par_a] = par_b;
            queries[par_a].clear();
        }
    }
    
    for(int i : ans) cout << i << endl;
}
