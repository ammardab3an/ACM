// Problem: C. Petya and Exam
// Contest: Codeforces - Codeforces Round 610 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1282/C
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

		int n, T, a, b;
		cin >> n >> T >> a >> b;
		
		int cnt_a = n;
		int cnt_b = 0;
		
		vpii vec(n);
		for(auto &[a, b] : vec) cin >> b, cnt_a -= b, cnt_b += b;
		for(auto &[a, b] : vec) cin >> a;
		
		sort(vec.begin(), vec.end());
		
		vi pre(n);
		for(int i = 0; i < n; i++){
			pre[i] = vec[i].second ? b : a;
			if(i) pre[i] += pre[i-1];
		}
		
		// for(auto [aa, bb] : vec){
			// cout << aa << ' ' << (bb ? b : a) << endl;
		// }
		
		int ans = 0;
		
		for(int i = -1; i < n; i++){
			
			if(i >= 0){
				cnt_b -= vec[i].second;
				cnt_a -= !vec[i].second;
			}
			
			if(i >= 0) if(i+1 < n) if(vec[i+1].first==vec[i].first) continue;
			
			int sm = i==-1 ? 0 : pre[i];
			int mx = i+1 < n ? vec[i+1].first-1 : T;
			
			if(sm <= mx){
				
				int cans = i+1;
				int rm = mx-sm;
				int mn = min(rm/a, cnt_a);
				cans += mn;
				mn = min((rm-a*mn)/b, cnt_b);
				cans += mn;
				ans = max(ans, cans);
				
				// cout << ' ' << i << ' ' << sm << ' ' << rm << ' ' << cans << endl;
				// cout << ' ' << cnt_a << ' ' << cnt_b << endl;
			}
		}
		
		if(pre.back() <= T) ans = n;
		
		cout << ans << endl;
    }
}
