// Problem: I. Mason's Mark
// Contest: Codeforces - 2018-2019 ICPC Southwestern European Regional Programming Contest (SWERC 2018)
// URL: https://codeforces.com/gym/102465/problem/I
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
char grid[1010][1010];
int pre[1010][1010];
bool vis[1010][1010];

void build(){
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++){
		pre[i][j] = grid[i][j]=='#';
		if(i) pre[i][j] += pre[i-1][j];
		if(j) pre[i][j] += pre[i][j-1];
		if(i && j) pre[i][j] -= pre[i-1][j-1]; 
	}
}

int calc_sub(int i0, int j0, int i1, int j1){
	
	int ret = pre[i1][j1];	
	if(i0) ret -= pre[i0-1][j1];
	if(j0) ret -= pre[i1][j0-1];
	if(i0 && j0) ret += pre[i0-1][j0-1];
	
	return ret;
}

int calc_val(int i0, int j0, int i1, int j1){
	
	if(i0 > i1) swap(i0, i1);
	if(j0 > j1) swap(j0, j1);
	
	int ret = calc_sub(i0, j0, i1, j1);
	
	if(ret==0){
		return 0;	
	}
	
	int area = (i1-i0+1) * (j1-j0+1);
	
	if(ret==area){
		return 1;
	}
	else{
		return -1;
	}
}

int calc_msk(int i, int j, int x, int y){
	
	int r0 = i;
    int r1 = i+x;
    int r2 = i+x+y;
    int r3 = i+x+y+x;
    int r4 = i+x+y+x+y;
    int r5 = i+x+y+x+y+x;
    
    int c0 = j;
    int c1 = j+x;
    int c2 = j+x+y;
    int c3 = j+x+y+x;

	vi vals(15);
	
    vals[0] = calc_val(r0, c0, r1-1, c1-1);
	vals[1] = calc_val(r0, c1, r1-1, c2-1);
	vals[2] = calc_val(r0, c2, r1-1, c3-1);
	vals[3] = calc_val(r1, c0, r2-1, c1-1);
	vals[4] = calc_val(r1, c1, r2-1, c2-1);
	vals[5] = calc_val(r1, c2, r2-1, c3-1);
	vals[6] = calc_val(r2, c0, r3-1, c1-1);
	vals[7] = calc_val(r2, c1, r3-1, c2-1);
	vals[8] = calc_val(r2, c2, r3-1, c3-1);
	vals[9] = calc_val(r3, c0, r4-1, c1-1);
	vals[10] = calc_val(r3, c1, r4-1, c2-1);
	vals[11] = calc_val(r3, c2, r4-1, c3-1);
	vals[12] = calc_val(r4, c0, r5-1, c1-1);
	vals[13] = calc_val(r4, c1, r5-1, c2-1);
	vals[14] = calc_val(r4, c2, r5-1, c3-1);
	
	int ret = 0;
	for(int k = 0; k < 15; k++){
		if(vals[k]==-1){
			return -1;
		}
		if(vals[k]==1){
			ret ^= 1 << k;
		}
	}
	
	return ret;
}

bool in(int i, int j){
	return 0 <= i && 0 <= j && i < n && j < m;
}

pii mn, mx;
void dfs(int i, int j){
	
	mn.first = min(mn.first, i);
	mn.second = min(mn.second, j);
	mx.first = max(mx.first, i);
	mx.second = max(mx.second, j);
	
	vis[i][j] = true;
	
	for(int ni = i-1; ni <= i+1; ni++)
	for(int nj = j-1; nj <= j+1; nj++) if(in(ni, nj)){
		if(!vis[ni][nj] && grid[ni][nj]=='#'){
			dfs(ni, nj);
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
    
    cin >> m >> n;
    for(int i = 0; i < n; i++){
    	cin >> grid[i];
    }
    
    for(int i = 1; i < n-1; i++)
    for(int j = 1; j < m-1; j++) if(grid[i][j]=='#'){
    	
    	int cnt = 0;
    	for(int ni = i-1; ni <= i+1; ni++)
    	for(int nj = j-1; nj <= j+1; nj++) if(grid[ni][nj]=='.'){
    		cnt++;
    	}	
    	
    	if(cnt==8){
    		grid[i][j] = '.';
    	}
    }
    
    build();
    
    vi cnt(3);
    vi msk(3);
    msk[0] = 0b101101111101111;
    msk[1] = 0b111101111101111;
    msk[2] = 0b111001001001111;
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) if(!vis[i][j] && grid[i][j]=='#'){
    	
    	::mn = {i, j};
    	::mx = {i, j};
    	
    	dfs(i, j);
    	
    	int a = mx.first-mn.first+1;
    	int b = mx.second-mn.second+1;
    	
    	int x = 2*b-a;
    	int y = b-2*x;
    	
    	if(x > 0 && y > 0){
    		int cur = calc_msk(i, j, x, y);
			for(int k = 0; k < 3; k++){
				cnt[k] += cur==msk[k];
			}
    	}
    }
    
    for(int i = 0; i < 3; i++){
    	cout << cnt[i] << ' ';
    }
}
