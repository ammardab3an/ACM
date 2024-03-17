// centroid 3
 
const int NMAX = 1e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));

int n, q, LOG;
set<int> adj[NMAX];
int depth[NMAX], sub[NMAX], par[NMAX][LOG_MAX];
int cpar[NMAX];
multiset<pii> ans[NMAX];
bool white[NMAX];

void dfs0(int u, int p){
    
    for(auto v: adj[u]) if(v != p){
        
        depth[v] = depth[u] + 1;
        
        par[v][0] = u;
        for(int i = 1; i < LOG; i++)
            par[v][i] = par[par[v][i-1]][i-1];
        
        dfs0(v, u);
    }
}

int lca(int u, int v){
    
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i = 0; i < LOG; i++) if(diff & (1<<i)) u = par[u][i];
    if(u == v) return u;
    for(int i = LOG-1; i >= 0; i--) if(par[u][i] != par[v][i])
        u = par[u][i], v = par[v][i];
    return par[u][0];    
}

int dist(int u, int v){
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int nn;
void dfs1(int u, int p){
    
    nn++;
    sub[u] = 1;
    
    for(auto v : adj[u]) if(v != p){
        dfs1(v, u);
        sub[u] += sub[v];
    }    
}

int dfs2(int u, int p){
    
    for(auto v : adj[u]) if(v != p) if(sub[v] > nn/2){
        return dfs2(v, u);
    }    
    
    return u;
}

void decompose(int u, int p){
    
    nn = 0;
    dfs1(u, u);
    int centroid = dfs2(u, u);
    if(p == -1) p = centroid;
    cpar[centroid] = p;
    
    for(auto v : adj[centroid]){
        adj[v].erase(centroid);
        decompose(v, centroid);
    }    
    
    adj[centroid].clear();
}

int solve(int u){
    
    auto &mst = ans[u];
    
    while(!mst.empty()){
        
        pii tp = *mst.begin();
        
        if(white[tp.second] == 0){
            mst.erase(mst.begin());
        }
        else{
            return tp.first;
        }
    }    
    
    return INF;
}

int32_t main(){
    
    cin >> n;
    for(int i = 0; i < n-1; i++){
        
        int u, v;
        cin >> u >> v;
        u--, v--;
        
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    LOG = ceil(log2(double(n)));
    dfs0(0, -1);
    
    decompose(0, -1);
    
    cin >> q; while(q--){
        
        int x, u;
        cin >> x >> u;
        u--;
        
        if(x == 0){
            
            white[u] = !white[u];
            
            int p = u;
            while(true){
                
                ans[p].insert({dist(u, p), u});
                
                if(cpar[p] == p) break;
                p = cpar[p];
            }
        }
        else{
            
            int ans = INF;
            
            int p = u;
            while(true){
                
                ans = min(ans, dist(u, p) + solve(p));
                
                if(cpar[p] == p) break;
                p = cpar[p];
            }
            
            cout << (ans < INF ? ans : -1) << endl;
        }
    }
}
