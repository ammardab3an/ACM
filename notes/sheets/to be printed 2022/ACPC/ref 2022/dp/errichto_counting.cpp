// errichto counting

bool mem[22][1<<20];
int vis[22][1<<20];
int cnt[22], cnt_vis;
int vid;

bool go(int ln, int msk){
	
	if(ln==1){
		return msk;
	}	
	
	bool &ret = mem[ln][msk];
	if(vis[ln][msk]==vid) return ret;
	vis[ln][msk] = vid;
	
	bool b = ln%2==0;
	bool ans = !b ? 0 : 1;
	
	for(int i = 0; i < ln; i++) if(i != 2){
		
		int x = msk&((1<<i)-1);
		int y = msk&((1<<(i+1))-1);
		int nmsk = (msk>>1)^(y>>1)^x;
		
		// cout << i << ' ' << bitset<3>(msk) << ' ' << bitset<3>(nmsk) << endl;
		
		if(!b){
			ans |= go(ln-1, nmsk);
		}	
		else{
			ans &= go(ln-1, nmsk);
		}
	}
	
	return ret = ans;
}

int count(int n, int c){
	
	/*
		count the number of arrays that have c elements greater or equal
		to some value, and the rest are less than that value,
		and value of that array is greater or equal to that value,
		
		=
		count the number of arrays that have c ones and n-c zeros,
		and the value of that array is 1,
	*/	
	
	if(cnt_vis==vid){
		return cnt[c];
	}
	
	cnt_vis = vid;
	
	for(int i = 0; i <= n; i++){
		cnt[i] = 0;
	}
	
	for(int i = 0; i < (1<<n); i++) if(go(n, i)){
		int c = __builtin_popcount(i);
		cnt[c] = add(cnt[c], 1);
	}
	
	return cnt[c];
}

int solve0(int n, int m){
	
	/*
		for each i = 0...m
		ans += number of arrays that its answer is >= i
	*/
	
	vid++;
	int ans = 0;
	
	/*
		i starts from 1, and do not start from 0,
		so we only sum values of:
		>= 1
		>= 2
		>= 3
		
		and we do not sum 
		>= 0
		
		because it doesn't add any value to the final answer,
		as the arrays that its value is 0, add up to 0.	
	*/
	
	for(int i = 1; i <= m; i++){
		for(int c = 1; c <= n; c++){
			int cans = mul(count(n, c), mul(pow_exp(m-i+1, c), pow_exp(i, n-c)));
			ans = add(ans, cans);		
		}
	}
	
	return ans;
}

int32_t main(){
    
    /*
    	two players are plaing a game, initally they got
    	an array, then each player is going to remove an element
    	in turns, until there is only 1 element left,
    	the first player is trying to maximize that element, 
    	and the second one is trying to minimize that element,
    	the value of the array is equal to the last remaiming element,
    	
    	+ at any point, a player cannot delete the 3rd element,
    	
    	count the sum of values of all arrays of size N with elements less or equal to M,
    	N is odd for convenience,
    	
    	N <= 20
    	M <= 1e5
    */
    
    int t; cin >> t; while(t--){

		int n, m;
		cin >> n >> m;
		
		cout << solve0(n, m) << endl;
    }	
    
}
