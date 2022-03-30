// Problem: E. Pencils and Boxes
// Contest: Codeforces - Educational Codeforces Round 44 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/985/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int NMAX = 5e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

bool tree[NMAX << 2];

void update(int nd, int l, int r, int p){
	
	if(p < l || r < p){
		return;
	}	
	
	if(l == r){
		tree[nd] = true;
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, p);
	update(nd*2+1, mid+1, r, p);
	
	tree[nd] = tree[nd*2] || tree[nd*2+1];
}

bool query(int nd, int l, int r, int q_l, int q_r){
	
	if(r < q_l || q_r < l){
		return false;
	}	
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	bool st_path = query(nd*2, l, mid, q_l, q_r);
	bool nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return st_path || nd_path;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, k, d;
    cin >> n >> k >> d;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    sort(vec.begin(), vec.end());
    
    vi dp(n+1);
    dp[n] = true;
    update(1, 0, n, n);
    
    for(int i = n-1; i >= 0; i--){
    	
    	int j = upper_bound(vec.begin()+i, vec.end(), vec[i]+d) - vec.begin();
    	
    	if(j-i < k){
    		dp[i] = false;
    	}	
    	else{
    		int l = i+k;
    		int r = j;
    		dp[i] = query(1, 0, n, l, r);
    		if(dp[i]) update(1, 0, n, i);
    	}
    }
    
    cout << (dp[0] ? "YES" : "NO") << endl;
}
