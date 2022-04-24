// Problem: C. Krosh and paths
// Contest: Codeforces - Krosh Kaliningrad Contest 2
// URL: https://codeforces.com/gym/103451/problem/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
// const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int MOD;

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

int tree[NMAX << 2];
int cnt[NMAX << 2];
int par[NMAX];
int sz[NMAX];
int fib[NMAX];

int get_par(int u){
	return par[u] = par[u]==u ? u : get_par(par[u]);
}

void merge(int u, int v){
	
	if((u=get_par(u)) == (v=get_par(v))){
		return;
	}
	
	if(sz[u] > sz[v]){
		swap(u, v);
	}
	
	par[u] = v;
	sz[v] += sz[u];
}

void update(int nd, int l, int r, int p, int v){
	
	if(p < l || r < p){
		return;
	}	
	
	if(l==r){
		cnt[nd] = add(cnt[nd], v);
		tree[nd] = pow_exp(fib[p], cnt[nd]);
		return;
	}
	
	int mid = (l+r)/2;
	
	update(nd*2, l, mid, p, v);
	update(nd*2+1, mid+1, r, p, v);
	
	tree[nd] = mul(tree[nd*2], tree[nd*2+1]);
}

void init_fib(){
	
	fib[0] = 0;
	fib[1] = 1;
	for(int i = 2; i < NMAX; i++){
		fib[i] = add(fib[i-1], fib[i-2]);
	}	
	
	for(int i = 0; i < NMAX*4; i++){
		tree[i] = 1;
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n >> MOD;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    int x = 0;
    
    {
    	int l = 0;
    	int r = INF;
    	
    	while(l <= r){
    		
    		int mid = (l+r)/2;
    		
    		bool good = true;
    		
    		for(int i = 0; i < n; i++){
    			if(vec[i] > mid){
    				if(i==0 || i==n-1 || (i&&(vec[i-1]>mid))){
    					good = false;
    					break;
    				}	
    			}
    		}
    		
    		if(good){
    			x = mid;
    			r = mid-1;
    		}
    		else{
    			l = mid+1;
    		}
    	}
    }
    
    init_fib();
    
    for(int i = 0; i < n; i++){
    	par[i] = i;
    	sz[i] = 1;
    }
    
    for(int i = 0; i < n; i++){
    	if(vec[i] <= x){
    		if(i && vec[i-1] <= x){
    			merge(i, i-1);
    		}		
    	}
    	else{
			update(1, 0, n, sz[get_par(i-1)], +1);
    	}
    }
    
    update(1, 0, n, sz[get_par(n-1)], +1);
    
    int ans = mul(x, tree[1]);
    
    priority_queue<pii> que;
    for(int i = 0; i < n; i++) if(vec[i] > x){
    	que.push({-vec[i], i});
    }
    
    while(!que.empty()){
    	
    	pii tp = que.top();
    	que.pop();
    	
    	int a = -tp.first;
    	int i = tp.second;
    	
    	int bk = tree[1];
    	
    	bool b0 = vec[i-1] <= vec[i];
    	bool b1 = i && (vec[i+1] <= vec[i]);
    	
    	if(b0) update(1, 0, n, sz[get_par(i-1)], -1);
    	if(b1) update(1, 0, n, sz[get_par(i+1)], -1);
    	
    	if(b0) merge(i, i-1);
    	if(b1) merge(i, i+1);
    	
    	update(1, 0, n, sz[get_par(i)], +1);
    	
    	int dif = add(tree[1], mul(-1, bk));
    	
    	ans = add(ans, mul(a, dif));
    }
    
    cout << ans << endl;
}
