
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

int n;
int arr[NMAX];

bool good(int l, int r, int b){
	
	// cout << l << ' ' << r << ' ' << b << endl;
	
	if(l >= r){
		return true;
	}
	
	for(int i = l+1; i <= r; i++){
		
		bool b0 = (arr[i-1]>>b)&1;
		bool b1 = (arr[i]>>b)&1;
		
		// if(b==0) cout << i << ' ' << b0 << ' ' << b1 << endl;
		
		if(b0 && !b1){
			return false;
		}
	}
	
	return true;
}

int get_k(int l, int r, int b){
	
	if(l >= r){
		return -1;
	}
	
	for(int i = l+1; i <= r; i++){
		
		bool b0 = (arr[i-1]>>b)&1;
		bool b1 = (arr[i]>>b)&1;
		
		if(!b0 && b1){
			return i-1;
		}
		if(b0 && !b1){
			assert(false);
		}
	}
	
	return r;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    freopen("sort.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		vector<pii> tmp;
		tmp.push_back({0, n-1});
		
		int ans = 0;
		
		for(int b = 31; b >= 0; b--){
			
			bool found = false;
			for(auto [l, r] : tmp){
				// cout << ' ' << l << ' ' << r << endl;
				if(!good(l, r, b)){
					found = true;
					break;
				}
			}	
			
			// cout << b << ' ' << found << endl;
			
			if(found){
				ans ^= (1ll<<b);
				continue;
			}
			
			vpii ntmp;
			for(auto [l, r] : tmp){
				
				int k = get_k(l, r, b);
				if(k==-1) continue;
				
				ntmp.push_back({l, k});
				ntmp.push_back({k+1, r});
			}
			
			tmp = ntmp;
		}
		
		cout << ans << endl;
    }	
}
