// Problem: Point Set Range Composite
// Contest: Library Checker
// URL: https://judge.yosupo.jp/problem/point_set_range_composite
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
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
const int MOD = 998244353; //1e9 + 7;
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
const int NMAX = 5e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct f{
    int a, b;
} fun[NMAX];

f tree[NMAX << 2];

f merge(const f &f0, const f &f1){
    f ret;
    ret.a = mul(f0.a, f1.a);
    ret.b = add(mul(f1.a, f0.b), f1.b);
    return ret;
}

void build(int nd, int l, int r){
    
    if(l == r){
        tree[nd] = fun[l];
        return;
    }
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int p, f fn){
    
    if(p < l || r < p){
        return;
    }
    
    if(l == r){
        tree[nd] = fun[l] = fn;
        return;
    }    
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, p, fn);
    update(nd*2+1, mid+1, r, p, fn);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

f query(int nd, int l, int r, int q_l, int q_r){
    
    if(r < q_l || q_r < l){
        return {1, 0};
    }    
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    }
    
    int mid = (l+r)/2;
    f st_path = query(nd*2, l, mid, q_l, q_r);
    f nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return merge(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, q;
    cin >> n >> q; 
    
    for(int i = 0; i < n; i++){
        cin >> fun[i].a >> fun[i].b;
    }
    
    build(1, 0, n-1);
    
    while(q--){
        
        int k;
        cin >> k;
        
        if(k == 0){
            int p, a, b;
            cin >> p >> a >> b;
            update(1, 0, n-1, p, (f){a, b});
        }
        else{
            int l, r, x;
            cin >> l >> r >> x;
            f que = query(1, 0, n-1, l, r-1);
            int ans = add(mul(que.a, x), que.b);
            cout << ans << endl;
        }
    }
}
