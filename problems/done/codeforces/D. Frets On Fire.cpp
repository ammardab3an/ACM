// Problem: D. Frets On Fire
// Contest: Codeforces - Codeforces Global Round 2
// URL: https://codeforces.com/contest/1119/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
    
    sort(vec.begin(), vec.end());
    
    int mn = vec[0];
    
    for(int i = n-1; i > 0; i--){
    	vec[i] -= vec[i-1];
    }
    
    sort(vec.begin(), vec.end());
    
    vi pre(n);
    pre[0] = vec[0];
    for(int i = 1; i < n; i++){
    	pre[i] = pre[i-1] + vec[i];
    }
    
    // for(auto i : vec) cout << i << ' '; cout << endl;
    
    int q; cin >> q; while(q--){
    	
    	int l, r;
    	cin >> l >> r;
    	
    	int x = r-l+1;
    	
    	int p = lower_bound(vec.begin(), vec.end(), x)-vec.begin();
    	
    	int ans = (n-p) * x;
    	if(p) ans += pre[p-1];
    		
    	cout << ans+max(int(0), x-mn) << ' ';
    }
}

/*
	7 8 10 11 12 16
	
	0-2
	3
	
	0 2
	1 3
	3 5
	4 6
	5 7
	9 11
*/
