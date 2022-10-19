// Problem: Subset
// Contest: HackerRank - CounterCode 2015
// URL: https://www.hackerrank.com/contests/countercode/challenges/subset/problem
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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

const int N = 16;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    vpii queries;
    vi frq(1<<N);
    vi dp(1<<N);
    
    int q; cin >> q; while(q--){
    	
    	string k;
    	int val;
    	
    	cin >> k >> val;
    	
    	if(k=="add"){
    		queries.push_back({+1, val});
    	}	
    	else if(k=="del"){
    		queries.push_back({-1, val});
    	}	
    	else if(k=="cnt"){
    		
    		int ans = dp[val];
    		for(auto [f, v] : queries) if((val&v)==v){
    			ans += f;
    		}
    		
    		cout << ans << endl;
    	}
    	
    	if(queries.size() >= BLOCK){
    		
    		for(auto [f, v] : queries){
    			frq[v] += f;
    		}
    		
    		for(int i = 0; i<(1<<N); ++i){
    			dp[i] = frq[i];
    		}
				
			for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
				if(mask & (1<<i)){
					dp[mask] += dp[mask^(1<<i)];
				}
			}
			
			queries.clear();
    	}
    }
}
