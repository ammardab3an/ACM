
// K. Kooky Tic-Tac-Toe
// https://qoj.ac/contest/1103/problem/5509

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

int n, k;
char grid[10][10];

bool check(){
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++) if(grid[i][j] != '.'){
		
		int cnt = 0;
		char c = grid[i][j];
		
		if(i+k-1 < n){
			bool good = true;
			for(int l = 0; l < k; l++) if(grid[i+l][j] != c){
				good = false;
				break;
			}
			cnt += good;
		}
		
		if(j+k-1 < n){
			bool good = true;
			for(int l = 0; l < k; l++) if(grid[i][j+l] != c){
				good = false;
				break;
			}
			cnt += good;
		}
		
		if(i+k-1 < n && j+k-1 < n){
			bool good = true;
			for(int l = 0; l < k; l++) if(grid[i+l][j+l] != c){
				good = false;
				break;
			}
			cnt += good;
		}
		
		if(i+k-1 < n && j-k+1 >= 0){
			bool good = true;
			for(int l = 0; l < k; l++) if(grid[i+l][j-l] != c){
				good = false;
				break;
			}
			cnt += good;
		}
		
		if(cnt){
			return true;
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
    
	// init();
	
    int t; cin >> t; while(t--){
		
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			cin >> grid[i];
		}
		
		bool init_check = check();
		
		vpii tmp;
		int cnt_non_zero = 0;
		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) if(grid[i][j] != '.'){
			cnt_non_zero++;
			if(init_check){
				char c = grid[i][j];
				grid[i][j] = '.';
				if(!check()){
					tmp.push_back({i, j});
				}
				grid[i][j] = c;
			}
		}
		
		bool bad = false;
		bad |= !init_check && (cnt_non_zero!=(n*n));
		bad |= init_check && tmp.empty();
		
		if(bad){
			cout << "NIE" << endl;
			continue;
		}
		
		int i0 = -1;
		int j0 = -1;
		
		if(!tmp.empty()){
			i0 = tmp[0].first;
			j0 = tmp[0].second;
		}
		
		vector<vpii> ttmp(2);
		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) if(grid[i][j] != '.') if((i != i0) || (j != j0)){
			ttmp[grid[i][j]=='o'].push_back({i, j});
		}
		
		bool c0 = (i0!=-1) ? (grid[i0][j0]=='o') : (ttmp[1].size() >= ttmp[0].size());
		
		if(i0 != -1){
			ttmp[c0].push_back({i0, j0});
		}
		
		vpii ans;
		while(!ttmp[c0].empty()){
			ans.push_back(ttmp[c0].back());
			ttmp[c0].pop_back();
			c0 = !c0;
		}
		
		if(ttmp[0].size() || ttmp[1].size()){
			cout << "NIE" << endl;
			continue;
		}
		
		reverse(ans.begin(), ans.end());
		
		cout << "TAK" << endl;
		for(auto [i, j] : ans){
			cout << i+1 << ' ' << j+1 << endl;
		}
    }	
}
