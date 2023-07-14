// Problem: D. Flexible String Revisit
// Contest: Codeforces - Codeforces Round #848 (Div. 2)
// URL: https://codeforces.com/contest/1778/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
		
		string a, b;
		cin >> a >> b;
		
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(a[i] != b[i]){
				cnt++;
			}
		}
		
		vpii tmp(n+1);
		tmp[n] = {1, 1};
		tmp[0] = {0, 0};
		
		int _n = pow_exp(n, MOD-2);
		
		for(int i = n-1; i > 0; i--){
			
			// dp[i] = x*dp[i-1] + y
			// tmp[i] = {x, y}
			
			// dp[i] = i/n * (dp[i-1] + 1) + (n-i)/n * (dp[i+1] + 1)
			// dp[i] = i/n * (dp[i-1] + 1) + (n-i)/n * (tmp[i+1][0]*dp[i] + tmp[i+1][1] + 1)
			// dp[i] = p * (dp[i-1]+1) + q*tmp[i+1][0]*dp[i] + q*tmp[i+1][1] + q
			// dp[i] = p*(dp[i-1]+1) + q*tmp[i+1][1] + q
			// inv = 1 / (1-q*tmp[i+1][0])
			// dp[i] = inv*(p*(dp[i-1]+1) + q*tmp[i+1][1] + q)
			// dp[i] = inv*p*dp[i-1] + inv*(p + q*(tmp[i+1][1] + 1))
			
			int p = mul(i, _n);
			int q = mul(n-i, _n);
			
			int _inv = inv(add(1, mul(-1, mul(q, tmp[i+1].first))));
			
			tmp[i].first = mul(_inv, p);
			tmp[i].second = mul(_inv, add(p, mul(q, add(tmp[i+1].second, 1))));
		}
		
		vi ans(n+1);
		
		ans[0] = 0;
		for(int i = 1; i <= cnt; i++){
			ans[i] = add(mul(tmp[i].first, ans[i-1]), tmp[i].second);
		}
		
		cout << ans[cnt] << endl;
    }	
}
