// Problem: Can you answer these queries I
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/GSS1/
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
 
 
const int NMAX = 5e4 + 10;

struct node{
	
	int sm;
	int pre, suf;
	int ans;
	int mx;
	
	node(){
		sm=pre=suf=ans = 0;
	}	
	
	node(int x){
		sm=pre=suf=ans = x;
	}
};

int n;
int arr[NMAX];
node tree[NMAX << 2];

node merge(const node &a, const node &b){
	node ret;
	ret.sm = a.sm + b.sm;
	ret.pre = max(a.pre, a.sm + b.pre);
	ret.suf = max(b.suf, a.suf + b.sm);
	ret.ans = max({a.ans, b.ans, a.suf+b.pre});
	return ret;
}

void build(int nd, int l, int r){
	
	if(l==r){
		tree[nd] = node(arr[l]);
		return;
	}
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

node query(int nd, int l, int r, int q_l, int q_r){
	
	if(r < q_l || q_r < l){
		return node(-INF);
	}	
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	node st_path = query(nd*2, l, mid, q_l, q_r);
	node nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	if(st_path.sm==-INF){
		return nd_path;
	}
	if(nd_path.sm==-INF){
		return st_path;
	}
	
	return merge(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    build(1, 0, n-1);
    
    int q; cin >> q; while(q--){
    	
    	int l, r;
    	cin >> l >> r;
    	l--, r--;
    	
    	cout << query(1, 0, n-1, l, r).ans << endl;
    }
}
