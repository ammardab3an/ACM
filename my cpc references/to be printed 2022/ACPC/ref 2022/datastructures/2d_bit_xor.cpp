
struct bit_2d
{ 
    
    int n, m;
    vector<vi> b1, b2, b3, b4;
    
    bit_2d(){}
    
    bit_2d(int h, int w){
        n = h, m = w;
        b1 = vector<vi>(h, vi(w));
        b2 = vector<vi>(h, vi(w));
        b3 = vector<vi>(h, vi(w));
        b4 = vector<vi>(h, vi(w));
    }
    
    void update(vector<vi> &tree, int i, int j, int val) 
    {
        if(!val) return;
        
        for(i++ ; i <= n ; i += (i & (-i))) 
        { 
            for(int jj = j + 1 ; jj <= m ; jj += (jj & (-jj))) 
            { 
                tree[i - 1][jj - 1] ^= val; 
            } 
        } 
    }    
    
    void update_range(vector<vi> &tree_m, vector<vi> &tree_c, int x, int l, int r, int c){
        update(tree_m, x, l, c);
        update(tree_m, x, r+1, c);
        update(tree_c, x, l, c*((l-1)%2==0));
        update(tree_c, x, r+1, c*(r%2==0));   
    }
    
    void update_submatrix(int x1, int y1, int x2, int y2, int c){
        update_range(b1, b2, x1, y1, y2, c);
        update_range(b1, b2, x2+1, y1, y2, c);
        update_range(b3, b4, x1, y1, y2, c*((x1-1)%2==0));
        update_range(b3, b4, x2+1, y1, y2, c*(x2%2==0));
    }
    
    int query(vector<vi> &tree, int i, int j) 
    { 
        int ret = 0; 
        for(i++ ; i ; i -= (i & (-i))) 
        { 
            for(int jj = j + 1 ; jj ; jj -= (jj & (-jj))) 
            { 
                ret ^= tree[i - 1][jj - 1]; 
            } 
        } 
        return ret; 
    } 
    
    int query_range(vector<vi> &tree_m, vector<vi> &tree_c, int x, int l, int r){
        
        int m = (r%2==0) ? query(tree_m, x, r) : 0;
        int c = query(tree_c, x, r);
        int ans = m ^ c;
        
        if(l){
            m = ((l-1)%2==0) ? query(tree_m, x, l-1) : 0;
            c = query(tree_c, x, l-1);
            ans ^= m ^ c;
        }
        
        return ans;
    }
    
    int query_submatrix(int x, int y){
        
        int s1 = (x%2==0) ? query_range(b1, b2, x, 0, y) : 0;
        int s2 = query_range(b3, b4, x, 0, y);

        return s1^s2;
    }
    
    int query_submatrix(int x1, int y1, int x2, int y2){
        
        int ans = query_submatrix(x2, y2);
        if(x1) ans ^= query_submatrix(x1-1, y2);
        if(y1) ans ^= query_submatrix(x2, y1-1);
        if(x1&&y1) ans ^= query_submatrix(x1-1, y1-1);
        
        return ans;
    }
};
