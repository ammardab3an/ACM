// Problem: Expected move
// Contest: CodeChef - JUNE221
// URL: https://www.codechef.com/problems/EXMV
// Memory Limit: 256 MB
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int x, n;
		cin >> x >> n;
		
		int d = n-x;
		int ex_x = (n+d) * (n-d-1);
		
		cout << ex_x << endl;
    }	
}

/*

initially we have:
	ex(1) = 0
	ex(i) = 0.5*(1+ex(i+1)) + 0.5*(1+ex(i-1))
	ex(n) = 0.5*(1+ex(n)) + 0.5*(1+ex(n-1))

ex(n) = 0.5*(1+ex(n)) + 0.5*(1+ex(n-1))
ex(n) = 0.5 + 0.5*ex(n) + 0.5 + 0.5*ex(n-1)
0.5*ex(n) = 1 + 0.5*ex(n-1)
=> ex(n) = 2 + ex(n-1)

we have:
ex(1) = 0
ex(2) = 1 + 0.5(ex(1) + ex(2))
 = 1 + 0.5*ex(3)
 
ex(3) = 1 + 0.5(ex(2) + ex(4))
 = 1 + 0.5*(1+0.5*ex(3)) + 0.5*ex(4)
 = 1 + 0.5 + 0.25*ex(3) + 0.5*ex(4)
 = (1/(1-0.25)) * (1.5 + 0.5*ex(4))
 = c + p*ex(4)
 
in general:
ex(i) = c0 + p0*ex(i+1)
ex(i+1) = c + p*ex(i+2)
 = 1 + 0.5(ex(i) + ex(i+2))
 = 1 + 0.5*ex(i) + 0.5*ex(i+2)
 = 1 + 0.5(c0+p0ex(i+1)) + 0.5*ex(i+2)
 = 1 + 0.5*c0 + 0.5*p0*ex(i+1) + 0.5*ex(i+2)
 = (1/(1-0.5*p0)) * (1+0.5*c0 + 0.5*ex(i+2))
 = (2/(2-p0)) * ((2+c0)/2 + 0.5*ex(i+2))
 = (2+c0)/(2-p0) + (1/(2-p0))*ex(i+2))
 = c + p*ex(i+2)
 =>
 c = (2+c0)/(2-p0)
 p = 1/(2-p0)

=> pattern found:
i -> (
	c_i = (i-1)
	p_i = (i-1)/i
)

=> ex(n-1) = (n-2) + (n-2)/(n-1) * ex(n)
 = c + p*ex(n)
 
we have:
ex(n) = 2 + ex(n-1)
 = 2 + (c + p*ex(n))
 = 1/(1-p) * (2+c)
 = (n-1)*n
 
=> ex(n) = (n-1)*n

// now we can calculate ex(n)
// and we need to find a way te calculate ex(x) from it

ex(n-1) = c + p*ex(n)
 c = n-2
 p = (n-2)/(n-1)

ex(n-2) = c + p*ex(n)
 c = 2*(n-3)
 p = (n-3)/(n-1)

ex(n-3) = c + p*ex(n)
 c = 3*(n-4)
 p = (n-4)/(n-1)

=> pattern found:
ex(x) = c + p * ex(n)
 c = d*(n-d-1)
 p = (n-d-1)/(n-1)
 where: d = n-x

ex(x) = c + p * ex(n)
 = c + p * (n*(n-1))
 = d*(n-d-1) + (n-d-1)/(n-1) * n*(n-1)
 = d*(n-d-1) + n * (n-d-1)
 = (n-d-1) * (n+d)
*/