
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
		
		vi vec_p(n), vec_m(n);
		for(auto &i : vec_p) cin >> i;
		for(auto &i : vec_m) cin >> i;
		
		map<int, int> mp;
		
		for(int i = 0; i < n; i++){
			
			if(!mp.count(vec_m[i])){
				mp[vec_m[i]] = vec_p[i];
			}
			else{
				mp[vec_m[i]] = min(mp[vec_m[i]], vec_p[i]);
			}
		}
		
		const int N = 20;
		vi F(1<<N, INFLL);
		vi X(1<<N, 0);
		
		for(auto [m, p] : mp){
			F[m] = p;
			X[m] = 1;
		}
		
		for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
			if(mask & (1<<i)){
				if(F[mask^(1<<i)] >= F[mask]){
					F[mask^(1<<i)] = F[mask];
					X[mask^(1<<i)] = 0;
				}
			}
		}
		
		int ans = 0;
		for(auto [m, p] : mp){
			ans += X[m];
		}
		
		// for(int i = 0; i < 8; i++){
			// cout << X[i] << ' ';
		// } cout << endl;
		
		cout << ans << endl;
    }	
}
