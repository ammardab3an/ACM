// Problem: C. DZY Loves Colors
// Contest: Codeforces - Codeforces Round #254 (Div. 1)
// URL: https://codeforces.com/problemset/problem/444/C
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
	int col;
	int value;
	int lazy;
	
} tree[NMAX << 2];

void push(int nd, int l, int r){
	
	auto &a = tree[nd];
	
	if(!a.lazy){
		return;
	}
	
	a.value += a.lazy * (r-l+1);
	
	if(l != r){
		
		tree[nd*2].lazy += a.lazy;
		tree[nd*2+1].lazy += a.lazy;
		
		if(a.col){
			tree[nd*2].col = a.col;
			tree[nd*2+1].col = a.col;
		}
	}
	
	a.lazy = 0;
}

node merge(const node &a, const node &b){
	
	assert(!a.lazy && !b.lazy);
	
	return (node){
		a.col==b.col ? a.col : 0, 
		a.value+b.value,
		0
	};
}

void build(int nd, int l, int r){
	
	if(l==r){
		tree[nd] = (node){l, 0, 0};
		return;
	}
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_l, int q_r, int col){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return;
	}
	
	if(q_l <= l && r <= q_r && tree[nd].col){
		tree[nd].lazy += abs(tree[nd].col-col);
		tree[nd].col = col;
		push(nd, l, r);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, col);
	update(nd*2+1, mid+1, r, q_l, q_r, col);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

int query(int nd, int l, int r, int q_l, int q_r){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return 0;
	}	
	
	if(q_l <= l && r <= q_r){
		return tree[nd].value;
	}
	
	int mid = (l+r)/2;
	int st_path = query(nd*2, l, mid, q_l, q_r);
	int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return st_path + nd_path;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    build(1, 1, n);
    
    while(m--){
    	
    	int k;
    	cin >> k;
    	
    	if(k==1){
	    	int l, r, x;
	    	cin >> l >> r >> x;
    		update(1, 1, n, l, r, x);
    	}
    	else{
    		int l, r;
    		cin >> l >> r;
    		cout << query(1, 1, n, l, r) << endl;
    	}
    }
}
