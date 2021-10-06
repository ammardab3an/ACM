// Problem: F. Array Stabilization (GCD version)
// Contest: Codeforces - Codeforces Round #731 (Div. 3)
// URL: https://codeforces.com/contest/1547/problem/F
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
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
		
		int lg = ceil(log2(double(n)));
		
		vector<vi> pre(lg, vi(n));
		
		for(int i = 0; i < n; i++){
			pre[0][i] = __gcd(vec[i], vec[(i+1)%n]);
		}
		
		for(int i = 1; i < lg; i++){
			for(int j = 0; j < n; j++){
				pre[i][j] = __gcd(pre[i-1][j], pre[i-1][(j+(1<<(i-1)))%n]);
			}
		}
		
		auto good = [](vi &vec){
			
			int sz = vec.size();
			for(int i = 0; i < sz; i++){
				if(vec[i] != vec[(i+1)%sz]){
					return false;
				}
			}
			return true;
		};
		
		auto go = [&](int m){
			
			vi ret = vec;
			int foo = 0;
			
			for(int i = 0; i < lg; i++) if(m&(1<<i)){
					
				for(int j = 0; j < n; j++){
					ret[j] = __gcd(ret[j], pre[i][(j+foo)%n]);
				}	
				
				foo += 1 << i;
			}
			
			return ret;
		};
		
		int l = 0;
		int r = n;
		
		int ans = -1;
		
		while(l <= r){
			
			int mid = (l+r)/2;
			
			vi tmp = go(mid);
			
			if(good(tmp)){
				ans = mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		
		cout << ans << endl;
    }	
}