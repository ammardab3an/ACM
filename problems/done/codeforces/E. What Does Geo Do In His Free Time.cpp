// Problem: E. What Does Geo Do In His Free Time
// Contest: Codeforces - Al-Baath Collegiate Programming Contest 2023
// URL: https://codeforces.com/gym/104447/problem/E
// Memory Limit: 1024 MB
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int NMAX = 2*707 + 10;

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
	if(c > n) return 0;
	// assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

int n, k;
int mem[NMAX];
int mem2[NMAX][NMAX];

int calc(int n, int m){
	
	int &ret = mem2[n][m];
	if(ret+1) return ret;
	
	int tot = choose(n+k-1, k-1);
	int cnt = 0;
	
	for(int i = 0; (i <= k) && (i*(m+1) <= n); i++){
		int a = (i%2==0) ? 1 : -1;
		int b = choose(k, i);
		int rm = (n-i*(m+1));
		int c = choose(rm+k-1, k-1);
		int ccnt = mul(a, mul(b, c));
		cnt = add(cnt, ccnt);
	}
	
	return ret = mul(cnt, inv(tot));
}

int go(int n){
	
	if(n==0){
		return 0;
	}
	
	int &ret = mem[n];
	if(ret+1) return ret;
	
	int l = (n+k-1)/k;
	int r = n;
	
	int ans = 0;
	for(int i = l; i <= r; i++){
		int cans = mul(calc(n, i)-calc(n, i-1), 1 + go(n-i));
		ans = add(ans, cans);
	}
	
	return ret = ans;
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

		cin >> n >> k;
		
		memset(mem, -1, sizeof mem);
		memset(mem2, -1, sizeof mem2);
		
		int ans = go(n);
		cout << ans << endl;
    }	
}