// Problem: D. Nearest Excluded Points
// Contest: Codeforces - Educational Codeforces Round 124 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1651/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
 
const int NMAX = 2e5 + 10;
const pii mvArr[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct segTree{
	
	vector<iii> tree;
	
	segTree(int n){
		tree.resize(n<<2, (iii){INFLL, {}});
	}	
	
	void update(int nd, int l, int r, int p, iii val){
		
		if(p < l || r < p){
			return;
		}
		
		if(l==r){
			tree[nd] = min(tree[nd], val);
			return;
		}
		
		int mid = (l+r)/2;
		update(nd*2, l, mid, p, val);
		update(nd*2+1, mid+1, r, p, val);
		

		tree[nd] = min(tree[nd*2], tree[nd*2+1]);
	}
	
	iii query(int nd, int l, int r, int q_l, int q_r){
		
		if(r < q_l || q_r < l){
			return {INFLL, {}};
		}
		
		if(q_l <= l && r <= q_r){
			return tree[nd];
		}
		
		int mid = (l+r)/2;
		iii st_path = query(nd*2, l, mid, q_l, q_r);
		iii nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
		
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
    
    int n;
    cin >> n;
    
    vpii blue(n);
    for(auto &[x, y] : blue){
    	cin >> x >> y;
    }
    
    vi pos(n);
    iota(pos.begin(), pos.end(), 0);
    sort(pos.begin(), pos.end(), [&](int i, int j){
    	return blue[i] < blue[j];
    });
    
    sort(blue.begin(), blue.end());
    
    vpii red;
    for(auto [x, y] : blue){
    	
    	for(auto p : mvArr){
    		int nx = x + p.first;
    		int ny = y + p.second;
    		if(!binary_search(blue.begin(), blue.end(), (pii){nx, ny})){
    			red.push_back({nx, ny});
    		}
    	}
    }
    
    sort(red.begin(), red.end());
    red.resize(unique(red.begin(), red.end())-red.begin());
    
    vector<iii> ans(n, {INFLL, {}});
    
    for(auto k : {0, 1}){
    	
    	if(k){
    		for(auto &[x, y] : blue) x *= -1;
    		for(auto &[x, y] : red) x *= -1;
    		reverse(blue.begin(), blue.end());
    		reverse(red.begin(), red.end());
    	}
    	
    	segTree s0(NMAX), s1(NMAX);
    	
    	int j = 0;
    	for(int i = 0; i < n; i++){
    		
    		while((j < (int)red.size()) && red[j].first <= blue[i].first){
    			auto [x, y] = red[j];
    			s0.update(1, 0, NMAX-1, y, (iii){y-x, {x, y}});
    			s1.update(1, 0, NMAX-1, y, (iii){-y-x, {x, y}});	
    			j++;
    		}
    		
    		auto [x, y] = blue[i];
    		iii st_path = s0.query(1, 0, NMAX-1, y, NMAX-1);
    		iii nd_path = s1.query(1, 0, NMAX-1, 0, y);
    		
    		st_path.first += -y+x;
    		nd_path.first += y+x;
    		
    		if(k){
	    		st_path.second.first *= -1;
	    		nd_path.second.first *= -1;
    		}
    		
    		if(!k){
	    		int p = pos[i];
	    		ans[p] = min(ans[p], min(st_path, nd_path));			
    		}
    		else{
	    		int p = pos[n-i-1];
	    		ans[p] = min(ans[p], min(st_path, nd_path));			
    		}
    	}	
    }
    
    for(auto [v, p] : ans){
    	cout << p.first << ' ' << p.second << endl;
    }
}
