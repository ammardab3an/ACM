// Problem: F - Best Concatenation
// Contest: AtCoder - UNIQUE VISION Programming Contest 2022 Summer (AtCoder Beginner Contest 268)
// URL: https://atcoder.jp/contests/abc268/tasks/abc268_f
// Memory Limit: 1024 MB
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
    
    int n;
    cin >> n;
    
    vector<string> vec(n);
    for(auto &s : vec) cin >> s;
    
    int ans = 0;
    
    vpii val(n);
    for(int i = 0; i < n; i++){
    	
    	int sm = 0;
    	int cnt_x = 0;
    	
    	for(auto c : vec[i]){
    		
    		if(c=='X'){
    			cnt_x++;
    		}
    		else{
    			sm += c-'0';
    			ans += (c-'0') * cnt_x;
    		}
    	}
    	
    	val[i] = {sm, cnt_x};
    }
    
    sort(val.begin(), val.end(), [](const pii &a, const pii &b){
    	return a.second*b.first < a.first*b.second;
    });
    
    int cnt_x = 0;
    for(auto [c, s] : val){
    	ans += s*cnt_x;
    	cnt_x += c;
    }
    
    cout << ans << endl;
}