// Problem: G. Noonerized Spumbers
// Contest: Codeforces - 2021-2022 ICPC East Central North America Regional Contest (ECNA 2021)
// URL: https://codeforces.com/gym/104196/problem/G
// Memory Limit: 1024 MB
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

vpii gen(int a, int b){
	
	vpii ret;
	int lena=0, lenb=0;
	
	{
		int aa = a;
		while(aa){
			lena++;
			aa /= 10;
		}
		
		int bb = b;
		while(bb){
			lenb++;
			bb /= 10;
		}
	}
	
	int pa = 10;
	
	for(int i = 1; i < lena; i++){
		
		int pb = 10;
		
		for(int j = 1; j < lenb; j++){
			
			int na = (a%pa) + (b/pb)*pa;
			int nb = (b%pb) + (a/pa)*pb;
			
			ret.emplace_back(na, nb);
			
			pb *= 10;
		}
		
		pa *= 10;
	}
	
	return ret;
}

int calc(int a, int b, char op){
	
	if(op=='+'){
		return a+b;
	}
	else{
		return a*b;
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int a, b, c;
	char op, eq;
	
	cin >> a >> op >> b >> eq >> c;
	
	bool found = false;
	
	for(auto [na, nb] : gen(a, b)){
		
		// cout << na << ' ' << nb << endl;
		
		if(calc(na, nb, op) == c){
			found = true;
			a = na;
			b = nb;
			break;
		}
	}
	
	if(!found)
	for(auto [na, nc] : gen(a, c)){
		if(calc(na, b, op) == nc){
			found = true;
			a = na;
			c = nc;
			break;
		}
	}
	
	if(!found)
	for(auto [nb, nc] : gen(b, c)){
		if(calc(a, nb, op) == nc){
			found = true;
			b = nb;
			c = nc;
			break;
		}
	}
	
	assert(calc(a, b, op) == c);
	cout << a << ' ' << op << ' ' << b << ' ' << eq << ' ' << c << endl;
}
