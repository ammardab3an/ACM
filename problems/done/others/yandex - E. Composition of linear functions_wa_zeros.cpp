// Problem: E. Composition of linear functions
// Contest: Yandex - Yandex Cup 2023 — Algorithm — Qualification
// URL: https://contest.yandex.com/contest/54452/problems/E/
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include <bits/stdc++.h>

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

// int fac[NMAX], ifac[NMAX];
// 
// void init(){
// 	
	// fac[0] = 1;
	// for(int i = 1; i < NMAX; i++){
		// fac[i] = mul(fac[i-1], i);
	// }
// 	
	// ifac[NMAX-1] = inv(fac[NMAX-1]);
	// for(int i = NMAX-2; i >= 0; i--){
		// ifac[i] = mul(ifac[i+1], i+1);
	// }
// }
// 
// int choose(int n, int c){
	// assert(n >= c);
	// return mul(fac[n], mul(ifac[c], ifac[n-c]));
// }

struct node{
	int sm_val, lazy, cnt;	
};

node merge(const node &a, const node &b){
	
	assert(a.lazy==1);
	assert(b.lazy==1);
	
	node ret;
	ret.sm_val = add(a.sm_val, b.sm_val);
	ret.cnt = a.cnt + b.cnt;
	ret.lazy = 1;
	
	return ret;
}

node tree[NMAX << 2];
const node empty_nd = (node){0, 1, 0};

void push(int nd, int l, int r){
	
	if(tree[nd].lazy==1){
		return;
	}	
	
	tree[nd].sm_val = mul(tree[nd].sm_val, tree[nd].lazy);
	
	if(l != r){
		tree[nd*2].lazy = mul(tree[nd*2].lazy, tree[nd].lazy);
		tree[nd*2+1].lazy = mul(tree[nd*2+1].lazy, tree[nd].lazy);
	}
	
	tree[nd].lazy = 1;
}

void build(int nd, int l, int r, const vi& vec){
	
	if(l==r){
		tree[nd] = (node){vec[l], 1, 1};
		return;
	}	
	
	int mid = (l+r)/2;
	
	build(nd*2, l, mid, vec);
	build(nd*2+1, mid+1, r, vec);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

int query_p(int nd, int l, int r, int p){
	
	push(nd, l, r);
	
	if(l==r){
		return l;
	}	
	
	int mid = (l+r)/2;
	
	if(tree[nd*2].cnt >= p){
		return query_p(nd*2, l, mid, p);
	}
	else{
		return query_p(nd*2+1, mid+1, r, p-tree[nd*2].cnt);
	}
}

void update(int nd, int l, int r, int q_l, int q_r, int val){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return;
	}	
	
	if(q_l <= l && r <= q_r){
		// cout << l << ' ' << r << endl;
		tree[nd].lazy = val;
		push(nd, l, r);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, val);
	update(nd*2+1, mid+1, r, q_l, q_r, val);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int p){

	push(nd, l, r);
	
	if(p < l || r < p){
		return;
	}
	
	if(l==r){
		tree[nd] = empty_nd;
		return;
	}	
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, p);
	update(nd*2+1, mid+1, r, p);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n;
	cin >> n;
	
	vpii vec(n);
	for(auto &[a, b] : vec) cin >> a >> b;
	
	vi val(n);
	int ml_a = 1;
	for(int i = 0; i < n; i++){
		auto [a, b] = vec[i];
		val[i] = mul(b, ml_a);
		ml_a = mul(ml_a, a);
	}
	
	build(1, 0, n-1, val);
	
	auto calc = [&](){
		int x = tree[1].sm_val;
		x = mul(-1, mul(x, inv(ml_a)));
		return x;
	};
	
	cout << calc() << endl;
	
	for(int i = 1; i < n; i++){
		
		int p;
		cin >> p;
		p = query_p(1, 0, n-1, p);
		
		auto [a, b] = vec[p];
		
		update(1, 0, n-1, p);
		update(1, 0, n-1, p+1, n-1, inv(a));
		ml_a = mul(ml_a, inv(a));
		
		// cout << p << ' ' << a << ' ' << b << ' ';	
		// cout << ml_a << ' ';
		cout << calc() << endl;
	}
}
