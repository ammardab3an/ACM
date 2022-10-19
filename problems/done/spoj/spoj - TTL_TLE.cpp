// Problem: To the moon
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/TTM/en/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m, t;
int arr[NMAX];

struct node{
	
	int sum, lazy_add;
	node *lf, *ri;
	
	node(){
		sum=lazy_add = 0;
		lf=ri = this;
	}
	
	node(int sum, int lazy_add, node *lf, node *ri):
		sum(sum), lazy_add(lazy_add), lf(lf), ri(ri) {}
		
	node(node *other) : 
		node(other->sum, other->lazy_add, other->lf, other->ri) {}
		
};

node *rts[NMAX];
node *null = new node();

node *push(node *rt, int l, int r){
	
	if(!(rt->lazy_add)) return rt;
	
	if(l != r){
		rt->lf = new node(rt->lf);
		rt->ri = new node(rt->ri);
		rt->lf->lazy_add += rt->lazy_add;									
		rt->ri->lazy_add += rt->lazy_add;
	}
	
	rt->sum += (r-l+1) * rt->lazy_add;
	rt->lazy_add = 0;
	
	return rt;
}

node *build(int l, int r){
	
	if(l==r){
		return new node(arr[l], 0, null, null);
	}	
	
	int mid = (l+r)/2;
	node *nlf = build(l, mid);
	node *nri = build(mid+1, r);
	
	return new node(nlf->sum + nri->sum, 0, nlf, nri);
}

node *update(node *rt, int l, int r, int q_l, int q_r, int val){
	
	rt = push(rt, l, r);
	
	if(r < q_l || q_r < l){
		return rt;
	}	
	
	if(q_l <= l && r <= q_r){
		rt = new node(rt);
		rt->lazy_add += val;
		rt = push(rt, l, r);
		return rt;
	}
	
	int mid = (l+r)/2;
	node *nlf = update(rt->lf, l, mid, q_l, q_r, val);
	node *nri = update(rt->ri, mid+1, r, q_l, q_r, val);
	
	return new node(nlf->sum + nri->sum, 0, nlf, nri);
}

int query(node *rt, int l, int r, int q_l, int q_r){
	
	rt = push(rt, l, r);
	
	if(r < q_l || q_r < l){
		return 0;
	}	
	
	if(q_l <= l && r <= q_r){
		return rt->sum;
	}
	
	int mid = (l+r)/2;
	int st_path = query(rt->lf, l, mid, q_l, q_r);
	int nd_path = query(rt->ri, mid+1, r, q_l, q_r);
	
	return st_path + nd_path;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    rts[0] = build(0, n-1);
    t = 1;
    
    for(int i = 0; i < m; i++){
    	
    	char c;
    	cin >> c;
    	
    	if(c=='C'){
    		int l, r, d;
    		cin >> l >> r >> d;
    		l--, r--;
    		rts[t] = update(rts[t-1], 0, n-1, l, r, d);
    		t++;
    	}
    	else if(c=='Q'){
    		int l, r;
    		cin >> l >> r;
    		l--, r--;
    		int q = query(rts[t-1], 0, n-1, l, r);
    		cout << q << endl;
    	}
    	else if(c=='H'){
    		int l, r, ht;
    		cin >> l >> r >> ht;
    		l--, r--;
    		int q = query(rts[ht], 0, n-1, l, r);
    		cout << q << endl;
    	}
    	else if(c=='B'){
    		int nt;
    		cin >> nt;
    		t = nt+1;
    	}
    	else if(c=='P'){
    		for(int i = 0; i < n; i++){
    			cout << query(rts[t-1], 0, n-1, i, i) << ' ';
    		}
    		cout << endl;
    	}
    }
}

