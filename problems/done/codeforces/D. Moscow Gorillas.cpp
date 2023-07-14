// Problem: D. Moscow Gorillas
// Contest: Codeforces - Codeforces Round #852 (Div. 2)
// URL: https://codeforces.com/contest/1793/problem/D
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
    
    vi vec_a(n);
    for(auto &i : vec_a) cin >> i, --i;
    
    vi vec_b(n);
    for(auto &i : vec_b) cin >> i, --i;
    
    vi pos_a(n), pos_b(n);
    vi mn_pos_a(n), mx_pos_a(n);
    vi mn_pos_b(n), mx_pos_b(n);
    
    for(int i = 0; i < n; i++){
    	pos_a[vec_a[i]] = i;
    	pos_b[vec_b[i]] = i;
    }
    for(int i = 0; i < n; i++){
    	
    	mn_pos_a[i] = mx_pos_a[i] = pos_a[i];
    	mn_pos_b[i] = mx_pos_b[i] = pos_b[i];
    	
    	if(i){
    		mn_pos_a[i] = min(mn_pos_a[i], mn_pos_a[i-1]);
    		mx_pos_a[i] = max(mx_pos_a[i], mx_pos_a[i-1]);
    		mn_pos_b[i] = min(mn_pos_b[i], mn_pos_b[i-1]);
    		mx_pos_b[i] = max(mx_pos_b[i], mx_pos_b[i-1]);
    	}
    }
    
    int ans = 1;
    
    {
    	int l = min(pos_a[0], pos_b[0]);
    	int r = max(pos_a[0], pos_b[0]);
    	int r0 = l;
    	int r1 = n-r-1;
    	int r2 = r-l-1;
    	if(r0) ans += (r0*(r0+1))/2;
    	if(r1) ans += (r1*(r1+1))/2;
    	if(r2 > 0) ans += (r2*(r2+1))/2;
    	// cout << r0 << ' ' << r1 << ' ' << ans << endl;
    }
    
    for(int i = 1; i < n; i++){
    	
    	int l = min(mn_pos_a[i-1], mn_pos_b[i-1]);
    	int r = max(mx_pos_a[i-1], mx_pos_b[i-1]);
    	
    	pii r0 = {0, l};
    	pii r1 = {r, n-1};
    	
    	int p0 = pos_a[i];
    	int p1 = pos_b[i];
    	
    	if(l <= p0 && p0 <= r){
    		continue;
    	}
    	if(l <= p1 && p1 <= r){
    		continue;
    	}
    	
    	// cout << ' ' << l << ' ' << r << endl;
    	
    	for(auto p : {p0, p1}){
    		if(r0.first <= p && p <= r0.second){
    			r0.first = p+1;
    		}
    		if(r1.first <= p && p <= r1.second){
    			r1.second = p-1;
    		}
    	}
    	
    	int cans = 0;
    	
    	if(r0.first <= r0.second)
    	if(r1.first <= r1.second){
    		cans += (r0.second-r0.first+1) * (r1.second-r1.first+1);
    	}
    	
    	ans += cans;
    	
    	// cout << i << ' ' << cans << endl;
    }
    
    cout << ans << endl;
}
