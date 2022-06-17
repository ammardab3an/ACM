#pragma GCC optimize("O3") 
#pragma GCC optimize ("unroll-loops") 
#pragma GCC target("avx,avx2,fma") 

// Problem: Pizza Delivery
// Contest: CodeChef - July Challenge 2018 Division 1
// URL: https://www.codechef.com/JULY18A/problems/PDELIV
// Memory Limit: 256 MB
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct Line{
	int m, b;
	int operator()(int x) { 
		if(m==INFLL) return INFLL;
		return m * x + b; 
	}
};

struct node{
	
	Line ln;
	node *left;
	node *right; 
	
	node(){
		ln.m = ln.b = INFLL;
		left=right=nullptr;
	}
	
	~node(){
		delete left;
		delete right;
	}
};

void insert(node*&nd, int l, int r, Line seg){
	
	if(!nd){
		nd = new node();
	}
	
	if(l==r){
		if(seg(l) < nd->ln(l)){
			nd->ln = seg;
		}
		return;
	}		
	
	int mid = (l+r)/2;
	
	if(nd->ln.m < seg.m){
		swap(nd->ln, seg);
	}
	
	if(nd->ln(mid) > seg(mid)){
		swap(nd->ln, seg);
		insert(nd->left, l, mid, seg);
	}
	else{
		insert(nd->right, mid+1, r, seg);
	}
}

int query(node* nd, int l, int r, int x){
	
	if(!nd){
		return INFLL;
	}
	
	if(l==r){
		return nd->ln(x);
	}	
	
	int mid = (l+r)/2;
	if(x < mid){
		return min(nd->ln(x), query(nd->left, l, mid, x));
	}
	else{
		return min(nd->ln(x), query(nd->right, mid+1, r, x));
	}
}

struct seg_node{
	node *root;
	seg_node(){
		root = new node();
	}
	~seg_node(){
		delete root;
	}
};

vector<seg_node> tree;

void seg_update(int nd, int l, int r, int p, Line ln){
	
	if(p < l || r < p){
		return;
	}
	
	insert(tree[nd].root, 0, 1e9, ln);
	
	if(l==r){
		return;
	}
	
	int mid = (l+r)/2;
	seg_update(nd*2, l, mid, p, ln);
	seg_update(nd*2+1, mid+1, r, p, ln);
}

int seg_query(int nd, int l, int r, int q_l, int q_r, int x){
	
	if(r < q_l || q_r < l){
		return INFLL;
	}	
	
	if(q_l <= l && r <= q_r){
		return query(tree[nd].root, 0, 1e9, x);
	}
	
	int mid = (l+r)/2;
	int st_path = seg_query(nd*2, l, mid, q_l, q_r, x);
	int nd_path = seg_query(nd*2+1, mid+1, r, q_l, q_r, x);
	
	return min(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    while(cin >> n >> m){
    
	    vpii vec(n);
	    for(auto &p : vec){
	    	// p = {si, pi}
	    	cin >> p.first >> p.second;
	    }
	    
	    tree.clear();
	    tree.resize(n*4);
	    
	    /*
	    	ci
	    	si pi
	    	cost = pi + (si-ci)^2
	    	     = pi + si*si + ci*ci -2*si*ci
			     = ci*ci + ( pi + si*si + (-2*si) * ci )
			m = -2*si
			c = pi
			x = ci
	    */
	    
	    for(int i = 0; i < n; i++){
	    	int ln_m = -2ll*vec[i].first;
	    	int ln_c = vec[i].second + vec[i].first*vec[i].first;
	    	seg_update(1, 0, n-1, i, (Line){ln_m, ln_c});    		
	    }
	    
	    while(m--){
	    	
	    	int ci;
	    	cin >> ci;
	    	
	    	int k;
	    	cin >> k;
	    	vi tmp(k+2);
	    	tmp[0] = -1;
	    	tmp[tmp.size()-1] = n;
	    	for(int i = 1; i < tmp.size()-1; i++){
	    		cin >> tmp[i];
	    		tmp[i]--;
	    	}
	    	
	    	sort(tmp.begin(), tmp.end());
	    	
	    	int ans = INFLL;
	    	
	    	for(int i = 1; i < tmp.size(); i++){
	    		
	    		int l = tmp[i-1]+1;
	    		int r = tmp[i]-1;
	    		
	    		if(l > r) continue;
	    		
	    		// cout << l << ' ' << r << endl;
	    		
	    		int cans = seg_query(1, 0, n-1, l, r, ci);
	    		if(cans < ans){
	    			ans = min(ans, cans+ci*ci);
	    		}
	    	}
	    	
	    	cout << ans << endl;
	    }
    }
}
