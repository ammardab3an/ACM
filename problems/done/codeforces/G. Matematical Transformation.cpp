// Problem: G. Matematical Transformation
// Contest: Codeforces - 2021 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/103577/problem/G
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
using lll = __int128;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
const int NMAX = 3e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));

int n;
vector<int> adj[NMAX];
int depth[NMAX];
int par[NMAX][LOG_MAX];
int sz[NMAX];
int tin[NMAX], nit[NMAX], tout[NMAX], t;
int nxt[NMAX];

struct node{
	
	lll val;
	lll sm_depth;
	lll lazy_a, lazy_b;
	
} tree[NMAX << 2];

void push(int nd, int l, int r){
	
	if(!tree[nd].lazy_a && !tree[nd].lazy_b){
		return;
	}	
	
	tree[nd].val += tree[nd].lazy_a * (r-l+1);
	tree[nd].val += tree[nd].lazy_b * tree[nd].sm_depth;
	
	if(l != r){
		tree[nd*2].lazy_a += tree[nd].lazy_a;
		tree[nd*2].lazy_b += tree[nd].lazy_b;
		tree[nd*2+1].lazy_a += tree[nd].lazy_a;
		tree[nd*2+1].lazy_b += tree[nd].lazy_b;
	}
	
	tree[nd].lazy_a = tree[nd].lazy_b = 0;
}

node merge(const node &a, const node &b){
	
	assert(!(a.lazy_a+a.lazy_b) && !(b.lazy_a+b.lazy_b));
	
	node ret;
	ret.val = a.val + b.val;
	ret.sm_depth = a.sm_depth + b.sm_depth;
	ret.lazy_a=ret.lazy_b = 0;
	
	return ret;	
}

void build(int nd, int l, int r){
	
	if(l==r){
		tree[nd] = (node){0, depth[nit[l]], 0, 0};
		return;
	}
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_l, int q_r, int a, int b){

	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return;
	}
	
	if(q_l <= l && r <= q_r){
		tree[nd].lazy_a += a;
		tree[nd].lazy_b += b;
		push(nd, l, r);	
		return;	
	}	
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, a, b);
	update(nd*2+1, mid+1, r, q_l, q_r, a, b);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

node query(int nd, int l, int r, int q_l, int q_r){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return (node){0, 0, 0, 0};
	}
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	node st_path = query(nd*2, l, mid, q_l, q_r);
	node nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return merge(st_path, nd_path);
}

void dfs(int u, int p){
	
	sz[u] = 1;
	
	for(auto &v : adj[u]) if(v != p){
		
		depth[v] = depth[u]+1;
		
		par[v][0] = u;
		for(int i = 1; i < LOG_MAX; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}
		
		dfs(v, u);
		sz[u] += sz[v];
		
		if((adj[u][0]==p) || (sz[v] > sz[adj[u][0]])){
			swap(v, adj[u][0]);
		}
	}	
}

void hld(int u, int p){
	
	tin[u] = t;
	nit[t] = u;
	t++;
	
	for(auto v : adj[u]) if(v != p){
		nxt[v] = (v==adj[u][0]) ? nxt[u] : v;
		hld(v, u);
	}	
	
	tout[u] = t;
}

int lca(int u, int v){
	
	if(depth[u] < depth[v]) swap(u, v);
	
	int dif = depth[u]-depth[v];
	
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

void update_sub_tree(int u, int a, int b){
	update(1, 0, n-1, tin[u], tout[u]-1, a-b*depth[u], b);	
}

lll query_path(int u, int v){
	
	lll ans = 0;
	
	while(nxt[u] != nxt[v]){
		
		if(depth[nxt[u]] < depth[nxt[v]]){
			swap(u, v);
		}
		
		ans += query(1, 0, n-1, tin[nxt[u]], tin[u]).val;
		u = par[nxt[u]][0];
	}	
	
	if(depth[u] < depth[v]){
		swap(u, v);
	}
	
	ans += query(1, 0, n-1, tin[v], tin[u]).val;
	
	return ans;
}

string to_string(lll x){
	
	if(!x) return "0";
	
	string s;
	while(x){
		s.push_back('0' + (x%10));
		x /= 10;
	}	
	reverse(s.begin(), s.end());
	return s;
}

int32_t main(){
    
    fastIO;
    
    cin >> n;
    for(int i = 0; i < n-1; i++){
    	
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    dfs(0, -1);
    hld(0, -1);
    build(1, 0, n-1);
    
    int q; cin >> q; while(q--){
    	
    	int k;
    	cin >> k;
    	
    	if(k==1){
    		
    		int u, a, b;
    		cin >> u >> a >> b;
    		u--;
    		
    		update_sub_tree(u, a, b);
    	}
    	else{
    		
    		int u, v;
    		cin >> u >> v;
    		u--, v--;
    		
    		lll ans = query_path(u, v);
    		cout << to_string(ans) << endl;
    	}
    }
}
