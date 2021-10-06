// Problem: E - LEQ
// Contest: AtCoder - AtCoder Beginner Contest 221
// URL: https://atcoder.jp/contests/abc221/tasks/abc221_e
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
const int MOD = 998244353;//1e9 + 7;
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
 
const int NMAX = 3e5 + 10;

struct node{
    
    int val;
    int lazy;
    
    node(){
        val = 0;
        lazy = 1;
    }
    
} tree[NMAX << 2];

void push(int nd, int l, int r){
    
    if(tree[nd].lazy == 1){
        return;
    }    
    
    tree[nd].val = mul(tree[nd].val, tree[nd].lazy);
    
    if(l != r){
        tree[nd*2].lazy = mul(tree[nd*2].lazy, tree[nd].lazy);
        tree[nd*2+1].lazy = mul(tree[nd*2+1].lazy, tree[nd].lazy);
    }
    
    tree[nd].lazy = 1;
}

int query(int nd, int l, int r, int q_l, int q_r){
    
    push(nd, l, r);
    
    if(r < q_l || q_r < l){
        return 0;
    }    
    
    if(q_l <= l && r <= q_r){
        return tree[nd].val;
    }
    
    int mid = (l+r)/2;
    int st_path = query(nd*2, l, mid, q_l, q_r);
    int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return add(st_path, nd_path);
}

void update(int nd, int l, int r, int p, int val_add){
    
    push(nd, l, r);
    
    if(p < l || r < p){
        return;
    }    
    
    if(l == r){
        tree[nd].val = add(tree[nd].val, val_add);
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, p, val_add);
    update(nd*2+1, mid+1, r, p, val_add);
    
    tree[nd].val = add(tree[nd*2].val, tree[nd*2+1].val);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    vi vec(n), comp;
    for(auto &i : vec) cin >> i, comp.push_back(i);
    
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    for(auto &i : vec) i = lower_bound(comp.begin(), comp.end(), i) - comp.begin();
    
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        ans = add(ans, query(1, 0, n-1, 0, vec[i]));
        tree[1].lazy = mul(tree[1].lazy, 2);
        update(1, 0, n-1, vec[i], +1);
    }
    
    cout << ans << endl;
}
