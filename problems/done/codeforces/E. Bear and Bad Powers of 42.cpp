// Problem: E. Bear and Bad Powers of 42
// Contest: Codeforces - Codeforces Round #356 (Div. 1)
// URL: https://codeforces.com/contest/679/problem/E
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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

int n;
int arr[NMAX];
vi po = {1LL, 42LL, 1764LL, 74088LL, 3111696LL, 130691232LL, 5489031744LL, 230539333248LL, 9682651996416LL, 406671383849472LL, 17080198121677824LL, 717368321110468608LL, INFLL};

pii calc(int x){
	int p = lower_bound(po.begin(), po.end(), x) - po.begin();
	return {po[p] - x, p};
}

const pii calc_inf = calc(INFLL/2);

struct node{
	
	pii mn;
	int mx_p;
	int lazy;
	node *lf, *ri;
	
	node(){
		mn = calc_inf;
		mx_p = -1;
		lf = ri = nullptr;
		lazy = 0;
	}
	
	~node(){
		delete lf;
		delete ri;
	}
	
	void push(){
		if(!lazy) return;	
		int x = po[mn.second]-mn.first + lazy;
		while(po[mn.second] < x) mn.second++;
		mn.first = po[mn.second]-x;
		if(lf) lf->lazy += lazy;
		if(ri) ri->lazy += lazy;
		lazy = 0;
	}
	
	void merge(){
		mx_p = -1;	
		mn = calc_inf;
		assert(lf || ri);
		if(lf) lf->push();
		if(ri) ri->push();
		if(lf) mn = min(mn, lf->mn), mx_p = max(mx_p, lf->mx_p);
		if(ri) mn = min(mn, ri->mn), mx_p = max(mx_p, ri->mx_p);
	}
	
	void build(int l, int r){
		
		if(l==r){
			mn = calc(arr[l]);
			mx_p = l;
			return;
		}
		
		lf = new node();
		ri = new node();
		
		int mid = (l+r)/2;
		lf->build(l, mid);
		ri->build(mid+1, r);
		
		merge();
	}
	
	void update_set(int l, int r, int p, int x){
		
		push();
		
		if(l==r){
			mn = calc(x);
			mx_p = p;
			return;
		}
		
		int mid = (l+r)/2;
		if(p <= mid){
			if(!lf) lf = new node();
			lf->update_set(l, mid, p, x);
		}
		else{
			if(!ri) ri = new node();
			ri->update_set(mid+1, r, p, x);
		}
		
		merge();
	}
	
	void update_inc(int l, int r, int q_l, int q_r, int d){
		
		push();
		
		if(r < q_l || q_r < l){
			return;
		}
		
		if((l==r) || ((q_l <= l && r <= q_r) && mn.first >= d)){
			lazy += d;
			push();
			return;
		}
		
		int mid = (l+r)/2;
		if(lf) lf->update_inc(l, mid, q_l, q_r, d);
		if(ri) ri->update_inc(mid+1, r, q_l, q_r, d);
		
		merge();
	}
	
	node* update_del(int l, int r, int q_l, int q_r){
		
		push();
		
		if(r < q_l || q_r < l){
			return this;
		}
		
		if(q_l <= l && r <= q_r){
			delete this;
			return nullptr;
		}
		
		int mid = (l+r)/2;
		if(lf) lf = lf->update_del(l, mid, q_l, q_r);
		if(ri) ri = ri->update_del(mid+1, r, q_l, q_r);
		
		if(!lf && !ri){
			delete this;
			return nullptr;
		}
		
		merge();
		
		return this;
	}
	
	pii query(int l, int r, int p){
		
		push();
		
		if(l==r){
			return mn;
		}
		
		int mid = (l+r)/2;
		if(lf && lf->mx_p >= p){
			return lf->query(l, mid, p);
		}
		else{
			assert(ri && ri->mx_p >= p);
			return ri->query(mid+1, r, p);
		}
	}
};

int32_t main(){
    
    fastIO;
	
	int m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	node tree;
	tree.build(0, n-1);
	
	while(m--){
		
		int k;
		cin >> k;
		
		if(k==1){
			int i;
			cin >> i;
			i--;
			pii cans = tree.query(0, n-1, i);
			cout << po[cans.second]-cans.first << endl;
		}
		else{
			
			int a, b, x;
			cin >> a >> b >> x;
			a--, b--;
			
			if(a){
				pii tmp = tree.query(0, n-1, a-1);
				tree.update_set(0, n-1, a-1, po[tmp.second]-tmp.first);
			}
			{
				pii tmp = tree.query(0, n-1, b);
				tree.update_set(0, n-1, b, po[tmp.second]-tmp.first);
			}
			
			if(k==2){	
				if(a < b) tree.update_del(0, n-1, a, b-1);
				tree.update_set(0, n-1, b, x);
			}
			else{
				do{
					tree.update_inc(0, n-1, a, b, x);
				}while(tree.mn.first==0);
			}
		}
	}
}
