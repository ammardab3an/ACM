
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
 
const int NMAX = 5e5 + 10;

int n, x, k;
int spf[NMAX];
const array<int, 2> pp = {100000007, 1000001011};
const array<int, 2> mm = {100003, 200003};
array<int, 2> pow_mm[NMAX];

bool is_prime(int x){
	for(int i = 2; i*i <= x; i++) if(x%i==0){
		return false;
	}
	return true;
}

void init_hash(){
	
	for(int i = 0; i < 2; i++){
		// while(!is_prime(pp[i])) pp[i]++;
		// while(!is_prime(mm[i])) mm[i]++;
		assert(is_prime(pp[i]));
		assert(is_prime(mm[i]));
	}
	
	// cout << pp[0] << ' ' << pp[1] << endl;
	// cout << mm[0] << ' ' << mm[1] << endl;
	
	pow_mm[0] = {1, 1};
	for(int i = 1; i < NMAX; i++){
		for(int j = 0; j < 2; j++){
			pow_mm[i][j] = (pow_mm[i-1][j] * mm[j]) % pp[j];
		}
	}
}

void init_sieve(){
	
	for(int i = 1; i < NMAX; i++){
		spf[i] = i;
	}
	
	for(int i = 2; i*i < NMAX; i++) if(spf[i]==i){
		for(int j = i*i; j < NMAX; j += i){
			if(spf[j]==j){
				spf[j] = i;
			}
		}
	}
}

vpii factorize(int n){
	
	vpii ret;
	
	while(n > 1){
		int cnt = 0;
		int p = spf[n];
		while(n%p==0) n/=p, cnt++;
		ret.push_back({p, cnt});
	}
	
	return ret;
}

array<int, 2> calc_hash(const vpii &vec, bool b){
	
	array<int, 2> ret = {0};
	
	for(auto [p, f] : vec){
		
		f %= x;
		if(b) f = (x-f)%x;
		
		if(f){
			for(int i = 0; i < 2; i++){
				ret[i] = (ret[i] + f*pow_mm[p][i])%pp[i];
			}
		}
	}
	
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	init_hash();
	init_sieve();
	
	cin >> n >> x >> k;
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	if(n==0){
		n = 5e5;
		x = 2;
		k = 2;
		vec = vi(n, 1);
		rng = mt19937(123);
		for(auto &e : vec) e = rand(1, 10);
	}
	
	// for(auto e : vec) cout << e << ' '; cout << endl;
	
	vi ans;
	ans.push_back(0);
	
	map<array<int, 2>, int> mp;
	
	int j = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		
		vpii cur = factorize(vec[i]);
		
		auto h0 = calc_hash(cur, false);
		auto h1 = calc_hash(cur, true);
		
		int ncnt = 0;
		auto it = mp.find(h0);
		if(it != mp.end()) ncnt += it->second;
		
		if(cnt+ncnt <= k){
			cnt += ncnt;
		}
		else{
			j = i;
			ans.push_back(i);
			cnt = 0;
			mp.clear();
		}
		
		mp[h1]++;
	}
	
	ans.push_back(n);
	cout << int(ans.size())-1 << endl;
	for(int i = 1; i < ans.size(); i++){
		cout << ans[i]-ans[i-1] << ' ';
	}
}
