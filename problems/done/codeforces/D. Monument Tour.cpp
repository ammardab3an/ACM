// Problem: D. Monument Tour
// Contest: Codeforces - 2018-2019 ICPC Southwestern European Regional Programming Contest (SWERC 2018)
// URL: https://codeforces.com/gym/102465/problem/D
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
    
    int x, y;
    cin >> x >> y;
    
    int n;
    cin >> n;
    
    vpii vec(n);
    for(auto &[i, j] : vec){
    	cin >> i >> j;
    }
    
    vpii tmp(x+1, {INF, -INF});
    for(auto [i, j] : vec){
    	auto &[mn, mx] = tmp[i];
    	mn = min(mn, j);
    	mx = max(mx, j);
    }
    
    int cnt_up=0, cnt_down=0;
    int sm_up=0, sm_down=0;
    
    vpii nvec;
    for(auto [mn, mx] : tmp) if(mn != INF){
    	nvec.push_back({mn, mx});
    	sm_up += mx;
    	cnt_up += 1;
    }
    
    vpii foo;
    for(int i = 0; i < nvec.size(); i++){
    	foo.push_back({nvec[i].first, i});
    	if(nvec[i].first != nvec[i].second){		
	    	foo.push_back({nvec[i].second, i});
    	}
    }
    
    sort(foo.begin(), foo.end());
    
    int ans = INFLL;
    
    for(int i = 0; i < foo.size(); i++){
    	
    	auto [v, p] = foo[i];
    	
    	{
    		auto [v0, p0] = foo[i];
			auto [mn, mx] = nvec[p0];
		
			// cout << v0 << ' ' << mn << ' ' << mx << endl;
			
    		if(v0==mn){
    			cnt_down++;
    			sm_down += v0;
    		}
    		if(v0==mx){
    			cnt_up--;
    			sm_up -= v0;
    		}
    	}
    	
    	int st = sm_up - cnt_up*v;
    	int nd = cnt_down*v - sm_down;
    	int cans = 2*(st + nd);
    	
    	// cout << v << ' ' << sm_up << ' ' << sm_down << ' ' << cnt_up << ' ' << cnt_down << ' ' << st << ' ' << nd << endl;
    	
    	ans = min(ans, cans);
    }
    
    cout << ans+x-1 << endl;
}
