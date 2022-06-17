
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

vpii tmp;

void init_tmp(){
	
	tmp.push_back({2, 1});
	tmp.push_back({8, 0});
	
	int cur_mex = 2;
	int cur_cnt = 18;
	int cur_num = 9;
	
	while(cur_num < 1e18){
		
		// if(cur_num < 10000){
			// cout << tmp.back().first << ' ' << tmp.back().second << endl;
		// }
		
		tmp.push_back({cur_num+cur_cnt-1, cur_mex});
		cur_mex += 1;
		cur_num += cur_cnt;
		cur_cnt *= 3;
	}
}

int query_mex(int i){
	if(i < 3) return 0;
	auto it = lower_bound(tmp.begin(), tmp.end(), (pii){i, -1});
	return it->second;
}

int n, q;
int arr[NMAX];
int tree[NMAX << 2];
int all_zero[NMAX << 2];

void build(int nd, int l, int r){
	
	if(l==r){
		tree[nd] = arr[l];
		all_zero[nd] = tree[nd]==0;
		return;
	}
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = tree[nd*2] ^ tree[nd*2+1];
	all_zero[nd] = all_zero[nd*2] && all_zero[nd*2+1];
}

void update(int nd, int l, int r, int p, int x){
	
	if(p < l || r < p){
		return;
	}
	
	if(l==r){
		tree[nd] = arr[l] = query_mex(x);
		all_zero[nd] = tree[nd]==0;
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, p, x);
	update(nd*2+1, mid+1, r, p, x);
	
	tree[nd] = tree[nd*2] ^ tree[nd*2+1];
	all_zero[nd] = all_zero[nd*2] && all_zero[nd*2+1];
}

pii query(int nd, int l, int r, int q_l, int q_r){
	
	if(r < q_l || q_r < l){
		return {0, 1};
	}
	
	if(q_l <= l && r <= q_r){
		return {tree[nd], all_zero[nd]};
	}
	
	int mid = (l+r)/2;
	pii st_path = query(nd*2, l, mid, q_l, q_r);
	pii nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	pii ret;
	ret.first = st_path.first ^ nd_path.first;
	ret.second = st_path.second && nd_path.second;
	
	return ret;
}

int32_t main(){
    
    // fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    freopen("bero.in", "r", stdin);
    
    init_tmp();
    
    int t;
    scanf("%lld", &t);
    
    while(t--){
    	
    	scanf("%lld%lld", &n, &q);
    	for(int i = 0; i < n; i++){
    		scanf("%lld", arr+i);
    		arr[i] = query_mex(arr[i]);
    	}
    	
    	// for(int i = 0; i < n; i++){
    		// cout << arr[i] << ' ' ;
    	// } cout << endl;
    	
    	build(1, 0, n-1);
    	
    	while(q--){
    		
    		int k;
    		scanf("%lld", &k);
    		
			// cout << k << endl;
			// return 0;
    		
    		if(k==1){
    			int idx, val;
    			scanf("%lld%lld", &idx, &val);
    			idx--;
    			update(1, 0, n-1, idx, val);
    		}
    		else{
    			int l, r;
    			scanf("%lld%lld", &l, &r);
    			l--, r--;
    			pii ans = query(1, 0, n-1, l, r);
    			puts((ans.first>1 || ans.second) ? "Bero" : "Besho");
    		}
    	}
    }
}
