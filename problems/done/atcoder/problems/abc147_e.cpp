// Problem: E - Balanced Path
// Contest: AtCoder - AtCoder Beginner Contest 147
// URL: https://atcoder.jp/contests/abc147/tasks/abc147_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m;
int arr_a[88][88];
int arr_b[88][88];
int mem[88][88][88*88*2];

int go(int i, int j, int sm){
	
	int &ret = mem[i][j][sm];
	if(ret+1) return ret;
	
	if(i==n-1 && j==m-1){
		int st_path = abs(sm + arr_a[i][j] - arr_b[i][j]);
		int nd_path = abs(sm - arr_a[i][j] + arr_b[i][j]);
		return ret = min(st_path, nd_path);
	}	
	
	int ans = INF;
	
	if(i != n-1){
		int st_path = go(i+1, j, abs(sm + arr_a[i][j] - arr_b[i][j]));
		int nd_path = go(i+1, j, abs(sm - arr_a[i][j] + arr_b[i][j]));
		ans = min({ans, st_path, nd_path});
	}
	if(j != m-1){
		int st_path = go(i, j+1, abs(sm + arr_a[i][j] - arr_b[i][j]));
		int nd_path = go(i, j+1, abs(sm - arr_a[i][j] + arr_b[i][j]));
		ans = min({ans, st_path, nd_path});
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
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
    	cin >> arr_a[i][j];
    }
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
    	cin >> arr_b[i][j];
    }
    
    memset(mem, -1, sizeof mem);
    
    int ans = go(0, 0, 0);
    cout << ans << endl;
}
