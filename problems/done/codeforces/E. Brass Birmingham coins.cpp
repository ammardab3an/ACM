// Problem: E. Brass Birmingham: coins
// Contest: Codeforces - ICPC Central Russia Regional Contest, 2021
// URL: https://codeforces.com/gym/104454/problem/E
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

int n;
int sz[4];
int arr[4][44];
int mem[33][33][33][33];

int go(int i, int j, int k, int l){
	
	if((i+j+k+l) == -4){
		return 0;
	} 
	
	int &ret = mem[i+1][j+1][k+1][l+1];
	if(ret+1) return ret;
	
	int ans = INF;
	
	for(int d = 1; d <= n; d++){
		
		int ni = i;
		int nj = j;
		int nk = k;
		int nl = l;
		
		while(ni >= 0 && arr[0][ni]==d) ni--;
		while(nj >= 0 && arr[1][nj]==d) nj--;
		while(nk >= 0 && arr[2][nk]==d) nk--;
		while(nl >= 0 && arr[3][nl]==d) nl--;
		
		if(ni==i && nj==j && nk==k && nl==l) continue;
		
		int cans = 1 + go(ni, nj, nk, nl);
		ans = min(ans, cans);
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	cin >> n;
	for(int i = 0; i < 4; i++){
		cin >> sz[i];
	}
	
	for(int i = 0; i < 4; i++)
	for(int j = 0; j < sz[i]; j++){
		cin >> arr[i][j];
	}
	
	memset(mem, -1, sizeof mem);
	
	int ans = go(sz[0]-1, sz[1]-1, sz[2]-1, sz[3]-1);
	cout << ans << endl;
}
