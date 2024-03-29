// Problem: F - Lottery
// Contest: AtCoder - AtCoder Beginner Contest 243
// URL: https://atcoder.jp/contests/abc243/tasks/abc243_f
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

int n, m, k;
int arr[55];
int ppr[55][55];
int mem[55][55][55];
int fac[55], ifac[55];

int go(int i, int rm_m, int rm_k){
	
	if(rm_k!=0 && rm_m==0){
		return 0;
	}
	
	if(i==n){
		return rm_m==0 && rm_k==0;
	}
	
	int &ret = mem[i][rm_m][rm_k];
	if(ret+1) return ret;
	
	int ans = go(i+1, rm_m, rm_k);
	
	for(int cnt = 1; cnt <= rm_k; cnt++){
		int cans = mul(ifac[cnt], mul(ppr[i][cnt], go(i+1, rm_m-1, rm_k-cnt)));
		ans = add(ans, cans);	
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int sm = 0;
    
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    	sm += arr[i];
    }
    
    int _sm = pow_exp(sm, MOD-2);
    
    for(int i = 0; i < n; i++){
    	
    	int p = mul(arr[i], _sm);
    	
    	ppr[i][0] = 1;
    	for(int j = 1; j <= k; j++){
    		ppr[i][j] = mul(ppr[i][j-1], p);
    	}
    }
    
    fac[0] = 1;
    for(int i = 1; i <= k; i++){
    	fac[i] = mul(fac[i-1], i);
    }
    ifac[k] = pow_exp(fac[k], MOD-2);
    for(int i = k-1; i >= 0; i--){
    	ifac[i] = mul(ifac[i+1], i+1);
    }
    
    memset(mem, -1, sizeof mem);
    
    int ans = mul(fac[k], go(0, m, k));
    cout << ans << endl;
}
