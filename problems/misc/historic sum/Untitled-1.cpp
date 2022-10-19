
// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

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
