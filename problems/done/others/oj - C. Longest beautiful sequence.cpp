// sort on bits 2

//  C. Longest beautiful sequence
// https://oj.uz/problem/view/IZhO17_subsequence

// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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

pii mem[1<<10][1<<10][11];

pii query(int x, int k){
	
	pii ret = {0, 0};
	
	int ri = x & ((1<<10)-1);
	int lf = x >> 10;
	
	for(int i = 0; i < (1<<10); i++){
		
		int cnt_lf = __builtin_popcount(lf&i);
		int cnt_ri = k-cnt_lf;
		
		if(0 <= cnt_ri && cnt_ri <= 10){
			ret = max(ret, mem[i][ri][cnt_ri]);
		}
	}	
	
	return ret;
}

void update(int x, pii val){
	
	int ri = x & ((1<<10)-1);
	int lf = x >> 10;
	
	for(int i = 0; i < (1<<10); i++){
		
		int cnt_ri = __builtin_popcount(ri&i);
		
		if(cnt_ri <= 10){		
			mem[lf][i][cnt_ri] = max(mem[lf][i][cnt_ri], val);
		}
	}	
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    vi vec_k(n);
    for(auto &i : vec_k) cin >> i;
    
    vi par(n);
    iota(par.begin(), par.end(), 0);
    pii ans = {1, 0};
    
    for(int i = 0; i < n; i++){
    	
    	pii que = query(vec[i], vec_k[i]);
    	auto [len, lst] = que;
    	
    	if(len){
    		par[i] = lst;
    		ans = max(ans, {len+1, i});
    	}
    	
    	update(vec[i], {len+1, i});
    }
    
    auto [len, lst] = ans;
    
    vi tmp;
    while(par[lst] != lst){
    	tmp.push_back(lst);
    	lst = par[lst];
    }
    tmp.push_back(lst);
    
    cout << tmp.size() << endl;
    reverse(tmp.begin(), tmp.end());
    for(auto i : tmp) cout << i+1 << ' '; 
    cout << endl;
}
