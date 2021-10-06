// Problem: D1. Mocha and Diana (Easy Version)
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.com/contest/1559/problem/D1
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int par[2][NMAX];
int get_par(int u, int i){
    return par[i][u] = par[i][u] == u ? u : get_par(par[i][u], i);
}

bool merge(int u, int v, int i){
    
    if((u=get_par(u, i)) == (v=get_par(v, i))){
        return false;
    }    
    
    if(rand()&1) swap(u, v);
    
    par[i][u] = v;
    
    return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    
    for(int i = 0; i < n; i++) par[0][i] = i, par[1][i] = i;
    
    for(int i = 0; i < m1; i++){
        
        int u, v;
        cin >> u >> v;
        u--, v--;
        
        merge(u, v, 0);
    }
    
    for(int i = 0; i < m2; i++){
        
        int u, v;
        cin >> u >> v;
        u--, v--;
        
        merge(u, v, 1);
    }
    
    vpii ans;
    
    for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++){
        
        if(get_par(i, 0) == get_par(j, 0)) continue;
        if(get_par(i, 1) == get_par(j, 1)) continue;
        
        merge(get_par(i, 0), get_par(j, 0), 0);
        merge(get_par(i, 1), get_par(j, 1), 1);
        
        ans.emplace_back(i+1, j+1);
    }
    
    cout << ans.size() << endl;
    for(auto p : ans) cout << p.first << ' ' << p.second << endl;
}
