// Problem: E. Boxes and Balls
// Contest: Codeforces - Educational Codeforces Round 151 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1845/problem/E
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int fac[NMAX], ifac[NMAX];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

void rem_mod(int &x){
	if(x >= MOD) x -= MOD;
}

int dp[2][121][1515];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n, kk;
	cin >> n >> kk;
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	// dp[i][j][k] = 
	// 	              dp[i-1][j+1-ai][k-(j+1-ai)]
	//              + dp[i-1][j-ai][k-(j-ai)]
	
	dp[0][55 + 0][0] = 1;
	
	for(int i = 0; i < n; i++)
	for(int j = -55; j <= 55; j++)
	for(int k = 0; k <= kk; k++){
		
		int ai = vec[i];
		
		dp[(i+1)&1][55 + j][k] = 0;
		
		if(abs(j+1-ai) <= 55) if(abs(j+1-ai) <= k){
			dp[(i+1)&1][55 + j][k] += dp[i&1][55 + j+1-ai][k-abs(j+1-ai)];
			rem_mod(dp[(i+1)&1][55 + j][k]);
		}	
		
		if(abs(j-ai) <= 55) if(abs(j-ai) <= k){
			dp[(i+1)&1][55 + j][k] += dp[i&1][55 + j-ai][k-abs(j-ai)];
			rem_mod(dp[(i+1)&1][55 + j][k]);
		}
	}
	
	int ans = 0;
	for(int k = kk&1; k <= kk; k+=2){
		ans = add(ans, dp[n&1][55 + 0][k]);
	}
	
	cout << ans << endl;
}
