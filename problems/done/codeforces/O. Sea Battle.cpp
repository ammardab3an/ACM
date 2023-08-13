// Problem: O. Sea Battle
// Contest: Codeforces - ICPC Central Russia Regional Contest, 2021
// URL: https://codeforces.com/gym/104454/problem/O
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int fac[NMAX], ifac[NMAX];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

string grid[10];
pii par[10][10];
int sz[10][10];
int dm[10][10];
bool vis[10][10];
pii mvArr[] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

pii get_par(pii a){
	if(par[a.first][a.second]==a) return a;
	return par[a.first][a.second] = get_par(par[a.first][a.second]);	
}

void merge(pii a, pii b){
	
	a = get_par(a);
	b = get_par(b);
	
	if(a == b) return;
	
	par[a.first][a.second] = b;
	sz[b.first][b.second] += sz[a.first][a.second];
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	for(int i = 0; i < 10; i++){
		cin >> grid[i];
	}
	
	for(int i = 0; i < 10; i++)
	for(int j = 0; j < 10; j++){
		par[i][j] = {i, j};
		sz[i][j] = 1;
	}
	
	for(int i = 0; i < 10; i++)
	for(int j = 0; j < 10; j++) if(grid[i][j] == '#'){
		for(auto [di, dj] : mvArr){
			int ni = i + di;
			int nj = j + dj;
			if(0 <= ni && ni < 10 && 0 <= nj && nj < 10) if(grid[ni][nj]=='#'){
				merge({i, j}, {ni, nj});
			}
		}
	}
	
	vi cnt(3);
	cnt[0] = 10;
	
	int q; cin >> q; while(q--){
		
		string str;
		cin >> str;
		
		if(str=="SHOW"){
			for(auto e : cnt) cout << e << ' '; cout << endl;
		}
		else{
			
			int i, j;
			cin >> i >> j;
			i--, j--;
			
			if(grid[i][j]=='*' || vis[i][j]) continue;
			vis[i][j] = true;
			
			pii p = get_par({i, j});
			int &dd = dm[p.first][p.second];
			int &ss = sz[p.first][p.second];
			dd++;
			
			if(dd==1){
				cnt[0]--;
				cnt[1]++;
			}
			
			if(dd==ss){
				cnt[1]--;
				cnt[2]++;
			}
		}
	}
}
