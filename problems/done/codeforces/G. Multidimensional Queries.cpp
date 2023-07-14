// Problem: G. Multidimensional Queries
// Contest: Codeforces - Educational Codeforces Round 56 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1093/problem/G
// Memory Limit: 512 MB
// Time Limit: 6000 ms
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

int n, k;
int arr[NMAX][5];
vi tree[NMAX<<2];

void build(int nd, int l, int r){
	
	if(l==r){
		
		tree[nd] = vi(1<<k);
		
		for(int i = 0; i < (1<<k); i++){
			tree[nd][i] = 0;
			for(int j = 0; j < k; j++){
				if((i>>j)&1){
					tree[nd][i] += arr[l][j];
				}
				else{
					tree[nd][i] -= arr[l][j];
				}
			}		
		}
		
		return;
	}	
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = vi(1<<k);
	for(int i = 0; i < (1<<k); i++){
		tree[nd][i] = max(tree[nd*2][i], tree[nd*2+1][i]);
	}
}

void update(int nd, int l, int r, int p){
	
	if(l==r){
		
		for(int i = 0; i < (1<<k); i++){
			tree[nd][i] = 0;
			for(int j = 0; j < k; j++){
				if((i>>j)&1){
					tree[nd][i] += arr[l][j];
				}
				else{
					tree[nd][i] -= arr[l][j];
				}
			}		
		}
		
		return;
	}	
	
	int mid = (l+r)/2;
	if(p <= mid){
		update(nd*2, l, mid, p);
	}
	else{
		update(nd*2+1, mid+1, r, p);
	}
	
	for(int i = 0; i < (1<<k); i++){
		tree[nd][i] = max(tree[nd*2][i], tree[nd*2+1][i]);
	}
}

vi query(int nd, int l, int r, int q_l, int q_r){
	
	if(r < q_l || q_r < l){
		return vi(1<<k, -INF);
	}	
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	vi st_path = query(nd*2, l, mid, q_l, q_r);
	vi nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	vi ret(1<<k);
	for(int i = 0; i < (1<<k); i++){
		ret[i] = max(st_path[i], nd_path[i]);
	}
	
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	for(int j = 0; j < k; j++){
		cin >> arr[i][j];
	}
	
	build(1, 0, n-1);
	
	int q; cin >> q; while(q--){
		
		int ty;
		cin >> ty;
		
		if(ty==1){
			
			int i;
			cin >> i;
			i--;
			
			for(int j = 0; j < k; j++){
				cin >> arr[i][j];
			}	
			
			update(1, 0, n-1, i);
		}
		else{
			
			int l, r;
			cin >> l >> r;
			l--, r--;
			
			vi tmp = query(1, 0, n-1, l, r);
			
			int ans = 0;
			for(int i = 0; i < (1<<k); i++){
				ans = max(ans, tmp[i] + tmp[i^((1<<k)-1)]);
			}
			
			cout << ans << endl;
		}
	}
}
