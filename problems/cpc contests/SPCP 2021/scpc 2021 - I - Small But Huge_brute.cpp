
// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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

vi primes = {2, 3, 5, 7, 11};
const int PRIME_SZ = 3;

int n;
int arr[NMAX];
int mem[NMAX][1 << PRIME_SZ];
int vis[NMAX][1 << PRIME_SZ], vid;

int calc(int x){
	
	int ret = 0;
	for(int i = 0; i < PRIME_SZ; i++){
		if(x%primes[i]==0){
			ret |= 1 << i;
		}
	}
	return ret;
}

int go(int i, int msk){
	
	if(!msk){
		return 0;
	}
	if(i==n){
		return msk > 0;
	}
	
	int &ret = mem[i][msk];
	if(vis[i][msk]==vid) return ret;
	vis[i][msk] = vid;
	
	int ans = 0;
	
	int x = 1;
	
	for(int j = i; j < n; j++){
		
		x *= arr[j];
		
		for(auto p : primes){
			while(x && (x%(p*p)==0)){
				x /= p;
			}
		}
		
		if(msk&calc(x)){
			ans = add(ans, go(j+1, msk&calc(x)));
		}
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		vid++;
		cout << go(0, (1<<PRIME_SZ)-1) << endl;
    }	
}
