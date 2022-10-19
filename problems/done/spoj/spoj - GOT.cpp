// Problem: Gao on a tree
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/GOT/
// Memory Limit: 1536 MB
// Time Limit: 602 ms
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

int n, q;
int arr[NMAX];
vi adj[NMAX];
int par[NMAX][LOG_MAX];
int depth[NMAX];

struct node;
extern node *null;

struct node{
	
	int sm;
	node *lf, *ri;
	
	node(){
		sm=0;
		lf=ri=this;
	}
	
	node(int sm, node *lf, node *ri): 
		sm(sm), lf(lf), ri(ri){}	
		
	node(int sm): 
		node(sm, null, null) {}
};

node *rts[NMAX];
node *null = new node();

node *insert(node *rt, int l, int r, int p, int val){
	
	if(p < l || r < p){
		return rt;
	}
	
	if(l==r){
		return new node(rt->sm + val);
	}
	
	int mid = l + (r-l)/2;
	node *nlf = insert(rt->lf, l, mid, p, val);
	node *nri = insert(rt->ri, mid+1, r, p, val);
	
	return new node(rt->sm + val, nlf, nri);
}

int find_c(node *rt_u, node *rt_v, node *rt_p, int l, int r, int p){
	
	if(l==r){
		return (rt_u->sm) + (rt_v->sm) - 2*(rt_p->sm);
	}	
	
	int mid = l + (r-l)/2;
	
	if(p <= mid){
		return find_c(rt_u->lf, rt_v->lf, rt_p->lf, l, mid, p);
	}
	else{
		return find_c(rt_u->ri, rt_v->ri, rt_p->ri, mid+1, r, p);
	}
}

void go(int u, int p){
	
	for(auto v : adj[u]) if(v != p){
		
		depth[v] = depth[u]+1;
		
		par[v][0] = u;
		for(int i = 1; i < LOG_MAX; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}
		
		rts[v] = insert(rts[u], 0, n, arr[v], +1);
		
		go(v, u);
	}
}

int lca(int u, int v){
	
	if(depth[u] < depth[v]) swap(u, v);
	
	int dif = depth[u] - depth[v];
	
	for(int i = 0; i < LOG_MAX; i++) if((dif>>i)&1){
		u = par[u][i];
	}
	
	if(u==v) return u;
	
	for(int i = LOG_MAX-1; i >= 0; i--) if(par[u][i] != par[v][i]){
		u = par[u][i];
		v = par[v][i];
	}
	
	return par[u][0];
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    while(cin >> n >> q){
	    
	    for(int i = 0; i < n; i++){
	    	adj[i].clear();
	    }
    	
	    for(int i = 0; i < n; i++){
	    	cin >> arr[i];
	    }
	    
	    for(int i = 0; i < n-1; i++){
	    	int u, v;
	    	cin >> u >> v;
	    	u--, v--;
	    	adj[u].push_back(v);
	    	adj[v].push_back(u);
	    }
	    
	    rts[0] = insert(new node(), 0, n, arr[0], +1);
	    go(0, -1);
	    
	    while(q--){
	    	
	    	int u, v, c;
	    	cin >> u >> v >> c;
	    	u--, v--;
	    	
	    	int p = lca(u, v);
	    	int cnt_c = (arr[p]==c) || find_c(rts[u], rts[v], rts[p], 0, n , c);
	    	
	    	cout << (cnt_c ? "Find" : "NotFind") << endl;
	    }
    }
}
