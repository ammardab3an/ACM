
// historic sum 

int32_t main(){
    
    fastIO;
    
    /*
    	
    	a = arr of n integers
    	bi = sum of a0 -> ai
    	ci = sum of b0 -> bi
    	
    	c0: a0
    	c1: a0 + a1
    	c2: a0 + a1 + a2
    	c3: a0 + a1 + a2 + a3
    	...
    	
    	ci = i*(a0) + (i-1)*(a1) + (i-2)*a2 + ...
    	
    	to handel updates on ai
    	updates of form: ai += delta
    	
		lets maintain:
		di = sum of delta_i
		xi = n*d0 + (n-1)*d1 + ... (n-i)*di;
		si = d0 + d1 + ... di
		
    	so when he query for some ci
    	ans_ci = inicial_ci + xi-si*(n-i-1) // -1 is for 0-indexing purposes
    */
    
    int n;
    cin >> n;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    vi c(n);
    
    {
    	int sm = 0;
    	for(int i = 0; i < n; i++){
    		sm += vec[i];
    		c[i] = sm;
    		if(i) c[i] += c[i-1];
    	}
    }
    
    FenwickTree sm_x(n), sm_d(n);
    
    int q; cin >> q; while(q--){
    	
    	int k;
    	cin >> k;
    	
    	if(k==0){
    		
    		int p, delta;
    		cin >> p >> delta;
    		
    		sm_d.add(p, delta);
    		sm_x.add(p, delta*(n-p));
    	}
    	else{
    		
    		int p;
    		cin >> p;
    		
    		int ans = c[p] + sm_x.sum(p) - (n-p-1) * sm_d.sum(p);
    		cout << ans << endl;
    	}
    }
}
