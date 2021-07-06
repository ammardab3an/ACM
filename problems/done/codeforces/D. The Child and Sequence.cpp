// Problem: D. The Child and Sequence
// Contest: Codeforces - Codeforces Round #250 (Div. 1)
// URL: https://codeforces.com/contest/438/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>      iii;
typedef pair<ll, pll>      lll;
typedef vector<int>         vi;
typedef vector<ll>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

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
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 1e5 + 10;

int n, m;
int arr[NMAX];
int tree_sum[NMAX*4];
int tree_max[NMAX*4];
int tree_min[NMAX*4];

void merge(int nd){
	tree_sum[nd] = tree_sum[nd*2] + tree_sum[nd*2+1];
	tree_max[nd] = max(tree_max[nd*2], tree_max[nd*2+1]);
}

void build(int nd, int l, int r){
	
	if(l == r){
		tree_max[nd] = tree_sum[nd] = arr[l];
		return;
	}
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	merge(nd);
}

void update_mod(int nd, int l, int r, int q_l, int q_r, int x){
	
	
	if(l > q_r || q_l > r || (tree_max[nd] < x)){
		return;
	}	
	
	if(l == r){
		tree_max[nd] = tree_sum[nd] = tree_max[nd]%x;
		return;
	}
	
	int mid = (l+r)/2;
	update_mod(nd*2, l, mid, q_l, q_r, x);
	update_mod(nd*2+1, mid+1, r, q_l, q_r, x);
	
	merge(nd);
}

void update_ele(int nd, int l, int r, int p, int x){
	
	if(p < l || r < p){
		return;
	}	
	
	if(l == r){
		tree_max[nd] = tree_sum[nd] = x;
		return;
	}
	
	int mid = (l+r)/2;
	update_ele(nd*2, l, mid, p, x);
	update_ele(nd*2+1, mid+1, r, p, x);
	
	merge(nd);
}

int query_sum(int nd, int l, int r, int q_l, int q_r){
	
	if(l > q_r || q_l > r){
		return 0;
	}
	
	if(q_l <= l && r <= q_r){
		return tree_sum[nd];
	}
	
	int mid = (l+r)/2;
	int stPath = query_sum(nd*2, l, mid, q_l, q_r);
	int ndPath = query_sum(nd*2+1, mid+1, r, q_l, q_r);
	
	return stPath + ndPath;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    build(1, 0, n-1);
    
    while(m--){
    	
    	int q;
    	cin >> q;
    	
    	if(q == 1){
    		int l, r;
    		cin >> l >> r;
    		l--, r--;
    		int que = query_sum(1, 0, n-1, l, r);
    		cout << que << endl;
    	}
    	else if(q == 2){
    		int l, r, x;
    		cin >> l >> r >> x;
    		l--, r--;
    		update_mod(1, 0, n-1, l, r, x);
    	}
    	else {
    		int k, x;
    		cin >> k >> x;
    		k--;
    		update_ele(1, 0, n-1, k, x);
    	}
    	
    	// for(int i = 0; i < n; i++){
    		// cout << query_sum(1, 0, n-1, i, i) << ' ' ;
    	// }
    	// cout << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  notes : 
  
  
*/    
