// Problem: F. One Occurrence
// Contest: Codeforces - Educational Codeforces Round 46 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1000/F
// Memory Limit: 768 MB
// Time Limit: 3000 ms
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
const int AMAX = 5e5 + 10;

int n, m;
int arr[NMAX];
vpii queries[AMAX];
pii tree[AMAX << 2];
pii lst[AMAX];
int ans[NMAX];

void update(int nd, int l, int r, int p, int val){
	
	if(p < l || r < p){
		return;
	}	
	
	if(l==r){
		tree[nd] = {val, l};
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, p, val);
	update(nd*2+1, mid+1, r, p, val);
	
	tree[nd] = min(tree[nd*2], tree[nd*2+1]);
}

pii query(int nd, int l, int r, int q_l, int q_r){
	
	if(q_r < l || r < q_l){
		return {INF, INF};
	}
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	pii st_path = query(nd*2, l, mid, q_l, q_r);
	pii nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return min(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    cin >> m;
    for(int i = 0; i < m; i++){
    	int l, r;
    	cin >> l >> r;
    	l--, r--;
    	queries[r].push_back({i, l});
    }
    
    fill(begin(lst), end(lst), (pii){-1, -1});
    fill(begin(tree), end(tree), (pii){-1, -1});
    
    for(int i = 0; i < n; i++){
    	
    	if(lst[arr[i]].second==-1){
    		update(1, 0, n-1, i, -INF);
    		lst[arr[i]] = {i, i};
    	}
    	else{
	    	update(1, 0, n-1, lst[arr[i]].first, INF);
	    	update(1, 0, n-1, i, lst[arr[i]].first);
	    	lst[arr[i]].second = lst[arr[i]].first;
	    	lst[arr[i]].first = i;
    	}
    	
    	for(auto [p, l] : queries[i]){
    		
    		pii q = query(1, 0, n-1, l, i);

    		if(q.first < l){
				ans[p] = arr[q.second];
    		}
    		else{
    			ans[p] = 0;
    		}
    	}
    }
    
    for(int i = 0; i < m; i++){
    	cout << ans[i] << endl;
    }
}
