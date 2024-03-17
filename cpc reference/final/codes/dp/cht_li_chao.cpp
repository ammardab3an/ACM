// li-chao 

const int C = (int)5e4 + 5;

namespace segtree {
  struct Line {
    ld m, b;
    ld operator()(ld x) { return m * x + b; }
  } a[C * 4];
  
  void insert(int l, int r, Line seg, int o=0) {
    if(l + 1 == r) {
      if(seg(l) > a[o](l)) a[o] = seg;
      return;
    }
    int mid= (l + r) >> 1, lson = o * 2 + 1, rson = o * 2 + 2;
    if(a[o].m > seg.m) swap(a[o], seg);
    if(a[o](mid) < seg(mid)) {
      swap(a[o], seg);
      insert(l, mid, seg, lson);
    }
    else insert(mid, r, seg, rson);
  }
  ld query(int l, int r, int x, int o=0) {
    if(l + 1 == r) return a[o](x);
    int mid = (l + r) >> 1, lson = o * 2 + 1, rson = o * 2 + 2;
    if(x < mid) return max(a[o](x), query(l, mid, x, lson));
    else return max(a[o](x), query(mid, r, x, rson));
  }
}

// li-chao pointers min

struct Line{
	int m, b;
	int operator()(int x) { 
		if(m==INFLL) return INFLL;
		return m * x + b; 
	}
};

struct node{
	
	Line ln;
	node *left;
	node *right; 
	
	node(){
		ln.m = ln.b = INFLL;
		left=right=nullptr;
	}
	
	~node(){
		delete left;
		delete right;
	}
};

void insert(node*&nd, int l, int r, Line seg){
	
	if(!nd){
		nd = new node();
	}
	
	if(l==r){
		if(seg(l) < nd->ln(l)){
			nd->ln = seg;
		}
		return;
	}		
	
	int mid = (l+r)/2;
	
	if(nd->ln.m < seg.m){
		swap(nd->ln, seg);
	}
	
	if(nd->ln(mid) > seg(mid)){
		swap(nd->ln, seg);
		insert(nd->left, l, mid, seg);
	}
	else{
		insert(nd->right, mid+1, r, seg);
	}
}

int query(node* nd, int l, int r, int x){
	
	if(!nd){
		return INFLL;
	}
	
	if(l==r){
		return nd->ln(x);
	}	
	
	int mid = (l+r)/2;
	if(x < mid){
		return min(nd->ln(x), query(nd->left, l, mid, x));
	}
	else{
		return min(nd->ln(x), query(nd->right, mid+1, r, x));
	}
}

struct seg_node{
	node *root;
	seg_node(){
		root = new node();
	}
	~seg_node(){
		delete root;
	}
};

// li-chao pointers max

struct Line{
	int m, b;
	int operator()(int x) { return m * x + b; }
};

struct node{
	
	Line ln;
	node *left;
	node *right; 
	
	node(){
		ln.m = ln.b = 0;
		left=right=nullptr;
	}
	
	~node(){
		delete left;
		delete right;
	}
};

void insert(node*&nd, int l, int r, Line seg){
	
	if(!nd){
		nd = new node();
	}
	
	if(l==r){
		if(seg(l) > nd->ln(l)){
			nd->ln = seg;
		}
		return;
	}		
	
	int mid = (l+r)/2;
	
	if(nd->ln.m > seg.m){
		swap(nd->ln, seg);
	}
	
	if(nd->ln(mid) < seg(mid)){
		swap(nd->ln, seg);
		insert(nd->left, l, mid, seg);
	}
	else{
		insert(nd->right, mid+1, r, seg);
	}
}

int query(node* nd, int l, int r, int x){
	
	if(!nd){
		return -INF;
	}
	
	if(l==r){
		return nd->ln(x);
	}	
	
	int mid = (l+r)/2;
	if(x < mid){
		return max(nd->ln(x), query(nd->left, l, mid, x));
	}
	else{
		return max(nd->ln(x), query(nd->right, mid+1, r, x));
	}
}

