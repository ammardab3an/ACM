// Problem: D. World of Darkraft - 2
// Contest: Codeforces - Codeforces Round #265 (Div. 1)
// URL: https://codeforces.com/problemset/problem/464/D
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
 
const int NMAX = 1E5 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, k;
    cin >> n >> k;
    
    vector<double> dp(777);
    
    while(n--){
    	
    	for(int i = 1; i <= 700; i++){
    		int level = i;
			double st_path = (double(1)/double(k*(level+1))) * ((level*(level+3))/2.0 + level*dp[level] + dp[level+1]);
			double nd_path = (double(k-1)/double(k)) * dp[level];
			dp[level] = st_path + nd_path;
    	}
    }
    
    double ans = double(k) * dp[1];
    cout << fixed << setprecision(10) << ans << endl;
}

/*

for some element, with probability of 1/k we will do a move on it, and with probability of (1-1/k)
we will do move on it.


dp[n][level] = 1/k * 1/(level+1) * (1+dp[n-1][level] + 2+dp[n-1][level] + ... + level+dp[n-1][level] + level+dp[n-1][level+1])
               + (k-1)/k * dp[n-1][level]
               
               
               

*/