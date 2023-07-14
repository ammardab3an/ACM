// Problem: D. XOR Counting
// Contest: Codeforces - Codeforces Round 865 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1815/D
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
const int MOD = 998244353; // 1e9 + 7;
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

int n;
int mem[66][66][11];

int go(int i, int j, int rm){
	
	if(rm < 0){
		return 0;
	}
	
	if(i==-1){
		return rm==0;
	}
	
	if((n>>i)&1){
		rm++;
	}
	
	if(rm > 4){
		return 0;
	}
	
	int &ret = mem[j][i][rm];
	if(ret+1) return ret;
	
	if(i==j){
		int st_path = go(i-1, j, (rm-1)*2);
		return ret = st_path;
	}
	else{
		int st_path = go(i-1, j, rm*2);
		int nd_path = go(i-1, j, (rm-2)*2);
		int rd_path = go(i-1, j, (rm-1)*2);
		return ret = (st_path + nd_path + rd_path) % MOD;
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int _2 = pow_exp(2, MOD-2);
    
    int t; cin >> t; while(t--){
    	
	 	int n, m;
	 	cin >> n >> m;
	 	
	 	// n = 576460752303423488ll;
	 	// m = 2;
	 	
	 	if(m==1){
	 		cout << n%MOD << endl;
	 	}   
	 	else if(m>=3){
	 		
	 		int a = n%2;
	 		int b = n;
	 		int cnt = (b-a)/2 + 1;
	 		
	 		int ans = mul(add(a, b), mul(cnt, _2));
	 		cout << ans << endl;
	 	}
	 	else{
	 		
	 		::n = n;
	 		memset(mem, -1, sizeof mem);
	 		
	 		int ans = 0;
	 		for(int i = 60; i >= 0; i--){
	 			int cans = mul(1ll<<i, go(60, i, 0));
	 			ans = add(ans, cans);
	 		}
	 		
	 		cout << ans << endl;
	 	}
    }
}
