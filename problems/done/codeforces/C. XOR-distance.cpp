// Problem: C. XOR-distance
// Contest: Codeforces - Codeforces Round 922 (Div. 2)
// URL: https://codeforces.com/contest/1918/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
    int t; cin >> t; while(t--){

		int a, b, r;
		cin >> a >> b >> r;
		
		vi bits_a, bits_b;
		for(int i = 0; i < 64; i++){
			if((a>>i)&1) if(!((b>>i)&1)) bits_a.push_back(i);
			if((b>>i)&1) if(!((a>>i)&1)) bits_b.push_back(i);
		}
		
		bool b0 = bits_a.empty();
		bool b1 = bits_a.size() && bits_b.size() && (bits_b.back() > bits_a.back());
		bool b2 = bits_a.size() && bits_b.size() && (bits_b.back() == bits_a.back()) && (b > a);
		
		if(b0 || b1 || b2){
			swap(a, b);
			swap(bits_a, bits_b);
		}
		
		if(bits_a.empty()){
			cout << abs(a-b) << endl;
			continue;
		}
		
		if(bits_a.size()){
			bits_a.pop_back();
		}
		
		int x = 0;
		reverse(bits_a.begin(), bits_a.end());
		
		for(auto e : bits_a){
			if((x^(1ll<<e)) <= r){
				x ^= (1ll << e);
			}
		}
		
		cout << abs((a^x)-(b^x)) << endl;
    }	
}
