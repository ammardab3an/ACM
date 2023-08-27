// Problem: F. New Year and Handle Change
// Contest: Codeforces - Educational Codeforces Round 79 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1279/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

pii calc(const vi &vec, int l, int x_factor){
	
	int n = vec.size();
	
	// for(auto e : vec) cout << e << ' '; cout << endl;
	
	vpii dp(n+1);
	dp[0] = {0, 0};
	
	for(int i = 1; i <= n; i++){
		
		pii cans = {INFLL, INFLL};
		
		pii st_path = dp[i-1];
		st_path.first += vec[i-1];
		cans = min(cans, st_path);
		
		if(i-l >= 0){
			pii nd_path = dp[i-l];
			nd_path.first += x_factor;
			nd_path.second += 1;
			cans = min(cans, nd_path);
		}
		else if(l <= n){
			pii nd_path = dp[0];
			nd_path.first += x_factor;
			nd_path.second += 1;
			cans = min(cans, nd_path);
		}
		
		dp[i] = cans;
	}	
	
	return dp.back();
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n, k, len;
	cin >> n >> k >> len;
	
	string str;
	cin >> str;
	
	vi vec(n);
	for(int i = 0; i < n; i++){
		vec[i] = (bool)islower(str[i]);
	}
	
	int ans = INF;
	
	for(auto b : {0, 1}){
		
		int l = 0;
		int r = INF;
		
		int bs_ans = -1;
		
		while(l <= r){
			
			int mid = (l+r)/2;
			pii cans = calc(vec, len, mid);
			
			// cout << mid << ' ' << cans.first << ' ' << cans.second << endl;
			
			if(cans.second <= k){
				bs_ans = mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		
		ans = min(ans, calc(vec, len, bs_ans).first - k*bs_ans);
		
		for(auto &i : vec) i = !i;
	}
	
	cout << ans << endl;
}
