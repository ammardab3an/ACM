// Problem: F. Divide, XOR, and Conquer
// Contest: Codeforces - Pinely Round 2 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1863/problem/F
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int32_t main(){
    
    fastIO;
	
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		vi pre = vec;
		for(int i = 1; i < n; i++){
			pre[i] ^= pre[i-1];
		}
		
		auto calc = [&](int i, int j)->int{
			int cxor = pre[j]^pre[i]^vec[i];
			if(!cxor) return (1ll<<61)-1;
			int b = 64 - __builtin_clzll(cxor);
			return 1ll << (b-1);
		};
		
		vi msk_lf(n);
		vi msk_ri(n);
		msk_lf[0] ^= calc(0, n-1);
		msk_ri[n-1] ^= calc(0, n-1);
		
		vector<bool> ans(n);
		if(n==1) ans[0] = 1;
		
		for(int len = n-1; len >= 1; len--){
			
			for(int i = 0, j = len-1; j < n; i++, j++){
				int cxor = pre[j]^pre[i]^vec[i];
				if((msk_lf[i]&cxor) || (msk_ri[j]&cxor) || (msk_lf[i]==((1ll<<61)-1)) || (msk_ri[j]==((1ll<<61)-1))){
					int tmp = calc(i, j);
					msk_lf[i] |= tmp;
					msk_ri[j] |= tmp;
					if(len==1) ans[i] = true;
				}
			}	
		}
		
		for(auto e : ans) cout << e; cout << endl;
    }	
}
