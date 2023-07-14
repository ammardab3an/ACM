// Problem: G. Periodic RMQ Problem
// Contest: Codeforces - Educational Codeforces Round 20
// URL: https://codeforces.com/contest/803/problem/G
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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
 
const int NMAX = 1e6 + 10;

struct sparse_table{
    
    vector<int> lg2;
    vector<vi> st;
    vi arr;
    
    sparse_table(){};
    
    sparse_table(int n, const vi &_arr){
        
        arr = _arr;
        int k = ceil(log2(double(n)));
        st.resize(n, vi(k+1));
        
        for (int i = 0; i < n; i++){
            st[i][0] = i;
        }

        for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << j) <= n; i++){
            if(arr[st[i][j-1]] < arr[st[i+(1<<(j-1))][j-1]]){
                st[i][j] = st[i][j-1];
            }
            else{
                st[i][j] = st[i+(1<<(j-1))][j-1];
            }
        }
        
        lg2.resize(n+1);
        
        lg2[1] = 0;
        for(int i = 2; i <= n; i++){
            lg2[i] = lg2[i/2] + 1;
        }
    }
        
    int query_range(int l, int r){
        int j = lg2[r-l+1];
        if(arr[st[l][j]] < arr[st[r-(1<<j)+1][j]]){
            return st[l][j];
        }
        else{
            return st[r-(1<<j)+1][j];
        }
    }
    
    int query_range2(int l, int r){
    	return arr[query_range(l, r)];
    }
};

int sz;
int arr[NMAX];

int tree[NMAX << 2];
int lazy[NMAX << 2];

void push(int nd, int l, int r){
	
	if(lazy[nd]==-1){
		return;
	}
	
	tree[nd] = lazy[nd];
	
	if(l != r){
		lazy[nd*2] = lazy[nd*2+1] = lazy[nd];
	}
	
	lazy[nd] = -1;
}

void build(int nd, int l, int r){
	
	if(l==r){
		tree[nd] = arr[l];
		return;
	}	
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = min(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_l, int q_r, int x){
	
	push(nd, l, r);
	
	if(q_r < l || r < q_l){
		return;
	}
	
	if(q_l <= l && r <= q_r){
		lazy[nd] = x;
		push(nd, l, r);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, x);
	update(nd*2+1, mid+1, r, q_l, q_r, x);
	
	tree[nd] = min(tree[nd*2], tree[nd*2+1]);
}

int query(int nd, int l, int r, int q_l, int q_r){
	
	push(nd, l, r);
	
	if(q_r < l || r < q_l){
		return INF;
	}
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	int st_path = query(nd*2, l, mid, q_l, q_r);
	int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return min(st_path, nd_path);
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
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    sparse_table st(n, vec);
    
    int q;
    cin >> q;
    
    vi tmp;
    vector<vi> queries(q);
    for(int i = 0; i < q; i++){
    	
    	int k, l, r;
    	cin >> k >> l >> r;
    	l--;
    	
		tmp.push_back(l);
		tmp.push_back(r);
		
    	if(k==1){
    		int x;
    		cin >> x;
    		queries[i] = {1, l, r, x};
    	}
    	else{
    		queries[i] = {2, l, r};
    	}
    }
    
    tmp.push_back(0);
    tmp.push_back(n*m);
    
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    
    for(auto &q : queries){
    	q[1] = lower_bound(tmp.begin(), tmp.end(), q[1])-tmp.begin();
    	q[2] = lower_bound(tmp.begin(), tmp.end(), q[2])-tmp.begin();
    }
    
    sz = int(tmp.size())-1;
    for(int i = 0; i < sz; i++){
    	
    	int l = tmp[i];
    	int r = tmp[i+1]-1;
    	
    	l %= n;
    	r %= n;
    	
 		if(l <= r){		
	    	arr[i] = st.query_range2(l, r);
 		}   	
 		else{
 			int st_path = st.query_range2(l, n-1);
 			int nd_path = st.query_range2(0, r);
 			arr[i] = min(st_path, nd_path);
 		}
    }
    
    build(1, 0, sz-1);
    memset(lazy, -1, sizeof lazy);
    
    for(auto q : queries){
    	
    	int k = q[0], l = q[1], r = q[2];
    	
    	if(k==1){
    		int x = q[3];
    		update(1, 0, sz-1, l, r-1, x);
    	}
    	else{
    		cout << query(1, 0, sz-1, l, r-1) << endl;
    	}
    }
}
