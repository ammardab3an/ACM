// centroid 1 
// Problem: E. Xenia and Tree

int n, m, LOG;
set<int> adj[NMAX];
int depth[NMAX], sz[NMAX], par[NMAX][LOG_MAX], cpar[NMAX];
int ans[NMAX];

// init ----------------------------------  

void dfs0(int u, int p){
    
    for(auto nxt : adj[u]) if(nxt != p){
        
        depth[nxt] = depth[u]+1;
        
        par[nxt][0] = u;
        for(int i = 1; i < LOG; i++)
            par[nxt][i] = par[par[nxt][i-1]][i-1];
        
        dfs0(nxt, u);
    }    
}

void preprocess(){
    LOG = ceil(log2(double(n)));    
    dfs0(0, -1);
}

int lca(int u, int v){
    
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i = 0; i < LOG; i++) if(diff & (1<<i))
        u = par[u][i];
    if(u == v) return u;
    for(int i = LOG-1; i >= 0; i--) if(par[u][i] != par[v][i])
        u = par[u][i], v = par[v][i];
    return par[u][0];    
}

int dist(int u, int v){
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

// decompose -------------------------------

int nn;
void dfs1(int u, int p){
    
    nn++;
    sz[u] = 1;
    for(auto nxt : adj[u]) if(nxt != p){
        dfs1(nxt, u);
        sz[u] += sz[nxt];
    }
}

int dfs2(int u, int p){
    
    for(auto nxt : adj[u]) if(nxt != p) if(sz[nxt] > nn/2)
        return dfs2(nxt, u);
    
    return u;
}

void decompose(int u, int p){
    
    nn = 0;
    dfs1(u, u);
    
    int centroid = dfs2(u, u);
    if(p == -1) p = centroid;    
    cpar[centroid] = p;
    
    for(auto nxt : adj[centroid]){
        adj[nxt].erase(centroid);
        decompose(nxt, centroid);
    }
    
    adj[u].clear();
}

// queries ---------------------------------

void update(int u){
    
    int x = u;
    
    while(true){
        ans[x] = min(ans[x], dist(x, u));
        if(x == cpar[x]) break;
        x = cpar[x];
    }    
}

int query(int u){
    
    int x = u;
    int ret = INF;
    
    while(true){
        ret = min(ret, dist(u, x) + ans[x]);
        if(x == cpar[x]) break;
        x = cpar[x];
    }
    
    return ret;
}

int32_t main(){
    
    cin >> n >> m;
    for(int i = 0; i < n-1; i++){
        
        int u, v;
        cin >> u >> v;
        u--, v--;
        
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    preprocess();
    decompose(0, -1);
    
    for(int i = 0; i < n; i++) ans[i] = INF;
    
    update(0);
    
    while(m--){
        
        int t, v;
        cin >> t >> v;
        v--;
        
        if(t == 1)
            update(v);
        else
            cout << query(v) << endl;
    }
}
