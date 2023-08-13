// Problem: G - Banned Substrings
// Contest: AtCoder - KYOCERA Programming Contest 2023（AtCoder Beginner Contest 305）
// URL: https://atcoder.jp/contests/abc305/tasks/abc305_g
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
const int MOD = 998244353; // 1e9 + 7;
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

struct matrix{
	
	array<array<int, 64>, 64> mat = {0};
	
	matrix operator * (const matrix &other){
		
		matrix ret;
		
		for(int k = 0; k < 64; k++)
		for(int i = 0; i < 64; i++)
		for(int j = 0; j < 64; j++){
			ret.mat[i][j] = add(ret.mat[i][j], mul(mat[i][k], other.mat[k][j]));
		}
		
		return ret;
	}
};

matrix mat_pow(matrix m, int p){
	
	matrix ret;
	for(int i = 0; i < 64; i++){
		ret.mat[i][i] = 1;
	}
	
	while(p){
		if(p&1) ret = ret * m;
		m = m * m;
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
    
	// init();
	
	int n, m;
	cin >> n >> m;
	
	vector<bool> bad(1<<6);
	while(m--){
	
		string s;
		cin >> s;
	
		if(s.size() > n) continue;
		
		int x = 0;
		for(auto c : s){
			x *= 2;
			if(c=='b') x++;
		}
		
		int mn = min(n, int(6));
		int ln = s.size();
		int k = mn-ln;
		
		for(int i = 0; i < (1<<mn); i++) if(!bad[i]){
			bool good = true;
			for(int j = 0; j <= k; j++){
				if(((i>>j) & ((1<<ln)-1)) == x){
					good = false;
					break;
				}
			}
			if(!good) bad[i] = true;
		}
	}
	
	if(n < 6){
		int ans = 0;
		for(int i = 0; i < (1<<n); i++){
			ans += !bad[i];
		}
		cout << ans << endl;
		return 0;
	}
	
	matrix a;
	for(int i = 0; i < (1<<6); i++){
		a.mat[i][0] = !bad[i];
	}
	
	matrix mm;
	for(int i = 0; i < (1<<6); i++) if(!bad[i]){
		
		int x = (i<<1) & ((1<<6)-1);
		int y = ((i<<1)|1) & ((1<<6)-1);
		
		if(!bad[x]){
			mm.mat[i][x] = 1;
		}
		if(!bad[y]){
			mm.mat[i][y] = 1;
		}
	}
	
	matrix res = mat_pow(mm, n-6) * a;
	
	int ans = 0;
	for(int i = 0; i < (1<<6); i++) if(!bad[i]){
		ans = add(ans, res.mat[i][0]);
	}
	
	cout << ans << endl;
}
