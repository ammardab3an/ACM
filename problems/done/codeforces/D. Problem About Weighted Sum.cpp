// Problem: D. Problem About Weighted Sum
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 2 - Step 4
// URL: http://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/D
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
 
const int NMAX = 1e5 + 10;

int n, q;
int arr[NMAX];

struct node{
	int sz = 0;
	int sm = 0;
	int ans = 0;
	int lazy = 0;
};

node tree[NMAX << 2];

node merge(const node &a, const node &b){
	
	assert(a.lazy==0 && b.lazy==0);
	
	node ret;
	ret.sz = a.sz + b.sz;
	ret.sm = a.sm + b.sm;
	ret.ans = a.ans + b.ans + b.sm * a.sz;
	ret.lazy = 0;
	
	return ret;
}

void push(int nd, int l, int r){
	
	if(tree[nd].lazy == 0) return;
	
	tree[nd].sm += tree[nd].lazy * (r-l+1);
	tree[nd].ans += tree[nd].lazy * ((1+tree[nd].sz)*tree[nd].sz)/2;
	
	if(l != r){
		tree[nd*2].lazy += tree[nd].lazy;
		tree[nd*2+1].lazy += tree[nd].lazy;
	}
	
	tree[nd].lazy = 0;
}

void build(int nd, int l, int r){
	
	if(l==r){
		tree[nd].sm = arr[l];
		tree[nd].ans = arr[l];
		tree[nd].sz = 1;
		return;
	}	
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_l, int q_r, int d){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return;
	}
	
	if(q_l <= l && r <= q_r){
		tree[nd].lazy += d;
		push(nd, l, r);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, d);
	update(nd*2+1, mid+1, r, q_l, q_r, d);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

node query(int nd, int l, int r, int q_l, int q_r){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return node();
	}
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	node st_path = query(nd*2, l, mid, q_l, q_r);
	node nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return merge(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> q;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    build(1, 0, n-1);
    
    while(q--){
    	
    	int k;
    	cin >> k;
    	
    	if(k == 1){
    		
    		int l, r, d;
    		cin >> l >> r >> d;
    		l--, r--;
    		
    		update(1, 0, n-1, l, r, d);		
    	}
    	else{
    		
    		int l, r;
    		cin >> l >> r;
    		l--, r--;
    		
    		node que = query(1, 0, n-1, l, r);
    		cout << que.ans << endl;
    	}
    }
}
