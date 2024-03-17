
struct bit_1d{
    
    int n;
    vi tree_m, tree_c;
    
    bit_1d(){}
    
    bit_1d(int sz){
        n = sz;
        tree_m = vi(n, 0);
        tree_c = vi(n, 0);
    }
    
    void update(vi &tree, int idx, int delta){
        for (; idx < n; idx = idx | (idx + 1))
            tree[idx] += delta;       
    }
    

    void update_range(int l, int r, int c){
        update(tree_m, l, c);
        update(tree_m, r+1, -c);
        update(tree_c, l, -c*(l-1));
        update(tree_c, r+1, +c*(l-1));
        update(tree_c, r+1, c*(r-l+1));
    }    
    
    int query(vi &tree, int r){   
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += tree[r];
        return ret;
    }
    
    int query_range(int l, int r){
        
        int m = query(tree_m, r);
        int c = query(tree_c, r);
        int x = m*(r) + c;
        
        if(l){
            m = query(tree_m, l-1);
            c = query(tree_c, l-1);
            x -= m*(l-1) + c;
        }
        
        return x;
    }
};
