
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

const int NMAX = 5e5 + 10;
const int AMAX = 5e5 + 10;

pii tree[NMAX << 2];

pii comp(pii a, pii b){
	if(a.first != b.first){
		return a.first>b.first ? a : b;
	}
	return a.second < b.second ? a : b;
}

void build(int nd, int l, int r){
	
	if(l==r){
		tree[nd] = {0, -1};
		return ;
	}
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = {0, -1};
}

void update(int nd, int l, int r, int p, int val, int idx){
	
	if(p < l || r < p){
		return;
	}
	
	if(l==r){
		tree[nd].first = val;
		tree[nd].second = idx;
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, p, val, idx);
	update(nd*2+1, mid+1, r, p, val, idx);
	
	tree[nd] = comp(tree[nd*2], tree[nd*2+1]);
}

pii query(int nd, int l, int r, int q_l, int q_r){
	
	if(q_r < l || r < q_l){
		return {0, -1};
	}
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	pii st_path = query(nd*2, l, mid, q_l, q_r);
	pii nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return comp(st_path, nd_path);
}

struct sparse_table{
    
    vector<int> lg2;
    vector<vi> st;
    
    sparse_table(){};
    
    sparse_table(int n, vector<int> &arr){
        
        int k = ceil(log2(double(n)));
        st.resize(n, vi(k+1));
        
        for (int i = 0; i < n; i++){
            st[i][0] = i;
        }

        for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << j) <= n; i++){
            if(arr[st[i][j-1]] > arr[st[i+(1<<(j-1))][j-1]]){
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
        
    int query_range(int l, int r, vector<int> &arr){
        int j = lg2[r-l+1];
        if(arr[st[l][j]] > arr[st[r-(1<<j)+1][j]]){
            return st[l][j];
        }
        else{
            return st[r-(1<<j)+1][j];
        }
    }
    
};


int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		build(1, 0, n-1);
		sparse_table st(n, vec);
		
		for(int i = 0; i < n; i++){
			
			pii que = query(1, 1, AMAX, 0, vec[i]-1);
			int cans = que.first + 1;
			
			if(que.second+1 < i){
				int j = st.query_range(que.second+1, i-1, vec);
				if(vec[j] >= vec[i]) cans++;
			}
			
			update(1, 1, AMAX, vec[i]-1, cans, i);
		}
		
		pii que = query(1, 0, n-1, 0, n-1);
		cout << que.first << endl;
    }	
}
