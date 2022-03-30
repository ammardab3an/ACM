// Problem: C. Fault-tolerant Network
// Contest: Codeforces - Educational Codeforces Round 124 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1651/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    
    int t; cin >> t; while(t--){
		
		int n;
		cin >> n;
		
		vi vec_a(n), vec_b(n);
		for(auto &i : vec_a) cin >> i;
		for(auto &i : vec_b) cin >> i;
		
		int ans = INFLL;
		
		for(int k = 0; k < 2; k++){
			
			int st_path = abs(vec_a[0]-vec_b[0]) + abs(vec_a[n-1]-vec_b[n-1]);
			int nd_path = abs(vec_a[0]-vec_b[n-1]) + abs(vec_a[n-1]-vec_b[0]);
			int rd_path = 0;
			
			int mn_a_1 = INFLL;
			int mn_a_n = INFLL;
			int mn_b_1 = INFLL;
			int mn_b_n = INFLL;
			
			for(auto i : vec_a){
				mn_a_1 = min(mn_a_1, abs(vec_b[0]-i));
				mn_a_n = min(mn_a_n, abs(vec_b[n-1]-i));
			}
			
			for(auto i : vec_b){
				mn_b_1 = min(mn_b_1, abs(vec_a[0]-i));
				mn_b_n = min(mn_b_n, abs(vec_a[n-1]-i));
			}
			
			rd_path = mn_a_1 + mn_a_n + mn_b_1 + mn_b_n;
			
			int fo_a = mn_a_1 + mn_b_1 + abs(vec_a[n-1]-vec_b[n-1]);
			int fo_b = mn_a_n + mn_b_n + abs(vec_a[0]-vec_b[0]);
			
			rd_path = min({rd_path, fo_a, fo_b});
			
			int cans = min({st_path, nd_path, rd_path});
			ans = min(ans, cans);
			
			if(k==0){
				reverse(vec_a.begin(), vec_a.end());
			}
		}
		
		cout << ans << endl;
    }	
}
