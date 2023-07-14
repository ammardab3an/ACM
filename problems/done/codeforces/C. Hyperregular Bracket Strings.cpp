// Problem: C. Hyperregular Bracket Strings
// Contest: Codeforces - Codeforces Round 875 (Div. 1)
// URL: https://codeforces.com/contest/1830/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const int MOD = 998244353; // 1e9 + 7;
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
const int NMAX = 3e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int fac[NMAX], ifac[NMAX];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

int catalan(int i){
	return mul(fac[i*2], mul(ifac[i+1], ifac[i]));
}

int n, k;
int arr[NMAX];

int go(int l, int r){
		
	// cout << l+1 << ' ' << r+1 << endl << flush;
	
	if(l > r){
		return 1;
	}
	
	int rm = l != 0;
	int ans = 1;
	
	for(int i = l+1; i <= r; i++){
		
		if(arr[i]==-1){
			rm += i != n-1;
			continue;
		}
		
		if(arr[i] > r){
			
			vpii tmp;
			tmp.push_back({r+1, arr[i]});
			arr[i] = r;
			
			for(int p = 0; p < tmp.size(); p++){
				auto [l, r] = tmp[p];
				
				if(arr[l]==-1){
					arr[l] = r;
				}
				else if(arr[l]==r){
					continue;
				}
				else{
					
					if(arr[l] > r){
						swap(arr[l], r);
					}
					
					tmp.push_back({arr[l]+1, r});
				}
			}
		}
		
		int cans = go(i, arr[i]);
		ans = mul(ans, cans);
		i = arr[i];
	}
	
	if(rm%2==1){
		return 0;
	}
	
	// cout << l << ' ' << r << ' ' << rm << ' ' << catalan(rm/2) << endl;
	
	ans = mul(ans, catalan(rm/2));
	return ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	init();
	
    int t; cin >> t; while(t--){

		cin >> n >> k;
		
		n += 2;
		
		for(int i = 0; i <= n; i++){
			arr[i] = -1;
		}
		
		vpii vec(k);
		for(auto &[l, r] : vec){
			cin >> l >> r;
			// l--, r--;
		}
		
		bool bad = false;
		bad |= n%2==1;
		
		for(int p = 0; p < vec.size(); p++){
			
			auto [l, r] = vec[p];
			
			if((r-l+1)%2==1){
				bad = true;
				break;
			}
			
			if(arr[l]==-1){
				arr[l] = r;
			}
			else if(arr[l]==r){
				continue;
			}
			else{
				
				if(arr[l] > r){
					swap(arr[l], r);
				}
				
				vec.push_back({arr[l]+1, r});
			}
		}
		
		if(bad){
			cout << 0 << endl;
			continue;
		}
		
		int ans = go(0, n-1);
		cout << ans << endl;
		
		// for(int i = 0; i < n; i++) if(arr[i] != -1){
			// cout << i << ' ' << arr[i] << endl;
		// }
    }	
}