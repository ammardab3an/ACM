// Problem: E. Good Subsegments
// Contest: Codeforces - Codeforces Round 493 (Div. 1)
// URL: https://codeforces.com/contest/997/problem/E
// Memory Limit: 512 MB
// Time Limit: 7000 ms
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
const int NMAX = 120000 + 10; // 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int fac[NMAX], ifac[NMAX];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

pii tree[NMAX << 2];
int lazy[NMAX << 2];
int val[NMAX << 2]; 
int lazy_val[NMAX << 2];
bool foo[NMAX << 2];
int tim;

pii merge(const pii &a, const pii &b){
	if(a.first != b.first){
		return a.first < b.first ? a : b;
	}
	else{
		return {a.first, a.second + b.second};
	}
}

void build(int nd, int l, int r){

	if(l==r){
		tree[nd] = {1, 1};
		return;
	}	
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void push(int nd, int l, int r){
	
	if(lazy_val[nd]){
		
		val[nd] += lazy_val[nd] * tree[nd].second;
		
		if(l != r){
			if(tree[nd].first==(tree[nd*2].first+lazy[nd*2])){
				lazy_val[nd*2] += lazy_val[nd];
			}
			if(tree[nd].first==(tree[nd*2+1].first+lazy[nd*2+1])){		
				lazy_val[nd*2+1] += lazy_val[nd];
			}
		}
		
		lazy_val[nd] = 0;
	}	
	
	if(lazy[nd]){
		
		tree[nd].first += lazy[nd];	
		
		if(l != r){
			lazy[nd*2] += lazy[nd];
			lazy[nd*2+1] += lazy[nd];
		}
		
		lazy[nd] = 0;
	}
}

void update(int nd, int l, int r, int q_l, int q_r, int d){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return;
	}	
	
	if(foo[nd]){
		foo[nd] = false;
		lazy_val[nd] -= tim;		
		push(nd, l, r);
	}		
	
	if(q_l <= l && r <= q_r){
		
		lazy[nd] += d;
		push(nd, l, r);
		
		if(tree[nd].first==0){
			foo[nd] = true;
			lazy_val[nd] += tim;
			push(nd, l, r);
		}
		
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, d);
	update(nd*2+1, mid+1, r, q_l, q_r, d);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
	val[nd] = val[nd*2] + val[nd*2+1];
}

int query(int nd, int l, int r, int q_l, int q_r){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return 0;
	}	
	
	if(q_l <= l && r <= q_r){
		return val[nd] - (tree[nd].first==0) * tree[nd].second * (tim-1);
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
    
	// init();
	
	int n;
	cin >> n;
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	int q;
	cin >> q;
	
	vpii queries(q);
	for(auto &[l, r] : queries){
		cin >> l >> r;
		l--, r--;
	}
	
	vector<vpii> tmp(n);
	for(int i = 0; i < q; i++){
		auto [l, r] = queries[i];
		tmp[l].push_back({i, r});
	}
	
	vi ans(q);
	
	stack<pii> st_mn, st_mx;
	st_mn.push({-INFLL, n});
	st_mx.push({+INFLL, n});
	
	build(1, 0, n-1);
	
	for(int i = n-1; i >= 0; i--){
		
		::tim = i;
		
		{
			while(st_mn.top().first > vec[i]){
				auto [v, p] = st_mn.top();
				st_mn.pop();
				int q = st_mn.top().second;
				update(1, 0, n-1, p, q-1, v-vec[i]);
			}
			
			st_mn.push({vec[i], i});
		}
		{
			while(st_mx.top().first < vec[i]){
				auto [v, p] = st_mx.top();
				st_mx.pop();
				int q = st_mx.top().second;
				update(1, 0, n-1, p, q-1, vec[i]-v);
			}
			
			st_mx.push({vec[i], i});
		}
		
		update(1, 0, n-1, i, n-1, -1);
		
		for(auto [q_id, r] : tmp[i]){
			ans[q_id] += query(1, 0, n-1, i, r);
		}
	}
	
	for(auto i : ans) cout << i << endl;
}
