// Problem: F. Flipping El-fetiera
// Contest: Codeforces - 2018 Arab Collegiate Programming Contest (ACPC 2018)
// URL: https://codeforces.com/gym/101991/problem/F
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
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
 
const int NMAX = 300 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

#ifndef CPEDU
    freopen("fetiera.in", "r", stdin);
#endif

    int t; cin >> t; while(t--){
    	
    	int n, k;
    	cin >> n >> k;
    	
	    vector<vi> vec(n, vi(n));
	    
	    for(auto &v : vec)
	    for(auto &i : v) cin >> i;
	    
	    double ans = 0;
	    
	    int tot = 0;
	    for(int i = 0; i < n; i++)
	    for(int j = 0; j < n; j++){
	    	tot += (n-i)*(n-j);
	    }
	    
	    for(int i = 0; i < n; i++)
	    for(int j = 0; j < n; j++){
	    	
	    	int a = (i+1)*(j+1) * (n-i)*(n-j);
	    	int b = tot;
	    	
	    	double p = double(a)/double(b);
	    	double q = 1.0-p;
	    	
	    	double p0 = 1, p1 = 0;
	    	
	    	for(int w = 0; w < k; w++){
	    		
	    		double np0 = p * p1 + q * p0;
	    		double np1 = p * p0 + q * p1;
	    		
	    		p0 = np0;
	    		p1 = np1;
	    	}
	    	
	    	ans += vec[i][j] ? p0 : p1;
	    }
	    
	    cout << fixed << setprecision(5) << ans << endl;
    }
}