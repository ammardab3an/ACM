// persistant seg lazy

int n, m, t;
int arr[NMAX];

struct node{
	
	int sum, lazy_add;
	node *lf, *ri;
	
	node(){
		sum=lazy_add = 0;
		lf=ri = this;
	}
	
	node(int sum, int lazy_add, node *lf, node *ri):
		sum(sum), lazy_add(lazy_add), lf(lf), ri(ri) {}
		
	node(node *other) : 
		node(other->sum, other->lazy_add, other->lf, other->ri) {}
		
};

node *rts[NMAX];
node *null = new node();

node *push(node *rt, int l, int r){
	
	if(!(rt->lazy_add)) return rt;
	
	node *nrt = new node(rt);
	
	if(l != r){
		assert(nrt->lf);
		assert(nrt->ri);
		nrt->lf = new node(nrt->lf);
		nrt->ri = new node(nrt->ri);
		nrt->lf->lazy_add += nrt->lazy_add;
		nrt->ri->lazy_add += nrt->lazy_add;
	}
	
	nrt->sum += (r-l+1) * nrt->lazy_add;
	nrt->lazy_add = 0;
	
	return nrt;
}

node *build(int l, int r){
	
	if(l==r){
		return new node(arr[l], 0, null, null);
	}	
	
	int mid = (l+r)/2;
	node *nlf = build(l, mid);
	node *nri = build(mid+1, r);
	
	return new node(nlf->sum + nri->sum, 0, nlf, nri);
}

node *update(node *rt, int l, int r, int q_l, int q_r, int val){
	
	rt = push(rt, l, r);
	
	if(r < q_l || q_r < l){
		return rt;
	}	
	
	if(q_l <= l && r <= q_r){
		rt = new node(rt);
		rt->lazy_add += val;
		rt = push(rt, l, r);
		return rt;
	}
	
	int mid = (l+r)/2;
	node *nlf = update(rt->lf, l, mid, q_l, q_r, val);
	node *nri = update(rt->ri, mid+1, r, q_l, q_r, val);
	
	return new node(nlf->sum + nri->sum, 0, nlf, nri);
}

int query(node *rt, int l, int r, int q_l, int q_r){
	
	rt = push(rt, l, r);
	
	if(r < q_l || q_r < l){
		return 0;
	}	
	
	if(q_l <= l && r <= q_r){
		return rt->sum;
	}
	
	int mid = (l+r)/2;
	int st_path = query(rt->lf, l, mid, q_l, q_r);
	int nd_path = query(rt->ri, mid+1, r, q_l, q_r);
	
	return st_path + nd_path;
}

int32_t main(){
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    rts[0] = build(0, n-1);
    t = 1;
    
    for(int i = 0; i < m; i++){
    	
    	char c;
    	cin >> c;
    	
    	if(c=='C'){
    		int l, r, d;
    		cin >> l >> r >> d;
    		l--, r--;
    		rts[t] = update(rts[t-1], 0, n-1, l, r, d);
    		t++;
    	}
    	else if(c=='Q'){
    		int l, r;
    		cin >> l >> r;
    		l--, r--;
    		int q = query(rts[t-1], 0, n-1, l, r);
    		cout << q << endl;
    	}
    	else if(c=='H'){
    		int l, r, ht;
    		cin >> l >> r >> ht;
    		l--, r--;
    		assert(ht < t);
    		int q = query(rts[ht], 0, n-1, l, r);
    		cout << q << endl;
    	}
    	else if(c=='B'){
    		int nt;
    		cin >> nt;
    		assert(nt < t);
    		t = nt+1;
    	}
    	else if(c=='P'){
    		for(int i = 0; i < n; i++){
    			cout << query(rts[t-1], 0, n-1, i, i) << ' ';
    		}
    		cout << endl;
    	}
    }
}

