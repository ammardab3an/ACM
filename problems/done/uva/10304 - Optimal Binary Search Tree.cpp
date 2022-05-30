// Problem: 10304 - Optimal Binary Search Tree
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1245
// Memory Limit: 32 MB
// Time Limit: 10000 ms
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    while(cin >> n){
    	
    	vi vec(n);
    	for(auto &i : vec) cin >> i;
    	
    	vector<vi> dp(n, vi(n));
    	vector<vi> pos(n, vi(n));
    	
    	vi pre(n);
    	pre[0] = vec[0];
    	for(int i = 1; i < n; i++){
    		pre[i] = pre[i-1] + vec[i];
    	}
    	
    	auto calc = [&](int l, int r, int i){
    		return pre[r] - pre[l] + vec[l] - vec[i];
    	};
    	
    	for(int len = 1; len <= n; len++){
    		
    		for(int j = len-1; j < n; j++){
    			int i = j-len+1;
    			
    			if(len==1){
    				dp[i][j] = 0;
    				pos[i][j] = i;
    				continue;
    			}
    			
    			int ans = INFLL;
    			int ans_p = -1;
    			
    			for(int k = pos[i][j-1]; k <= pos[i+1][j]; k++){
    			
    				int cans = calc(i, j, k);
    				if(k!=i) cans += dp[i][k-1];
    				if(k!=j) cans += dp[k+1][j];	
    			
    				if(cans < ans){
    					ans = cans;
    					ans_p = k;
    				}
    			}	
    			
    			dp[i][j] = ans;
    			pos[i][j] = ans_p;
    		}
    	}
    	
    	cout << dp[0][n-1] << endl;
    }
}
