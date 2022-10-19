// Problem: D. Permutation Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/D
// Memory Limit: 512 MB
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
		
		vector<vi> pos(n+2);
		for(int i = 0; i < n; i++){
			pos[vec[i]].push_back(i+1);
		}
		
		for(int i = 0; i < n+2; i++){
			sort(pos[i].begin(), pos[i].end());
		}
		
		if(pos[0].empty() && pos[n+1].empty()){
			assert(false);
		}
		if(!pos[0].empty() && !pos[n+1].empty()){
			assert(false);
		}
		
		if(!pos[0].empty()){
			
			vi ans;
			vi cur = pos[0];
			int k = cur.front()-1;
			
			int cnt = n-cur.size();
			
			bool b = false;
			while(cnt > 0){
				
				int p = -1;
				for(auto i : cur) if(pos[i].size()){
					assert(p==-1);
					p = i;
				}	
				
				for(auto i : cur) if(i != p){
					ans.push_back(i);
				}
				ans.push_back(p);
				
				cur = pos[p];
				
				if(b){
					k = min(k, cur.front()-1);
				}
				else{
					k = max(k, cur.back());
				}
				
				b ^= 1;
				cnt -= cur.size();
			}
			
			for(auto i : cur) ans.push_back(i);
			
			cout << k << endl;
			for(auto i : ans) cout << i << ' '; cout << endl;
		}
		else if(!pos[n+1].empty()){
			
			vi ans;
			vi cur = pos[n+1]; //
			int k = cur.back(); //
			
			int cnt = n-cur.size();
			
			bool b = true; //
			while(cnt > 0){
				
				int p = -1;
				for(auto i : cur) if(pos[i].size()){
					assert(p==-1);
					p = i;
				}	
				
				for(auto i : cur) if(i != p){
					ans.push_back(i);
				}
				ans.push_back(p);
				
				cur = pos[p];
				
				if(b){
					k = min(k, cur.front()-1);
				}
				else{
					k = max(k, cur.back());
				}
				
				b ^= 1;
				cnt -= cur.size();
			}
			
			for(auto i : cur) ans.push_back(i);
			
			cout << k << endl;
			for(auto i : ans) cout << i << ' '; cout << endl;
		}
		else{
			assert(false);
		}
    }	
}
