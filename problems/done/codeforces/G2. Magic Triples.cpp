// Problem: G2. Magic Triples (Hard Version)
// Contest: Codeforces - Codeforces Round 867 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1822/G2
// Memory Limit: 256 MB
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

const int AMAX = sqrt(1e9) + 10;

bool not_prime[AMAX];
vi primes;

void sieve(){
	 
	for(int i = 2; i < AMAX; i++) if(!not_prime[i]){
		primes.push_back(i);
		for(int j = i*i; j < AMAX; j+=i){
			not_prime[j] = true;
		}
	}	
}

void go(int i, int x, const vpii &factors, vi &ret){
	
	if(i==factors.size()){
		ret.push_back(x);
		return;
	}	
	
	auto [p, cnt] = factors[i];
	for(int j = 0; j <= cnt; j++){
		go(i+1, x, factors, ret);
		x *= p;
	}
}

vi gen(const vpii &factors){
	vi ret;
	go(0, 1, factors, ret);
	return ret;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

bool isPrime(int x){
	for(int i = 2; i*i <= x; i++) if(x%i==0){
		return false;
	}
	return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("input.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);
    
	// init();
	
	sieve();
	
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		unordered_map<long long, int, custom_hash> mp;
		for(auto i : vec) mp[i]++;
		
		int ans = 0;
		
		for(auto [k, v] : mp){
			
			if(v >= 3) ans += v*(v-1)*(v-2);
			
			if(k*2 > 1e9) continue;
			
			int x = k;
			vpii factors;
			
			for(auto p : primes){
				if(p*p > x) break;
				int cnt = 0;
				while(x%p==0) cnt++, x/=p;
				if(cnt) factors.push_back({p, cnt});
			}
			
			if(x > 1) factors.push_back({x, 1});
			
			vi all_factors = gen(factors);
			
			for(auto f : all_factors) if(f > 1){
				
				if(k*f > 1e9) continue;
				
				auto it0 = mp.find(k*f);	
				if(it0==mp.end()) continue;
				auto it1 = mp.find(k/f);
				if(it1==mp.end()) continue;
				
				ans += v * (it0->second) * (it1->second);
			}	
		}
		
		cout << ans << endl;
    }	
}
