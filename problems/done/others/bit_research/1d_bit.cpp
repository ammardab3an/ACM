
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

struct bit_1d{
    
    int n;
    vi tree_m, tree_c;
    
    bit_1d(){}
    
    bit_1d(int sz){
        n = sz;
        tree_m = vi(n, 0);
        tree_c = vi(n, 0);
    }
    
    void update(vi &tree, int idx, int delta){
        for (; idx < n; idx = idx | (idx + 1))
            tree[idx] += delta;       
    }
    

    void update_range(int l, int r, int c){
        update(tree_m, l, c);
        update(tree_m, r+1, -c);
        update(tree_c, l, -c*(l-1));
        update(tree_c, r+1, +c*(l-1));
        update(tree_c, r+1, c*(r-l+1));
    }    
    
    int query(vi &tree, int r){   
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += tree[r];
        return ret;
    }
    
    int query_range(int l, int r){
        
        int m = query(tree_m, r);
        int c = query(tree_c, r);
        int x = m*(r) + c;
        
        if(l){
            m = query(tree_m, l-1);
            c = query(tree_c, l-1);
            x -= m*(l-1) + c;
        }
        
        return x;
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

        int n, m, q;
        cin >> n >> m >> q;
        
        bit_1d tree(n);
        
        while(m--){
            
            int l, r, c;
            cin >> l >> r >> c;
            
            tree.update_range(l, r, c);
        }
        
        while(q--){
            
            int l, r;
            cin >> l >> r;
            
            cout << tree.query_range(l, r) << endl;
        }
    }	
}
