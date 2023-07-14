// Problem: D. Could you help the judges?
// Contest: Codeforces - Al-Baath Collegiate Programming Contest 2023
// URL: https://codeforces.com/gym/104447/problem/D
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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
	
	vector<vi> tmp(11);
	for(int x = 0; x < (1<<10); x++){
		tmp[__builtin_popcount(x)].push_back(x);
	}
	
    int t; cin >> t; while(t--){

		int n, k;
		cin >> n >> k;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		if(n==0){
			n = 1e5;
			vec = vi(n);
			for(auto &e : vec) e = rand(0, 1023);
			k = 5;
		}
		
		vi pre = vec;
		for(int i = 1; i < n; i++){
			pre[i] ^= pre[i-1];
		}
		
		vi st0, st1;
		vi cnt(1<<10);
		vector<bool> vis0(1<<10), vis1(1<<10);
		
		vis0[0] = true;
		st0.push_back(0);
		
		for(auto i : pre){
			
			for(int p = cnt[i]; p < st0.size(); p++){
				int e = st0[p];
				if(!vis1[e^i]){
					vis1[e^i] = true;
					st1.push_back(e^i);
				}
			}
			
			if(!vis0[i]){
				vis0[i] = true;
				st0.push_back(i);
			}
			
			cnt[i] = st0.size();
		}
		
		int ans = tmp[k].back();
		ans = max(ans, *max_element(st1.begin(), st1.end()));
		
		for(auto i : tmp[k])
		for(auto j : st1){
			ans = max(ans, i^j);
		}
		
		cout << ans << endl;
    }	
}
