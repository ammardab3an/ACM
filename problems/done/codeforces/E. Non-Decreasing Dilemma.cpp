// Problem: E. Non-Decreasing Dilemma
// Contest: Codeforces - Codeforces Round #742 (Div. 2)
// URL: https://codeforces.com/contest/1567/problem/E
// Memory Limit: 256 MB
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
    
    int ans, sz;
    int pre_val, pre_cnt;
    int suf_val, suf_cnt;
    
    node(){
        ans = -1;
    }    
};

int arr[NMAX];
node tree[NMAX << 2];

node merge(const node &a, const node &b){
    
    node ret;
    
    ret.sz = a.sz + b.sz;
    ret.ans = a.ans + b.ans;
    
    ret.pre_val = a.pre_val;
    ret.pre_cnt = a.pre_cnt;
    ret.suf_val = b.suf_val;
    ret.suf_cnt = b.suf_cnt;
    
    if(a.suf_val <= b.pre_val){
        
        ret.ans += a.suf_cnt * b.pre_cnt;
        
        if(b.suf_cnt == b.sz){
            ret.suf_cnt += a.suf_cnt;
        } 
        
        if(a.pre_cnt == a.sz){
            ret.pre_cnt += b.pre_cnt;
        }
    }
    
    
    return ret;
}

void build(int nd, int l, int r){
    
    if(l==r){
        node &tmp = tree[nd];
        tmp.pre_val = arr[l];
        tmp.suf_val = arr[l];
        tmp.ans = tmp.sz = tmp.pre_cnt = tmp.suf_cnt = 1;
        return;
    }   
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]); 
}

void update(int nd, int l, int r, int p, int val){
    
    if(p < l || r < p) return;
    
    if(l==r){
        node &tmp = tree[nd];
        tmp.pre_val = arr[l];
        tmp.suf_val = arr[l];
        tmp.ans = tmp.sz = tmp.pre_cnt = tmp.suf_cnt = 1;
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, p, val);
    update(nd*2+1, mid+1, r, p, val);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

node query(int nd, int l, int r, int q_l, int q_r){
    
    if(r < q_l || q_r < l){
        return node();
    }    
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    }
    
    int mid = (l+r)/2;
    node st_path = query(nd*2, l, mid, q_l, q_r);
    node nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
    
    if(st_path.ans != -1 && nd_path.ans != -1) 
        return merge(st_path, nd_path);
    if(st_path.ans != -1)
        return st_path;
    if(nd_path.ans != -1)
        return nd_path;
        
    assert(false);
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
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    build(1, 0, n-1);
    
    while(m--){
        
        int k;
        cin >> k;
        
        if(k==1){
            
            int p, val;
            cin >> p >> val;
            p--;
            
            update(1, 0, n-1, p, arr[p] = val);
        }
        else{
            
            int q_l, q_r;
            cin >> q_l >> q_r;
            q_l--, q_r--;
            
            node que = query(1, 0, n-1, q_l, q_r);
            cout << que.ans << endl;
        }
    }   
}
