// parallel bs dfs

int n, m, q;
vi adj[NMAX];
int par[NMAX];
int sz[NMAX];
int queries[NMAX][3];
int edges[NMAX][2];
int ans[NMAX];

struct dsu_struct{
	
	vi par, sz;
	
	dsu_struct(){}
	dsu_struct(int n){
		par = sz = vi(n);
		for(int i = 0; i < n; i++){
			par[i] = i;
			sz[i] = 1;
		}
	}
	
	int get_par(int u){
		return par[u] = (par[u]==u) ? u : get_par(par[u]);
	}
	
	void merge(int u, int v){
		
		u = get_par(u);
		v = get_par(v);
		
		if(u==v) return;
		
		if(sz[u] > sz[v]) swap(u, v);
		
		par[u] = v;
		sz[v] += sz[u];
	}
	
	int query(int u, int v){
		u = get_par(u);
		v = get_par(v);
		return sz[u] + (u!=v)*sz[v];
	}
	
} dsu[22];

void go(int depth, int l, int r, vi &v){
	
	if(l==r){
		dsu[depth].merge(edges[l][0], edges[l][1]);
		for(auto i : v) ans[i] = l+1;
		return;
	}	
	
	int mid = (l+r)/2;
	for(int i = l; i <= mid; i++){
		dsu[depth].merge(edges[i][0], edges[i][1]);
	}
	
	vi lf, ri;
	for(auto i : v){
		
		int u = queries[i][0];
		int v = queries[i][1];
		int x = queries[i][2];
		
		int tot = dsu[depth].query(u, v);
		
		if(x <= tot){
			lf.push_back(i);
		}
		else{
			ri.push_back(i);
		}
	}
	
	for(int i = mid+1; i <= r; i++){
		dsu[depth].merge(edges[i][0], edges[i][1]);
	}
	
	go(depth+1, l, mid, lf);
	go(depth+1, mid+1, r, ri);
}

int32_t main(){
    
    // fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    
    for(int i = 0; i < 22; i++){
    	dsu[i] = dsu_struct(n);
    }
    
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	edges[i][0] = u;
    	edges[i][1] = v;
    }
    
    cin >> q;
    
    for(int i = 0; i < q; i++){
    	int u, v, x;
    	cin >> u >> v >> x;
    	u--, v--;
    	queries[i][0] = u;
    	queries[i][1] = v;
    	queries[i][2] = x;
    }
    
    vi tmp(q);
    iota(tmp.begin(), tmp.end(), 0);
    
    go(0, 0, m-1, tmp);
    
    for(int i = 0; i < q; i++){
    	cout << ans[i] << endl;
    }
}
