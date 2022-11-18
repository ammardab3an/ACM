// Problem: E - Round Trip
// Contest: AtCoder - AtCoder Beginner Contest 276
// URL: https://atcoder.jp/contests/abc276/tasks/abc276_e
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
vector<string> grid;
vector<vector<bool>> vis;
vpii mvArr = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool in(int i, int j){
	return 0 <= i && i < n && 0 <= j && j <= m;
}

void go(int i, int j){
	vis[i][j] = true;
	for(auto [di, dj] : mvArr){
		int ni = i + di;
		int nj = j + dj;
		if(in(ni, nj) && grid[ni][nj]=='.' && !vis[ni][nj]){		
			go(ni, nj);
		}
	}	
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    
    grid.resize(n);
    vis.resize(n, vector<bool>(m));
    
    for(int i = 0; i < n; i++){
    	cin >> grid[i];
    }
    
    pii s;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) if(grid[i][j]=='S'){
    	s = {i, j};
    	break;
    }
    
    bool ans = false;
    
    for(auto [di, dj] : mvArr){
    	
    	int ni = di + s.first;
    	int nj = dj + s.second;
    	
    	if(in(ni, nj) && grid[ni][nj]=='.'){
    		if(vis[ni][nj]){
    			ans = true;
    			break;
    		}
    		else{			
	    		go(ni, nj);
    		}
    	}
    }
    
    cout << (ans ? "Yes" : "No") << endl;
}
