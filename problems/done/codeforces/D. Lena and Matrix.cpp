// Problem: D. Lena and Matrix
// Contest: Codeforces - Codeforces Round #798 (Div. 2)
// URL: https://codeforces.com/contest/1689/problem/D
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

char grid[1010][1010];
int pre[4][1010][1010];

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
		
		for(int i = 0; i < n; i++){
			cin >> grid[i];
		}
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			
			if(grid[i][j]=='B'){
				pre[0][i][j] = -i -j;
			}
			else{
				pre[0][i][j] = -INF;
			}
			
			if(i) pre[0][i][j] = max(pre[0][i][j], pre[0][i-1][j]);
			if(j) pre[0][i][j] = max(pre[0][i][j], pre[0][i][j-1]);
		}
		
		for(int i = n-1; i >= 0; i--)
		for(int j = m-1; j >= 0; j--){
			
			if(grid[i][j]=='B'){
				pre[1][i][j] = +i +j;
			}
			else{
				pre[1][i][j] = -INF;
			}
			
			if(i+1<n) pre[1][i][j] = max(pre[1][i][j], pre[1][i+1][j]);
			if(j+1<m) pre[1][i][j] = max(pre[1][i][j], pre[1][i][j+1]);
		}
		
		for(int i = 0; i < n; i++)
		for(int j = m-1; j >= 0; j--){
			
			if(grid[i][j]=='B'){
				pre[2][i][j] = -i +j;
			}
			else{
				pre[2][i][j] = -INF;
			}
			
			if(i) pre[2][i][j] = max(pre[2][i][j], pre[2][i-1][j]);
			if(j+1<m) pre[2][i][j] = max(pre[2][i][j], pre[2][i][j+1]);
		}
		
		for(int i = n-1; i >= 0; i--)
		for(int j = 0; j < m; j++){
			
			if(grid[i][j]=='B'){
				pre[3][i][j] = +i -j;
			}
			else{
				pre[3][i][j] = -INF;
			}
			
			if(i+1<n) pre[3][i][j] = max(pre[3][i][j], pre[3][i+1][j]);
			if(j) pre[3][i][j] = max(pre[3][i][j], pre[3][i][j-1]);
		}
		
		int ans = INF;
		pii ans_cor;
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			
			int cans0 = +i+j + pre[0][i][j];
			int cans1 = -i-j + pre[1][i][j];
			int cans2 = +i-j + pre[2][i][j];
			int cans3 = -i+j + pre[3][i][j];
			
			int cans = max({cans0, cans1, cans2, cans3});
			
			if(ans > cans){
				ans = cans;
				ans_cor = {i, j};
			}
		}
		
		// cout << ans << endl;
		cout << ans_cor.first+1 << ' ' << ans_cor.second+1 << endl;
    }	
}
