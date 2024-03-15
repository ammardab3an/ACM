// div&con rec dsu rollback

const int NMAX = 3e5 + 10;

int par[NMAX];
int sz[NMAX];
stack<int> st;
int ans;

int get_par(int u){
    return par[u]==u ? u : get_par(par[u]);
}

void merge(int u, int v){
    
    if((u=get_par(u)) == (v=get_par(v))){
        return;
    }    
    
    if(sz[u] > sz[v]){
        swap(u, v);
    }
    
    st.push(u);
    
    par[u] = v;
    sz[v] += sz[u];
    ans--;
}

bool rollback(){
    
    if(st.empty()){
        return false;
    }
    
    while(true){
        
        assert(!st.empty());
        
        int u = st.top();
        st.pop();
        
        if(u == -1) break;
        
        sz[par[u]] -= sz[u];
        par[u] = u;
        ans++;
    }    
    
    return true;
}

void persist(){
    st.push(-1);    
}

struct query{
    int ty;
    int u, v;
    int l, r;
};

void go(int l, int r, const vector<query> &vec){
    
    if(l==r){
        persist();
        for(auto q : vec){
            if(q.ty==1 && q.l <= l && r <= q.r){
                merge(q.u, q.v);
            }   
        }
        for(auto q : vec){
            if(q.ty==0 && q.l==l){
                cout << ans << endl;
            }
        }
        rollback();
        return;
    }    
    
    persist();
    vector<query> nvec;
    
    for(auto q : vec){
        
        if(q.ty==0 && (l <= q.l && q.l <= r)){
            nvec.push_back(q);
        }
        else if(q.ty==1){
            if(q.l <= l && r <= q.r){
                merge(q.u, q.v);
            }
            else if(!(q.r < l || r < q.l)){
                nvec.push_back(q);
            }
        }
    }
    
    int mid = (l+r)/2;
    go(l, mid, nvec);
    go(mid+1, r, nvec);
    rollback();
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, q;
    cin >> n >> q;
    
    if(!q) return 0;
    
    for(int i = 0; i < n; i++){
        sz[i] = 1;
        par[i] = i;
    }
    
    ans = n;
    map<pii, int> mp;
    vector<query> vec;
    
    for(int i = 0; i < q; i++){
        
        char c;
        cin >> c;
        
        if(c=='?'){
            query que;
            que.ty = 0;
            que.l = que.r = i;
            vec.push_back(que);
        }
        else if(c=='+'){
            
            query que;
            que.ty = 1;
            cin >> que.u >> que.v;
            if(que.u > que.v) swap(que.u, que.v);
            que.u--, que.v--;
            
            mp[{que.u, que.v}] = vec.size();
            
            que.l = i, que.r = q;
            vec.push_back(que);
        }
        else if(c=='-'){
            
            int u, v;
            cin >> u >> v;
            if(u > v) swap(u, v);
            u--, v--;
            
            vec[mp[{u, v}]].r = i-1;
        }
    }
    
    mp.clear();
    
    go(0, q-1, vec);
}
    