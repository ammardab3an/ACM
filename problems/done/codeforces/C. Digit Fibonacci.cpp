// Problem: C. Digit Fibonacci
// Contest: Codeforces - SpecialForces
// URL: https://codeforces.com/gym/409982/problem/C
// Memory Limit: 128 MB
// Time Limit: 500 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct matrix{
	
	int n;
	vector<vi> arr;
	
	matrix(int _n, bool _init=false){
		n = _n;
		arr = vector<vi>(2, vi(2, 0));
		if(_init) init();
	}
	
	void init(){
		for(int i = 0; i < n; i++) arr[i][i] = 1;
	}
	
	matrix operator * (matrix &other){
		
		matrix ret(n);
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		for(int k = 0; k < n; k++){
			ret.arr[i][j] = (ret.arr[i][j] + (arr[i][k]*other.arr[k][j])%10)%10;
		}
		
		return ret;
	}
};

matrix mat_pow(matrix mat, int p){
	
	matrix ret(mat.n, true);
	
	while(p){
		if(p&1) ret = ret * mat;
		mat = mat * mat;
		p /= 2;
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
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		matrix init(2);
		init.arr[0][0] = 0;
		init.arr[1][0] = 1;
		
		matrix conv(2);
		conv.arr[0] = {1, 1};
		conv.arr[1] = {1, 0};
		
		conv = mat_pow(conv, n);
		
		matrix res = conv * init;
		cout << res.arr[0][0] << endl;
    }	
}
