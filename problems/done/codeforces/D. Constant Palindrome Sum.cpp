// Problem: D. Constant Palindrome Sum
// Contest: Codeforces - Codeforces Round 636 (Div. 3)
// URL: https://codeforces.com/contest/1343/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
		
		vi tmp(2*k + 2);
		
		for(int i = 0; i < n/2; i++){
			
			int a = vec[i];
			int b = vec[n-i-1];
			
			if(a > b) swap(a, b);
			
			// 1+1 ... a+1 ... a+b ... b+k ... k+k
			
			tmp[2] += 2;
			tmp[a+1] -= 2;
			
			tmp[a+1] += 1;
			tmp[a+b] -= 1;
			
			tmp[a+b+1] += 1;
			tmp[b+k+1] -= 1;
			
			tmp[b+k+1] += 2;
			tmp[k+k+1] -= 2;
		}
		
		int ans = INF;
		
		for(int i = 1; i < tmp.size(); i++){
			tmp[i] += tmp[i-1];
		}
		
		for(int i = 2; i <= 2*k; i++){
			ans = min(ans, tmp[i]);
		}
		
		cout << ans << endl;
    }	
}
