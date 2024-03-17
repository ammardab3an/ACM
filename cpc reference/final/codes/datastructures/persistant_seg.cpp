// persistant seg

const int AMAX = 1e9 + 10;

struct node;
extern node *empty;

struct node{
	
	int add, mul;
	node *lf, *ri;
	
	node(){
		add=mul = 0;
		lf=ri = this;
	}
	
	node(int _add, int _mul, node *_lf, node *_ri):
		add(_add), mul(_mul), lf(_lf), ri(_ri) {}
		
	int calc(int i){
		return i*mul + add;
	}
};

node *empty = new node();

node *update(node *rt, int l, int r, int q_l, int q_r, int a, int m){
	
	if(r < q_l || q_r < l){
		return rt;
	}	
	
	if(q_l <= l && r <= q_r){
		return new node(rt->add+a, rt->mul+m, rt->lf, rt->ri);	
	}
	
	int mid = (l+r)/2;
	node *nlf = update(rt->lf, l, mid, q_l, q_r, a, m);
	node *nri = update(rt->ri, mid+1, r, q_l, q_r, a, m);
	
	return new node(rt->add, rt->mul, nlf, nri);
}

int query(node *rt0, node *rt1, int l, int r, int p){
	
	if(p < l || r < p){
		return 0;
	}	
	
	int cur = rt0->calc(p) - rt1->calc(p);
	
	if(l==r){
		return cur;
	}
	
	int mid = (l+r)/2;
	int st_path = query(rt0->lf, rt1->lf, l, mid, p);
	int nd_path = query(rt0->ri, rt1->ri, mid+1, r, p);
	
	return cur + st_path + nd_path;
}

int n;
node *rts[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    
    node *rt = new node();
    
    for(int i = 0; i < n; i++){
    	
    	int x1, x2, y1, a, b, y2;
    	cin >> x1 >> x2 >> y1 >> a >> b >> y2;
    	
    	rt = update(rt, 0, AMAX-1, 0, x1, y1, 0);
    	rt = update(rt, 0, AMAX-1, x1+1, x2, b, a);
    	rt = update(rt, 0, AMAX-1, x2+1, AMAX-1, y2, 0);
    	
    	rts[i] = rt;
    }
    
    int last = 0;
    
    int m; cin >> m; while(m--){
    	int l, r, x;
    	cin >> l >> r >> x;
    	r--, l--;
    	int p = (last + x) % (int)(1e9);
    	last = query(rts[r], l ? rts[l-1] : empty, 0, AMAX-1, p);
    	cout << last << endl;
    }
}
