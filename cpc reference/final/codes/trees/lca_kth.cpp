
// lca - kth

int n;
vpii adj[NMAX];
int par[NMAX][LOG];
int len[NMAX][LOG];
int depth[NMAX];

void dfs(int nd, int pa){
    
    for(auto p : adj[nd]){
        
        int nxt_n = p.second;
        int nxt_d = p.first;
        
        if(nxt_n != pa){
            
            depth[nxt_n] = depth[nd] + 1;
            
            par[nxt_n][0] = nd;
            len[nxt_n][0] = nxt_d;
            
            for(int i = 1; i < LOG; i++){
                par[nxt_n][i] = par[par[nxt_n][i-1]][i-1];
                len[nxt_n][i] = len[nxt_n][i-1] + len[par[nxt_n][i-1]][i-1];
            }
            
            dfs(nxt_n, nd);
        }
    }
}

int lca_dist(int u, int v){
    
    int dep_u = depth[u];
    int dep_v = depth[v];
    
    if(dep_u < dep_v){
        swap(u, v), swap(dep_u, dep_v);
    }
    
    int d = dep_u - dep_v;
    int len_u = 0, len_v = 0;
    
    for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
        len_u += len[u][i];
        u = par[u][i];
    }    
    
    if(u == v) return len_u;
    
    for(int i = LOG-1; i >= 0; i--){
        if(par[u][i] != par[v][i]){
            len_u += len[u][i];
            len_v += len[v][i];
            u = par[u][i];
            v = par[v][i];
        }
    }
    
    len_u += len[u][0];
    len_v += len[v][0];
    
    return len_u + len_v;
}





int lca_kth(int u, int v, int k){
    
    int dep_u = depth[u];
    int dep_v = depth[v];
    
    int tmp_u = u;
    int tmp_v = v;
    bool b = false;
    
    if(dep_u < dep_v){
        swap(u, v), swap(dep_u, dep_v);
        b = true;
    }
    
    int dis = lca_dist(u, v);
    
    int d = dep_u - dep_v;
    int len_u = 0, len_v = 0;
    
    for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
        len_u += 1 << i;
        u = par[u][i];
    }    
    
    if(u == v){
        
        if(b){
            swap(u, v), swap(depth[u], depth[v]), swap(len_u, len_v);
        }
        
        u = tmp_u;
        v = tmp_v;
        k--;
		
        int d = k;
        
		if(b){
            d = len_v - k;
            swap(u, v);
        }
        for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
            u = par[u][i];
        }    
        return u;
    }
    
    for(int i = LOG-1; i >= 0; i--){
        if(par[u][i] != par[v][i]){
            len_u += 1 << i;
            len_v += 1 << i;
            u = par[u][i];
            v = par[v][i];
        }
    }
    len_u++;
    len_v++;
    if(b){
        swap(u, v), swap(depth[u], depth[v]), swap(len_u, len_v);
    }
    
    u = tmp_u;
    v = tmp_v;
    k--;
    
    if(len_u >= k){
        int d = k;
        for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
            u = par[u][i];
        }   
        return u;
    }
    else{
        int d = len_v - (k-len_u);
        for(int i = LOG-1; i >= 0; i--) if(d & (1 << i)){
            v = par[v][i];
        }
        return v;
    }
}
cout << lca_dist(u, v) << endl;
cout << lca_kth(u, v, k)+1 << endl;
