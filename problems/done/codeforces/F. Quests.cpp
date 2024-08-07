// Problem: F. Quests
// Contest: Codeforces - Codeforces Round #835 (Div. 4)
// URL: https://codeforces.com/contest/1760/problem/F
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

		int n, c, d;
		cin >> n >> c >> d;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		
		vi pre = vec;
		for(int i = 1; i < n; i++){
			pre[i] += pre[i-1];
		}
		
		pre.resize(2*d+10, pre.back());
		
		auto check = [&](int k){
			
			int sm = 0;	
			int rm = d;
			
			if(k+1 <= rm){
				sm += pre[k] * (rm/(k+1));
				rm %= (k+1);
			}
			
			if(rm){
				sm += pre[rm-1];
			}
			
			return sm >= c;
		};
		
		int l = 0;
		int r = 2*d;
		
		int ans = -1;
		
		while(l <= r){
			
			int mid = (l+r)/2;
			
			if(check(mid)){
				ans = mid;
				l = mid+1;
			}
			else{
				r = mid-1;
			}
		}
		
		if(ans==-1){
			cout << "Impossible" << endl;
		}
		else if(ans > d){
			cout << "Infinity" << endl;
		}
		else{
			cout << ans << endl;
		}
    }	
}
