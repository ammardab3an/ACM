// Problem: D. Tree Construction
// Contest: Codeforces - Codeforces Round #353 (Div. 2)
// URL: https://codeforces.com/contest/675/problem/D
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct node{
	pii val;
	pii lazy;	
} tree[NMAX << 2];

void push(int nd, int l, int r){
	
	if(!tree[nd].lazy.first){
		return;
	}	
	
	tree[nd].val = max(tree[nd].val, tree[nd].lazy);
	
	if(l != r){
		tree[nd*2].lazy = max(tree[nd*2].lazy, tree[nd].lazy);
		tree[nd*2+1].lazy = max(tree[nd*2+1].lazy, tree[nd].lazy);	
	}
	
	tree[nd].lazy = {0, 0};
}

void update(int nd, int l, int r, int q_l, int q_r, pii p){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return;
	}	
	
	if(q_l <= l && r <= q_r){
		tree[nd].lazy = p;
		push(nd, l, r);
		return;	
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, p);
	update(nd*2+1, mid+1, r, q_l, q_r, p);
}

int query(int nd, int l, int r, int p){
	
	push(nd, l, r);
	
	if(l==r){
		return tree[nd].val.second;
	}
	
	int mid = (l+r)/2;
	if(p <= mid){
		return query(nd*2, l, mid, p);
	}
	else{
		return query(nd*2+1, mid+1, r, p);
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
    tmp.resize(unique(tmp.begin(), tmp.end())-tmp.begin());
    
    for(auto &i : vec){
	    i = lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin();	
    }
    
    int t = 1;
    int sz = tmp.size();
    update(1, 0, sz-1, 0, sz-1, (pii){t++, 0});
    
    vpii rng(n);
    rng[0] = {0, sz-1};
    
    vi ans(n-1);
    
    // for(auto i : vec) cout << i << ' '; cout << endl;
    
    for(int i = 1; i < n; i++){
    	
    	int val = vec[i];	
    	
    	int p = query(1, 0, sz-1, val);
    	ans[i-1] = p;
    	
    	auto [l, r] = rng[p];
    	
    	if(vec[p] < val){
    		rng[i] = {vec[p], r};
    		update(1, 0, sz-1, vec[p], r, (pii){t++, i});
    	}
    	else{
    		rng[i] = {l, vec[p]};
    		update(1, 0, sz-1, l, vec[p], (pii){t++, i});
    	}
    	
    	// cout << i << ' ' << val << ' ' << p << ' ' << vec[p] << ' ' << rng[i].first << ' ' << rng[i].second << endl;
    }
    
    for(auto i : ans) cout << tmp[vec[i]] << ' '; cout << endl;
}
