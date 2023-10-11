// Problem: E. Data Structures Fan
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/contest/1872/problem/E
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

int n;
int arr[NMAX];
char str[NMAX];

struct node{
	int xor_0 = 0;
	int xor_1 = 0;
	int lazy = 0;
} tree[NMAX << 2];

void push(int nd, int l, int r){
	
	if(!tree[nd].lazy) return;
	
	swap(tree[nd].xor_0, tree[nd].xor_1);
	
	if(l != r){
		tree[nd*2].lazy ^= 1;
		tree[nd*2+1].lazy ^= 1;
	}
	
	tree[nd].lazy = 0;
}

node merge(const node &a, const node &b){
	
	assert(!a.lazy && !b.lazy);
	
	node ret;
	ret.xor_0 = a.xor_0 ^ b.xor_0;
	ret.xor_1 = a.xor_1 ^ b.xor_1;
	ret.lazy = 0;
	
	return ret;	
}

void build(int nd, int l, int r){
	
	if(l==r){
		
		if(str[l]=='0'){		
			tree[nd] = (node){arr[l], 0, 0};
		}
		else{
			tree[nd] = (node){0, arr[l], 0};
		}
		return;
	}	
	
	int mid = (l+r)/2;
	
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_l, int q_r){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return;
	}
	if(q_l <= l && r <= q_r){
		tree[nd].lazy = 1;
		push(nd, l, r);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r);
	update(nd*2+1, mid+1, r, q_l, q_r);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

node query(int nd, int l, int r, int q_l, int q_r){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return (node){0, 0, 0};
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
    
	// init();
	
    int t; cin >> t; while(t--){

		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		cin >> str;
		
		build(1, 0, n-1);
		
		int m; cin >> m; while(m--){
			
			int k;
			cin >> k;
			
			if(k==1){
				int l, r;
				cin >> l >> r;
				l--, r--;
				update(1, 0, n-1, l, r);
			}
			else{
				
				int x;
				cin >> x;
				
				if(x==0){
					cout << tree[1].xor_0 << ' ';
				}
				else{
					cout << tree[1].xor_1 << ' ';
				}
			}
		}
		
		cout << endl;
    }	
}
