// Problem: XOR Sums
// Contest: CodeChef - FEB21
// URL: https://www.codechef.com/problems/SUMXOR2
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

const int mod = 998244353;
const int root = 15311432;
const int root_1 = 469870224;
const int root_pw = 1 << 23;

void fft (vector<int> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		int wlen = invert ? root_1 : root;
		for (int i=len; i<root_pw; i<<=1)
			wlen = int (wlen * 1ll * wlen % mod);
		for (int i=0; i<n; i+=len) {
			int w = 1;
			for (int j=0; j<len/2; ++j) {
				int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
				a[i+j] = u+v < mod ? u+v : u+v-mod;
				a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
				w = int (w * 1ll * wlen % mod);
			}
		}
	}
	if (invert) {
		int nrev = pow_exp (n, mod-2);
		for (int i=0; i<n; ++i)
			a[i] = int (a[i] * 1ll * nrev % mod);
	}
}

int fac[NMAX], ifac[NMAX];

void init(){
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	ifac[NMAX-1] = pow_exp(fac[NMAX-1], MOD-2);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	assert(n >= c);
	return mul(mul(fac[n], ifac[c]), ifac[n-c]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    init();
    
    int n;
    
    while(cin >> n){
    	
	    vi vec(n);
	    for(auto &i : vec) cin >> i;
	    
	    vi ans(n+1);
	    
	    for(int i = 0; i < 30; i++){
	    	
	    	int ones = 0;
	    	int zeros = n;
	    	
	    	for(auto e : vec) if((e>>i)&1){
	    		ones++;
	    		zeros--;
	    	}
	    	
	    	int res_sz = ones+zeros+1;
	    	res_sz = 1 << int(ceil(log2(double(res_sz))));
	    	
	    	vi A(res_sz), B(res_sz);
	    	
	    	for(int i = 1; i <= ones; i+=2){
	    		A[i] = choose(ones, i);
	    	}
	    	for(int i = 0; i <= zeros; i++){
	    		B[i] = choose(zeros, i);
	    	}
	    	
	    	fft(A, false);
	    	fft(B, false);
	    	for(int i = 0; i < res_sz; i++){
	    		A[i] = mul(A[i], B[i]);
	    	}
	    	fft(A, true);
	    	
	    	int p2 = 1<<i;
	    	for(int i = 1; i <= n; i++){
	    		ans[i] = add(ans[i], mul(p2, A[i]));
	    	}
	    }
	    
	    for(int i = 1; i <= n; i++){
	    	ans[i] = add(ans[i], ans[i-1]);
	    }
	    
	    int q; cin >> q; while(q--){
	    	int m;
	    	cin >> m;
	    	cout << ans[m] << endl;
	    }
    }
}
