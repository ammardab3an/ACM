// x_factor int
// I. Investors
// https://qoj.ac/contest/1103/problem/5507

// By AmmarDab3an 
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int pre[6060][6060];

int32_t main(){
    
    fastIO;
	
    int t; cin >> t; while(t--){

		int n, k;
		cin >> n >> k;
		
		k++;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		if(n==0){
			srand(0);
			n = 6000;
			vec = vi(n);
			iota(vec.begin(), vec.end(), 0);
			random_shuffle(vec.begin(), vec.end());
			k = 5 + 1;
		}		
		
		vi tmp = vec;
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
		
		for(auto &e : vec){
			e = lower_bound(tmp.begin(), tmp.end(), e) - tmp.begin();
		}
		
		for(int i = 0; i < n; i++){
			FenwickTree bit(n);
			int cnt = 0;
			for(int j = i; j >= 0; j--){
				cnt += bit.sum(0, vec[j]-1);
				bit.add(vec[j], 1);
				pre[i][j] = cnt;
			}
		}
		
		auto calc = [&](int x_factor)->pii{
			
			vpii dp(n);
			
			for(int i = 0; i < n; i++){
				
				pii cans = {INFLL, 0};
				
				for(int j = i; j >= 0; j--){
					
					pii nxt = j ? dp[j-1] : (pii){0, 0};
					nxt.first += pre[i][j] + x_factor;
					nxt.second++;
					
					cans = min(cans, nxt);
				}
				
				dp[i] = cans;
			}	
			
			return dp[n-1];
		};
		
		int l = 0;
		int r = INF;
		
		int bs_ans = -1;
		
		while(l <= r){
			
			int mid = (l+r)/2;
			
			pii cans = calc(mid);
			
			if(cans.second <= k){
				bs_ans = mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		
		pii ans = calc(bs_ans);
		cout << ans.first - bs_ans*k << endl;
    }	
}
