// Problem: F. Mountain
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 2 - Step 4
// URL: https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
	
	int val, sm, mx;
	node *lf, *ri;
	
	node(){
		val = sm = mx = 0;
		lf = ri = nullptr;
	}
	
	~node(){
		delete lf;
		delete ri;
	}
	
	node(int l, int r, int val) : val(val){
		sm = val * (r-l+1);
		mx = val >= 0 ? sm : val;
		lf = ri = nullptr;
	}
	
	void merge(){
		
		assert((!lf && !ri) || (lf && ri));
		
		if(lf && ri){
			val = 0;
			sm = lf->sm + ri->sm;
			mx = max(lf->mx, lf->sm + ri->mx);
		}
	}
	
	void update(int l, int r, int q_l, int q_r, int q_x){
		
		if(r < q_l || q_r < l){
			return;
		}
		
		if(q_l <= l && r <= q_r){
			
			delete lf;
			delete ri;
			
			val = q_x;
			sm = val * (r-l+1);
			mx = val >= 0 ? sm : val;
			lf = ri = nullptr;
			
			return;
		}
		
		int mid = (l+r)/2;
		
		if(!lf) lf = new node(l, mid, val);
		if(!ri) ri = new node(mid+1, r, val);
		
		lf->update(l, mid, q_l, q_r, q_x);
		ri->update(mid+1, r, q_l, q_r, q_x);
		
		merge();
	}
	
	int query(int l, int r, int q_x){
		
		assert(q_x >= 0);
		
		if(l==r){
			return l;
		}
		
		int mid = (l+r)/2;
		if(!lf) lf = new node(l, mid, val);
		if(!ri) ri = new node(mid+1, r, val);
		
		if(lf->mx > q_x){
			return lf-> query(l, mid, q_x);
		}
		else{
			return ri->query(mid+1, r, q_x - (lf->sm));
		}
	}
};

int32_t main(){
    
    fastIO;
    
	int n;
	cin >> n;
	
	node tree;
	
	char c;
	while(cin >> c){
		
		if(c=='Q'){
			int x;
			cin >> x;
			int ans = tree.query(0, n, x);
			cout << ans << endl;
		}
		else if(c=='I'){
			int l, r, x;
			cin >> l >> r >> x;
			l--, r--;
			tree.update(0, n, l, r, x);
		}
		else{
			break;
		}
	}
}