// Problem: F - Numbered Checker
// Contest: AtCoder - UNICORN Programming Contest 2022(AtCoder Beginner Contest 269)
// URL: https://atcoder.jp/contests/abc269/tasks/abc269_f
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    auto calc = [](int p, bool b)->int{
    	if(!p){
    		return 0;
    	}
    	if(!b){
    		if(p%2==1) p--;
    		int ret = (p*(p/2+1))/2;
    		return ret%MOD;
    	}
    	else{
    		if(p%2==0) p--;
    		int ret = ((p+1)*(p/2+1))/2;
    		return ret%MOD;
    	}
    };
    
    auto cnt = [](int p, bool b)->int{
		int ret = (p+b)/2;
		return ret%MOD;
    };
    
    int q; cin >> q; while(q--){
    	
    	int x0, x1;
    	cin >> x0 >> x1;
    	
    	int y0, y1;
    	cin >> y0 >> y1;
    	
    	int ans = 0;
    	
    	for(auto b : {0, 1}){
    		
	    	int calc_r = add(calc(y1, b), mul(-1, calc(y0-1, b)));
	    	int calc_c = add(calc(x1, b), mul(-1, calc(x0-1, b)));
	    	
	    	int cnt_r = add(cnt(y1, b), mul(-1, cnt(y0-1, b)));
	    	int cnt_c = add(cnt(x1, b), mul(-1, cnt(x0-1, b)));
	    	
	    	int st_path = mul(calc_r, cnt_c);
	    	int nd_path = mul(m, mul(add(calc_c, mul(-1, cnt_c)), cnt_r));
	    	
	    	ans = add(ans, add(st_path, nd_path));
    	}
    	
    	cout << ans << endl;
    }
}
