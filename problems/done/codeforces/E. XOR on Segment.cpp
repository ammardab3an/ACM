// Problem: E. XOR on Segment
// Contest: Codeforces - Codeforces Round #149 (Div. 2)
// URL: https://codeforces.com/problemset/problem/242/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

int n;
int arr[NMAX];

struct node{
	
	int cnt[32];
	
	node(){
		memset(cnt, 0, sizeof cnt);
	}
	
} tree[NMAX<<2];

int lazy[NMAX<<2];

node merge(const node &a, const node &b){
	
	node ret;
	for(int i = 0; i < 32; i++){
		ret.cnt[i] = a.cnt[i] + b.cnt[i];
	}	
	
	return ret;
}

void push(int nd, int l, int r){
	
	for(int i = 0; i < 32; i++) if((lazy[nd]>>i)&1){
		tree[nd].cnt[i] = (r-l+1) - tree[nd].cnt[i];
	}	
	
	if(l != r){
		lazy[nd*2] ^= lazy[nd];
		lazy[nd*2+1] ^= lazy[nd];
	}
	
	lazy[nd] = 0;
}

void build(int nd, int l, int r){
	
	if(l==r){
		
		for(int i = 0; i < 32; i++){
			tree[nd].cnt[i] = (arr[l]>>i)&1;
		}
		
		return;
	}
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_l, int q_r, int x){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return;
	}
	
	if(q_l <= l && r <= q_r){
		lazy[nd] = x;
		push(nd, l, r);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, x);
	update(nd*2+1, mid+1, r, q_l, q_r, x);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);	
}

node query(int nd, int l, int r, int q_l, int q_r){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return node();
	}
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	node st_path = query(nd*2, l, mid, q_l, q_r);
	node nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
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
    
    int m; cin >> m; while(m--){
    	
    	int k;
    	cin >> k;
    	
    	if(k==1){
    		
    		int l, r;
    		cin >> l >> r;
    		l--, r--;
    		
    		node q = query(1, 0, n-1, l, r);
    		
    		int ans = 0;
    		for(int i = 0; i < 32; i++){
    			ans += (1ll << i) * q.cnt[i];
    		}
    		
    		cout << ans << endl;
    	}
    	else{
    		int l, r, x;
    		cin >> l >> r >> x;
    		l--, r--;
    		update(1, 0, n-1, l, r, x);
    	}
    }
}
