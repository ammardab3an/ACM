// Problem: B. Putting Bricks in the Wall
// Contest: Codeforces - Codeforces Round 676 (Div. 2)
// URL: https://codeforces.com/contest/1421/problem/B
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

char grid[222][222];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		for(int i = 0; i < n; i++){
			cin >> grid[i];
		}
		
		vpii ans;
		
		bool b0 = grid[0][1]-'0';
		bool b1 = grid[1][0]-'0';
		bool d0 = grid[n-1][n-2]-'0';
		bool d1 = grid[n-2][n-1]-'0';
		
		if(b0==b1){
			if(d0 == b0){
				ans.push_back({n, n-1});
			}
			if(d1 == b0){
				ans.push_back({n-1, n});
			}
		}
		else if(d0==d1){
			if(b0 == d0){
				ans.push_back({1, 2});
			}
			if(b1 == d0){
				ans.push_back({2, 1});
			}
		}
		else{
			if(b0 != 0){
				ans.push_back({1, 2});
			}
			if(b1 != 0){
				ans.push_back({2, 1});
			}
			if(d0 != 1){
				ans.push_back({n, n-1});
			}
			if(d1 != 1){
				ans.push_back({n-1, n});
			}
		}
		
		cout << ans.size() << endl;
		for(auto [i, j] : ans){
			cout << i << ' ' << j << endl;
		}
    }	
}
