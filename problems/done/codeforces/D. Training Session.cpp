// Problem: D. Training Session
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: http://codeforces.com/contest/1598/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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
		
		map<int, vi> mp;
		for(int i = 0; i < n; i++){
			int a, b;
			cin >> a >> b;
			mp[a].push_back(b);
		}
		
		vi tmp(4);
		int ans = 0;
		
		for(auto &p : mp){
			
			int t = p.second.size();
			
			ans += tmp[2] * t;
			tmp[2] += tmp[1] * t;
			tmp[1] += t;
			
			if(t >= 3){			
				ans += (t * (t-1) * (t-2)) / (3 * 2);
			}
		}
		
		vi cnt(n+1);
		int water_level = 0;
		
		for(auto &p : mp){
			
			auto &v  = p.second;
			int t = p.second.size();
			
			if(t < 2) continue;
			
			water_level += (t * (t-1)) / 2;
			
			for(auto i : v){
				cnt[i] -= (t * (t-1)) / 2;
				cnt[i] += ((t-1) * (t-2)) / 2;
			}
		}
		
		for(auto &p : mp){
			
			auto &v = p.second;
			int t = p.second.size();
			
			for(auto i : v){
				int cans = cnt[i] + water_level;
				cans -= (t >= 2) * ((t-1) * (t-2)) / 2;
				ans += cans;	
			}
		}
		
		cout << ans << endl;
    }	
}