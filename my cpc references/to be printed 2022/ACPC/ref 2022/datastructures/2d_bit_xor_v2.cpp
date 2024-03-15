struct bit_2d
{ 

    int n;
    int tree[2][2][NMAX][NMAX];
    
    bit_2d(){}
    bit_2d(int h, int w){
        n = max(h, w);
    }    
    
    void add(int X , int Y , int V){
        for(int x = X ; x <= n ; x+=x&(-x))
            for(int y = Y ; y<=n ; y+=y&(-y))
                tree[X&1][Y&1][x][y] ^= V;
    }
    
    int get(int X , int Y){
        int ret = 0;
        for(int x = X ; x > 0 ; x-=x&(-x))
            for(int y = Y ; y > 0 ; y-=y&(-y))
                ret ^= tree[X%2][Y%2][x][y];
        return ret;
    }
    
    void update_submatrix(int x1, int y1, int x2, int y2, int val){
        add(x1 , y1 , val);
        add(x2+1 , y1 , val);
        add(x1 , y2+1 , val);
        add(x2+1 , y2+1 , val);
    }
    
    int query_submatrix(int x1, int y1, int x2, int y2){
        return get(x2, y2) ^ get(x1-1, y2) ^ get(x2, y1-1) ^ get(x1-1, y1-1);
    }
    
};

