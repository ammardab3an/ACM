// Problem: E. Comb
// Contest: Codeforces - School Personal Contest #2 (Winter Computer School 2010/11) - Codeforces Beta Round #43 (ACM-ICPC Rules)
// URL: https://codeforces.com/problemset/problem/46/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    vector<vi> grid(n, vi(m));
    
    for(auto &v : grid)
    for(auto &i : v) cin >> i;
    
    for(int i = 0; i < n; i++){
    	for(int j = 1; j < m; j++){
    		grid[i][j] += grid[i][j-1];
    	}
    }
    
    vi dp(m), pre(m), suf(m);
    
    for(int i = n-1; i >= 0; i--){
    	
		vi new_dp(m, -INFLL);
    	
    	for(int j = 0; j < m; j++){
    		
    		if(i%2==0){
    			new_dp[j] = j ? pre[j-1]+grid[i][j] : -INFLL;
    		}
    		else{
    			new_dp[j] = j+1<m ? suf[j+1]+grid[i][j] : -INFLL;
    		}
    	}
    	
    	dp = new_dp;
    	pre[0] = dp[0];
    	for(int i = 1; i < m; i++){
    		pre[i] = max(pre[i-1], dp[i]);
    	}
    	suf[m-1] = dp[m-1];
    	for(int i = m-2; i >= 0; i--){
    		suf[i] = max(suf[i+1], dp[i]);
    	}
    	
    	for(auto i : dp) cout << i << ' '; cout << endl;
    }
    
    cout << *max_element(dp.begin(), dp.end()) << endl;
}