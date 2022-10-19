// Problem: K. Walking Tiles
// Contest: Codeforces - 2021 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/103577/problem/K
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
 
const int NMAX = 2*2e5 + 10;

struct segTree{
	
	vi tree;
	
	segTree(){
		tree = vi(NMAX<<2, INFLL);
	}
	 
	void update(int nd, int l, int r, int p, int v){
		
		if(p < l || r < p){
			return;
		}
		
		if(l==r){
			tree[nd] = min(tree[nd], v);
			return;
		}
		
		int mid = (l+r)/2;
		update(nd*2, l, mid, p, v);
		update(nd*2+1, mid+1, r, p, v);
		
		tree[nd] = min(tree[nd*2], tree[nd*2+1]);
	}
	
	int query(int nd, int l, int r, int q_l, int q_r){
		
		if(r < q_l || q_r < l){
			return INFLL;
		}
		
		if(q_l <= l && r <= q_r){
			return tree[nd];
		}
		
		int mid = (l+r)/2;
		int st_path = query(nd*2, l, mid, q_l, q_r);
		int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
		
		return min(st_path, nd_path);
	}
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    vpii blue(n);
    for(auto &[i, j] : blue){
    	cin >> i >> j;
    }
    
    vpii red(m);
    for(auto &[i, j] : red){
    	cin >> i >> j;
    }
    
	vi tmp;
    {
    	for(auto [i, j] : blue){
    		tmp.push_back(j);
    	}	
    	for(auto [i, j] : red){
    		tmp.push_back(j);
    	}
    	
    	sort(tmp.begin(), tmp.end());
    	tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
    	
    	for(auto &[i, j] : blue){
    		j = lower_bound(tmp.begin(), tmp.end(), j) - tmp.begin();
    	}
    	for(auto &[i, j] : red){
    		j = lower_bound(tmp.begin(), tmp.end(), j) - tmp.begin();
    	}
    }
    
    sort(blue.begin(), blue.end());
    sort(red.begin(), red.end());
    
    vi ans(n, INFLL);
    
    for(auto fo : {0, 1}){
    	
    	if(fo){
    		for(auto &[x, y] : blue) x *= -1;
    		for(auto &[x, y] : red) x *= -1;
    		reverse(blue.begin(), blue.end());
    		reverse(red.begin(), red.end());
    	}
    	
	    segTree t0, t1;
	    
	    int p = 0;
	    for(int i = 0; i < blue.size(); i++){
	    	
	    	auto [x, y] = blue[i];
	    	
	    	while(p < red.size() && red[p].first <= x){

	    		auto [x0, y0] = red[p];	
    			t0.update(1, 0, NMAX-1, y0, -tmp[y0]-x0);	
    			t1.update(1, 0, NMAX-1, y0, tmp[y0]-x0);
	    		p++;
	    	}
	    	
	    	int q0 = x+tmp[y]+t0.query(1, 0, NMAX-1, 0, y);
	    	int q1 = x-tmp[y]+t1.query(1, 0, NMAX-1, y, NMAX-1);
	    	
	    	if(!fo){
		    	ans[i] = min(ans[i], min(q0, q1));
	    	}
	    	else{
		    	ans[n-i-1] = min(ans[n-i-1], min(q0, q1));
	    	}
	    }
    }
    
    int tot = 0;
    for(auto i : ans) tot += i;
    cout << tot << endl;
}
