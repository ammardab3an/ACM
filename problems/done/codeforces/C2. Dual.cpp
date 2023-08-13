// Problem: C2. Dual (Hard Version)
// Contest: Codeforces - Codeforces Round 889 (Div. 2)
// URL: https://codeforces.com/contest/1855/problem/C2
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
	
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		if(false){
			n = 20;
			vec = vi(n);
			for(auto &e : vec) e = rand(-10, 10);
			cout << n << endl;
			for(auto e : vec) cout << e << ' '; cout << endl;
			cout << flush;
		}
		
		if(is_sorted(vec.begin(), vec.end())){
			cout << 0 << endl;
			continue;
		}
		
		vi pos(n);
		iota(pos.begin(), pos.end(), 0);
		sort(pos.begin(), pos.end(), [&](int i, int j){
			return vec[i] < vec[j];
		});
		
		int mn_p = pos[0];
		int mx_p = pos[n-1];
		int cnt_neg = 0;
		int cnt_pos = 0;
		
		for(auto e : vec){
			if(e > 0){
				cnt_pos++;
			}
			if(e < 0){
				cnt_neg++;
			}
		}
		
		bool b = true;
		
		if(-vec[mn_p] > vec[mx_p]){
			b = false;
		}
		
		vpii ans;
		
		if(!cnt_pos || !cnt_neg){
			b = !cnt_neg;
		}
		else if(n-1 + (b ? cnt_neg : cnt_pos) <= 31){
			int p = b ? mx_p : mn_p;
			for(int i = 0; i < n; i++){
				if((b && (vec[i] < 0)) || (!b && (vec[i] > 0))){
					ans.push_back({i, p});
					vec[i] += vec[p];
				}
			}
		}
		else if(n-1 + min(cnt_pos, cnt_neg) + 5 <= 31){
			
			b = cnt_pos > cnt_neg;
			
			int p = b ? mx_p : mn_p;
			for(int i = 0; i < 5; i++){
				ans.push_back({p, p});
				vec[p] += vec[p];
			}
			
			for(int i = 0; i < n; i++){
				if((b && (vec[i] < 0)) || (!b && (vec[i] > 0))){
					ans.push_back({i, p});
					vec[i] += vec[p];
				}
			}
		}
		else{
			assert(false);
		}
		
		if(b){
			for(int i = 1; i < n; i++){
				ans.push_back({i, i-1});
				vec[i] += vec[i-1];
			}
		}
		else{
			for(int i = n-2; i >= 0; i--){
				ans.push_back({i, i+1});
				vec[i] += vec[i+1];
			}
		}
		
		assert(ans.size() <= 31);
		assert(is_sorted(vec.begin(), vec.end()));
		
		// cout << b << endl;
		// for(auto e : vec) cout << e << ' '; cout << endl;
		
		cout << ans.size() << endl;
		for(auto [i, j] : ans){
			cout << i+1 << ' ' << j+1 << endl;
		}
    }	
}
