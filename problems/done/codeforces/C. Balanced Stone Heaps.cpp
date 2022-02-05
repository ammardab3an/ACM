// Problem: C. Balanced Stone Heaps
// Contest: Codeforces - Codeforces Round #763 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1623/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		int l = 0;
		int r = INT_MAX;
		
		int ans = 0;
		
		while(l <= r){
			
			int m = (l+r)/2;
			
			bool good = true;
			
			vi tmp = vec;
			int c_0 = 0;
			int c_1 = 0;
			
			for(int i = n-1; i >= 2; i--){
				
				if(tmp[i]+c_0 < m){
					good = false;
					break;
				}
				
				if(c_0 >= m){
					
					int d = tmp[i]/3;
					
					tmp[i] -= 3*d;
					tmp[i] += c_0;
					
					c_0 = c_1 + d;
					c_1 = 2*d;
				}
				else{
					
					int r = m-c_0;
					
					int d = (tmp[i]-r)/3;
					
					tmp[i] -= 3*d;
					tmp[i] += c_0;
					
					c_0 = c_1 + d;
					c_1 = 2*d;
				}
			}
			
			good &= tmp[1] + c_0 >= m;
			good &= tmp[0] + c_1 >= m;
			
			if(good){
				ans = m;
				l = m+1;
			}
			else{
				r = m-1;
			}
		}
		
		cout << ans << endl;
    }	
}
