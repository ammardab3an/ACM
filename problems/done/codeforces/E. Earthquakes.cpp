// Problem: E. Earthquakes
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 1 - Step 4
// URL: http://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/E?locale=en
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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
const int NMAX = 1e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));


struct node{
	int min = INF;
};

node tree[NMAX << 2];

void update(int nd, int l, int r, int p, int h){
	
	if(l == r){
		tree[nd].min = h;
		return;
	}
	
	int mid = (l+r)/2;
	
	if(p <= mid){
		update(nd*2, l, mid, p, h);
	}
	else{
		update(nd*2+1, mid+1, r, p, h);
	}
	
	tree[nd].min = min(tree[nd*2].min, tree[nd*2+1].min);
}

int query(int nd, int l, int r, int q_l, int q_r, int h){
	
	if(tree[nd].min > h){
		return 0;
	}
	
	if(r < q_l || q_r < l){
		return 0;
	}
	
	if(l == r){
		tree[nd].min = INF;
		return 1;	
	}
	
	int mid = (l+r)/2;
	int st_path = query(nd*2, l, mid, q_l, q_r, h);
	int nd_path = query(nd*2+1, mid+1, r, q_l, q_r, h);
	
	tree[nd].min = min(tree[nd*2].min, tree[nd*2+1].min);
	
	return st_path + nd_path;
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
    	
    	int k;
    	cin >> k;
    	
    	if(k==1){
    		int p, h;
    		cin >> p >> h;
    		update(1, 0, n-1, p, h);
    	}
    	else{
    		int l, r, h;
    		cin >> l >> r >> h;
    		int ans = query(1, 0, n-1, l, r-1, h);
    		cout << ans << endl;
    	}
    }
}
