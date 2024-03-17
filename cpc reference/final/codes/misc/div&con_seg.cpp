// div&con seg dsu
 
const int NMAX = 3e5 + 10;

vpii tree[NMAX << 2];
int par[NMAX];
int sz[NMAX];
stack<int> st;
int ans;
int _ans[NMAX];


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

void update(int nd, int l, int r, int q_l, int q_r, pii edge){
	
	if(r < q_l || q_r < l){
		return;
	}
	
	if(q_l <= l && r <= q_r){
		tree[nd].push_back(edge);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, edge);
	update(nd*2+1, mid+1, r, q_l, q_r, edge);
}

void go(int nd, int l, int r){
	
	persist();
	
	for(auto [u, v] : tree[nd]){
		merge(u, v);	
	}
	
	if(l == r){
		_ans[l] = ans;
		rollback();
		return;
	}	
	
	int mid = (l+r)/2;
	go(nd*2, l, mid);
	go(nd*2+1, mid+1, r);
	
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
    int sz = 0;
    map<pii, int> mp;
    
    for(int i = 0; i < q; i++){
        
        char c;
        cin >> c;
        
        if(c=='?'){
        	sz++;
        }
        else if(c=='+'){
            
            int u, v;
            cin >> u >> v;
            if(u > v) swap(u, v);
            u--, v--;
            
            mp[{u, v}] = sz;
        }
        else if(c=='-'){
            
            int u, v;
            cin >> u >> v;
            if(u > v) swap(u, v);
            u--, v--;
            
            auto it = mp.find({u, v});
            
            int l = it->second;
            int r = sz-1;
            
            if(l <= r){
            	update(1, 0, NMAX-1, l, r, (pii){u, v});
            }
            
            mp.erase(it);
        }
    }
    
    for(auto p : mp){
    	
    	pii edge = p.first;
    	int l = p.second;
    	int r = sz-1;
    	
    	if(l <= r){		
	    	update(1, 0, NMAX-1, l, r, edge);	
    	}
    }
    
    mp.clear();
    
    go(1, 0, NMAX-1);
    for(int i = 0; i < sz; i++){
    	cout << _ans[i] << endl;
    }
}
    