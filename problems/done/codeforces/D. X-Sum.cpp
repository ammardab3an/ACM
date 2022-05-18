// Problem: D. X-Sum
// Contest: Codeforces - Codeforces Round #790 (Div. 4)
// URL: https://codeforces.com/contest/1676/problem/D
// Memory Limit: 256 MB
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

		int n, m;
		cin >> n >> m;
		
		vector<vi> grid(n, vi(m));
		
		for(auto &v : grid)
		for(auto &i : v) cin >> i;
		
		vector<vi> v0(n, vi(m)), v1=v0, v2=v0, v3=v0;
		
		{
			v0[0] = grid[0];
			for(int i = 1; i < n; i++){
				v0[i][0] = grid[i][0];
				for(int j = 1; j < m; j++){
					v0[i][j] = v0[i-1][j-1] + grid[i][j];
				}
			}
		}
		{
			v1[0] = grid[0];
			for(int i = 1; i < n; i++){
				v1[i][m-1] = grid[i][m-1];
				for(int j = m-2; j >= 0; j--){
					v1[i][j] = v1[i-1][j+1] + grid[i][j];
				}
			}
		}
		{
			v2[n-1] = grid[n-1];
			for(int i = n-2; i >= 0; i--){
				v2[i][0] = grid[i][0];
				for(int j = 1; j < m; j++){
					v2[i][j] = v2[i+1][j-1] + grid[i][j];
				}
			}
		}
		{
			v3[n-1] = grid[n-1];
			for(int i = n-2; i >= 0; i--){
				v3[i][m-1] = grid[i][m-1];
				for(int j = m-2; j >= 0; j--){
					v3[i][j] = v3[i+1][j+1] + grid[i][j];
				}
			}
		}
		
		int ans = 0;
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			
			int cans = v0[i][j] + v1[i][j] + v2[i][j] + v3[i][j];
			cans -= 3 * grid[i][j];
			
			ans = max(ans, cans);
		}
		
		cout << ans << endl;
    }	
}
