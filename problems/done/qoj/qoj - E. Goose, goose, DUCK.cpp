
// E. Goose, goose, DUCK?
// https://qoj.ac/contest/1099/problem/5459?v=1

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
const int NMAX = 1e6 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

pii tree[NMAX << 2];
int lazy[NMAX << 2];

pii merge(const pii &a, const pii &b){
	if(a.first != b.first){
		return min(a, b);
	}
	else{
		return {a.first, a.second + b.second};
	}
}

void push(int nd, int l, int r){
	
	if(!lazy[nd]) return;
	
	tree[nd].first += lazy[nd];
	
	if(l != r){
		lazy[nd*2] += lazy[nd];
		lazy[nd*2+1] += lazy[nd];
	}
	
	lazy[nd] = 0;
}

void build(int nd, int l, int r){
	
	if(l==r){
		tree[nd] = {0, 1};
		return;
	}	
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_l, int q_r, int v){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return;
	}	
	
	if(q_l <= l && r <= q_r){
		lazy[nd] += v;
		push(nd, l, r);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, v);
	update(nd*2+1, mid+1, r, q_l, q_r, v);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

pii query(int nd, int l, int r, int q_l, int q_r){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return {INF, 0};
	}
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	pii st_path = query(nd*2, l, mid, q_l, q_r);
	pii nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return merge(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
	int n, k;
	cin >> n >> k;
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	int m;
	{
		vi tmp = vec;
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
		for(auto &e : vec) e = lower_bound(tmp.begin(), tmp.end(), e) - tmp.begin();
		m = tmp.size();
	}
	
	
	build(1, 0, n-1);
	
	vector<vi> pos(m, {-1});
	
	auto calc = [&](const vi &pos)->pii{
		
		assert(pos.size() > k);
		
		int sz = pos.size();
		int r = pos[sz-k];
		int l = pos[sz-k-1];
		
		return {l+1, r};
	};
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		
		int cval = vec[i];
		if(pos[cval].size() > k){
			auto [l, r] = calc(pos[cval]);
			update(1, 0, n-1, l, r, -1);
		}
		pos[cval].push_back(i);
		if(pos[cval].size() > k){
			auto [l, r] = calc(pos[cval]);
			update(1, 0, n-1, l, r, +1);
		}
		
		pii q = query(1, 0, n-1, 0, i);
		if(q.first == 0) ans += q.second;
	}
	
	cout << ans << endl;
}
