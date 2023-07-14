// Problem: F. Reverse and Swap
// Contest: Codeforces - Codeforces Round 665 (Div. 2)
// URL: https://codeforces.com/contest/1401/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const int NMAX = (1<<18) + 10;
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

int arr[NMAX];
int tree[NMAX << 2];

void build(int nd, int l, int r, int p){
	
	if(l==r){
		tree[nd] = arr[l];
		return;
	}	
	
	int mid = (l+r)/2;
	build(nd*2, l, mid, p-1);
	build(nd*2+1, mid+1, r, p-1);
	
	tree[nd] = tree[nd*2] + tree[nd*2+1];
}

void update(int nd, int l, int r, int p, int i, int v){
	
	if(l==r){
		tree[nd] = arr[l] = v;
		return;
	}	
	
	int mid = (l+r)/2;
	
	if(i <= mid){
		update(nd*2, l, mid, p-1, i, v);
	}
	else{
		update(nd*2+1, mid+1, r, p-1, i, v);
	}
	
	tree[nd] = tree[nd*2] + tree[nd*2+1];
}

int query(int nd, int l, int r, int p, int q_l, int q_r, int x){
		
	if(r < q_l || q_r < l){
		return 0;
	}	
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	int nd_lf = nd*2;
	int nd_ri = nd*2+1;
	
	if((x>>(p-1))&1){
		x ^= 1<<(p-1);
		nd_lf ^= 1;
		nd_ri ^= 1;	
	}
	
	int st_path = query(nd_lf, l, mid, p-1, q_l, q_r, x);
	int nd_path = query(nd_ri, mid+1, r, p-1, q_l, q_r, x);
	
	return st_path + nd_path;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n, q;
	cin >> n >> q;
	
	int m = 1<<n;
	for(int i = 0; i < m; i++){
		cin >> arr[i];
	}
	
	build(1, 0, m-1, n);
	
	int x = 0;
	
	while(q--){
		
		int k;
		cin >> k;
		
		if(k==1){
			
			int p, v;
			cin >> p >> v;
			p--;
			
			update(1, 0, m-1, n, p^x, v);
		}
		else if(k==2){
			
			int p;
			cin >> p;
			
			x ^= (1<<p)-1;
		}
		else if(k==3){
			
			int p;
			cin >> p;
			
			x ^= 1<<p;
		}
		else{
			
			int l, r;
			cin >> l >> r;
			l--, r--;
			
			int ans = query(1, 0, m-1, n, l, r, x);
			cout << ans << endl;
		}
	}
}
