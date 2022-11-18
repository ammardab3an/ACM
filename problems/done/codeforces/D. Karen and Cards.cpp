// Problem: D. Karen and Cards
// Contest: Codeforces - Codeforces Round #419 (Div. 1)
// URL: https://codeforces.com/contest/815/problem/D
// Memory Limit: 512 MB
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
 
const int NMAX = 5e5 + 10;

int tree[NMAX<<2];
int lazy[NMAX<<2];
int mn[NMAX<<2];
int mx[NMAX<<2];
int up[3];

void push(int nd, int l, int r){
	
	if(!lazy[nd]) return;
	
	mn[nd] = mx[nd] = lazy[nd];
	tree[nd] = lazy[nd] * (r-l+1);
	
	if(l < r){
		lazy[nd*2] = lazy[nd*2+1] = lazy[nd];
	}
	
	lazy[nd] = 0;
}

void update(int nd, int l, int r, int q_l, int q_r, int val){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l || mn[nd] >= val){
		return;
	}
	
	if(q_l <= l && r <= q_r && mx[nd] <= val){
		lazy[nd] = val;
		push(nd, l, r);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, val);
	update(nd*2+1, mid+1, r, q_l, q_r, val);
	
	tree[nd] = tree[nd*2] + tree[nd*2+1];	
	mn[nd] = min(mn[nd*2], mn[nd*2+1]);
	mx[nd] = max(mx[nd*2], mx[nd*2+1]);
}

int query(int nd, int l, int r, int q_l, int q_r){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return 0;
	}
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	int st_path = query(nd*2, l, mid, q_l, q_r);
	int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return st_path + nd_path;
}

int query_bs(int nd, int l, int r, int q_l, int q_r, int val){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return 0;
	}	
	
	if(q_l <= l && r <= q_r){
		if(mn[nd] >= val){		
			return up[2]*(r-l+1) - tree[nd];
		}
		if(mx[nd] <= val){
			return (r-l+1)*(up[2]-val);
		}
	}
	
	int mid = (l+r)/2;
	int st_path = query_bs(nd*2, l, mid, q_l, q_r, val);
	int nd_path = query_bs(nd*2+1, mid+1, r, q_l, q_r, val);
	
	return st_path + nd_path;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < 3; i++){
    	cin >> up[i];
    }
    
    vector<vi> vec(n, vi(3));
    for(auto &v : vec)
    for(auto &i : v) cin >> i;
    
    sort(vec.begin(), vec.end());
    
    vector<vi> suf(n);
    suf[n-1] = vec[n-1];
    for(int i = n-2; i >= 0; i--){
    	suf[i] = suf[i+1];
    	for(int j = 0; j < 3; j++){
    		suf[i][j] = max(suf[i][j], vec[i][j]);
    	}
    }
    
    int ans = 0;
	ans += (up[1]-suf[0][1]) * (up[2]-suf[0][2]);	
    
    int p = 0;
    for(int i = 1; i < up[0]; i++){
    	
    	while(p < n && vec[p][0]==i){
    		update(1, 1, up[1], 1, vec[p][1], vec[p][2]);
    		p++;
    	}
    	
    	if(p==n){
    		ans += (up[0]-i) * (up[1]*up[2] - tree[1]);
    		break;
    	}
    	
    	int a = suf[p][1];
    	int b = suf[p][2];
    	int cans = query_bs(1, 1, up[1], a+1, up[1], suf[p][2]);
    	ans += cans;
    }
    
    cout << ans << endl;
}
