// Problem: C2. Make Nonzero Sum (hard version)
// Contest: Codeforces - Codeforces Round #829 (Div. 2)
// URL: https://codeforces.com/contest/1754/problem/C2
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
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		int cnt = 0;
		for(auto i : vec) if(i==0) cnt++;
		
		if((n-cnt)%2==1){
			cout << -1 << endl;
			continue;
		}
		
		vpii ans;
		
		vi pos;
		for(int i = 0; i < n; i++){
			if(vec[i] != 0){
				pos.push_back(i);
			}	
		}
		
		assert(pos.size()%2==0);
		
		for(int i = 0; i < pos.size(); i+=2){
			
			int l = pos[i];
			int r = pos[i+1];
			bool b = (l%2) != (r%2);
			
			int sm = vec[l] + (!b ? vec[r] : -vec[r]);
			
			if(sm==0){
				ans.push_back({l, r});
				continue;
			}
			
			if(b){
				ans.push_back({l, r-1});
				ans.push_back({r, r});
			}
			else{
				ans.push_back({l, r-2});
				ans.push_back({r-1, r});
			}
		}
		
		vpii tmp;
		
		int lst = -1;
		for(auto [l, r] : ans){
			if(lst+1 < l){
				tmp.push_back({lst+1, l-1});
			}
			tmp.push_back({l, r});
			lst = r;
		}
		
		if(lst<n-1){
			tmp.push_back({lst+1, n-1});
		}
		
		cout << tmp.size() << endl;
		for(auto [l, r] : tmp){
			cout << l+1 << ' ' << r+1 << endl;
		}
    }	
}
