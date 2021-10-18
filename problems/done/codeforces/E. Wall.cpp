// Problem: E. Wall
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 2 - Step 4
// URL: https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e6 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct node{    

    int max, smax;
    int min, smin;
    
    node(){
        max = min = 0;
        smax = -INF, smin = INF;
    }
};

node tree[NMAX << 2];
int ans[NMAX];

void update_node_max(int nd, int x){
    
    if(tree[nd].max == tree[nd].min){
        tree[nd].max = tree[nd].min = x;
    }
    else if(tree[nd].max == tree[nd].smin){
        tree[nd].max = tree[nd].smin = x;
    }
    else{
        tree[nd].max = x;
    }
}

void update_node_min(int nd, int x){
    
    if(tree[nd].min == tree[nd].max){
        tree[nd].min = tree[nd].max = x;
    }
    else if(tree[nd].min = tree[nd].smax){
        tree[nd].min = tree[nd].smax = x;
    }
    else{
        tree[nd].min = x;
    }
}

void push(int nd){
    
    if(tree[nd].max < tree[nd*2].max){
        update_node_max(nd*2, tree[nd].max);
    }
    
    if(tree[nd].max < tree[nd*2+1].max){
        update_node_max(nd*2+1, tree[nd].max);
    }
    
    if(tree[nd].min > tree[nd*2].min){
        update_node_min(nd*2, tree[nd].min);
    }
    
    if(tree[nd].min > tree[nd*2+1].min){
        update_node_min(nd*2+1, tree[nd].min);
    }
}

node merge(const node &a, const node &b){
    
    node ret;
    
    if(a.max == b.max){
        ret.max = a.max;
        ret.smax = max(a.smax, b.smax);
    }
    else if(a.max > b.max){
        ret.max = a.max;
        ret.smax = max(a.smax, b.max);
    }
    else{
        ret.max = b.max;
        ret.smax = max(a.max, b.smax);
    }
    
    if(a.min == b.min){
        ret.min = a.min;
        ret.smin = min(a.smin, b.smin);
    }
    else if(a.min < b.min){
        ret.min = a.min;
        ret.smin = min(a.smin, b.min);
    }
    else{
        ret.min = b.min;
        ret.smin = min(a.min, b.smin);
    }
    
    return ret;
}

inline void pull(int nd){
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update_min(int nd, int l, int r, int q_l, int q_r, int x){
    
    if(r < q_l || q_r < l || tree[nd].max <= x){
        return;
    }    
    
    if(q_l <= l && r <= q_r && tree[nd].smax < x){
        update_node_max(nd, x);
        return;
    }
    
    push(nd);
    
    int mid = (l+r)/2;
    update_min(nd*2, l, mid, q_l, q_r, x);
    update_min(nd*2+1, mid+1, r, q_l, q_r, x);
    
    pull(nd);
}

void update_max(int nd, int l, int r, int q_l, int q_r, int x){
    
    if(r < q_l || q_r < l || x <= tree[nd].min){
        return;
    }    
    
    if(q_l <= l && r <= q_r && x < tree[nd].smin){
        update_node_min(nd, x);
        return;
    }
    
    push(nd);
    
    int mid = (l+r)/2;
    update_max(nd*2, l, mid, q_l, q_r, x);
    update_max(nd*2+1, mid+1, r, q_l, q_r, x);
    
    pull(nd);
}

void build(int nd, int l, int r){
    
    if(l == r){
        ans[l] = tree[nd].max;
        return;
    }
    
    push(nd);
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
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
    
    while(m--){
    
        int k;
        cin >> k;
        
        if(k == 1){
            int l, r, x;
            cin >> l >> r >> x;
            update_max(1, 0, n-1, l, r, x);
        }
        else{
            int l, r, x;
            cin >> l >> r >> x;
            update_min(1, 0, n-1, l, r, x);
        }
    }
    
    build(1, 0, n-1);
    
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
}
