// c++14

// Problem: E. Army Creation
// Contest: Codeforces - Educational Codeforces Round 22
// URL: https://codeforces.com/problemset/problem/813/E
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

struct node;
extern node *empty;

struct node{
	int sm;
	node *lf, *ri;
	node(){
		sm=0;
		lf=ri = this;
	}
	node(int _sm, node *_lf=empty, node *_ri=empty):
		sm(_sm), lf(_lf), ri(_ri) {}
};

node *empty = new node();

node *update(node *rt, int l, int r, int p, int val){
	
	if(p < l || r < p){
		return rt;
	}	
	
	if(l==r){
		return new node(rt->sm + val);
	}
	
	int mid = (l+r)/2;
	node *nlf = update(rt->lf, l, mid, p, val);
	node *nri = update(rt->ri, mid+1, r, p, val);
	
	return new node (rt->sm + val, nlf, nri);
}

int query(node *rt, int l, int r, int q_l, int q_r){
	
	if(r < q_l || q_r < l){
		return 0;
	}	
	
	if(q_l <= l && r <= q_r){
		return rt->sm;
	}
	
	int mid = (l+r)/2;
	int st_path = query(rt->lf, l, mid, q_l, q_r);
	int nd_path = query(rt->ri, mid+1, r, q_l, q_r);
	
	return st_path + nd_path;
}

int n, k;
int arr[NMAX];
queue<int> lst[NMAX];
node *rts[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    node *rt = new node();
    for(int i = 0; i < n; i++){
    	
    	if((int)(lst[arr[i]].size())==k){
    		rt = update(rt, 0, NMAX-1, lst[arr[i]].front(), -1);
    		lst[arr[i]].pop();
    	}
    	
    	rt = update(rt, 0, NMAX-1, i, +1);
    	lst[arr[i]].push(i);
    	
    	rts[i] = rt;
    }
    
    int last = 0;
    int q; cin >> q; while(q--){
    	
    	int x, y;
    	cin >> x >> y;
    	int l = (last+x)%n;
    	int r = (last+y)%n;
    	if(l > r) swap(l, r);
    	
    	last = query(rts[r], 0, NMAX-1, l, r);
    	cout << last << endl;
    }
}
