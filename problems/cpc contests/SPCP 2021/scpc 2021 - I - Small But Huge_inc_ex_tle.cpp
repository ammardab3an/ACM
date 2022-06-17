
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
 
const int NMAX = 3e5 + 10;

const vi primes = {2, 3, 5, 7, 11, 13};
const int PRIME_SZ = 6;

int n;
int arr[NMAX];
int val[55];

int mask;
int mem[NMAX][1 << PRIME_SZ];
int vis[NMAX][1 << PRIME_SZ], vid;

int calc(int x){
	
	int &ret = val[x];
	if(ret+1) return ret;
	
	int ans = 0;
	for(int i = 0; i < PRIME_SZ; i++){
		if(x%primes[i]==0){
			ans |= (1<<i);
		}
	}
	
	return ret = ans;
}

int go(int i, int cur){
	
	if(i==n){
		return (mask&cur)==mask;
	}	
	
	int &ret = mem[i][cur];
	if(vis[i][cur]==vid) return ret;
	vis[i][cur] = vid;
	
	int st_path = go(i+1, cur | calc(arr[i]));
	int nd_path = go(i+1, calc(arr[i]));
	
	int ans = st_path;
	if((mask&cur)==mask) 
		ans = add(ans, nd_path);
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
    memset(val, -1, sizeof val);
    
    int t; cin >> t; while(t--){

		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		int ans = 0;
		
		for(int i = 1; i < (1<<PRIME_SZ); i++){
			
			vid++;
			::mask = i;
			int cans = go(1, calc(arr[0]));
			
			if(__builtin_popcount(i)%2==0){
				cans = mul(cans, -1);
			}
			
			ans = add(ans, cans);
		}
		
		cout << ans << endl;
    }	
}
