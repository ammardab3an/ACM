
// K. Maximum Rating
// https://contest.ucup.ac/contest/1449/problem/7787

// By AmmarDab3an 

#include <bits/stdc++.h>

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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

// int fac[NMAX], ifac[NMAX];
// 
// void init(){
// 	
	// fac[0] = 1;
	// for(int i = 1; i < NMAX; i++){
		// fac[i] = mul(fac[i-1], i);
	// }
// 	
	// ifac[NMAX-1] = inv(fac[NMAX-1]);
	// for(int i = NMAX-2; i >= 0; i--){
		// ifac[i] = mul(ifac[i+1], i+1);
	// }
// }
// 
// int choose(int n, int c){
	// assert(n >= c);
	// return mul(fac[n], mul(ifac[c], ifac[n-c]));
// }


struct FenwickTree{
	
	int n;
	int sz;
	int lg_n;
	vector<int> bit;
	
	FenwickTree(){
		assert(false);
	}
	
	FenwickTree(int n) : n(n){
		lg_n = int(ceil(log2(double(n))));
		sz = 1 << lg_n;
		bit.resize(sz, 0);
	}
	
	FenwickTree(const vector<int> &vec) : FenwickTree(vec.size()){
		
		for(int i = 0; i < n; i++){
			bit[i] += vec[i];
		}
		
		for(int i = 0; i < sz; i++){
			int r = i | (i+1);
			if(r < sz) bit[r] += bit[i];
		}
	}
	
	int query(int i){
		int ret = 0;
		while(i >= 0){
			ret += bit[i];
			i = (i&(i+1))-1;
		}
		return ret;
	}
	
	int query(int l, int r){
		int ret = query(r) - query(l-1);
		return ret;
	}
	
	void update(int i, int d){
		while(i < sz){
			bit[i] += d;
			i |= i+1;
		}
	}
	
	int lower_bound(int val){
		int ptr = 0;
		for(int i = lg_n-1; i >= 0; i--){
			if(val-bit[ptr+(1<<i)-1] > 0){	
				val -= bit[ptr+(1<<i)-1];
				ptr += (1<<i);
			}
		}
		return ptr;
	}
};


int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n, m;
	cin >> n >> m;
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	vi tmp = vec;
	
	vpii queries(m);
	for(auto &[a, b] : queries){
		cin >> a >> b;
		a--;
		tmp.push_back(b);
	}
	
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	int sz = tmp.size();
	
	FenwickTree tr(sz);
	FenwickTree frq(sz);
	int tot_sm = 0;
	int tot_pos = 0;
	
	for(int i = 0; i < n; i++){
		int val = lower_bound(tmp.begin(), tmp.end(), vec[i])-tmp.begin();	
		val = sz-val-1;
		tot_sm += vec[i];
		tot_pos += vec[i] > 0;
		tr.update(val, +vec[i]);
		frq.update(val, +1);
	}
	
	for(auto &[p, val] : queries){
		
		int o_val = lower_bound(tmp.begin(), tmp.end(), vec[p])-tmp.begin();
		o_val = sz-o_val-1;
		tot_sm -= vec[p];
		tot_pos -= vec[p] > 0;
		tr.update(o_val, -vec[p]);
		frq.update(o_val, -1);
		
		int n_val = lower_bound(tmp.begin(), tmp.end(), val)-tmp.begin();
		n_val = sz-n_val-1;
		tot_sm += val;
		tot_pos += val > 0;
		tr.update(n_val, +val);		
		frq.update(n_val, +1);
		
		vec[p] = val;
		
		int l = 0; 
		int r = n;
		
		int bs_ans = -1;
		
		while(l <= r){
			
			int mid = (l+r)/2;
			
			int q = frq.lower_bound(mid);
			int cur_sm = tr.query(q);
			
			int dif = frq.query(q)-mid;
			
			if(dif){
				cur_sm -= tmp[sz-q-1] * dif;
			}
			
			if(cur_sm >= tot_sm){
				bs_ans = mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		
		cout << tot_pos-bs_ans+1 << endl;
	}
}
