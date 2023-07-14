// Problem: Moving Robots
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1726
// Memory Limit: 512 MB
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

typedef long double dt;

const int n = 8;
pii mvArr[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool vis[n][n][n][n][111];
dt mem[n][n][n][n][111];

bool good(int i, int j){
	return 0 <= i && i < n && 0 <= j && j < n;	
}

dt go(int i, int j, int x, int y, int rem){
	
	if(!rem){
		return (i!=x) || (j!=y);
	}
	
	auto &ret = mem[x][y][i][j][rem];
	auto &vis = ::vis[x][y][i][j][rem];
	if(vis) return ret;
	vis = true;
	
	dt ans = 0;
	
	int cnt = 0;
	if(i) cnt++;
	if(j) cnt++;
	if(i < n-1) cnt++;
	if(j < n-1) cnt++;
	
	for(auto [di, dj] : mvArr){
		
		int ni = i + di;
		int nj = j + dj;
		
		if(good(ni, nj)){
			ans += go(ni, nj, x, y, rem-1) / dt(cnt);
		}
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
	
	int k;
	cin >> k;
	
	dt ans = 0;
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++){
		
		dt p = 1;
			
		for(int x = 0; x < n; x++)
		for(int y = 0; y < n; y++){
			p *= go(x, y, i, j, k);
		}
		
		ans += p;
	}
	
	cout << fixed << setprecision(6) << ans << endl;
}
