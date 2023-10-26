// L. Partially Free Meal
// https://qoj.ac/contest/1358/problem/7523


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

struct node{
	
	int cnt;	
	int sm_val;
	node *lf, *ri;
	
	node(){
		cnt = 0;
		sm_val = 0;
		lf = ri = nullptr;
	}
	
	node(int cnt, int val) : cnt(cnt), sm_val(val) {
		lf = ri = nullptr;
	}
	
	node(node *lf, node *ri) : lf(lf), ri(ri) {
		cnt = 0;
		sm_val = 0;
		if(lf) cnt += lf->cnt, sm_val += lf->sm_val;
		if(ri) cnt += ri->cnt, sm_val += ri->sm_val;
	}
	
	node *update(int l, int r, int p){
		
		if(p < l || r < p){
			return this;
		}
		
		if(l==r){
			return new node(cnt+1, sm_val+p);
		}
		
		int mid = (l+r)/2;
		node *nlf = lf;
		node *nri = ri;
		
		if(p <= mid){
			if(!lf) lf = new node();
			nlf = lf->update(l, mid, p);
		}
		else{
			if(!ri) ri = new node();
			nri = ri->update(mid+1, r, p);
		}
		
		return new node(nlf, nri);
	}
	
	node *update(int p){
		return update(0, 1e9, p);
	}
	
	int query(int l, int r, int k){
		
		if(!k){
			return 0;
		}
		
		if(k > cnt){
			return INFLL;
		}
		
		if(l==r){
			assert(cnt >= k);
			return k * l;
		}
		
		int mid = (l+r)/2;
		
		if(lf && lf->cnt > k){
			return lf->query(l, mid, k);
		}
		else{
			int ret = 0; 
			if(lf) ret += lf->sm_val;
			if(ri) ret += ri->query(mid+1, r, k - (!lf ? 0 : lf->cnt));
			return ret;
		}
	}
	
	int query(int k){
		return query(0, 1e9, k);
	}
	
	void dfs(int l=0, int r=1e9){
		
		if(l==r){
			cout << l << ' ' << this->cnt << ' ' << this->sm_val << endl;
			return;
		}
		
		int mid = (l+r)/2;
		if(lf) lf->dfs(l, mid);
		if(ri) ri->dfs(mid+1, r);
	}
};

vpii vec;
vi ans;
node* tree[NMAX];

void go(int i, int j, int l, int r){
	
	if(i > j){
		return;
	}	
	
	int mid = (i+j)/2;
	pii bst = {INFLL, -1};
	for(int k = l; k <= r; k++){
		pii cans = {((mid-1==0) ? 0 : (!k ? INFLL : tree[k-1]->query(mid-1))) + (vec[k].first + vec[k].second), k};
		// cout << mid << ' ' << k << ' ' << cans.first << endl;
		bst = min(bst, cans);
	}
	
	assert(bst.second != -1);
	
	ans[mid-1] = bst.first;
	int opt = bst.second;
	
	go(i, mid-1, l, opt);
	go(mid+1, j, opt, r);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n;
	cin >> n;
	
	vec = vpii(n);
	for(auto &[b, a] : vec) cin >> a >> b;
	
	if(n==0){
		n = 1e5;
		vec = vpii(n);
		rng = mt19937(0);
		for(auto &[b, a] : vec){
			a = rand(0, 1e9);
			b = rand(0, 1e9);
			// cout << a << ' ' << b << endl << flush;
		}
	}
	
	sort(vec.begin(), vec.end());
	
	tree[0] = new node();
	tree[0] = tree[0]->update(vec[0].second);
	
	for(int i = 1; i < n; i++){
		tree[i] = tree[i-1]->update(vec[i].second);
	}
	
	// tree[n-1]->dfs();
	// cout << tree[n-1]->query(3) << endl;
	
	ans.resize(n);
	go(1, n, 0, n-1);
	
	for(int i = 0; i < n; i++){
		cout << ans[i] << endl;
	}
}
