// Problem: C. Tea Tasting
// Contest: Codeforces - Educational Codeforces Round 143 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1795/problem/C
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
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec_a(n);
		for(auto &i : vec_a) cin >> i;
		
		vi vec_b(n);
		for(auto &i : vec_b) cin >> i;
		
		vi pre = vec_b;
		for(int i = 1; i < n; i++){
			pre[i] += pre[i-1];
		}
		
		vi add0(n);
		vi add1(n);
		
		for(int i = 0; i < n; i++){
			
			int l = i;
			int r = n-1;
			
			int ans = n-1;
			
			while(l <= r){
				
				int mid = (l+r)/2;
				int sm = pre[mid]-pre[i]+vec_b[i];
				
				if(sm >= vec_a[i]){
					ans = mid;
					r = mid-1;
				}
				else{
					l = mid+1;
				}
			}
			
			int p = ans;
			
			add0[i] += 1;
			add0[p] -= 1;
			
			int lft = vec_a[i];
			if(i < p) lft -= pre[p-1] - pre[i] + vec_b[i];
			
			add1[p] += min(lft, vec_b[p]);
		}
		
		for(int i = 1; i < n; i++){
			add0[i] += add0[i-1];
		}
		
		for(int i = 0; i < n; i++){
			cout << (add0[i]*vec_b[i] + add1[i]) << ' ';
		} 
		cout << endl;
    }	
}
