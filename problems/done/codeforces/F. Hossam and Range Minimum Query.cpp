// Problem: F. Hossam and Range Minimum Query
// Contest: Codeforces - Codeforces Round 837 (Div. 2)
// URL: https://codeforces.com/contest/1771/problem/F
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

struct node{
	
	int val;
	node *lf, *ri;
	
	node() : node(0){}
	
	node(int val) : node(val, this, this){}
	
	node(int val, node *lf, node *ri) : 
		val(val), lf(lf), ri(ri) {}
};

node* update(node* &nd, int l, int r, int p, int x){
	
	if(!nd){
		nd = new node();	
	}
	
	if(p < l || r < p){
		return nd;
	}	
	
	if(l==r){
		return new node(nd->val ^ x);
	}
	
	int mid = (l+r)/2;
	node *lf = update(nd->lf, l, mid, p, x);
	node *ri = update(nd->ri, mid+1, r, p, x);
	
	return new node(lf->val ^ ri->val, lf, ri);	
}

int query(node* nd, int l, int r, int q_l, int q_r){
	
	if(q_r < l || r < q_l || !nd){
		return 0;
	}	
	
	if(q_l <= l && r <= q_r){
		return nd->val;
	}
	
	int mid = (l+r)/2;
	int st_path = query(nd->lf, l, mid, q_l, q_r);
	int nd_path = query(nd->ri, mid+1, r, q_l, q_r);
	
	return st_path^nd_path;
}

int query(node *nd0, node *nd1, int l, int r){
	
	if(l==r){
		return l;
	}
	
	int mid = (l+r)/2;
	
	if(nd0->lf->val == nd1->lf->val){
		return query(nd0->ri, nd1->ri, mid+1, r);
	}
	else{
		return query(nd0->lf, nd1->lf, l, mid);
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
    
	vi tmp = vec;
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	for(auto &i : vec){
		i = lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin();
	}
    
    
    vi val(n);
    for(auto &i : val){
    	i = rand(0, 1ll << 61);
    }
    
    vector<node*> trees(n+1);
    trees[0] = new node();
    
    for(int i = 1; i <= n; i++){
    	trees[i] = update(trees[i-1], 0, n-1, vec[i-1], val[vec[i-1]]);
    }
    
    auto go = [&](int lf, int ri)->int{
    	
    	auto nd0 = trees[ri+1];
    	auto nd1 = trees[lf];
    	
    	if(nd0->val == nd1->val){
    		return 0;
    	}
    	else{
    		int ans = query(nd0, nd1, 0, n-1);
    		return tmp[ans];
    	}
    };
    
    int ans = 0;
    int m; cin >> m; while(m--){
    	
    	int l, r;
    	cin >> l >> r;
    	l ^= ans, r ^= ans;
    	if(l > r) swap(l, r);
    	l--, r--;
    	
    	// cout << l << ' ' << r << endl << flush;
    	
    	assert(0 <= l && l <= r && r < n);
    	
    	ans = go(l, r);
    	
    	cout << ans << endl;
    }
}
