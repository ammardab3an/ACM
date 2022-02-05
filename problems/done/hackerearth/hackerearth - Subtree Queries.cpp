// Problem: Subtree Queries
// Contest: HackerEarth
// URL: https://www.hackerearth.com/problem/algorithm/subtree-queries/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 1e5 + 10;

int n, q;
int arr[NMAX];
vi adj[NMAX];
int posInBase[NMAX];
int base[NMAX];
int sz[NMAX];
int t = -1;
int tree[NMAX << 2];

void build(int nd, int l, int r){
    
    if(l == r){
        tree[nd] = arr[base[l]];
        return;
    }
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    
    tree[nd] = __gcd(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int p, int val){
    
    if(p < l || r < p) return;
    
    if(l == r){
        tree[nd] = val;
        return;
    }    
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, p, val);
    update(nd*2+1, mid+1, r, p, val);
    
    tree[nd] = __gcd(tree[nd*2], tree[nd*2+1]);
}

int query(int nd, int l, int r, int q_l, int q_r){
    
    if(l > q_r || q_l > r) return 0;
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    }    
    
    int mid = (l+r)/2;
    int stPath = query(nd*2, l, mid, q_l, q_r);
    int ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return __gcd(stPath, ndPath);
}

int dfs(int nd, int p){
    
    posInBase[nd] = ++t;
    base[t] = nd;
    
    sz[nd] = 1;
    
    for(auto nxt : adj[nd]) if(nxt != p){
        
        dfs(nxt, nd);
        
        sz[nd] += sz[nxt];
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> q;
    
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, -1);
    
    build(1, 0, n-1);
    
    while(q--){
        
        int x;
        cin >> x;
        
        if(x == 1){
            int pos, val;
            cin >> pos >> val;
            arr[pos-1] = val;
            update(1, 0, n-1, posInBase[pos-1], val);
        }
        else{
            int nd;
            cin >> nd;
            nd--;
            int que = query(1, 0, n-1, posInBase[nd], posInBase[nd]+sz[nd]-1);
            cout << que << endl;
        }
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
