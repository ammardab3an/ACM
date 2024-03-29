// Problem: E. Gojou and Matrix Game
// Contest: Codeforces - Codeforces Round #779 (Div. 2)
// URL: https://codeforces.com/contest/1658/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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
    
    int n, k;
    cin >> n >> k;
    
    vpii pos(n*n);
    vector<vi> grid(n, vi(n));
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
    	cin >> grid[i][j];
    	pos[--grid[i][j]] = {i, j};
    }
    
    vector<vi> ans(n, vi(n));
    
    auto [i0, j0] = pos[n*n-1];
    
    ans[i0][j0] = 1;
    int mn_x_p_y = i0+j0;
    int mx_x_p_y = i0+j0;
    int mn_x_m_y = i0-j0;
    int mx_x_m_y = i0-j0;
    
    for(int v = n*n-2; v >= 0; v--){
    	
    	auto &[i, j] = pos[v];
    	
    	int st_path = i+j - mn_x_p_y;
    	int nd_path = i-j - mn_x_m_y;
    	int rd_path = -(i-j) + mx_x_m_y;
    	int th_path = -(i+j) + mx_x_p_y;
    	
    	int mx = max({st_path, nd_path, rd_path, th_path});
    	
    	ans[i][j] = mx <= k;
    	
    	if(ans[i][j]){
    		mn_x_p_y = min(mn_x_p_y, i+j);
    		mx_x_p_y = max(mx_x_p_y, i+j);
    		mn_x_m_y = min(mn_x_m_y, i-j);
    		mx_x_m_y = max(mx_x_m_y, i-j);
    	}
    }
    
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		cout << "GM"[ans[i][j]];
    	}
    	cout << endl;
    }
}

/*
	
	max:
	dist((i, j), (x, y))
	
	max:
	i-x + j-y
	i-x + y-j
	x-i + j-y
	x-i + y-j
	
	max:
	(i+j) - (x+y)	
	(i-j) - (x-y)
	-(i-j) + (x-y)
	-(i+j) + (x+y)
*/