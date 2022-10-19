// Problem: D - Left Right Operation
// Contest: AtCoder - LINE  Verda Programming Contest（AtCoder Beginner Contest 263）
// URL: https://atcoder.jp/contests/abc263/tasks/abc263_d
// Memory Limit: 1024 MB
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
    
    int n, l, r;
    cin >> n >> l >> r;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    vi pre(n), suf(n);
    
    pre[0] = vec[0];
    pre[0] = min(pre[0], l);
    for(int i = 1; i < n; i++){
    	pre[i] = pre[i-1] + vec[i];
    	pre[i] = min(pre[i], (i+1)*l);
    }
    
    suf[n-1] = vec[n-1];
    suf[n-1] = min(suf[n-1], r);
    for(int i = n-2; i >= 0; i--){
    	suf[i] = suf[i+1] + vec[i];
    	suf[i] = min(suf[i], (n-i)*r);
    }
    
    int ans = suf[0];
    
    for(int i = 0; i < n; i++){
    	
    	int st_path = pre[i];
    	int nd_path = (i+1 < n) ? suf[i+1] : 0;
    	
    	ans = min(ans, st_path+nd_path);
    }
    
    cout << ans << endl;
}
