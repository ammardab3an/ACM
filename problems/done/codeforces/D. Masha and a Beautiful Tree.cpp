// Problem: D. Masha and a Beautiful Tree
// Contest: Codeforces - Codeforces Round #826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/D
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

iii go(int l, int r, const vi &vec){
	
	if(l==r){
		return {0, {vec[l], vec[l]}};
	}	
	
	int mid = (l+r)/2;
	
	auto lf = go(l, mid, vec);
	auto ri = go(mid+1, r, vec);
	
	iii ret;
	
	if(lf.second.second <= ri.second.first){
		ret = (iii){lf.first+ri.first, {lf.second.first, ri.second.second}};
	}
	else if(ri.second.second <= lf.second.first){
		swap(lf, ri);
		ret = (iii){1+lf.first+ri.first, {lf.second.first, ri.second.second}};
	}
	else{	
		ret = (iii){INF, {-INF, +INF}};
	}
	
	// cout << l << ' ' << r << ' ' << ret.first << ' '<< ret.second.first << ' ' << ret.second.second << endl;
	
	return ret;
}

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
		
		int m = n;
		
		vi vec(m);
		for(auto &i : vec) cin >> i;
		
		int ans = go(0, m-1, vec).first;
		if(ans >= m) ans = -1;
		
		cout << ans << endl;
    }	
}
