// Problem: K. Betrayed
// expected value with equations

int n, k;
vi adj[NMAX];
int p[22];
int mx[NMAX], sz[22];
int vis[NMAX], vid;

pii dfs0(int u, int p){
    
    pii ret = {0, u};
    
    for(auto v : adj[u]) if(v != p){
        pii tmp = dfs0(v, u);
        tmp.first++;
        ret = max(ret, tmp);
    }    
    
    return ret;
}

int dfs1(int u, int p, int d){
    
    int ret = 0;
    
    if(d > k){
        if(vis[u] != vid){
            vis[u] = vid;
            ret++;
        }
    }
    
    for(auto v : adj[u]) if(v != p){
        ret += dfs1(v, u, d+1);
    }    
    
    return ret;
}

int cmp(double x, double y = 0.0){
    
    if(fabs(x-y) < EPS){
        return 0;
    }
    else{
        return (x > y) * 2 -1;
    }
}

bool make_nonZero(vector<valarray<double>> &eq, int i){
    
    int n = eq.size();
    
    for(int j = i+1; j < n; j++){
        if(cmp(eq[j][i]) != 0){
            swap(eq[i], eq[j]);
            return true;
        }
    }
    
    return false;
}

bool solve(vector<valarray<double>> &eq){
    
    int n = eq.size();
    int m = eq.front().size();
    
    for(int i = 0; i < n; i++){
        
        
        if(cmp(eq[i][i]) == 0){
            if(!make_nonZero(eq, i)){
                return false;
            }
        }   
        
        double cur = eq[i][i];
        eq[i] /= cur;
        
        for(int j = 0; j < n; j++){
            
            if(i == j || cmp(eq[j][i]) == 0){
                continue;
            }
            
            cur = eq[j][i];
            eq[j] += -cur * eq[i];
        }
        
    }
    
    return true;
}

int32_t main(){
    
    int t; cin >> t; while(t--){

        cin >> n >> k;
        
        for(int i = 0; i < n; i++){
            
            int c;
            cin >> c;
            
            p[i] = 0;
            sz[i] = c;
            
            for(int j = 0; j < c; j++) adj[j].clear();
            
            for(int j = 1; j < c; j++){
                int pi; cin >> pi; pi--;
                adj[j].push_back(pi);
                adj[pi].push_back(j);
            }
            
            int p0 = dfs0(0, -1).second;
            int p1 = dfs0(p0, -1).second;
            
            vid++;
            p[i] = c - dfs1(p0, -1, 0) - dfs1(p1, -1, 0);
        }
        
        vector<valarray<double> > eq(n, valarray<double>(n+1));
        
        double p0 = (double) p[0] / (double) sz[0];
        double q0 = 1.0 - p0;
        
        eq[0][0] = q0-1.0;
        eq[0][1] = p0;
        eq[0][n] = -p0 -4.0*q0;
        
        for(int i = 1; i < n; i++){    
            
            double cp = (double) p[i] / (double) sz[i];
            double cq = 1.0 - cp;
             
            eq[i][0] = cq;
            eq[i][i] = -1.0;
            if(i+1 < n) eq[i][i+1] = cp;
            eq[i][n] = -cp -4.0*cq;
        }
        
        assert(solve(eq));
        
        cout << fixed << setprecision(4) << eq[0][n] << endl;
        
    }	
}
