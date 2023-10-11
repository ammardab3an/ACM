// Problem: E. Combinatorics Problem
// Contest: Codeforces - Educational Codeforces Round 148 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1832/problem/E
// Memory Limit: 1024 MB
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
const int MOD = 998244353; //1e9 + 7;
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
 
const int NMAX = 1e7 + 10;

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
	if(c > n) return 0;
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

const int N = 1e7 + 10;
const int mod = 998244353;

int32_t main(){
    
    fastIO;
    
	init();
	
	int n, a1, x, y, m, k;
	cin >> n >> a1 >> x >> y >> m >> k;
	
	vi vec(n);
	vec[0] = a1;
	
	for(int i = 1; i < n; i++){
		vec[i] = (vec[i-1]*1ll*x+y)%m;
	}
	
	vi res(n);
	
	vector<vi> dp(n, vi(k));
	
	for(int i = 0; i < n; i++){
		dp[i][0] = (vec[i] + (!i ? 0 : dp[i-1][0])) % mod;
	}
	
	for(int i = 1; i < n; i++){
		dp[i][0] = (dp[i][0] + dp[i-1][0]) % mod;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 1; j < k; j++){
			dp[i][j] = !i ? 0 : (dp[i-1][j] + dp[i-1][j-1]) % mod;
		}	
		res[i] = dp[i][k-1];
	}
	
	int64_t ans = 0;
	for(int i = 0; i < n; i++){
		int64_t cans = (i+1) *1ll * res[i];
		ans ^= cans;
	}
	
	cout << ans << endl;
}
