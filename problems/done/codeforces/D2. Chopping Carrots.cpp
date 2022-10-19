// Problem: D2. Chopping Carrots (Hard Version)
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/D2
// Memory Limit: 64 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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

		int n, k;
		cin >> n >> k;
		
		struct e{
			int a, s, c;
		};
		
		vector<e> vec(n);
		for(auto &e : vec){
			cin >> e.a;
			e.s = sqrt(e.a);
			e.c = 1;
		}
		
		auto calc = [&](int i, int plus=0){
			
			const e &tmp = vec[i];
			
			int a = tmp.a;
			int s = tmp.s;
			int p = tmp.c + plus;
			
			if(p <= s){
				return a/min(p, k);
			}
			else{
				int np = p - s;
				int b = s - np;
				if(s != a/s) b++;
				return max(b, a/k);
			}
		};
		
		int mn = INF;
		vector<vi> tmp(1e5 + 10);
		
		for(int i = 0; i < n; i++){
			int cur = calc(i);
			tmp[cur].push_back(i);
			mn = min(mn, cur);
		}
		
		int ans = INF;
		
		for(int i = tmp.size()-1; i >= 0; i--) if(!tmp[i].empty()){
			
			ans = min(ans, i-mn);
			
			bool bad = false;
			
			for(auto p : tmp[i]){
				
				int cur = i;
				int nxt = calc(p, 1);
				
				if(cur==nxt){
					bad = true;
					break;
				}
				
				vec[p].c++;
				tmp[nxt].push_back(p);
				mn = min(mn, nxt);
			}
			
			if(bad) break;
			
			tmp[i] = vi();
		}
		
		cout << ans << endl;
    }	
}
