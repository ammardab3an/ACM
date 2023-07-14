// Problem: B. Equalize by Divide
// Contest: Codeforces - Codeforces Round #854 by cybercats (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1799/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
		
		int mn = *min_element(vec.begin(), vec.end());
		int mx = *max_element(vec.begin(), vec.end());
		
		if(mn==mx){
			cout << 0 << endl;
			continue;
		}
		if(mn==1){
			cout << -1 << endl;
			continue;
		}
		
		vpii ans;
		
		{
			map<int, vi> mp;
			for(int i = 0; i < n; i++){
				mp[vec[i]].push_back(i);
			}	
			
			while(mp.size() > 1){
				
				auto it0 = mp.begin();
				auto it1 = next(it0);
				
				int nval = (it1->first + it0->first-1)/(it0->first);
				
				int p = it0->second.front();
				auto it2 = mp.insert({nval, {}}).first;
				
				for(auto e : it1->second){
					it2->second.push_back(e);
					ans.push_back({e, p});
					vec[e] = nval;
				}
				
				mp.erase(it1);
			}
		}
		
		for(auto i : vec) assert(vec.front());
		
		cout << ans.size() << endl;
		for(auto [i, j] : ans){
			cout << i+1 << ' ' << j+1 << endl;
		}
    }	
}
