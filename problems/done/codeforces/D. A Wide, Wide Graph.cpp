// Problem: D. A Wide, Wide Graph
// Contest: Codeforces - Codeforces Round 862 (Div. 2)
// URL: https://codeforces.com/contest/1805/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int n;
vi adj[NMAX];
int depth[NMAX];
int tin[NMAX], _tin[NMAX], tout[NMAX], tim;
int tree[NMAX << 2];
int lazy[NMAX << 2];
int ans[NMAX];

void push(int nd, int l, int r){
	
	if(!lazy[nd]){
		return;
	}
	
	tree[nd] += lazy[nd];
	
	if(l != r){
		lazy[nd*2] += lazy[nd];
		lazy[nd*2+1] += lazy[nd];
	}
	
	lazy[nd] = 0;
}

void build(int nd, int l, int r){
	
	if(l==r){
		tree[nd] = depth[_tin[l]];
		return;
	}	
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = max(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_l, int q_r, int val){
	
	push(nd, l, r);
	
	if(q_r < l || r < q_l){
		return;
	}
	
	if(q_l <= l && r <= q_r){
		lazy[nd] += val;
		push(nd, l, r);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, val);
	update(nd*2+1, mid+1, r, q_l, q_r, val);
	
	tree[nd] = max(tree[nd*2], tree[nd*2+1]);
}

void dfs(int u, int p){
	
	tin[u] = tim;
	_tin[tim] = u;
	tim++;
	
	for(auto v : adj[u]) if(v != p){
		depth[v] = depth[u]+1;
		dfs(v, u);
	}
	
	tout[u] = tim;
}

void go(int u, int p){
	
	ans[tree[1]]++;
	
	for(auto v : adj[u]) if(v != p){

		int l = tin[v];
		int r = tout[v]-1;
		
		update(1, 0, n-1, 0, n-1, +1);
		update(1, 0, n-1, l, r, -2);
		
		go(v, u);
		
		update(1, 0, n-1, l, r, +2);
		update(1, 0, n-1, 0, n-1, -1);
	}	
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    dfs(0, -1);
    build(1, 0, n-1);
	
	go(0, -1);
	
	for(int i = 1; i < n; i++){
		ans[i] += ans[i-1];
	}
	
	for(int i = 0; i < n; i++){
		if(ans[i] < n) ans[i]++;
	}
	
	for(int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
}
