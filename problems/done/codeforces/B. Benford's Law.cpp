// Problem: B. Benford's Law
// Contest: Codeforces - 2021 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/103306/problem/B
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
    
	init();
	
	int n, m;
	cin >> n >> m;
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	int pro0 = mul(n-1, inv(n));
	int pro1 = mul(1, inv(n));
	
	vi tmp(m+1);
	
	for(int i = 0; i <= m; i++){
		
		int cans0 = choose(m, i);
		int cans1 = pow_exp(pro1, i);
		int cans2 = pow_exp(pro0, m-i);
		int cans = mul(cans0, mul(cans1, cans2));
		
		if(i) tmp[i] = tmp[i-1];
		tmp[i] = add(tmp[i], cans);
	}
	
	auto calc = [&](int x, int d){
		
		int p = 1;
		while(p*10 <= x){
			p *= 10;
		}
		
		int ret = 0;
		
		while(x+m >= p*d){
			
			int l = p*d;
			int r = p*(d+1)-1;
			l = max(l, x);
			r = min(r, x+m);
			
			if(l > r){
				p *= 10;
				continue;
			}
			
			int dl = l-x;
			int dr = r-x;
			
			int cans0 = tmp[dr];
			int cans1 = !dl ? 0 : tmp[dl-1];
			int cans = add(cans0, mul(-1, cans1));
			ret = add(ret, cans);
			
			p *= 10;
		}
		
		return ret;
	};
	
	vi ans(10);
	for(auto e : vec){
		for(int i = 1; i < 10; i++){
			ans[i] = add(ans[i], calc(e, i));
		}
	}		
	
	for(int i = 1; i < 10; i++){
		cout << ans[i] << endl;
	}
}
