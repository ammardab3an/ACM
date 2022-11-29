// Problem: E. Sign on Fence
// Contest: Codeforces - Codeforces Round #276 (Div. 1)
// URL: https://codeforces.com/problemset/problem/484/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


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

struct node{
	
	int max, pre, suf, len;
	
	node(){
		max = pre = suf = len = 0;
	}	
	
	node(int val, int l, int r){
		max = pre = suf = val;
		len = r-l+1;
	}
	
} tree[NMAX << 2];

node merge(const node &a, const node &b){
	
	node ret;
	ret.max = max({a.max, b.max, a.suf+b.pre});
	ret.pre = (a.pre == a.len) ? a.len+b.pre : a.pre;
	ret.suf = (b.suf == b.len) ? a.suf+b.len : b.suf;
	ret.len = a.len + b.len;
	
	return ret;
}

void build(int nd, int l, int r){
	
	if(l==r){
		tree[nd] = node(0, l, r);
		return;
	}
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int p, int val){
	
	if(p < l || r < p){
		return;
	}	
	
	if(l==r){
		tree[nd] = node(val, l, r);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, p, val);
	update(nd*2+1, mid+1, r, p, val);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

node query(int nd, int l, int r, int q_l, int q_r){
	
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
    
    int n;
    cin >> n;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    vpii tmp(n);
    for(int i = 0; i < n; i++){
    	tmp[i] = {vec[i], i};
    }
    
    sort(tmp.begin(), tmp.end());
    reverse(tmp.begin(), tmp.end());
    
    int q;
    cin >> q; 
    
    vector<iii> queries(q);
    for(auto &[k, lr] : queries){
    	auto &[l, r] = lr;
    	cin >> l >> r >> k;
    	l--, r--;
    }
    
    
    queue<pair<pii, vi>> que;
    que.push({{0, n}, vi(q)});
    iota(que.front().second.begin(), que.front().second.end(), 0);
    
    vi ans(q);
    
    int cur = INF;
    
    while(!que.empty()){
    	
    	auto fr = que.front();
    	que.pop();
    	
    	auto [l, r] = fr.first;
    	vi &v = fr.second;
    	
    	if(l==r){
    		for(auto i : v){
    			ans[i] = l;
    		}
    		continue;
    	}
    	
    	int mid = (l+r)/2;
    	
    	if(cur <= mid){
    		for(int i = cur+1; i <= mid; i++){
    			auto [v, p] = tmp[i];
    			update(1, 0, n-1, p, 1);
    		}
    	}
    	else{
    		build(1, 0, n-1);
    		for(int i = 0; i <= mid; i++){
    			auto [v, p] = tmp[i];
    			update(1, 0, n-1, p, 1);    			
    		}
    	}
    	
    	cur = mid;
    	
    	vi lf, ri;
    	for(auto i : v){
    		
    		int k = queries[i].first;
    		auto [ql, qr] = queries[i].second;
    		
    		int mx = query(1, 0, n-1, ql, qr).max;
    		
    		if(mx >= k){
    			lf.push_back(i);
    		}
    		else{
    			ri.push_back(i);
    		}
    	}
    	
    	if(lf.size()) que.push({{l, mid}, lf});
    	if(ri.size()) que.push({{mid+1, r}, ri});
    }
    
    for(int i = 0; i < q; i++){
    	assert(ans[i] < n);
    	cout << tmp[ans[i]].first << endl;
    }
}
