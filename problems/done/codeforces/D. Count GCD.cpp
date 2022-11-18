// Problem: D. Count GCD
// Contest: Codeforces - CodeTON Round 3 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1750/problem/D
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
const int MOD = 998244353 ; // 1e9 + 7;
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

		int n, m;
		cin >> n >> m;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		vpii tmp;
		int x = vec[0];
		for(int i = 2; i*i <= x; i++) if(x%i==0){
			int cnt = 0;
			while(x%i==0) cnt++, x/=i;
			tmp.push_back({i, cnt});
		}
		if(x > 1) tmp.push_back({x, 1});
		
		int ans = 1;
		bool bad = false;
		
		for(int i = 1; i < n; i++){
			
			vpii cur;
			int x = vec[i];
			int yy = 1;
			
			for(auto &[p, f] : tmp){
				
				int cnt = 0;
				int p_pow = 1;
				while(x%p==0){
					cnt++;
					x /= p;
					p_pow *= p;
				}
				
				if(cnt > f){
					bad = true;
					break;	
				}
				
				if(f != cnt){
					cur.push_back({p, p_pow});
				}
				else{
					yy *= p_pow;
				}
				
				f = cnt;	
			}
			
			if(bad || x > 1){
				ans = 0;
				break;
			}
			
			int cans = 0;
			
			int mx = 1 << cur.size();
			for(int msk = 0; msk < mx; msk++){
				
				int y = 1;
				for(int i = 0; i < cur.size(); i++){
					if((msk>>i)&1){
						y *= cur[i].second * cur[i].first;
					}
					else{
						y *= cur[i].second;
					}
				}
				
				y *= yy;
				
				if(__builtin_popcount(msk)%2==1){				
					cans = add(cans, mul(-1, m/y));
				}
				else{
					cans = add(cans, m/y);
				}
			}
			
			ans = mul(ans, cans);
		}
		
		cout << ans << endl;
    }	
}
