// Problem: F.  Weird Koko
// Contest: Codeforces - Btunis beek
// URL: https://codeforces.com/group/rKyL0A9Cab/contest/447953/problem/F
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


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
	if(n < c) return 0;
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

auto calc = [](int n, int m){
			
	vector<vi> dp(n+1, vi(m*n+1));
	
	for(int i = 1; i <= m; i++){
		dp[1][i] = 1;
	}
	
	for(int i = 2; i <= n; i++)
	for(int j = 0; j <= i*m; j++)
	for(int k = 1; k <= m; k++){
		if(j-k < 0) break;
		dp[i][j] = add(dp[i][j], dp[i-1][j-k]);
	}
	
	int ret = 0;
	
	for(int i = 2; i <= n; i++)
	for(int j = 2; j <= i; j++){
		
		int a0 = choose(n, i);
		int a1 = pow_exp(m, n-i);
		int a2 = dp[i][j*m];
		
		ret = add(ret, mul(a0, mul(a1, a2)));
	}
	
	ret = mul(ret, inv(pow_exp(m, n)));
	ret = add(ret, 1);
		
	return ret;
};

auto calc2 = [](int n, int m){

	int ans = 0;
	for(int i = 2; i <= n; i++){
		
		int cans = 0;
		
		for(int j = 2; j <= i; j++){
			
			for(int k = 0; k < j; k++){
				
				int a0 = k%2==0 ? 1 : -1;
				int a1 = choose(i, k);
				int a2 = choose((j-k)*m-1, i-1);
				
				cans = add(cans, mul(a0, mul(a1, a2)));
			}
		}
		
		ans = add(ans, mul(mul(pow_exp(m, n-i), choose(n, i)), cans));
	}
	
	
	ans = mul(ans, inv(pow_exp(m, n)));
	ans = add(ans, 1);
		
	return ans;
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	init();
	
    int t; cin >> t; while(t--){

		int n, m;
		cin >> n >> m;
		
		int ans0 = mul(pow_exp(m, n-1), pow_exp(2, n)-1);
		int ans1 = pow_exp(m, n);
		int ans2 = 0;
		
		for(int i = 1; i <= n; i++){
			
			int a0 = choose(n, i);
			int a1 = pow_exp(m, n-i);
			int a2 = choose(m-1, i-1);
			
			int a = mul(a0, mul(a1, a2));
			ans2 = add(ans2, a);
		}
		
		int ans = add(ans0, add(ans1, -ans2));
		ans = mul(ans, inv(pow_exp(m, n)));
		
		cout << ans << endl;
		
		// cout << calc(n, m) << endl;
		// cout << calc2(n, m) << endl;
    }	
}
