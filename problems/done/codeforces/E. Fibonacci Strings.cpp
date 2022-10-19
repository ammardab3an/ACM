// Problem: E. Fibonacci Strings
// Contest: Codeforces - Codeforces Round #814 (Div. 2)
// URL: https://codeforces.com/contest/1719/problem/E
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
    
    vi fib = {1, 1};
    vi tmp = {1, 2};
    while(tmp.back() < 1e11){
    	fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
    	tmp.push_back(tmp.back() + fib.back());
    }
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		int sm = 0;
		
		vi vec(n);
		for(auto &i : vec) cin >> i, sm += i;
		
		int p = lower_bound(tmp.begin(), tmp.end(), sm) - tmp.begin();
		
		if(p==(int)tmp.size() || tmp[p]!=sm){
			cout << "NO" << endl;
			continue;
		}
		
		// for(int i = p; i >= 0; i--){
			// cout << fib[i] << ' ';
		// }
		// cout << endl;
		
		bool ans = true;
		
		multiset<pii> mst;
		for(int i = 0; i < n; i++){
			mst.insert({-vec[i], i});
		}
		
		int lst = -1;
		
		for(int i = p; i >= 0; i--){
			
			int fi = fib[i];
			
			bool b0 = mst.empty();
			bool b1 = b0 || (fi > -(mst.begin()->first));
			bool b2 = b1 || ((mst.size()==1) && ((mst.begin()->second)==lst));
			bool b3 = b2 || (((mst.begin()->second)==lst) && (fi > -((++mst.begin())->first)));
			
			// cout << fi << endl;
			// for(auto p : mst) cout << -p.first << ' '; cout << endl;
			
			if(b3){
				ans = false;
				break;
			}
			
			if(mst.begin()->second == lst){
				auto it = ++mst.begin();
				pii cp = *it;
				mst.erase(it);
				cp.first += fi;
				if(cp.first) mst.insert(cp);
				lst = cp.second;
			}
			else{
				pii cp = *mst.begin();
				mst.erase(mst.begin());
				cp.first += fi;
				if(cp.first) mst.insert(cp);
				lst = cp.second;
			}
		}
		
		cout << (ans ? "YES" : "NO") << endl;
    }	
}
