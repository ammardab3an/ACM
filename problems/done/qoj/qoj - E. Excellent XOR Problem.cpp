
// E. Excellent XOR Problem
// https://qoj.ac/contest/1106/problem/5521

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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		int xor_tot = 0;
		
		vi vec(n);
		for(auto &i : vec) cin >> i, xor_tot ^= i;
		
		int l = 0;
		int xor_l = vec[0];
		
		while(l+1 < n && !xor_l){
			xor_l ^= vec[++l];
		}
		
		if(!xor_l){
			cout << "NO" << endl;
			continue;
		}
		
		if((l != n-1) && (xor_tot^xor_l) != xor_l){
			cout << "YES" << endl;
			cout << 2 << endl;
			cout << 1 << ' ' << l+1 << endl;
			cout << l+2 << ' ' << n << endl;
			continue;	
		}
		
		int r = n-1;
		int xor_r = vec[n-1];
		
		while((r-1 >= 0) && !xor_r){
			xor_r ^= vec[--r];
		}
		
		if((r != 0) && ((xor_tot^xor_r) != xor_r)){
			cout << "YES" << endl;
			cout << 2 << endl;
			cout << 1 << ' ' << r << endl;
			cout << l+1 << ' ' << n << endl;
			continue;	
		}
		
		while((r-1 >= 0) && (!xor_r || (xor_r == xor_l))){
			xor_r ^= vec[--r];
		}
		
		if(r <= l){
			cout << "NO" << endl;
			continue;
		}
		
		if(l+1 == r){
			cout << "YES" << endl;
			cout << 2 << endl;
			cout << 1 << ' ' << l+1 << endl;
			cout << r+1 << ' ' << n << endl;
			continue;
		}
		
		int xor_btw = 0;
		for(int i = l+1; i < r; i++){
			xor_btw ^= vec[i];
		}
		
		if(xor_btw != xor_l && xor_btw != xor_r){
			cout << "YES" << endl;
			cout << 3 << endl;
			cout << 1 << ' ' << l+1 << endl;
			cout << l+2 << ' ' << r << endl;
			cout << r+1 << ' ' << n << endl;
			continue;
		}
		
		if(xor_btw==xor_l){
			l = r-1;
		}
		else{
			r = l+1;
		}
		
		if(l+1 == r){
			cout << "YES" << endl;
			cout << 2 << endl;
			cout << 1 << ' ' << l+1 << endl;
			cout << r+1 << ' ' << n << endl;
			continue;
		}
		
		assert(false);
    }	
}
