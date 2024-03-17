
// sqrt on bits 

int32_t main(){

    int n, q;
    cin >> n >> q;

    vi A(1<<n);
    for(auto &i : A) cin >> i;

    vi F(1<<n), iF(1<<n);

    auto build = [&](){

    	int N = n;

    	for(int i = 0; i<(1<<N); ++i)
			F[i] = A[i];
		for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
			if(mask & (1<<i))
				F[mask] += F[mask^(1<<i)];
		}

    	for(int i = 0; i<(1<<N); ++i)
			iF[i] = A[(~i) & ((1<<N)-1)];
		for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
			if(mask & (1<<i))
				iF[mask] += iF[mask^(1<<i)];
		}
    };

    build();

   unordered_map<int, int> queries;

    while(q--){

    	int k, a, b;
    	cin >> k >> a >> b;

    	if(k==1){
	   		queries[a] = b;
    	}
    	else{

    		if((b&a) != a){
    			cout << 0 << endl;
    			continue;
    		}

    		int ans = 0;
    		vi *f = &F;
    		int _a = a, _b = b;

    		if(__builtin_popcount(a) > n/2){
    			a = (~a) & ((1<<n)-1);
    			b = (~b) & ((1<<n)-1);
    			swap(a, b);
    			f = &iF;
    		}

    		int cnt = 0;

    		bool bo = __builtin_popcount(a)%2;

    		for(int mask = a; ; mask = (mask-1)&a){

                cnt++;

    			if(__builtin_popcount(mask)%2==bo){
    				ans += (*f)[b^a^mask];
    			}
    			else{
    				ans -= (*f)[b^a^mask];
    			}

    			if(!mask){
    				break;
    			}
    		}

    		for(auto [s, v] : queries){
    			if((_b&s)==s && (s&_a)==_a){
    				ans -= A[s];
    				ans += v;
    			}
    		}

    		cout << ans << endl;
//    		cout << cnt << ' ' << queries.size() << ' ' << cnt+queries.size() << endl;
    	}

    	if(queries.size() >= 2500){
    		for(auto [s, v] : queries){
    			A[s] = v;
    		}
    		build();
    		queries.clear();
    	}
    }
}