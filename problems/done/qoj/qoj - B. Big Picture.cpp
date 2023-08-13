
// B. Big Picture
// https://qoj.ac/contest/1099/problem/5456?v=1

// By AmmarDab3an 

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
const int MOD = 998244353; // 1e9 + 7;
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int grid[2][1010][1010];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n, m;
	cin >> n >> m;
	
	for(int k = 0; k < 2; k++)
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++){
		cin >> grid[k][i][j];
	}
	
	n++, m++;
	
	for(int i = 0; i < n; i++)
	for(int j = 1; j < m; j++){
		grid[0][i][j] = add(grid[0][i][j], grid[0][i][j-1]);
	}
	
	for(int i = 1; i < n; i++)
	for(int j = 0; j < m; j++){
		grid[1][i][j] = add(grid[1][i][j], grid[1][i-1][j]);
	}
		
	int ans = 2;
	
	for(int i = 1; i+1 < n; i++)
	for(int j = 1; j+1 < m; j++){
		
		int p0 = mul(grid[0][i][j-1], grid[1][i-1][j]);
		int p1 = add(grid[0][i+1][m-1], - grid[0][i+1][j-1]);
		int p2 = add(grid[1][n-1][j+1], - grid[1][i-1][j+1]);
		
		int cans = mul(p0, mul(p1, p2));
		ans = add(ans, cans); 
	}
	
	cout << ans << endl;
}
