// Problem: F - Manhattan Cafe
// Contest: AtCoder - AtCoder Beginner Contest 265
// URL: https://atcoder.jp/contests/abc265/tasks/abc265_f
// Memory Limit: 1024 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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


int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, d;
    cin >> n >> d;
    
    vi vec_a(n), vec_b(n);
    for(auto &i : vec_a) cin >> i;
    for(auto &i : vec_b) cin >> i;
    
    vector<vi> dp(d+1, vi(d+1, 1));
    
    auto calc = [&](const vector<vi> &vec, bool b){
    	vector<vi> ret = vec;
    	if(b) for(auto &v : ret) reverse(v.begin(), v.end());
    	for(int i = 1; i <= d; i++)
    	for(int j = 1; j <= d; j++){
    		ret[i][j] = add(ret[i][j], ret[i-1][j-1]);
    	}
    	if(b) for(auto &v : ret) reverse(v.begin(), v.end());
    	return ret;
    };
    
    auto v0 = calc(dp, 0);
    auto v1 = calc(dp, 1);
    
    for(int k = 0; k < n; k++){
    	
    	vector<vi> ndp(d+1, vi(d+1));
    	
    	int s = abs(vec_a[k]-vec_b[k]);
    	
    	for(int i = 0; i <= d; i++)
    	for(int j = 0; j <= d; j++){
    		
    		if(i && (j-(s+1)) >= 0){
    			ndp[i][j] = add(ndp[i][j], v0[i-1][j-(s+1)]);
    		}
    		
    		if(j && (i-(s+1)) >= 0){
    			ndp[i][j] = add(ndp[i][j], v0[i-(s+1)][j-1]);
    		}
    		
    		int i0 = i;
    		int j0 = j-s;
    		if(j0 < 0){
    			i0 -= -j0;
    			j0 = 0;
    		}
    		int i1 = i-s;
    		int j1 = j;
    		if(i1 < 0){
    			j1 -= -i1;
    			i1 = 0;
    		}
    		i1--;
    		j1++;
    		
    		if(i0 >= 0){
    			ndp[i][j] = add(ndp[i][j], v1[i0][j0]);
    			if(i1 >=0 && j1 <= d){
    				ndp[i][j] = add(ndp[i][j], mul(-1, v1[i1][j1]));
    			}
    		}
    	}
    	
    	swap(dp, ndp);
    	v0 = calc(dp, 0);
	    v1 = calc(dp, 1);
    }
    
    cout << dp[d][d] << endl;
}
