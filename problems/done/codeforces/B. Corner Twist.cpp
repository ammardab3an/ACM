// Problem: B. Corner Twist
// Contest: Codeforces - Codeforces Round #956 (Div. 2) and ByteRace 2024
// URL: https://codeforces.com/contest/1983/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include <bits/stdc++.h>

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

// int fac[NMAX], ifac[NMAX];
// 
// void init(){
// 	
	// fac[0] = 1;
	// for(int i = 1; i < NMAX; i++){
		// fac[i] = mul(fac[i-1], i);
	// }
// 	
	// ifac[NMAX-1] = inv(fac[NMAX-1]);
	// for(int i = NMAX-2; i >= 0; i--){
		// ifac[i] = mul(ifac[i+1], i+1);
	// }
// }
// 
// int choose(int n, int c){
	// assert(n >= c);
	// return mul(fac[n], mul(ifac[c], ifac[n-c]));
// }

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
    int t; cin >> t; while(t--){

		int n, m;
		cin >> n >> m;
		
		vector<vi> grid(n, vi(m));
		
		for(int i = 0; i < n; i++){
			string row;
			cin >> row;
			for(int j = 0; j < m; j++){
				grid[i][j] = row[j]-'0';
			}
		}
		
		for(int i = 0; i < n; i++){
			string row;
			cin >> row;
			for(int j = 0; j < m; j++){
				int x = row[j]-'0';			
				grid[i][j] = (x-grid[i][j]+3)%3;
			}
		}
		
		// for(auto v : grid){
			// for(auto e : v) cout << e;
			// cout << endl;
		// }
		// cout << endl;
		
		bool ans = true;
		
		for(int i = 0; i < n && ans; i++){
			
			for(int j = 0; j < m; j++) if(grid[i][j]){
				
				int k = j+1;
				while(k < m && !grid[i][k]) k++;
				
				if(k==m || i+1==n){
					ans = false;
					break;
				}
				
				int x = grid[i][j];
				grid[i][j] = 0;
				grid[i][k] = (grid[i][k]-(x==1 ? 2 : 1)+3)%3;
				grid[i+1][j] = (grid[i+1][j]-(x==1 ? 2 : 1)+3)%3;
				grid[i+1][k] = (grid[i+1][k]-x+3)%3;
			}
		}
		
		// for(auto v : grid){
			// for(auto e : v) cout << e;
			// cout << endl;
		// }
		
		cout << (ans ? "YES" : "NO") << endl;
    }	
}
