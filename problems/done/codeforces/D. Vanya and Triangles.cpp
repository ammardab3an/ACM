// Problem: D. Vanya and Triangles
// Contest: Codeforces - Codeforces Round 308 (Div. 2)
// URL: https://codeforces.com/problemset/problem/552/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n;
	cin >> n;
	
	vpii pnts(n);
	for(auto &[i, j] : pnts){
		cin >> i >> j;
	}
	
	sort(pnts.begin(), pnts.end());
	
	int ans = n*(n-1)*(n-2)/3/2;
	
	{
		map<int, int> tmp;
		
		for(auto [i, j] : pnts){
			tmp[i]++;
		}	
		
		for(auto [k, v] : tmp) if(v >= 3){
			ans -= v*(v-1)*(v-2)/3/2;
		}
	}
	
	map<array<int, 4>, int> mp;
	
	for(int i = 0; i < n; i++){
		
		map<array<int, 4>, int> tmp;
		
		for(int j = 0; j < i; j++){
			
			auto [x0, y0] = pnts[i];
			auto [x1, y1] = pnts[j];
			
			if(x0 != x1){
				
				int m0 = y0-y1;
				int m1 = x0-x1;
				
				int gm = __gcd(m0, m1);
				m0 /= gm, m1 /= gm;
				
				int c0 = y0*m1 - m0*x0;
				int c1 = m1;
				
				int gc = __gcd(c0, c1);
				c0 /= gc, c1 /= gc;
				
				array<int, 4> cur = {m0, m1, c0, c1};
				
				tmp[cur]++;
			}
		}
		
		for(auto [k, v] : tmp){
			ans -= mp[k];
			mp[k] += v;
		}
	}
	
	cout << ans << endl;
}

// (y-y0) = m(x-x0)
// y = mx - mx0 + y0
// c = y0-mx0
// c = y0 - m0.x0 / m1
// c = (y0.m1 - m0.x0)/m1