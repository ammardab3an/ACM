// Problem: J. Segments
// Contest: Codeforces - VK Cup 2018 - Wild-card Round 1
// URL: https://codeforces.com/contest/926/problem/J
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

pii arr[NMAX];
int comp[NMAX*2], comp_sz;

struct node{
    int ans;
    int pre, suf, sz;
    int lazy;   
} tree[(NMAX*2)<<2];

node merge(const node &a, const node &b){
    
    assert(!a.lazy && !b.lazy);
    
    node ret;
    ret.sz = a.sz + b.sz;
    ret.ans = a.ans + b.ans;    
    
    ret.pre = max(a.pre, (a.pre == a.sz) ? a.pre + b.pre : 0);
    ret.suf = max(b.suf, (b.suf == b.sz) ? a.suf + b.suf : 0);
    
    ret.ans -= a.suf && b.pre;
    ret.lazy = 0;
    
    return ret;
}

void push(int nd, int l, int r){
    
    if(!tree[nd].lazy){
        return;
    }    
    
    tree[nd].ans = 1;
    tree[nd].pre = tree[nd].suf = tree[nd].sz;
    
    if(l != r){
        tree[nd*2].lazy = tree[nd*2+1].lazy = 1;
    }
    
    tree[nd].lazy = 0;
}

void build(int nd, int l, int r){
    
    if(l == r){
        node &_nd = tree[nd];
        _nd.sz = 1;
        _nd.ans = _nd.pre = _nd.suf = _nd.lazy = 0;
        return;
    }    
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_l, int q_r){
    
    push(nd, l, r);
    
    if(r < q_l || q_r < l){
        return;
    }
    
    if(q_l <= l && r <= q_r){
        tree[nd].lazy = 1;
        push(nd, l, r);
        return;
    }
    
    if(tree[nd].pre == tree[nd].sz){
        return;
    }    
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r);
    update(nd*2+1, mid+1, r, q_l, q_r);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
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
    
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
        comp[comp_sz++] = arr[i].first;
        comp[comp_sz++] = arr[i].second;
    }
    
    sort(comp, comp+comp_sz);
    comp_sz = unique(comp, comp+comp_sz) - comp;
    
    for(int i = 0; i < n; i++){
        arr[i].first = lower_bound(comp, comp+comp_sz, arr[i].first) - comp;
        arr[i].second = lower_bound(comp, comp+comp_sz, arr[i].second) - comp;
    }
    
    build(1, 0, comp_sz-1);
    
    for(int i = 0; i < n; i++){
        // cout << arr[i].first+1 << ' ' << arr[i].second << endl;
        update(1, 0, comp_sz-1, arr[i].first+1, arr[i].second);
        cout << tree[1].ans << ' ';
    }
}
