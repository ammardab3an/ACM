// Problem: F. Jee, You See?
// Contest: Codeforces - Codeforces Round #788 (Div. 2)
// URL: https://codeforces.com/contest/1670/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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
 
const int NMAX = 1e4 + 10;

int n, l, r, z, x;
int mem[64][NMAX];
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
	return mul(mul(fac[n], ifac[c]), ifac[n-c]);
}

int go(int i, int rm){
	
	if(i==-1){
		return 1;
	}	
	
	rm += (x>>i)&1;
	rm = min(rm, 2*n);
	
	int &ret = mem[i][rm];
	if(ret+1) return ret;
	
	int ans = 0;
	
	for(int j = (z>>i)&1; j <= rm && j <= n; j+=2){
		ans += mul(choose(n, j), go(i-1, (rm-j)*2));		
	}
	
	return ret = ans;
}

int calc(int x){
	
	::x = x;	
	memset(mem, -1, sizeof mem);
	int ret = go(63, 0);
	
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    init();
    
    cin >> n >> l >> r >> z;
    
    int ans = calc(r);
    if(l) ans = add(ans, mul(-1, calc(l-1)));
    
    cout << ans << endl;
}
