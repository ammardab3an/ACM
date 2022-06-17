// Problem: Can you answer these queries II
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/GSS2/
// Memory Limit: 1536 MB
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct node{
	int cur, mx;
	int lazy_cur, lazy_best;
	node(){
		cur=mx=lazy_cur=lazy_best = 0;
	}
};

int n;
int arr[NMAX];
node tree[NMAX << 2];

bool push(int _nd, int l, int r){
	
	auto &nd = tree[_nd];
	
	if(!nd.lazy_cur && !nd.lazy_best){
		return false;
	}	
	
	nd.lazy_best = max(nd.lazy_best, nd.lazy_cur);
	nd.mx = max(nd.mx, nd.cur + nd.lazy_best);
	nd.cur += nd.lazy_cur;
	
	if(l != r){	
		for(auto ch : {&tree[_nd*2], &tree[_nd*2+1]}){
			ch->lazy_best = max(ch->lazy_best, ch->lazy_cur + nd.lazy_best);
			ch->lazy_cur += nd.lazy_cur;
		}
	}
	
	nd.lazy_cur = 0;
	nd.lazy_best = 0;
	
	return true;
}

node merge(const node &a, const node &b){
	
	node ret;
	ret.mx = max(a.mx, b.mx);
	ret.cur = max(a.cur, b.cur);
	ret.lazy_cur=ret.lazy_best = 0;
	
	return ret;
}

void update(int nd, int l, int r, int q_l, int q_r, int x){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return;
	}	
	
	if(q_l <= l && r <= q_r){
		tree[nd].lazy_cur += x;
		push(nd, l, r);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, x);
	update(nd*2+1, mid+1, r, q_l, q_r, x);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

int query(int nd, int l, int r, int q_l, int q_r){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return -INFLL;
	}
	
	if(q_l <= l && r <= q_r){
		return tree[nd].mx;
	}
	
	int mid = (l+r)/2;
	int st_path = query(nd*2, l, mid, q_l, q_r);
	int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return max(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    while(cin >> n){
    	
    	memset(tree, 0, sizeof tree);
    	
	    for(int i = 0; i < n; i++){
	    	cin >> arr[i];
	    }
	    
	    int q;
	    cin >> q;
	    vpii queries(q);
	    for(auto &p : queries){
	    	cin >> p.first >> p.second;
	    	p.first--, p.second--;
	    }
	    
	    vi pos(q);
	    iota(pos.begin(), pos.end(), 0);
	    sort(pos.begin(), pos.end(), [&](int i, int j){
	    	return queries[i].second > queries[j].second;
	    });
	    
	    vi ans(q);
	    map<int, int> mp;
	    
	    for(int i = 0; i < n; i++){
	    	
	    	{
		    	auto p = mp.emplace(arr[i], i);
		    	
		    	if(p.second){
		    		update(1, 0, n-1, 0, i, arr[i]);
		    	}	
		    	else{
		    		update(1, 0, n-1, p.first->second+1, i, arr[i]);
		    	}
		    	
		    	p.first->second = i;
	    	}
	    	
	    	while(pos.size() && queries[pos.back()].second==i){
	    		
	    		int p = pos.back();
	    		int l = queries[p].first;
	    		int r = queries[p].second;
	    		pos.pop_back();
				
	    		ans[p] = query(1, 0, n-1, l, r);
	    	}
	    }
	    
	    for(auto i : ans) cout << i << endl;
    }
}
