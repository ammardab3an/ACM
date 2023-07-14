// Problem: C. Counting Trees
// Contest: Codeforces - NUS CS3233 Final Team Contest 2023 Mirror
// URL: https://codeforces.com/gym/104296/problem/C
// Memory Limit: 1024 MB
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
const int MOD = 3000301; // 1e9 + 7;
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
 
int pow_exp(int n, int p, int m=MOD){
	if(!p) return 1;
	if(p&1) return (n *1ll* pow_exp(n, p-1, m)) % m;
	int tmp = pow_exp(n, p/2, m);
	return (tmp *1ll* tmp) % m;
}

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int NMAX = MOD;

int fac[NMAX], ifac[NMAX];
int mod = 10000003233;
vi mod_factors = {3, 11, 101, 3000301};
int mem[3][222][222];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
	
	memset(mem, -1, sizeof mem);
}

int cho(int n, int c, int i){
	
	if(n == c) return 1;
	if(n == 0) return 0;
	
	int &ret = mem[i][n][c];
	if(ret+1) return ret;
	
	int st_path = cho(n-1, c-1, i);
	int nd_path = cho(n-1, c, i);
	int ans = (st_path + nd_path) % mod_factors[i];
	
	return ret = ans;
}	

int choose(int n, int c, int i){
	
	if(n < c) return 0;
	
	if(i < 3){
		return cho(n, c, i);
	}
	else{
		return mul(fac[n], mul(ifac[c], ifac[n-c]));
	}
}

struct Congruence {
    long long a, m;
};

long long chinese_remainder_theorem(vector<Congruence> const& congruences) {
	
    long long M = 1;
    for (auto const& congruence : congruences) {
        M *= congruence.m;
    }

    long long solution = 0;
    for (auto const& congruence : congruences) {
        long long a_i = congruence.a;
        long long M_i = M / congruence.m;
        long long N_i = pow_exp(M_i, congruence.m-2, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    
    return solution;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	init();
	
    int t; cin >> t; while(t--){

		int n, k, c;
		cin >> n >> k >> c;
		
		if(c > n){
			cout << 0 << endl;
			continue;
		}
		
		vector<Congruence> vec(4);
		
		for(int i = 0; i < 4; i++){
			
			int cm = mod_factors[i];
			
			int cho = 1;
			int a = n-1;
			int b = c-1;
			
			while(a > 0){
				int ccho = choose(a%cm, b%cm, i);
				cho = (cho * ccho)%cm;
				a /= cm, b /= cm;
			}
			
			vec[i] = {cho, cm};
		}
		
		int ans = chinese_remainder_theorem(vec);
		ans = (ans * 2) % mod;
		
		cout << ans << endl;
    }	
}
