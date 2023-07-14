// Problem: H. Codeforces Scoreboard
// Contest: Codeforces - TypeDB Forces 2023 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/problemset/problem/1787/H
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int fac[NMAX], ifac[NMAX];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

struct node{
	
	int size, dp, lazy;
	node *lf, *ri;
	
	~node(){
		delete lf;
		delete ri;
	}
	
	bool is_leaf(){
		assert((lf==0) == (size==1));
		return size==1;
	}
	
	void push(){
		if(!lazy) return;
		dp += lazy;
		if(lf) lf->lazy += lazy;
		if(ri) ri->lazy += lazy;
		lazy = 0;	
	}
	
	void merge(){
		assert(!is_leaf());
		assert(lazy==0);
		size = lf->size + ri->size;
		dp = ri->dp;
	}
	
	bool is_balanced()  {
		assert(!is_leaf());
		int l = lf->size;
		int r = ri->size;
		return (l <= 2*r+5) && (r <= 2*l+5);
	}
	
	void balance(){
		
		assert(!is_leaf());
		if(is_balanced()) return;
		
		vi elements;
		dfs(elements);
		build(elements);
	}
	
	void build(vi elements){
		
		lazy = 0;
		size = elements.size();
		dp = elements.back();
		
		delete lf;
		delete ri;
		
		assert(!elements.empty());
		
		if(elements.size()==1){
			lf = ri = nullptr;
			return;
		}	
		
		lf = new node();
		ri = new node();
		auto mid = elements.begin() + elements.size()/2;
		lf->build(vi(elements.begin(), mid));
		ri->build(vi(mid, elements.end()));
	}
	
	bool wants(int i, int k, int b){
		push();
		int tt = b-(i+size-1)*k;
		return tt > dp;	
	}
	
	void update(int i, int k, int b){
		
		push();
		
		if(is_leaf()){
			build({b-i*k, dp-k});
			return;
		}
		
		if(lf->wants(i, k, b)){
			lf->update(i, k, b);
			ri->lazy -= k;
			ri->push();
		}
		else{
			ri->update(i+lf->size, k, b);
		}
		
		merge();
		balance();
	}
	
	void dfs(vi &elements){
		
		push();
		
		if(is_leaf()){
			elements.push_back(dp);
		}
		else{
			lf->dfs(elements);
			ri->dfs(elements);
		}
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
	
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		int sm_a = 0;
		vector<pii> vec(n);
		
		for(auto &[k, b] : vec){
			cin >> k >> b;
			int ai;
			cin >> ai;
			sm_a += ai;
			b -= ai;
		}
		
		sort(vec.rbegin(), vec.rend());
		
		node rt = (node){1, -INFLL, 0, nullptr, nullptr};
		
		for(auto [k, b] : vec){
			rt.update(1, k, b);
		}
		
		vi elements;
		rt.dfs(elements);
		
		int ans = sm_a;
		for(auto e : elements){
			if(e >= 0){
				ans += e;			
			}
		}
		
		cout << ans << endl;
    }	
}
