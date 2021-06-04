// Problem: D. Tree and Queries
// Contest: Codeforces - Codeforces Round #221 (Div. 1)
// URL: https://codeforces.com/problemset/problem/375/D
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 1e5 + 10;
const int MMAX = 1e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m;
vi adj[NMAX];
int col[NMAX];
int base[NMAX];
int sub[NMAX], in[NMAX], t = -1;
int frq[NMAX], cnt[NMAX];
int ans[NMAX];

struct query{    
    int lo, hi, idx, k;
    bool operator < (const query &other){
        if(lo/BLOCK != other.lo/BLOCK) return lo < other.lo;
        return lo/BLOCK % 2 ? hi > other.hi : hi < other.hi;
    }
} queries[MMAX];

struct FenwickTree {
    
    int n;
    vector<int> bit;  // binary indexed tree

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
    
} bit(NMAX);

void add(int c){
    
    if(cnt[c]) bit.add(cnt[c], -1);
    bit.add(++cnt[c], +1);
}

void rem(int c){
    
    bit.add(cnt[c], -1);
    --cnt[c];
    if(cnt[c]) bit.add(cnt[c], +1);
}

void dfs(int u, int p){
    
    in[u] = ++t;
    base[t] = u;
    
    sub[u] = 1;
    
    for(auto v : adj[u]) if(v != p){    
        dfs(v, u);
        sub[u] += sub[v];
    }    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> col[i];
    
    for(int i = 0; i < n-1; i++){
        
        int u, v;
        cin >> u >> v;
        u--, v--;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, -1);
    
    for(int i = 0; i < m; i++){
        
        int u, k;
        cin >> u >> k;
        u--;
        
        queries[i].lo = in[u];
        queries[i].hi = in[u]+sub[u]-1;
        queries[i].k = k;
        queries[i].idx = i;
    }
    
    sort(queries, queries+m);
    
    int l = 1, r = 0;
    
    for(int i = 0; i < m; i++){
        
        int cl = queries[i].lo;
        int cr = queries[i].hi;
        int ci = queries[i].idx;
        int ck = queries[i].k;
        
        while(r < cr) add(col[base[++r]]);
        while(cl < l) add(col[base[--l]]);
        while(cr < r) rem(col[base[r--]]);
        while(l < cl) rem(col[base[l++]]);
    
        ans[ci] += bit.sum(ck, NMAX);
    }
    
    for(int i = 0; i < m; i++) cout << ans[i] << endl;
}

/*
  arrays sizes 
  INFLL & 1ll]
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
