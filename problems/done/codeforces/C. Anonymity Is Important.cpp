// Problem: C. Anonymity Is Important
// Contest: Codeforces - Codeforces Round #773 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1641/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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

int par[2][NMAX];

int get_par(int u, int par[]){
	if(u==-1) return u;
	return par[u] = par[u]==u ? u : get_par(par[u], par);
}

int tree[NMAX << 2];

void update(int nd, int l, int r, int p, int val){
	
	if(p < l || r < p){
		return;
	}
	
	if(l == r){
		tree[nd] = min(tree[nd], val);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, p, val);
	update(nd*2+1, mid+1, r, p, val);
	
	tree[nd] = min(tree[nd*2], tree[nd*2+1]);
}

int query(int nd, int l, int r, int q_l, int q_r){
	
	if(r < q_l || q_r < l){
		return INF;
	}
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	int st_path = query(nd*2, l, mid, q_l, q_r);
	int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return min(st_path, nd_path);
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
 	
 	memset(tree, INF, sizeof tree);
 	
 	for(int i = 0; i <= n; i++){
 		par[0][i] = par[1][i] = i;
 	}
 	
 	while(q--){
 		
 		int k;
 		cin >> k;
 		
 		if(k==0){
 			
 			int l, r, x;
 			cin >> l >> r >> x;
 			l--, r--;
 			
 			if(x==0){
 				
 				{
	 				int u = get_par(l, par[0]);
	 				while(u <= r){
	 					par[0][u] = u+1;
	 					u = get_par(u, par[0]);
	 				}
 				}
 				{
 					int u = get_par(r, par[1]);
 					while(l <= u){
 						par[1][u] = u-1;
 						u = get_par(u, par[1]);
 					}
 				}
 				
 				// for(int i = 0; i < n; i++){
 					// cout << get_par(i, par[0]) << ' ';
 				// } cout << endl;
 				// for(int i = 0; i < n; i++){
 					// cout << get_par(i, par[1])<< ' ';
 				// } cout << endl;
 			}
 			else{
 				update(1, 0, n-1, l, r);
 			}
 		}
 		else{
 			
 			int p;
 			cin >> p;
 			p--;
 			
 			if(par[0][p]!=p){
 				cout << "NO" << endl;
 				continue;
 			}
 			
 			int l = get_par(p-1, par[1]);
 			int r = get_par(p+1, par[0]);
 			
 			int mn_r = query(1, 0, n-1, l+1, p);
 			
 			// cout << l << ' ' << r << ' ' << mn_r << endl;
 			
 			if(mn_r < r){
 				cout << "YES" << endl;
 			}
 			else{
 				cout << "N/A" << endl;
 			}
 		}
 	}
}
