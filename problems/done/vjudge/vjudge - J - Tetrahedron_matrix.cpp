// Problem: J - Tetrahedron
// Contest: Virtual Judge - Math Week 6
// URL: https://vjudge.net/contest/495976#problem/J
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
 
const int NMAX = 1e7 + 10;

struct matrix{
	
	vector<vi> vec;
	
	matrix(){
		vec = vector<vi>(4, vi(4));
	}
	
	matrix operator * (matrix &other){
		
		matrix product;
		for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
		for(int k = 0; k < 4; k++){
			product.vec[i][k] = add(product.vec[i][k], mul(vec[i][j], other.vec[j][k]));
		}
		
		return product;
	}
};

matrix fast_power(matrix &mat, int p){
	
	matrix product;
	for(int i = 0; i < 4; i++) product.vec[i][i] = 1;
	
	while(p){
		if(p&1) product = product * mat;
		mat = mat * mat;
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
    
    int n;
    cin >> n;
    
    matrix init;
    init.vec[0][0] = 1;
    
    matrix conv;
    conv.vec = vector<vi>(4, vi(4, 1));
    for(int i = 0; i < 4; i++) conv.vec[i][i] = 0;
    
    conv = fast_power(conv, n);
    
    matrix res = conv * init;
    
    cout << res.vec[0][0] << endl;
}
