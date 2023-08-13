// Problem: E1. Minibuses on Venus (easy version)
// Contest: Codeforces - Codeforces Round 861 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1808/E1
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	int ret = (a*1ll*b)%MOD;
	if(ret < 0) ret += MOD;
	return ret;
}
 
int add(int a, int b){
	int ret = (a+b)%MOD;
	if(ret < 0) ret += MOD;
	return ret;
}

// int mul(int a, int b){
	// int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	// return (ret+MOD)%MOD;
// }
//  
// int add(int a, int b){
	// int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	// return (ret+MOD)%MOD;
// }
 
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

int n, k, m;
int mem[2][30][30][111][30];

int go(bool b, int x, int d, int rm, int sm){
	
	if(!rm){
		return !sm;
	}	
	if(d==k){
		return 0;
	}
	
	int &ret = mem[b][x][d][rm][sm];
	if(ret+1) return ret;
	
	if((x==d) || (b && ((x+k/2) == d))){
		return ret = go(b, x, d+1, rm, sm);
	}
	
	int ans = 0;
	for(int i = 0; i <= rm; i++){
		int cans = go(b, x, d+1, rm-i, (sm+i*d)%k);
		ans = add(ans, mul(cans, ifac[i]));
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
	cin >> n >> k >> m;
	::MOD = m;
	
	init();
	
	memset(mem, -1, sizeof mem);
	
	int ans = 0;
	
	for(int i = 1; i <= n; i++)
	for(int x = 0; x < k; x++){
		
		int sm0 = (i-2)*x;
		sm0 = (sm0%k + k)%k;
		
		int cans = go(false, x, 0, n-i, sm0);
		cans = mul(cans, mul(fac[n], ifac[i]));
		
		ans = add(ans, cans);
	}
	
	if(k%2==0)
	for(int x = 0; x < k/2; x++)
	for(int i = 1; i <= n; i++)
	for(int j = 1; i+j <= n; j++){
		
		int y = x + k/2;
		int sm0 = (i-2)*x + j*y;
		sm0 = (sm0%k + k)%k;
		
		int sm1 = i*x + (j-2)*y;
		sm1 = (sm1%k + k)%k;
		
		assert(sm0 == sm1);
		
		int cans = go(true, x, 0, n-i-j, sm0);
		cans = mul(cans, mul(fac[n], mul(ifac[i], ifac[j])));
		
		ans = add(ans, mul(-1, cans));
	}
	
	cout << ans << endl;
}
