// Problem: E1. Efficient Partitioning
// Contest: Yandex - Upsolving
// URL: https://official.contest.yandex.com/ptz-summer-2021/contest/28728/problems/E1/
// Memory Limit: 512 MB
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

int n;
int a[NMAX], b[NMAX], c[NMAX];

bool test(int sm){
	
	int mx = c[n-1];
	
	for(int i = n-1; i > 0; i--){
		
		int rm = sm-b[i];
		
		if(mx >= rm){
			mx = max(mx, c[i-1]);
		}	
	}
	
	int rm0 = sm-b[0];
	
	return mx >= rm0;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    
    for(int i = 1; i < n; i++){
    	a[i] += a[i-1];
    }
    
    for(int i = 0; i < n; i++){
    	c[i] += a[i];
    	if(i) b[i] -= a[i-1];
    }
    
    int l = -1e15;
    int r = +1e15;
    
    int ans = -1;
    
    while(l <= r){
    	
    	int mid = (l+r)/2;
    	
    	if(test(mid)){
    		ans = mid;
    		l = mid+1;
    	}
    	else{
    		r = mid-1;
    	}
    }
    
    cout << ans << endl;
}
