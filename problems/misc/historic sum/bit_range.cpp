
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));


struct FenwickTree {
    
    int n;
    vector<int> bit;  // binary indexed tree

	FenwickTree(){
		
	}
	
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

struct DS{

	int n;
	vi c;	
	FenwickTree sm_d, sm_x;
	
	DS(){
		
	}
	
	DS(const vi &vec){
		
		n = vec.size();
		c = vi(n);
		sm_d = sm_x = FenwickTree(n);
		
		vi d = vec;
		for(int i = n-1; i > 0; i--){
			d[i] -= d[i-1];
		}
		
		int sm = 0;
    	for(int i = 0; i < n; i++){
    		sm += d[i];
    		c[i] = sm;
    		if(i) c[i] += c[i-1];
    	}
	}
	
	void add_suf(int p, int delta){
		sm_d.add(p, delta);
		sm_x.add(p, (n-p)*delta);	
	}
	
	int sum_pre(int p){
		int ans = c[p] + sm_x.sum(p) - (n-p-1) * sm_d.sum(p);
		return ans;
	}
	
	void add(int l, int r, int delta){
		add_suf(l, delta);
		if(r+1<n) add_suf(r+1, -delta);	
	}
	
	int sum(int l, int r){
		int ret = sum_pre(r);
		if(l) ret -= sum_pre(l-1);
		return ret;
	}
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    DS ds(vec);
    
    int q; cin >> q; while(q--){
    	
    	int k, l, r;
    	cin >> k >> l >> r;
    	
    	if(k==0){
    		int delta;
    		cin >> delta;
    		ds.add(l, r, delta);
    	}
    	else{
    		cout << ds.sum(l, r) << endl;
    	}
    }
}
