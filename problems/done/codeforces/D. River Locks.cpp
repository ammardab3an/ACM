// Problem: D. River Locks
// Contest: Codeforces - Codeforces Round #802 (Div. 2)
// URL: https://codeforces.com/contest/1700/problem/D
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
    cin >> n;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    vi suf(n);
    suf[n-1] = vec[n-1];
    for(int i = n-2; i >= 0; i--){
    	suf[i] = suf[i+1] + vec[i];
    }
    
    vi ans(n+1);
    
    int t = 0;
    int c = 0;
    for(int i = 0; i < n; i++){
    	
    	ans[i+1] = t + max(int(0), ((suf[i]-c-t) + i)/(i+1));
    	
    	c += t;
    	
    	if(c <= vec[i]){
    		int rm = vec[i]-c;
    		int k = (rm+i)/(i+1);
    		t += k;
    		c = k*(i+1)-rm;
    	}
    	else{
    		c -= vec[i];
    	}
    }
    
    // for(int i = 0; i <= n; i++){
    	// cout << i << ' ' << ans[i] << endl;
    // }
    
    int q; cin >> q; while(q--){
    	
    	int x;
    	cin >> x;
    	
    	int l = 1;
    	int r = n;
    	
    	int cans = -1;
    	
    	while(l <= r){
    		
    		int mid = (l+r)/2;
    		
    		if(ans[mid] <= x){
    			cans = mid;
    			r = mid-1;	
    		}	
    		else{
    			l = mid+1;
    		}
    	}
    	
    	cout << cans << endl;
    }
}
