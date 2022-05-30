// Problem: A - Modular Fibonacci
// Contest: Virtual Judge - Math Week 6
// URL: https://vjudge.net/contest/495976#problem/A
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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
int MOD = 1e9 + 7;
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct matrix{
	
	int n;
	vector<vi> vec;
	
	matrix(){}
	
	matrix(int _n){
		n = _n;
		vec = vector<vi>(n, vi(n));
	}
	
	matrix(vector<vi> tmp){
		vec = tmp;
		n = vec[0].size();
	}	
	
	matrix operator * (const matrix &other){
		
		matrix product(n);
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		for(int k = 0; k < n; k++){
			product.vec[i][k] = add(product.vec[i][k], mul(vec[i][j], other.vec[j][k]));
		}
		
		return product;
	}
};

matrix fast_power(matrix &a, int p){
	
	int n = a.n;
	
	matrix product(n);
	for(int i = 0; i < n; i++) 
		product.vec[i][i] = 1;
	
	while(p){
		if(p&1) product = product * a;
		a = a*a;
		p /= 2;
	}
	
	return product;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    while(cin >> n >> m){
    	
    	MOD = 1ll << m;
    	
    	matrix conv((vector<vi>){{0, 1}, {1, 1}});
    	matrix init((vector<vi>){{0, 0}, {1, 0}});
    	
    	matrix ans = fast_power(conv, n) * init;
    	
    	cout << ans.vec[0][0] << endl;
    }
}
