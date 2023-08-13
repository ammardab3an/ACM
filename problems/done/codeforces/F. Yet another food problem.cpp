// Problem: F. Yet another food problem
// Contest: Codeforces - Aleppo Private Universities CPC
// URL: https://codeforces.com/gym/464569/problem/F
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n, m;
	cin >> n >> m;
	
	vi vec_v(n), vec_d(n);
	for(auto &e : vec_v) cin >> e;
	for(auto &e : vec_d) cin >> e;
	
	int l = 1;
	int r = 1e9;
	
	int bs_ans = -1;
	
	while(l <= r){
		
		int mid = (l+r)/2;
		
		int cnt = 0;
		for(int i = 0; i < n; i++){
			
			int v = vec_v[i];
			int d = vec_d[i];
			
			if(mid > v) continue;
			
			// v-d*x >= mid
			// v-mid >= d*x
			// (v-mid)/d >= x
			
			int x = (v-mid)/d;
			cnt += x+1;
		}
		
		if(cnt >= m){
			bs_ans = mid;
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	
	int ans = 0;
	int cnt = 0;
	int cnt_rem = 0;
	int mn = bs_ans+1;
	
	for(int i = 0; i < n; i++){
		
		int v = vec_v[i];
		int d = vec_d[i];
		
		if(v < bs_ans){
			continue;
		}
		
		// v-d*x >= mn
		// v-mn >= d*x
		// (v-mn)/d >= x
		
		int x = (v-mn)/d;
		cnt += x+1;
		
		// v*(x+1) -d * (0 + 1 + .. + x)
		// v*(x+1) - d * (x*(x+1)/2)
		
		ans += v*(x+1) - d * (x*(x+1)/2);
		
		if(v-d*(x+1) == bs_ans){
			cnt_rem++;
		}
	}
	
	int mm = min(m-cnt, cnt_rem);
	ans += mm * bs_ans;
	
	cout << ans << endl;
}
