// Problem: Cyclist Race
// Contest: CodeChef - January Long Challenge 2016
// URL: https://www.codechef.com/JAN16/problems/CYCLRACE
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
	int operator()(int x) { return m * x + b; }
};

struct node{
	
	Line ln;
	node *left;
	node *right; 
	
	node(){
		ln.m = ln.b = 0;
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
	
	int mid = (l+r)/2;
	
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
		return -INF;
	}
	
	if(l==r){
		return nd->ln(x);
	}	
	
	int mid = (l+r)/2;
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
    
    int n, q;
    cin >> n >> q;
    
    node *root = new node();
    
    vector<Line> lns(n, (Line){0, 0});
    insert(root, 0, 1e9, lns[0]);
    
    while(q--){
    	
    	int k;
    	cin >> k;
    	
    	if(k==1){
    		
    		int time, i, new_speed;
    		cin >> time >> i >> new_speed;
    		i--;
    		
    		int cur_pos = lns[i](time);
    		lns[i] = {new_speed, cur_pos-time*new_speed};
    		
    		insert(root, 0, 1e9, lns[i]);
    	}
    	else{
    		
    		int time;
    		cin >> time;
    		
    		int ans = query(root, 0, 1e9, time);
    		cout << ans << endl;
    	}
    }
}
