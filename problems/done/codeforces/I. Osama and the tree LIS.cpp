// Problem: I. Osama and the tree LIS
// Contest: Codeforces - Btunis beek
// URL: https://codeforces.com/group/rKyL0A9Cab/contest/447953/problem/I
// Memory Limit: 1024 MB
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
 
const int SZ = MOD;
const int NMAX = 3e5 + 10;

struct node{
	
	int mx;
	int size;
	node *lf, *ri;
	
	node(){
		mx=size = 0;
		lf=ri = nullptr;
	}	
	
	~node(){
		// delete lf;
		// delete ri;
	}
	
	int query(int l, int r, int q_l, int q_r){
		
		if(r < q_l || q_r < l){
			return 0;
		}
		
		if(q_l <= l && r <= q_r){
			return mx;
		}
		
		int ret = 0;
		int mid = (l+r)/2;
		
		if(lf){
			ret = max(ret, lf->query(l, mid, q_l, q_r));
		}
		if(ri){
			ret = max(ret, ri->query(mid+1, r, q_l, q_r));	
		}
		
		return ret;
	}
	
	void merge(){
		
		mx = 0;	
		size = 0;
		
		if(lf){
			mx = max(mx, lf->mx);
			size += lf->size;
		}
		
		if(ri){
			mx = max(mx, ri->mx);
			size += ri->size;
		}
	}
	
	void update(int l, int r, int p, int v){
		
		if(l==r){
			mx = max(mx, v);
			size = 1;
			return;
		}
		
		int mid = (l+r)/2;
		
		if(p <= mid){
			if(!lf) lf = new node();
			lf->update(l, mid, p, v);
		}
		else{
			if(!ri) ri = new node();
			ri->update(mid+1, r, p, v);
		}
		
		merge();
	}
	
	void dfs(int l, int r, vpii &res){
		
		if(l==r){
			res.push_back({l, mx});
			return;
		}
		
		int mid = (l+r)/2;
		if(lf) lf->dfs(l, mid, res);
		if(ri) ri->dfs(mid+1, r, res);
	}
};

int n;
int arr_b[NMAX];
vi adj[NMAX];
int sm_ans[NMAX];
int ans[NMAX];

node go(int u, int p){
	
	node cur;
	bool is_leaf = true;
	
	for(auto v : adj[u]) if(v != p){
		
		is_leaf = false;
			
		node nxt = go(v, u);
		sm_ans[u] += sm_ans[v];
		
		if(nxt.size > cur.size){
			swap(cur, nxt);
		}
		
		vpii elements;
		nxt.dfs(0, SZ-1, elements);
		
		for(auto [k, v] : elements){
			cur.update(0, SZ-1, k, v);
		}
	}	
	
	int val = mul(arr_b[u], is_leaf ? 1 : sm_ans[u]);
	
	// cout << u+1 << ' ' << val << endl;
	
	ans[u] = cur.query(0, SZ-1, val+1, SZ-1) + 1;
	cur.update(0, SZ-1, val, ans[u]);
	sm_ans[u] += ans[u];
	
	return cur;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr_b[i];
	}
	
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	go(0, -1);
	
	for(int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
}
