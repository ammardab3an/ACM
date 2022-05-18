// Problem: J. Anti-merge
// Contest: Codeforces - 2021 Jiangsu Collegiate Programming Contest
// URL: https://codeforces.com/gym/103495/problem/J
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

int n, m;
int grid[555][555];
int val[555][555];
int vis[555][555], vid;

pii mvArr[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool in(int i, int j){
	return 0 <= i && i < n && 0 <= j && j < m;
}

int dfs(int i, int j, int color, bool val, bool fill){
	
	int ret = 0;
	
	if(val){
		ret += 1;
		if(fill){
			::val[i][j] = 1;
		}
	}	
	
	vis[i][j] = vid;
	
	for(auto p : mvArr){
		
		int ni = i + p.first;
		int nj = j + p.second;
		
		if(!in(ni, nj) || vis[ni][nj]==vid || grid[ni][nj] != color) continue;
		
		ret += dfs(ni, nj, color, !val, fill);
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
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> grid[i][j];
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) if(!vis[i][j]){
    	
    	vid++;
    	int st_path = dfs(i, j, grid[i][j], 0, 0);
    	vid++;
    	int nd_path = dfs(i, j, grid[i][j], 1, 0);
    	
    	if(st_path < nd_path){
    		vid++;
    		dfs(i, j, grid[i][j], 0, 1);
    	}
    	else{
    		vid++;
    		dfs(i, j, grid[i][j], 1, 1);
    	}
    }
    
    // for(int i = 0; i < n; i++){
    	// for(int j = 0; j < m; j++){
    		// cout << val[i][j] << ' ';
    	// }
    	// cout << endl;
    // }
    
    vpii ans;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) if(val[i][j]){
    	ans.push_back({i, j});
    }
    
    if(!ans.size()){
    	cout << "0 0" << endl;
    	return 0;
    }
    
    cout << 1 << ' ' << ans.size() << endl;
    for(auto [i, j] : ans){
    	cout << i+1 << ' ' << j+1 << ' ' << 1 << endl;
    }
}
