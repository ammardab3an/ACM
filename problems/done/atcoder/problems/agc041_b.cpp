// Problem: B - Voting Judges
// Contest: AtCoder - AtCoder Grand Contest 041
// URL: https://atcoder.jp/contests/agc041/tasks/agc041_b
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
	
	int n, m, v, p;
	cin >> n >> m >> v >> p;
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	sort(vec.begin(), vec.end());
	
	// for(auto e : vec) cout << e << ' '; cout << endl;
	
	int l = 0;
	int r = n-1;
	
	int ans = n;
	
	while(l <= r){
		
		int mid = (l+r)/2;
		
		int cnt = 0;
		int val = vec[mid] + m;
		int rm = m * (v-1);
		
		for(int i = n-1; i >= 0; i--) if(i != mid){
			
			int c = vec[i];
			
			if(cnt+1 < p){
				int mn = min(m, rm);
				rm -= mn;
				c += mn;
			}
			else{
				
				if(c > val){
					cnt++;
					break;
				}
				
				int mn = min(m, min(rm, val-c));
				rm -= mn;
				c += mn;
			}
			
			cnt += c > val;
		}
		
		// cout << l << ' ' << r << ' ' << mid << ' ' << cnt << ' ' << rm << endl;
		
		if(cnt < p && rm==0){
			ans = mid;
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	
	cout << n-ans << endl;
}
