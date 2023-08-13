// Problem: I. Ajam's Password
// Contest: Codeforces - 2023 ICPC HIAST Collegiate Programming Contest
// URL: https://codeforces.com/gym/104493/problem/I
// Memory Limit: 256 MB
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
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

int stars(int n, int c){
	return choose(n+c-1, c-1);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	init();
	
    int t; cin >> t; while(t--){

		int n0, n1;
		cin >> n0 >> n1;
		
		int l0, r0;
		cin >> l0 >> r0;
		
		int l1, r1;
		cin >> l1 >> r1;
		
		// (-1)^a * choose(i, a) * stars(n0-l0*i-a*(d0+1), i) 
		// (-1)^b * choose(i, b) * stars(n1-l1*i-b*(d1+1), i)
		
		int ans = 0;
		
		auto calc = [&](int n, int sm, int l, int r){
			int ret = 0;
			for(int i = 0; i <= n; i++){
				int rm = sm - l*(n-i) - (r+1)*i;
				if(rm < 0) break;
				int cans = mul(choose(n, i), stars(rm, n));
				if(i&1) cans = mul(cans, -1);
				ret = add(ret, cans);
			}
			return ret;
		};
		
		// 01...01
		// 10...10
		for(int i = 1; (i*l0 <= n0) && (i*l1 <= n1); i++){
			int cans0 = calc(i, n0, l0, r0);
			int cans1 = calc(i, n1, l1, r1);
			int cans = mul(cans0, cans1);
			ans = add(ans, mul(2, cans));
		}
		
		// 01...010
		for(int i = 1; ((i+1)*l0 <= n0) && (i*l1 <= n1); i++){
			int cans0 = calc(i+1, n0, l0, r0);
			int cans1 = calc(i, n1, l1, r1);
			int cans = mul(cans0, cans1);
			ans = add(ans, cans);
		}
		
		// 10...101
		for(int i = 1; (i*l0 <= n0) && ((i+1)*l1 <= n1); i++){
			int cans0 = calc(i, n0, l0, r0);
			int cans1 = calc(i+1, n1, l1, r1);
			int cans = mul(cans0, cans1);
			ans = add(ans, cans);
		}
		
	    cout << ans << endl;	
    }	
    
}
