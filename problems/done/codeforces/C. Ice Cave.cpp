// Problem: C. Ice Cave
// Contest: Codeforces - Codeforces Round #301 (Div. 2)
// URL: https://codeforces.com/problemset/problem/540/C
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

int n, m;
char grid[555][555];
bool vis[555][555];
pii mvArr[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool in(int i, int j){
	return 0 <= i && i < n && 0 <= j && j < m;
}

void bfs(int i, int j){
	
	vis[i][j] = true;
	queue<pii> que;
	que.push({i, j});
	
	while(!que.empty()){
		
		pii fr = que.front();
		que.pop();
		
		int i = fr.first;
		int j = fr.second;
		
		for(auto p : mvArr){
			
			int ni = i + p.first;
			int nj = j + p.second;
			
			if(in(ni, nj) && grid[ni][nj]=='.' && !vis[ni][nj]){
				vis[ni][nj] = true;
				que.push({ni, nj});
			}
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
    for(int i = 0; i < n; i++)
    	cin >> grid[i];
    
    
    int i0, j0;
    cin >> i0 >> j0;
    i0--, j0--;
    
    int i1, j1;
    cin >> i1 >> j1;
    i1--, j1--;
    
    if(i0==i1 && j0==j1){
    	
    	int cnt = 0;
    	for(auto p : mvArr){
    		int ni = i1+p.first;
    		int nj = j1+p.second;
    		if(in(ni, nj) && grid[ni][nj]=='.'){
    			cnt++;
    		}
    	}
    	
    	cout << (cnt >= (1+(grid[i0][j0]=='.')) ? "YES" : "NO") << endl;
    	
    	return 0;
    }
    
    if(grid[i1][j1]=='X'){
    	grid[i1][j1] = '.';
    	bfs(i0, j0);
    	cout << (vis[i1][j1] ? "YES" : "NO") << endl;
    }
    else{
    	
    	grid[i1][j1] = 'X';
    	bfs(i0, j0);
    	
    	int cnt = 0;
    	bool found = false;
    	
    	for(auto p : mvArr){
    		int ni = i1+p.first;
    		int nj = j1+p.second;
    		if(in(ni, nj)){			
				found |= vis[ni][nj];
				cnt += grid[ni][nj]=='.' || vis[ni][nj];
    		}
    	}
    	
    	// cout << cnt << ' ' << found << endl;
    	
    	cout << (cnt >= 2 && found ? "YES" : "NO") << endl;
    }
}
