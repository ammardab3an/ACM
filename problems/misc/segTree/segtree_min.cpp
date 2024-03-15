
struct segTree{
	
	vi tree;
	
	segTree(){
		tree = vi(NMAX<<2, INFLL);
	}
	 
	void update(int nd, int l, int r, int p, int v){
		
		if(p < l || r < p){
			return;
		}
		
		if(l==r){
			tree[nd] = min(tree[nd], v);
			return;
		}
		
		int mid = (l+r)/2;
		update(nd*2, l, mid, p, v);
		update(nd*2+1, mid+1, r, p, v);
		
		tree[nd] = min(tree[nd*2], tree[nd*2+1]);
	}
	
	int query(int nd, int l, int r, int q_l, int q_r){
		
		if(r < q_l || q_r < l){
			return INFLL;
		}
		
		if(q_l <= l && r <= q_r){
			return tree[nd];
		}
		
		int mid = (l+r)/2;
		int st_path = query(nd*2, l, mid, q_l, q_r);
		int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
		
		return min(st_path, nd_path);
	}
};
