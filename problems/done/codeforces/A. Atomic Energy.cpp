// Problem: A. Atomic Energy
// Contest: Codeforces - 2020-2021 ICPC Northwestern European Regional Programming Contest (NWERC 2020)
// URL: https://codeforces.com/gym/103049/problem/A
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
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
    
    int n, m;
    cin >> n >> m;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    vec.resize(1e4);
    
    for(int i = n; i < vec.size(); i++){
    	
    	int ai = i+1;
    	int cans = INFLL;
    	for(int i = 1; i <= ai/2; i++){
    		cans = min(cans, vec[i-1] + vec[ai-i-1]);
    	}	
    	
    	vec[i] = cans;
    }
    
    // for(int i : vec) cout << i << ' ' ; cout << endl;
    
    while(m--){
    	
    	int k;
    	cin >> k;
	    
	    if(k <= vec.size()){
	    	cout << vec[k-1] << endl;
	    	continue;
	    }
	    
	    int ans = INFLL;
	    
	    for(int i = 0; i < n; i++){
	    	
	    	int cans = 0;
	    	int dif = k - (vec.size()-200);
	    	cans += (dif / (i+1)) * vec[i];
	    	
	    	int rem = k - (dif/(i+1)) * (i+1);
	    	cans += vec[rem-1];
	    	
	    	// cout << n << ' ' << rem << endl;
	    	
	    	ans = min(ans, cans);
	    }
	    
	    cout << ans << endl;
    }
}
