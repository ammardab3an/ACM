// A. Almost Prefix Concatenation
// https://qoj.ac/contest/1358/problem/7512

// By AmmarDab3an 

#include <bits/stdc++.h>

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

// int fac[NMAX], ifac[NMAX];
// 
// void init(){
// 	
	// fac[0] = 1;
	// for(int i = 1; i < NMAX; i++){
		// fac[i] = mul(fac[i-1], i);
	// }
// 	
	// ifac[NMAX-1] = inv(fac[NMAX-1]);
	// for(int i = NMAX-2; i >= 0; i--){
		// ifac[i] = mul(ifac[i+1], i+1);
	// }
// }
// 
// int choose(int n, int c){
	// assert(n >= c);
	// return mul(fac[n], mul(ifac[c], ifac[n-c]));
// }

struct hash_struct{
	
	int n;
	string str;
	
	array<int, 2> p, m;
	vector<array<int, 2>> pre;
	vector<array<int, 2>> pow_m;
	
	hash_struct(){}
	
	hash_struct(string _str){
		str = _str;
		n = str.size();
		init();
		build();
	}
	
	bool is_prime(int x){
		for(ll i = 2; i*i <= x; i++) if(x%i==0){
			return false;
		}
		return true;
	}
	
	void init(){
		
		p = {130807, 1250284429}; //{rand(1e5, 2e5), rand(1e9, 2e9)};
		m = {53, 79}; //{rand(30, 50), rand(50, 100)};
		
		for(int j = 0; j < 2; j++){
			while(!is_prime(p[j])) p[j]++;
			while(!is_prime(m[j])) m[j]++;
		}
		
		// for(auto i : p) cout << i << ' '; cout << endl;
		// for(auto i : m) cout << i << ' '; cout << endl;
		
		pow_m.resize(n, array<int, 2>({0, 0}));
		
		pow_m[0][0] = pow_m[0][1] = 1;
		for(int i = 1; i < n; i++)
		for(int j = 0; j < 2; j++){
			pow_m[i][j] = (pow_m[i-1][j] *1ll* m[j])%p[j];
		}
	}
	
	void build(){
		
		pre.resize(n);
		
		array<int, 2> cval = {0, 0};
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 2; j++){
				cval[j] = ((cval[j] *1ll* m[j])%p[j] + (str[i]-'a'+1))%p[j];
			}
			pre[i] = cval;
		}
	}
	
	array<int, 2> query(int l, int r){
		if(r >= n) return {-1, -1};
		array<int, 2> ret = pre[r];
		if(l) for(int j = 0; j < 2; j++){
			ret[j] = (ret[j] - (pre[l-1][j] *1ll* pow_m[r-l+1][j])%p[j] + p[j])%p[j];
		}
		return ret;
	}
	
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	string str_a, str_b;
	cin >> str_a >> str_b;
	
	int n = str_a.size();
	int m = str_b.size();
	
	hash_struct hash_a(str_a);
	hash_struct hash_b(str_b);
	
	auto calc = [&](int i){
		
		int l = i;
		int r = n-1;
		int bs_ans = i-1;
		
		while(l <= r){
			
			int mid = (l+r)/2;
			
			auto h0 = hash_a.query(i, mid);
			auto h1 = hash_b.query(0, mid-i);
			
			if(h0==h1){
				bs_ans = mid;
				l = mid+1;
			}
			else{
				r = mid-1;
			}
		}
		
		int p = bs_ans+1;
		int q = bs_ans-i+1;
		if(p >= n-1) return min(n-1, i+m-1);
		
		// cerr << i << ' ' << p << endl;
		
		l = p+1;
		r = n-1;
		bs_ans = p;
		
		while(l <= r){
			
			int mid = (l+r)/2;
			
			auto h0 = hash_a.query(p+1, mid);
			auto h1 = hash_b.query(q+1, q+1+(mid-(p+1)));
			
			if(h0==h1){
				bs_ans = mid;
				l = mid+1;
			}
			else{
				r = mid-1;
			}
		}
		
		return min(bs_ans, i+m-1);
	};
	
	// for(int i = 0; i < n; i++){
		// cout << i << ' ' << calc(i) << endl;
	// }
	
	vector<array<int, 3>> dp(n+2);
	vector<array<int, 3>> suf(n+2);
	dp[n] = suf[n] = {0, 0, 1};
	
	for(int i = n-1; i >= 0; i--){
		
		int p = calc(i);
		
		array<int, 3> tmp;
		for(int j = 0; j < 3; j++){
			tmp[j] = add(suf[i+1][j], mul(-1, suf[p+2][j]));
		}
		
		dp[i] = {add(tmp[0], tmp[1]), add(tmp[1], tmp[2]), tmp[2]};
		
		for(int j = 0; j < 3; j++){
			suf[i][j] = add(suf[i+1][j], dp[i][j]);
		}
		
		// cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
	}
	
	int ans = add(mul(2, dp[0][0]), dp[0][1]);
	cout << ans << endl;
}
