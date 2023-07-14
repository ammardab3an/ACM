
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

const int n=8,m=8;
char grid[n][m];
bool vis[n][m];

bool in(int i, int j){
	return 0 <= i && i < n && 0 <= j && j < m;	
}

void go_rock(int x, int y){
	
	for(int i = y+1; i < m; i++){
		if(grid[x][i] != '.') break;
		vis[x][i] = true;
	}
	
	for(int i = y-1; i >= 0; i--){
		if(grid[x][i] != '.') break;
		vis[x][i] = true;
	}
	
	for(int i = x+1; i < n; i++){
		if(grid[i][y] != '.') break;
		vis[i][y] = true;
	}
	
	for(int i = x-1; i >= 0; i--){
		if(grid[i][y] != '.') break;
		vis[i][y] = true;
	}
}

void go_bishop(int x, int y){
	
	for(int i = 1; i < 8; i++){
		int xx = x+i;
		int yy = y+i;
		if(!in(xx, yy) || grid[xx][yy]!='.') break;
		vis[xx][yy] = true;
	}
	for(int i = 1; i < 8; i++){
		int xx = x+i;
		int yy = y-i;
		if(!in(xx, yy) || grid[xx][yy]!='.') break;
		vis[xx][yy] = true;
	}
	for(int i = 1; i < 8; i++){
		int xx = x-i;
		int yy = y+i;
		if(!in(xx, yy) || grid[xx][yy]!='.') break;
		vis[xx][yy] = true;
	}
	for(int i = 1; i < 8; i++){
		int xx = x-i;
		int yy = y-i;
		if(!in(xx, yy) || grid[xx][yy]!='.') break;
		vis[xx][yy] = true;
	}
}

void go_knight(int x, int y){
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++){
		
		int d0 = abs(i-x);
		int d1 = abs(j-y);
		if(d0 > d1) swap(d0, d1);
		
		if(d0==1 && d1==2){
			vis[i][j] = true;
		}
	}	
}

void go_pawn(int i, int j){
	if(in(i-1, j+1)){
		vis[i-1][j+1] = true;
	}	
	if(in(i-1, j-1)){
		vis[i-1][j-1] = true;
	}
}

void fill_vis(){
	
	memset(vis, 0, sizeof vis);
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++){
		
		if(grid[i][j]=='Q'){
			go_rock(i, j);
			go_bishop(i, j);
		}
		else if(grid[i][j]=='P'){
			go_pawn(i, j);
		}
		else if(grid[i][j]=='N'){
			go_knight(i, j);
		}
		else if(grid[i][j]=='B'){
			go_bishop(i, j);
		}
		else if(grid[i][j]=='R'){
			go_rock(i, j);
		}
	}
}

bool check_king(int x, int y){
	
	for(int i = -1; i <= 1; i++)
	for(int j = -1; j <= 1; j++){
		if(in(x+i, y+j)){
			
			char c = grid[x+i][y+j];
			grid[x+i][y+j] = '.';
			grid[x][y] = '.';
			
			fill_vis();
			
			if(!vis[x+i][y+j]){
				return true;
			}
			
			grid[x][y] = 'K';
			grid[x+i][y+j] = c;
		}
	}	
	
	return false;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		for(int i = 0; i < n; i++){
			cin >> grid[i];
		}
		
		int x0=-1, y0=-1;
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			if(grid[i][j]=='K'){
				x0 = i, y0 = j;
				break;
			}
		}
		
		assert(x0!=-1 && y0!=-1);
		
		cout << (check_king(x0, y0) ? "Yes" : "No") << endl;
    }	
}
