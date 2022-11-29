// parallel bs bfs
 
int n, m;
int val[NMAX];
int queries[NMAX][3];
vi tmp[NMAX];
int ans[NMAX];
FenwickTree tree;
 
void init_bit(){
    tree = FenwickTree(n);
}
 
void update_query(int l, int r, int x){
 
    if(l <= r){
        tree.update(l, r, x);
    }
    else{
        tree.update(l, n-1, x);
        tree.update(0, r, x);
    }
}
 
int query_pos(int p){
    return tree.query(p);
}
 
int32_t main(){
 
	cin >> m >> n;
 
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        c--;
        tmp[c].push_back(i);
    }
 
    for(int i = 0; i < m; i++){
        cin >> val[i];
    }
 
    int q;
    cin >> q;
 
    for(int i = 0; i < q; i++){
    	int l, r, x;
    	cin >> l >> r >> x;
    	l--, r--;
    	queries[i][0] = l;
    	queries[i][1] = r;
    	queries[i][2] = x;
    }
 
    queue<pair<pii, vi>> que;
    que.push({{0, q}, vi(m)});
    iota(que.front().second.begin(), que.front().second.end(), 0);
 
    int cur = INF;
 
    while(!que.empty()){
 
    	auto fr = que.front();
    	que.pop();
 
    	int l = fr.first.first;
    	int r = fr.first.second;
    	auto &v = fr.second;
 
    	// cout << l << ' ' << r << ' ' << (l+r)/2 << endl;
    	// for(auto i : v) cout << i << ' '; cout << endl;
 
    	if(l==r){
    		for(auto i : v) ans[i] = l;
    		continue;
    	}
 
    	int mid = (l+r)/2;
 
    	if(cur <= mid){
    		for(int i = cur+1; i <= mid; i++){
    			update_query(queries[i][0], queries[i][1], queries[i][2]);
    		}
    	}
    	else{
            init_bit();
    		for(int i = 0; i <= mid; i++){
    			update_query(queries[i][0], queries[i][1], queries[i][2]);
    		}
    	}
 
    	cur = mid;
 
		vi lf, ri;
    	for(auto i : v){
 
    		int tot = 0;
    		for(auto p : tmp[i]){
    			tot += query_pos(p);
    			if(tot > val[i]) break;
    		}
 
    		if(val[i] <= tot){
    			lf.push_back(i);
    		}
    		else{
    			ri.push_back(i);
    		}
    	}
 
    	if(!lf.empty()) que.push({{l, mid}, lf});
    	if(!ri.empty()) que.push({{mid+1, r}, ri});
    }
 
	for(int i = 0; i < m; i++){
 
		if(ans[i] < q){
			cout << ans[i]+1 << endl;
		}
		else{
			cout << "NIE" << endl;
		}
    }
}