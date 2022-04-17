// Problem: E - Max Min
// Contest: AtCoder - AtCoder Beginner Contest 247
// URL: https://atcoder.jp/contests/abc247/tasks/abc247_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

int n, x, y;
int arr[NMAX];
pii tree[NMAX << 2];

pii merge(pii a, pii b){
	return {min(a.first, b.first), max(a.second, b.second)};
}

void build(int nd, int l, int r){
	
	if(l==r){
		tree[nd] = {arr[l], arr[l]};
		return;
	}
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

pii query(int nd, int l, int r, int q_l, int q_r){
	
	if(r < q_l || q_r < l){
		return {INF, -INF};
	}
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	pii st_path = query(nd*2, l, mid, q_l, q_r);
	pii nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return merge(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> x >> y;
    
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    int ans = 0;
    
    build(1, 0, n-1);
    
    for(int i = 0; i < n; i++){
    	
    	int lb = i;
    	int ub = i;
    	
    	{
    		int l = i;
    		int r = n-1;
    		
    		int cans = -1;
    		
    		while(l <= r){
    			
    			int mid = (l+r)/2;
    			pii p = query(1, 0, n-1, i, mid);
    			
    			// cout << '-' << ' ' << l << ' ' << r << ' ' << mid << ' ' << p.first << ' ' << p.second << endl;
    			
    			if(p.first < y || p.second > x){
    				r = mid-1;
    			}
    			else if(p.first==y && p.second==x){
    				cans = mid;
    				r = mid-1;
    			}
    			else{
    				l = mid+1;
    			}
    		}
    		
    		lb = cans;
    	}
    	
    	if(lb != -1){
    		
    		int l = i;
    		int r = n-1;
    		
    		int cans = -1;
    		
    		while(l <= r){
    			
    			int mid = (l+r)/2;
    			pii p = query(1, 0, n-1, i, mid);
    			
    			if(p.first < y || p.second > x){
    				r = mid-1;
    			}
    			else if(p.first==y && p.second==x){
    				cans = mid;
    				l = mid+1;
    			}
    			else{
    				l = mid+1;
    			}
    		}
    		
    		ub = cans;
    	}
    	
    	if(lb != -1){
    		ans += ub-lb+1;
    	}
    	
    	// cout << i << ' ' << lb << ' ' << ub << endl;
    }
    
    cout << ans << endl;
}
