// Problem: F. Build a Tree and That Is It
// Contest: Codeforces - Codeforces Round #811 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1714/F
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

		int n, d12, d23, d13;
		cin >> n >> d12 >> d23 >> d13;
		
		int _x = (-d13+d12+d23);
		int _y = (+d13-d12+d23);
		int _z = (+d13+d12-d23);
		
		bool good = true;
		
		if(d12==0 || d23==0 || d13==0){
			good = false;
		}
		
		if(_x%2==1 || _y%2==1 || _z==1){
			good = false;	
		}
		
		if(_x < 0 || _y < 0 || _z < 0){
			good = false;
		}
		
		int x = _x/2;
		int y = _y/2;
		int z = _z/2;
		
		if(x+y+z > n-1){
			good = false;
		}
		
		if(!good){
			cout << "NO" << endl;
			continue;
		}
		
		vpii adj;
		
		int cur = 4;
		
		int lst = 1;
		while(z--){
			adj.push_back({lst, cur});
			lst = cur++;
		}
		
		if(!x){
			adj.back().second=2;
			lst = 2;
			cur--;
		}
		if(!y){
			adj.back().second=3;
			lst = 3;
			cur--;
		}
		
		int tt = lst;
		
		for(int i = 0; i < x-1; i++){
			adj.push_back({lst, cur});
			lst = cur++;
		}
		
		if(x){
			adj.push_back({lst, 2});
		}
		
		lst = tt;
		for(int i = 0; i < y-1; i++){
			adj.push_back({lst, cur});
			lst = cur++;
		}
		
		if(y){
			adj.push_back({lst, 3});
		}
		
		while(cur <= n){
			adj.push_back({1, cur++});
		}
		
		cout << "YES" << endl;
		for(auto [a, b] : adj){
			cout << a << ' ' << b << endl;
		}
    }	
}
