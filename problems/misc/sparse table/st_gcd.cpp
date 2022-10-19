struct sparse_table{
    
    vector<vi> st;
    vector<int> lg2;
    
    sparse_table(){};
    
    sparse_table(vi vec){
        
        int n = vec.size();
        int k = ceil(log2(double(n)));
        st.resize(n, vi(k+1));
        
        for (int i = 0; i < n; i++){
            st[i][0] = vec[i];
        }

        for (int j = 1; j <= k; j++){
	        for (int i = 0; i + (1 << j) <= n; i++){
	        	st[i][j] = __gcd(st[i][j-1], st[i+(1<<(j-1))][j-1]);
	        }
        }
        
        lg2.resize(n+1);
        
        lg2[1] = 0;
        for(int i = 2; i <= n; i++){
            lg2[i] = lg2[i/2] + 1;
        }
    }
        
    int query_range(int l, int r){
        int j = lg2[r-l+1];
        return __gcd(st[l][j], st[r-(1<<j)+1][j]);
    }
};

