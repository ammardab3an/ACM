// Problem: L. Leverage MDT
// Contest: Codeforces - 2019-2020 ACM-ICPC Latin American Regional Programming Contest
// URL: https://codeforces.com/gym/102428/problem/L
// Memory Limit: 1024 MB
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for(auto &s : grid) cin >> s;
    
    vector<vi> pre(n, vi(m));
    
    set<pair<int, pii> > st;
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        
        if((j>0) && (grid[i][j] == grid[i][j-1])){
            pre[i][j] = pre[i][j-1] + 1;
        }
        else{
            pre[i][j] = 1;
        }
        
        st.insert({-pre[i][j], {i, j}});
    }
    
    vector<vector<vi>> par(2, vector<vi>(n, vi(m)));
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) 
        par[0][i][j] = par[1][i][j] = i;
    
    auto get_par = [&](auto &self, int k, int i, int j) -> int{
        return par[k][i][j] = par[k][i][j] == i ? i : self(self, k, par[k][i][j], j);
    };
    
    int ans = 0;
    
    while(!st.empty()){
        
        auto tp = *st.begin();
        st.erase(st.begin());
        
        int i = tp.second.first;
        int j = tp.second.second;
        int v = -tp.first;
        
        if(i && pre[i-1][j] >= v){
            par[0][i][j] = get_par(get_par, 0, par[0][i-1][j], j);
            par[1][i-1][j] = par[1][i][j];
        }
        
        if(i+1<n && pre[i+1][j] >= v){
            par[1][i][j] = get_par(get_par, 1, par[1][i+1][j], j);
            par[0][i+1][j] = par[0][i][j];
        }
        
        int l = get_par(get_par, 0, par[0][i][j], j);
        int r = get_par(get_par, 1, par[1][i][j], j);
        
        ans = max(ans, min(r-l+1, v));
    }
    
    cout << ans*ans << endl;
}