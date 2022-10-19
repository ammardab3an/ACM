// Problem: D1. Chopping Carrots (Easy Version)
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/D1
// Memory Limit: 64 MB
// Time Limit: 4000 ms
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
    
    int t; cin >> t; while(t--){

		int n, k;
		cin >> n >> k;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		int ans = INF;
		
		for(int i = 0; i <= 3000; i++){
			
			int mn = INF;
			int mx = -INF;
			
			for(auto a : vec){
				
				int ans_l=k, ans_r=1;
				
				{
					int l = 1; 
					int r = k;
					
					while(l <= r){
						int mid = (l+r)/2;
						if(a/mid <= i){
							ans_l = mid;
							r = mid-1;
						}
						else{
							l = mid+1;
						}
					}
				}
				{
					int l = 1;
					int r = k;
					
					while(l <= r){
						int mid = (l+r)/2;
						if(i <= a/mid){
							ans_r = mid;
							l = mid+1;
						}
						else{
							r = mid-1;
						}
					}
				}
				
				if((i-a/ans_l) < (a/ans_r-i)){
					mn = min(mn, a/ans_l);
					mx = max(mx, a/ans_l);
				}
				else{
					mn = min(mn, a/ans_r);
					mx = max(mx, a/ans_r);
				}
			}
			
			ans = min(ans, mx-mn);
		}
		
		cout << ans << endl;
    }	
}
