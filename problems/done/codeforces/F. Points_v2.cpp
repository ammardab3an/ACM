// Problem: F. Points
// Contest: Codeforces - Educational Codeforces Round 131 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1701/problem/F
// Memory Limit: 512 MB
// Time Limit: 6500 ms
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

struct node{
	int tot;
	int val;
	int cnt;
	int lazy;
};

node tree[NMAX << 2];
bitset<NMAX> vis;

void push(int nd, int l, int r){
	
	if(!tree[nd].lazy) return;
	
	{
		int v = tree[nd].lazy;
		tree[nd].tot += v*tree[nd].val + tree[nd].cnt*((v*(v-1))/2);
		tree[nd].val += v*tree[nd].cnt;
	}
	
	if(l != r){
		tree[nd*2].lazy += tree[nd].lazy;
		tree[nd*2+1].lazy += tree[nd].lazy;
	}
	
	tree[nd].lazy = 0;
}

node merge(const node &a, const node &b){
	
	assert(a.lazy==b.lazy && a.lazy==0);
	
	node ret;
	ret.tot = a.tot + b.tot;
	ret.val = a.val + b.val;
	ret.cnt = a.cnt + b.cnt;
	ret.lazy = 0;
	
	return ret;
}

void update_pos(int p, int val, bool b, int nd=1, int l=0, int r=NMAX-1){
	
	push(nd, l, r);
	
	if(p < l || r < p){
		return;
	}
	
	if(l==r){
		tree[nd].tot = (val*(val-1))/2;
		tree[nd].val = val;
		tree[nd].cnt = b;
		return;	
	}
	
	int mid = (l+r)/2;
	update_pos(p, val, b, nd*2, l, mid);
	update_pos(p, val, b, nd*2+1, mid+1, r);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int q_l, int q_r, int val, int nd=1, int l=0, int r=NMAX-1){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return;
	}
	
	if(q_l <= l && r <= q_r){
		tree[nd].lazy += val;
		push(nd, l, r);
		return;
	}
	
	int mid = (l+r)/2;
	update(q_l, q_r, val, nd*2, l, mid);
	update(q_l, q_r, val, nd*2+1, mid+1, r);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

node query(int q_l, int q_r, int nd=1, int l=0, int r=NMAX-1){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return (node){0, 0, 0};
	}
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	node st_path = query(q_l, q_r, nd*2, l, mid);
	node nd_path = query(q_l, q_r, nd*2+1, mid+1, r);
	
	return merge(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int q, d;
    cin >> q >> d;
    
    while(q--){
    	
    	int ai;
    	cin >> ai;
    	ai--;
    	
    	int b = vis[ai] ? -1 : +1;
    	
		if(ai > 0){
			update(max(int(0), ai-d), ai-1, b);
		}
		
		if(b==+1){
			int cnt = query(ai+1, min(ai+d, NMAX-1)).cnt;
			update_pos(ai, cnt, 1);
		}
		else{
			update_pos(ai, 0, 0);
		}
    	
    	vis[ai] = !vis[ai];
    	
    	int cans = query(0, NMAX-1).tot;
    	cout << cans << endl;
    }
}
