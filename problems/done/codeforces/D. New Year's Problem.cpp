// Problem: D. New Year's Problem
// Contest: Codeforces - Codeforces Round #762 (Div. 3)
// URL: https://codeforces.com/contest/1619/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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

		int m, n;
		cin >> m >> n;
		
		vector<vi> grid(m, vi(n));
		
		for(auto &v : grid)
		for(auto &i : v) cin >> i;
		
		vector<vi> vec(n, vi(m));
		
		for(int i = 0; i < n; i++){
			
			auto &v = vec[i];
			iota(v.begin(), v.end(), 0);
			sort(v.begin(), v.end(), [&](int _i, int _j){
				return grid[_i][i] < grid[_j][i];
			});
			
			// for(int j = 0; j < m; j++){
				// cout << vec[i][j] << ' ';
			// } cout << endl;
		}
		
		int ans = 0;
		
		{
			set<int> st;
			for(int j = 0; j < n; j++){
				st.insert(vec[j].back());	
			}
			if(st.size() < n){
				ans = INFLL;
				for(int i = 0; i < n; i++){
					ans = min(ans, grid[vec[i].back()][i]);
				}		
			}
		}
		
		if(ans){
			cout << ans << endl;
			continue;
		}
		
		vector<vi> _vec(m, vi(n));
		
		for(int i = 0; i < m; i++){
			
			auto &v = _vec[i];
			iota(v.begin(), v.end(), 0);
			sort(v.begin(), v.end(), [&](int _i, int _j){
				return grid[i][_i] < grid[i][_j];
			});
		}
		
		for(int i = 0; i < m; i++){
			
			int a = _vec[i][n-1];
			int b = _vec[i][n-2];
			
			int cans = INFLL;
			for(int i = 0; i < n; i++) if(i != a && i != b){
				cans = min(cans, grid[vec[i].back()][i]);
			}	
			
			cans = min(cans, grid[i][a]);
			cans = min(cans, grid[i][b]);
			
			ans = max(ans, cans);
			
			// cout << i << ' ' << cans << endl;
		}
		
		cout << ans << endl;
    }	
}
