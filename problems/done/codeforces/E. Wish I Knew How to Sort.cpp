// Problem: E. Wish I Knew How to Sort
// Contest: Codeforces - Codeforces Round #829 (Div. 2)
// URL: https://codeforces.com/contest/1754/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		int zeros = 0;
		for(auto i : vec) if(!i) zeros++;
		
		int bad_ones = 0;
		for(int i = 0; i < zeros; i++) if(vec[i]){
			bad_ones++;
		}
		
		/*
		ex(ones) = p*(1+ex(ones-1)) + (1-p)*(1+ex(ones))
		 = p*(1+ex(ones-1)) + (1-p) + (1-p)*ex(ones)
 		 = (1+ex(ones-1)) + (1-p)/p
 		 = ex(ones-1) + 1/p
		*/
		
		vi dp(bad_ones+1);
		
		dp[0] = 0;
		for(int i = 1; i <= bad_ones; i++){
			
			int num_p = mul(2, mul(i, i));
			int den_p = mul(n, n-1);
			// int p = mul(num_p, pow_exp(den_p, MOD-2));
			int _p = mul(den_p, pow_exp(num_p, MOD-2));
			
			dp[i] = add(_p, dp[i-1]);	
		}
		
		cout << dp.back() << endl;
    }	
}
