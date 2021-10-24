// Problem: A. Looped Playlist
// Contest: Codeforces - ITMO Academy: pilot course - Two Pointers Method - Step 3
// URL: http://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    
    int n, p;
    cin >> n >> p;
    
    int sm = 0;
    vector<int> vec(n);
    for(auto &i : vec) cin >> i, sm += i;
    
    int ans_cnt = 0;
    ans_cnt += n * (p/sm);
    p %= sm;
    
    int l = 0;
    int csm = 0;
    int res_pos = 0;
    int res_cnt = INF;
    for(int r = 0; r < 2*n; r++){
    	
    	csm += vec[r%n];
    	
    	while((l <= r) && (csm-vec[l%n] >= p)){
    		csm -= vec[l%n];
    		l++;
    	}
    	
    	int cur_cnt = r-l+1;
    	
    	if(csm >= p){
	    	if(cur_cnt < res_cnt){
	    		res_pos = min(l, r);
	    		res_cnt = cur_cnt;
	    	}
    	}
    	
    }
    
    cout << res_pos+1 << ' ' << ans_cnt+res_cnt << endl;
}