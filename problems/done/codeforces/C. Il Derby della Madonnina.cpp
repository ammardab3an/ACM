// Problem: C. Il Derby della Madonnina
// Contest: Codeforces - 2021-2022 ICPC Southwestern European Regional Contest (SWERC 2021-2022)
// URL: https://codeforces.com/gym/104017/problem/C?f0a28=1
// Memory Limit: 256 MB
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));


struct segTree{
	
	vi tree;
	
	segTree(){
	}
	segTree(int n){
		tree = vi(n<<2, 0);
	}
	 
	void update(int nd, int l, int r, int p, int v){
		
		if(p < l || r < p){
			return;
		}
		
		if(l==r){
			tree[nd] = max(tree[nd], v);
			return;
		}
		
		int mid = (l+r)/2;
		update(nd*2, l, mid, p, v);
		update(nd*2+1, mid+1, r, p, v);
		
		tree[nd] = max(tree[nd*2], tree[nd*2+1]);
	}
	
	int query(int nd, int l, int r, int q_l, int q_r){
		
		if(r < q_l || q_r < l){
			return 0;
		}
		
		if(q_l <= l && r <= q_r){
			return tree[nd];
		}
		
		int mid = (l+r)/2;
		int st_path = query(nd*2, l, mid, q_l, q_r);
		int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
		
		return max(st_path, nd_path);
	}
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, v;
    cin >> n >> v;
    
    vi vec_t(n), vec_x(n);
    for(auto &i : vec_t) cin >> i, i*=v;
    for(auto &i : vec_x) cin >> i;
    
    for(int i = 0; i < vec_t.size(); i++){
    	int t = vec_t[i];
    	int x = vec_x[i];
    	if(abs(x) > t){
    		swap(vec_t[i], vec_t.back());
    		swap(vec_x[i], vec_x.back());
    		vec_t.pop_back();
    		vec_x.pop_back();
    		i--;
    		n--;
    	}	
    }
    
    if(n==0){
    	cout << 0 << endl;
    	return 0;
    }
    
    vpii vec(n);
    for(int i = 0; i < n; i++){
    	int t = vec_t[i];
    	int x = vec_x[i];
    	vec[i] = {t-x, t+x};
    }
    
    vi pos(n);
    iota(pos.begin(), pos.end(), 0);
    sort(pos.begin(), pos.end(), [&](int i, int j){
    	return vec[i] < vec[j];
    });
    
    vi comp;
    {
    	for(auto [a, b] : vec){
    		comp.push_back(b);
    	}
    	sort(comp.begin(), comp.end());
    	comp.resize(unique(comp.begin(), comp.end())-comp.begin());
    	for(auto &[a, b] : vec){
    		b = lower_bound(comp.begin(), comp.end(), b)-comp.begin();
    	}
    }
    
    vi dp(n);
    segTree tree(comp.size());
    for(int i = n-1; i >= 0; i--){
    	dp[i] = 1+tree.query(1, 0, comp.size()-1, vec[pos[i]].second, comp.size()-1);
    	tree.update(1, 0, comp.size()-1, vec[pos[i]].second, dp[i]);
    }
    
    cout << *max_element(dp.begin(), dp.end()) << endl;
}
