// Problem: B. Meeting on the Line
// Contest: Codeforces - Codeforces Round #823 (Div. 2)
// URL: https://codeforces.com/contest/1730/problem/B
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
		
		vi add(n);
		for(auto &i : add) cin >> i;
		
		if(n==1){
			cout << vec[0] << endl;
			continue;
		}
		
		vi pos(n);
		iota(pos.begin(), pos.end(), 0);
		sort(pos.begin(), pos.end(), [&](int i, int j){
			return vec[i] < vec[j];				
		});
		
		vi pre(n), suf(n);
		
		pre[0] = -add[pos[0]] + vec[pos[0]];
		for(int i = 1; i < n; i++){
			pre[i] = min(pre[i-1], -add[pos[i]]+vec[pos[i]]);
		}
		
		suf[n-1] = add[pos[n-1]] + vec[pos[n-1]];
		for(int i = n-2; i >= 0; i--){
			suf[i] = max(suf[i+1], +add[pos[i]]+vec[pos[i]]);
		}
		
		double ans = 1E15;
		double ans_p = -1;
		
		for(int i = 0; i < n; i++){
			
			int cans = add[pos[i]];
			
			if(i) cans = max(cans, vec[pos[i]]-pre[i-1]);
			if(i+1 < n) cans = max(cans, suf[i+1]-vec[pos[i]]);
			
			if(cans < ans){
				ans = cans;
				ans_p = vec[pos[i]];
			}
		}
		
		for(int i = 0; i+1 < n; i++){
			
			int l = vec[pos[i]]-pre[i];
			int r = suf[i+1]-vec[pos[i+1]];
			
			int dl, dr;
			dl = dr = 0;
			
			if(l < r){
				dl = r-l;
				dr = 0;
			}
			else if(l > r){
				dr = l-r;
				dl = 0;
			}
			
			if(vec[pos[i]]+dl <= vec[pos[i+1]]-dr){
				
				double m = double((vec[pos[i]]+dl)+(vec[pos[i+1]]-dr))/double(2);
				double foo = double(-(vec[pos[i]]+dl)+(vec[pos[i+1]]-dr))/double(2);
					
				double cans = max(l+dl+foo, r-dr+foo);
				
				if(cans < ans){
					ans = cans;
					ans_p = m;
				}
			}
			
		}
		
		cout << fixed << setprecision(10) << ans_p << endl;
    }	
}
