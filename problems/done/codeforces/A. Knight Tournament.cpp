// Problem: A. Knight Tournament
// Contest: Codeforces - Codeforces Round #207 (Div. 1)
// URL: https://codeforces.com/contest/356/problem/A
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const int NMAX = 3e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int tree[NMAX << 2];

void update(int nd, int l, int r, int q_l, int q_r, int x){
	
	if(r < q_l || q_r < l){
		return;
	}	
	
	if(tree[nd]){
		return;
	}
	
	if(q_l <= l && r <= q_r){
		tree[nd] = x;
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, x);
	update(nd*2+1, mid+1, r, q_l, q_r, x);
}

int query(int nd, int l, int r, int p){
	
	if(l==r){
		return tree[nd];
	}	
	
	int mid = (l+r)/2;
	
	if(p <= mid){
		int nxt = query(nd*2, l, mid, p);
		if(nxt) return nxt;
	}
	else{
		int nxt = query(nd*2+1, mid+1, r, p);
		if(nxt) return nxt;
	}
	
	return tree[nd];
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    while(m--){
    	
    	int l, r, x;
    	cin >> l >> r >> x;
    	l--, r--, x--;
    	
    	update(1, 0, n-1, l, x-1, x+1);
    	update(1, 0, n-1, x+1, r, x+1);
    }
    
    for(int i = 0; i < n; i++){
    	cout << query(1, 0, n-1, i) << ' ';
    }
}
