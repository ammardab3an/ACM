
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

typedef long double dtype;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    freopen("input.txt", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vector<dtype> vec(n);
		for(auto &i : vec) cin >> i;
		
		vector<dtype> pro(n-1);
		for(int i = 0; i < n-1; i++){
			dtype st_path = vec[i] * (1.0-vec[i+1]);
			dtype nd_path = (1.0-vec[i]) * vec[i+1];
			pro[i] = st_path + nd_path;
		}
		
		vector<dtype> pre(n-1);
		if(n-1){
			pre[0] = pro[0];
			for(int i = 1; i < n-1; i++){
				pre[i] = pre[i-1] + pro[i];
			}
		}
		
		dtype ex1 = 0;
		for(int i = 0; i < n-1; i++){
			ex1 += pro[i];	
		}
		
		dtype ex2 = 0;
		for(int i = 0; i+1 < n-1; i++){
			dtype st_path = vec[i] * (1.0-vec[i+1]) * vec[i+2];
			dtype nd_path = (1.0-vec[i]) * vec[i+1] * (1.0-vec[i+2]);
			ex2 += (st_path + nd_path)*2;
		}
		for(int i = 0; i < n-1; i++){
			ex2 += pro[i];	
		}
		for(int i = 0; i < n-1; i++){	
			if(i-2 >= 0){
				ex2 += pro[i] * pre[i-2];
			}
			if(i+2 < n-1){
				ex2 += pro[i] * (pre[n-2] - pre[i+1]);
			}
		}
		
		dtype ans = ex2 - ex1*ex1;
    	cout << fixed << setprecision(6) << ans << endl;
    }	
}
