// Problem: C. Double Sort
// Contest: Codeforces - Educational Codeforces Round 129 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1681/problem/C
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
		
		vi vec_a(n), vec_b(n);
		for(auto &i : vec_a) cin >> i;
		for(auto &i : vec_b) cin >> i;
		
		reverse(vec_a.begin(), vec_a.end());
		reverse(vec_b.begin(), vec_b.end());
		
		vpii ans;
		bool good = true;
		
		for(int k = n-1; k >= 0; k--){
		
			int mn_a = *min_element(vec_a.begin(), vec_a.end());
			int mn_b = *min_element(vec_b.begin(), vec_b.end());
			
			int p = -1;
			
			for(int i = 0; i < vec_a.size(); i++){
				if(vec_a[i]==mn_a && vec_b[i]==mn_b){
					p = i;
					break;
				}
			}
			
			// for(auto i : vec_a) cout << ' ' << i; cout << endl;
			// for(auto i : vec_b) cout << ' ' << i; cout << endl;
			// cout << p << ' ' << k << endl;
			
			if(p==-1){
				good = false;
				break;
			}
			
			if(p==k){
				vec_a.pop_back();
				vec_b.pop_back();
				continue;
			}
			
			ans.push_back({n-k, n-p});
			
			swap(vec_a.back(), vec_a[p]);
			swap(vec_b.back(), vec_b[p]);
			
			vec_a.pop_back();
			vec_b.pop_back();	
		}
		
		if(!good){
			cout << -1 << endl;
		}
		else{
			cout << ans.size() << endl;
			for(auto [i, j] : ans){
				cout << i << ' ' << j << endl;
			}
		}
    }
}
