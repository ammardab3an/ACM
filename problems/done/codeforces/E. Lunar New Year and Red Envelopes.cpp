// Problem: E. Lunar New Year and Red Envelopes
// Contest: Codeforces - Codeforces Round #536 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1106/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<iii>> tmp(n+1);
    
    while(k--){
    	
    	int s, t, d, w;
    	cin >> s >> t >> d >> w;
    	s--, t--, d--;
    	
    	tmp[s].push_back({1, {d, w}});
    	tmp[t+1].push_back({0, {d, w}});
    }
    
    vpii vec(n);
    
    multiset<pii> mst;
    
    for(int i = 0; i < n; i++){
    		
    	for(auto p : tmp[i]){
    		
    		int b = p.first;
    		int d = p.second.first;
    		int w = p.second.second;
    		
    		if(b){
    			mst.insert({-w, -d});
    		}
    		else{
    			mst.erase(mst.find({-w, -d}));
    		}
    	}
    	
    	if(!mst.empty()){
	    	pii p = *mst.begin();
	    	int w = -p.first;
	    	int d = -p.second;
	    	vec[i] = {w, d+1};
    	}
    	else{
    		vec[i] = {0, i+1};
    	}
    }
    
    vi dp(n+1);
    
    for(int i = n-1; i >= 0; i--){
    	dp[i] = vec[i].first + dp[vec[i].second];
    }
    
    while(m--){
    	
    	vi new_dp(n+1);
    	
    	for(int i = n-1; i >= 0; i--){
    		
    		int st_path = vec[i].first + new_dp[vec[i].second];
    		int nd_path = dp[i+1];
    		
    		new_dp[i] = min(st_path, nd_path);
    	}
    	
    	dp = new_dp;
    }
    
    cout << dp[0] << endl;
}
