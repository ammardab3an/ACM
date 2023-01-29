// Problem: E. Product Sum
// Contest: Codeforces - Codeforces Round #344 (Div. 2)
// URL: https://codeforces.com/problemset/problem/631/E
// Memory Limit: 256 MB
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

struct Line{
	int m, b;
	int operator()(int x) { 
		if(m==-INFLL) return -INFLL;
		return m * x + b; 
	}
};

struct node{
	
	Line ln;
	node *left;
	node *right; 
	
	node(){
		ln.m = ln.b = -INFLL;
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
		if(seg(l) > nd->ln(l)){
			nd->ln = seg;
		}
		return;
	}		
	
	int mid = l+(r-l)/2;
	
	if(nd->ln.m > seg.m){
		swap(nd->ln, seg);
	}
	
	if(nd->ln(mid) < seg(mid)){
		swap(nd->ln, seg);
		insert(nd->left, l, mid, seg);
	}
	else{
		insert(nd->right, mid+1, r, seg);
	}
}

int query(node* nd, int l, int r, int x){
	
	if(!nd){
		return -INFLL;
	}
	
	if(l==r){
		return nd->ln(x);
	}	
	
	int mid = l+(r-l)/2;
	
	if(x < mid){
		return max(nd->ln(x), query(nd->left, l, mid, x));
	}
	else{
		return max(nd->ln(x), query(nd->right, mid+1, r, x));
	}
}

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
    
    vi pre = vec;
    for(int i = 1; i < n; i++){
    	pre[i] += pre[i-1];
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
    	ans += (i+1) * vec[i];
    }
    
    int st_path = 0;
    int nd_path = 0;
    
    // st_path
    {
    	node *root = new node();
    	for(int i = 0; i < n; i++){
    		
    		if(i){
	    		int cans = (pre[i-1]-vec[i]*i) + query(root, -1e6, 1e6, vec[i]);
	    		st_path = max(st_path, cans);
	    	}
			
    		insert(root, -1e6, 1e6, (Line){i, -pre[i]+vec[i]});
    	}
    }
    
    // nd_path
    {
    	node *root = new node();
    	for(int i = 0; i < n; i++){
    		
    		if(i){
    			int cans = (-pre[i]) + query(root, -1e6, 1e6, i);
    			nd_path = max(nd_path, cans);
    		}
    	
    		insert(root, -1e6, 1e6, (Line){vec[i], pre[i]-vec[i]*i});	
    	}
    }
    
    cout << ans + max(st_path, nd_path) << endl;
}
