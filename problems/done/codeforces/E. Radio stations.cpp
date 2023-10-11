// Problem: E. Radio stations
// Contest: Codeforces - Educational Codeforces Round 17
// URL: https://codeforces.com/contest/762/problem/E
// Memory Limit: 256 MB
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct node{
	
	int sm;
	node *lf, *ri;
	
	node(){
		sm = 0;
		lf = ri = nullptr;
	}
	
	void update(int l, int r, int p, int d){
		
		sm += d;
		
		if(l==r){
			return;
		}
		
		int mid = (l+r)/2;
		if(p <= mid){
			if(!lf) lf = new node();
			lf->update(l, mid, p, d);
		}
		else{
			if(!ri) ri = new node();
			ri->update(mid+1, r, p, d);
		}
	}
	
	int query(int l, int r, int q_l, int q_r){
		
		if(r < q_l || q_r < l){
			return 0;
		}
		
		if(q_l <= l && r <= q_r){
			return sm;
		}
		
		int mid = (l+r)/2;
		int st_path = !lf ? 0 : lf->query(l, mid, q_l, q_r);
		int nd_path = !ri ? 0 : ri->query(mid+1, r, q_l, q_r);
		
		return st_path + nd_path;
	}
};

node tree[10100];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n, k;
	cin >> n >> k;
	
	vector<iii> vec(n);
	for(auto &[r, xf] : vec){
		auto &[x, f] = xf;
		cin >> x >> r >> f;
	}
	
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	
	int ans = 0;
	
	for(auto [r, xf] : vec){
		auto [x, f] = xf;
		
		for(int i = max((int)1, f-k); i <= f+k; i++){
			ans += tree[i].query(1, 1e9, x-r, x+r);
		}
		
		tree[f].update(1, 1e9, x, 1);
	}
	
	cout << ans << endl;
}
