// Problem: F. All Possible Digits
// Contest: Codeforces - Codeforces Round  #834 (Div. 3)
// URL: https://codeforces.com/contest/1759/problem/F
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

		int n, p;
		cin >> n >> p;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		int ans = 0;

		vi tmp = vec;
		sort(tmp.begin(), tmp.end());
		tmp.resize(unique(tmp.begin(), tmp.end())-tmp.begin());
		
		if(tmp.size()==p){
			cout << 0 << endl;
			continue;
		}
		
		int mn = 0;
		for(int i = 0; i < tmp.size(); i++){
			if(tmp[i] == mn){
				mn++;
			}
			else{
				break;
			}
		}
		
		int mx = p-1;
		for(int i = int(tmp.size())-1; i >= 0; i--){
			if(tmp[i] == mx){
				mx--;
			}
			else{
				break;
			}
		}
		
		if(vec.back() < mn && mx < p){
			cout << ans + (mx-vec.back()) << endl;
			continue;
		}
		
		ans += p-vec.back();
			
		{
			mx = min(mx, vec.back());
			int p = lower_bound(tmp.begin(), tmp.end(), mx)-tmp.begin();
			for(; p >= 0; p--){
				if(tmp[p] == mx){
					mx--;
				}
				else{
					break;
				}
			}
		}
		
		reverse(vec.begin(), vec.end());
		
		vec[0] = 0;
		int car = 1;
		for(int i = 1; i < vec.size(); i++){
			
			auto &e = vec[i];
			
			e += car;
			car = 0;
			
			if(e >= p){
				car = e/p;
				e %= p;
			}
		}
		if(car) vec.push_back(car);
		
		tmp.insert(tmp.end(), vec.begin(), vec.end());
		sort(tmp.begin(), tmp.end());
		tmp.resize(unique(tmp.begin(), tmp.end())-tmp.begin());
		
		{
			int p = lower_bound(tmp.begin(), tmp.end(), mx)-tmp.begin();
			for(; p >= 0; p--){
				if(tmp[p] == mx){
					mx--;
				}
				else{
					break;
				}
			}
		}
		{
			int p = lower_bound(tmp.begin(), tmp.end(), mn)-tmp.begin();
			for(; p < tmp.size(); p++){
				if(tmp[p] == mn){
					mn++;
				}
				else{
					break;
				}
			}
		}
		
		if(mn > mx){
			cout << ans << endl;
		}
		else{
			cout << ans+mx << endl;
		}
		
    }	
}
