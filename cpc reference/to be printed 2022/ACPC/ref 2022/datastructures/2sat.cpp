// 2 sat

struct _2SAT {
	
	int n;
	vector<vector<int>> adj, adj_t;
	vector<bool> used;
	vector<int> order, comp;
	vector<bool> assignment;
	
	_2SAT(int _n){
		n = _n*2;
		adj.resize(n);
		adj_t.resize(n);
	}
	
	void dfs1(int v) {
	    used[v] = true;
	    for (int u : adj[v]) {
	        if (!used[u])
	            dfs1(u);
	    }
	    order.push_back(v);
	}
	
	void dfs2(int v, int cl) {
	    comp[v] = cl;
	    for (int u : adj_t[v]) {
	        if (comp[u] == -1)
	            dfs2(u, cl);
	    }
	}
	
	bool solve_2SAT() {
	    order.clear();
	    used.assign(n, false);
	    for (int i = 0; i < n; ++i) {
	        if (!used[i])
	            dfs1(i);
	    }
	
	    comp.assign(n, -1);
	    for (int i = 0, j = 0; i < n; ++i) {
	        int v = order[n - i - 1];
	        if (comp[v] == -1)
	            dfs2(v, j++);
	    }
	
	    assignment.assign(n / 2, false);
	    for (int i = 0; i < n; i += 2) {
	        if (comp[i] == comp[i + 1])
	            return false;
	        assignment[i / 2] = comp[i] > comp[i + 1];
	    }
	    return true;
	}
	
	void add_disjunction(int a, bool na, int b, bool nb) {
	    // na and nb signify whether a and b are to be negated 
	    a = 2*a ^ na;
	    b = 2*b ^ nb;
	    int neg_a = a ^ 1;
	    int neg_b = b ^ 1;
	    adj[neg_a].push_back(b);
	    adj[neg_b].push_back(a);
	    adj_t[b].push_back(neg_a);
	    adj_t[a].push_back(neg_b);
	}
};

int32_t main(){
    
    int n, m;
    cin >> n >> m;
    
    _2SAT st(m);
    
    for(int i = 0; i < n; i++){
    	
    	int a, b;
    	cin >> a >> b;
    	
    	bool na = a < 0;
    	bool nb = b < 0;
    	
    	a = abs(a);
    	b = abs(b);
    	a--, b--;
    	
    	st.add_disjunction(a, na, b, nb);
    }
    
    if(!st.solve_2SAT()){
    	cout << -1 << endl;
    }
    else{
    	for(auto i : st.assignment){
    		cout << i << ' ';
    	}
    	cout << endl;
    }
}
