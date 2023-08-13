// Problem: B. Shooting
// Contest: Codeforces - ICPC Central Russia Regional Contest, 2021
// URL: https://codeforces.com/gym/104454/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int32_t main(){
    
    fastIO;
	
	int n, k, p;
	cin >> n >> k >> p;
	p++;
	
	vi po(n+1);
	po[0] = 1;
	for(int i = 1; i <= n; i++){
		po[i] = mul(po[i-1], k);
	}
	
	vi dp(p+1);
	dp[0] = po[0];
	
	for(int j = 1; j <= n; j++){	
		
		for(int i = 1; i <= p; i++){
			dp[i] = add(dp[i], dp[i-1]);
		}
		
		vi ndp(p+1);
		ndp[0] = po[j];
		
		for(int i = 1; i <= p; i++){
			
			int l = i-k;
			int r = i-1;
			int rm = 0;
			
			if(l < 0){
				rm = -l;
				l = 0;
			}
			
			ndp[i] = dp[r];
			if(l) ndp[i] = add(ndp[i], mul(-1, dp[l-1]));
			if(rm) ndp[i] = add(ndp[i], mul(rm, po[j-1]));
		}
		
		// for(auto e : ndp) cout << e << ' '; cout << endl;
		
		dp = ndp;
	}
	
	int ans = dp[p];
	cout << ans << endl;
}
