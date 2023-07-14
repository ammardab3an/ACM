
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

const int _2 = pow_exp(2, MOD-2);
const int _3 = pow_exp(3, MOD-2);
const int _6 = pow_exp(6, MOD-2);

int sum_all(int i){
	int s = i;
	int c = i+1;
	return mul(s*c, _2);
}

int sum_odd(int i){
	int s = i+1;
	int c = (i+1)/2;
	return mul(s*c, _2);
}

int sum_even(int i){
	int s = i;
	int c = i/2 + 1;
	return mul(s*c, _2);	
}

int sum_s_odd(int n){
	// n(2n+1)(2n-1)/3 
	return mul(mul(n, 2*n+1), mul(2*n-1, _3));
}

int sum_s_even(int n){
	// 2n(n+1)(2n+1)/3
	return mul(mul(2*n, n+1), mul(2*n+1, _3));
}

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
		
		int len = n/2;
		
		int s0_0 = mul(mul(n, n), len);
		int s0_1 = mul(mul(-2, n), sum_odd(len*2-1));
		int s0_2 = sum_s_odd(len);
		int s0 = add(s0_0, add(s0_1, s0_2));
		
		int s1_0 = mul(mul(n, n), len);
		int s1_1 = mul(mul(-1, n), sum_all(len*2-1));
		int s1_2 = add(sum_s_odd(len), mul(-1, sum_odd(len*2-1)));
		int s1 = add(s1_0, add(s1_1, s1_2));
		
		// cout << len << endl;
		// cout << s0 << ' ' << s1 << endl;
		// for(auto i : {s1_0, s1_1, s1_2}){
			// cout << i << ' ';
		// } cout << endl;
		// cout << endl;
		
		int ans = add(s0, s1);
		
		// if(n%2==1 && ){
			// ans = add(ans, 1);
		// }
		
		cout << ans << endl;
    }	
}

// 1 2 3
// 3 2 1
// 
// 2 2 1
// 3 2 1


