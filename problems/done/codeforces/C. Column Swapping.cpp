// Problem: C. Column Swapping
// Contest: Codeforces - Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1684/problem/C
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

bool test(int n, int m, vector<vi> &grid){
	
	for(int i = 0; i < n; i++)
	for(int j = 1; j < m; j++){
		if(grid[i][j-1] > grid[i][j]){
			return false;
		}
	}
	
	return true;
}

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
		
		if(test(n, m, grid)){
			cout << "1 1" << endl;
			continue;
		}
		
		vector<pii> tmp;
		
		for(int i = 0; i < n; i++){
			
			int l = -1;
			int r = -1;
			
			for(int j = 1; j < m; j++){
				if(grid[i][j-1] > grid[i][j]){
					l = j-1;
					break;
				}
			}
			
			for(int j = m-2; j >= 0; j--){
				if(grid[i][j+1] < grid[i][j]){
					r = j+1;
					break;
				}
			}
			
			tmp.push_back({l, r});
			
			// cout << '-' << ' ' << i << ' ' << tmp.size() << endl;
		}
		
		// cout << n << ' ' << m << ' ' << tmp.size() << endl;
		// for(auto [i, j] : tmp){
			// cout << ' ' << i << ' ' << j << endl;
		// }
		
		bool found = false;
		
		for(auto [i, j] : tmp) if(i!=-1 && j!=-1){
			
			found = true;
			
			for(int k = 0; k < n; k++)
				swap(grid[k][i], grid[k][j]);	
				
			if(test(n, m, grid)){
				cout << i+1 << ' ' << j+1 << endl;
			}
			else{
				cout << -1 << endl;
			}
			
			break;
		}
	
		if(!found){
			cout << -1 << endl;
		}
		
	}
}