// Problem: D. For Gamers. By Gamers.
// Contest: Codeforces - Educational Codeforces Round 125 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1657/D
// Memory Limit: 256 MB
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

int32_t main(){
    
    fastIO;
    
    #undef endl
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, c;
    cin >> n >> c;
    
    vpii vec(n);
    for(auto &p : vec){
    	int c, d, h;
    	cin >> c >> d >> h;
    	p = {c, d*h};
    }
    
    sort(vec.begin(), vec.end(), [](const pii &a, const pii &b){
    	if(a.first != b.first){
    		return a.first < b.first;
    	}
    	else{
    		return a.second > b.second;
    	}
    });
    
    {
	    vpii nvec;
	    nvec.push_back(vec[0]);
	    for(int i = 1; i < n; i++){
	    	if(nvec.back().second < vec[i].second){
	    		nvec.push_back(vec[i]);
	    	}
	    }
	    
	    vec = nvec;
	    n = vec.size();
    }
    
    vi best(c+1);
    
    for(int i = 0; i < n; i++){
    	int a = vec[i].first;
    	int b = vec[i].second;
    	for(int j = 1; j*a <= c; j++){
    		best[j*a] = max(best[j*a], j*b);
    	}
    }
    
    for(int i = 1; i <= c; i++){
    	best[i] = max(best[i], best[i-1]);
    }
    
    int m; cin >> m; while(m--){
    	
    	int d, h;
    	cin >> d >> h;
    	
    	int p = upper_bound(best.begin(), best.end(), d*h)-best.begin();
    	
    	if(p <= c){
    		cout << p << ' ';
    	}
    	else{
    		cout << -1 << ' ';
    	}
    }
}
