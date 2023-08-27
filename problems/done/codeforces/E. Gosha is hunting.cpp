// Problem: E. Gosha is hunting
// Contest: Codeforces - Codeforces Round 381 (Div. 1)
// URL: https://codeforces.com/problemset/problem/739/E
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

pair<double, int> merge(const pair<double, int> &a, const pair<double, int> &b){
	if(abs(a.first-b.first) < 1e-6){
		return a.second < b.second ? a : b;
	}	
	else{
		return a.first > b.first ? a : b;
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n, a, b;
	cin >> n >> a >> b;
	
	vector<vector<double>> vec(2, vector<double>(n));
	for(auto &v : vec) for(auto &i : v) cin >> i;
	
	auto calc = [&](double x_factor){
		
		vector<pair<double, int>> dp(a+1);
		
		for(int i = 0; i < n; i++){
			
			vector<pair<double, int>> ndp(a+1, {-1e18, INF});
			
			double p = vec[0][i];
			double q = vec[1][i];
			double pq = 1.0 - (1.0-p)*(1.0-q);
			
			for(int j = 0; j <= a; j++){
				
				// dp[i][a] = max(
					// dp[i-1][a],
					// dp[i-1][a-1] + vec[0][i]
					// dp[i-1][a] + vec[1][i] - x_factor
					// dp[i-1][a-1] + (1 - (1-vec[0][i])*(1-vec[1][i])) - x_factor
				// )
				
				auto &cans = ndp[j];
				
				auto st_path = dp[j];
				auto nd_path = dp[j];
				nd_path.first += q - x_factor;
				nd_path.second += 1;
				
				cans = merge(cans, merge(st_path, nd_path));
				
				if(j){
					auto rd_path = dp[j-1];
					rd_path.first += p;
					auto th_path = dp[j-1];
					th_path.first += pq - x_factor;
					th_path.second += 1;
					cans = merge(cans, merge(rd_path, th_path));
				}
			}
			
			dp = ndp;
		}
		
		return dp.back();
	};
	
	double l = 0;
	double r = 1e9;
	
	double bs_ans = -1;
	
	int cnt = 100;
	while(cnt--){
		
		double mid = (l+r)/2;
		auto cans = calc(mid);
		
		if(cans.second <= b){
			bs_ans = mid;
			r = mid;
		}
		else{
			l = mid;
		}
	}
	
	double ans = calc(bs_ans).first + b*bs_ans;
	
	cout << fixed << setprecision(6) << ans << endl;
}
