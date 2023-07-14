// Problem: B. Vittorio Plays with LEGO Bricks
// Contest: Codeforces - SWERC 2022-2023 - Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1776/problem/B
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
    
    int n, h;
    while(cin >> n >> h){
    	
	    vi vec(n);
	    for(auto &i : vec) cin >> i;
	    
	    vector<pair<vi, int>> cur(n);
	    for(int i = 0; i < n; i++){
	    	cur[i] = {(vi){vec[i]}, 0};
	    }
	    
	    int ans = 0;
	    
	    while(h >= 0 && cur.size() > 1){
	    	
	    	// for(auto &[v, h] : cur){
	    		// for(auto i : v) cout << i << ' ';
	    		// cout << h << endl;
	    	// }
	    	
	    	int mn = INFLL;
	    	for(int i = 0; i+1 < cur.size(); i++){
	    		
	    		auto lf = cur[i];
	    		auto ri = cur[i+1];
	    		
	    		int l = lf.first.back()+lf.second;
	    		int r = ri.first.front()-ri.second;
	    		
	    		int ch = (r-l+1)/2;
	    		mn = min(mn, ch);
	    	}
	    	
	    	// cout << mn << endl;
	    	
	    	if(mn > h) break;
	    	assert(mn >= 0);
	    	
	    	h -= mn;
	    	ans += mn*cur.size();
	    	
	    	for(auto &[v, h] : cur){
	    		h += mn;	
	    	}
	    	
	    	for(int i = 0; i+1 < cur.size(); i++){
	    		
	    		auto &lf = cur[i];
	    		auto &ri = cur[i+1];
	    		
	    		int l = lf.first.back()+lf.second;
	    		int r = ri.first.front()-ri.second;
	    		
	    		if(l+1 >= r){
	    			
	    			if(lf.second != ri.second){
	    				int mn = min(lf.second, ri.second);
	    				for(auto &i : lf.first) i += lf.second-mn;
	    				for(auto &i : ri.first) i -= ri.second-mn;
	    				lf.second=ri.second = mn;
	    			}
	    			
	    			int dist = ri.first.front()-lf.first.back();
	    			assert(dist >= 2);
	    			
	    			// cout << ri.first.front() << ' ' << lf.first.back() << ' ' << dist << endl << flush;
	    			// cout << ri.second << ' ' << lf.second << endl << flush;
	    			
    				int ch = (dist+1)/2;
    				int mxh = max(lf.second, ri.second);
    				assert(ch >= lf.second && ch >= ri.second);
    				
	    			// ans -= ch*2;
	    			// ans += ch*2-1;
	    			ans -= 1;
	    			
	    			if(dist%2==0){
	    				cur[i] = {(vi){lf.first.back()+dist/2}, mxh-ch};
	    			}
	    			else{
	    				cur[i] = {(vi){lf.first.back()+dist/2, lf.first.back()+dist/2+1}, mxh-ch};
	    			}
    			
    				cur.erase(cur.begin()+(i+1));
	    			
	    			i--;
	    		}
	    	}
	    }
	    
		ans += h*cur.size();
		cout << ans << endl;
    }
}
