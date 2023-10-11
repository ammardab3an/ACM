// Problem: G. Beautiful Crown
// Contest: Codeforces - UNICAMP Selection Contest 2023
// URL: https://codeforces.com/gym/104518/problem/G
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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
const int NMAX = 1e6 + 10;
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

int phi[NMAX];
int pow_m[NMAX];
vi factors[NMAX];

void init_phi(int m){
	
	for(int i = 1; i < NMAX; i++){
		phi[i] += i;
		for(int j = 2*i; j < NMAX; j+=i){
			phi[j] -= phi[i];
		}
	}	
	
	pow_m[0] = 1;
	for(int i = 1; i < NMAX; i++){
		pow_m[i] = mul(pow_m[i-1], m);
	}
	
	// for(int i = 1; i < NMAX; i++)
	// for(int j = i; j < NMAX; j+=i){
		// factors[j].push_back(i);
	// }
}

int32_t main(){
    
    fastIO;
	    
	int nn, m;
	cin >> nn >> m;
	
	init();
	init_phi(m);
	
	int ans = 0;
	
	for(int n = 1; n <= nn; n++){
		
		factors[n].push_back(n);
		for(auto f : factors[n]) if(n+f < NMAX){
			factors[n+f].push_back(f);
		}
		
		int sm = 0;
		for(auto f : factors[n]){
			int csm = mul(phi[n/f], pow_m[f]);
			sm = add(sm, csm);
		}
		
		int cans = mul(sm, inv(n));
		ans = add(ans, cans);
		
		factors[n].clear();
		factors[n].shrink_to_fit();
	}
	
	cout << ans << endl;
}