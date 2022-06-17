
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
char grid[111][111];
vpii mvArr = {{-1, 0}, {-1, 1}, {+1, 0}, {+1, 1}};

inline bool in(int i, int j){
	return 0 <= i && i < n && 0 <= j && j < m;
}

inline bool good(int i, int j){
	
	if(grid[i][j]=='*' || grid[i][j]=='?'){
		return false;
	}
	
	for(auto p : mvArr){
		
		int ni = i + p.first;
		int nj = j + p.second;
		
		if(in(ni, nj)) if(grid[ni][nj]=='#'){
			return false;
		}
	}
	
	return true;
}

inline void fill(int i, int j){
	
	grid[i][j] = '#';
	
	for(auto p : mvArr){
		
		int ni = i + p.first;
		int nj = j + p.second;
		
		if(in(ni, nj)) if(grid[ni][nj]=='.'){
			grid[ni][nj] = '?';
		}
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    freopen("event.in", "r", stdin);
    
    int t;
    scanf("%d", &t);
    
    while(t--){

		scanf("%d%d", &n, &m);
		
		for(int i = 0; i < n; i++){
			scanf("%s", grid[i]);
		}
		
		int ans = 0;
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			if(good(i, j)){
				fill(i, j);
				ans++;
			}	
		}
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) if(grid[i][j]=='?'){
			grid[i][j] = '.';
		}
		
		printf("%d\n", ans);
		for(int i = 0; i < n; i++){
			puts(grid[i]);
		}
    }	
}
