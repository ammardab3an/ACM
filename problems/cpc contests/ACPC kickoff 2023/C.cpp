
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
 
const int NMAX = 5e5 + 10;

int n, m;
vector<string> grid;
vector<vector<bool>> vis;
pii mvArr[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
pii mvArr2[] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

bool in(int i, int j){
	return 0 <= i && i < n && 0 <= j && j < m;
}

bool check(int i, int j){
	
	for(auto [di, dj] : mvArr2){
		int ni = i+di;
		int nj = j+dj;
		if(!in(ni, nj) || grid[ni][nj]!='.'){
			return false;
		}
	}	
	
	return true;
}

int bfs(int i, int j){
	
	queue<pii> que;
	que.push({i, j});
	vis[i][j] = true;
	
	int ret = 0;
	
	while(!que.empty()){
		
		auto [i, j] = que.front();
		que.pop();
		
		ret++;
		
		for(auto [di, dj] : mvArr){
			int ni = i+di;
			int nj = j+dj;
			if(check(ni, nj) && grid[ni][nj]=='.' && !vis[ni][nj]){
				vis[ni][nj] = true;
				que.push({ni, nj});
			}
		}
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
    
    grid.resize(n);
    vis.resize(n, vector<bool>(m));
    
    for(int i = 0; i < n; i++){
    	cin >> grid[i];
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) if(!vis[i][j]) if(check(i, j)){
    	ans = max(ans, bfs(i, j));	
    }
    
    cout << ans << endl;
}
