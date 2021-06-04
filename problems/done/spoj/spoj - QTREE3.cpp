// Problem: Query on a tree again!
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/QTREE3/
// Memory Limit: 1536 MB
// Time Limit: 2000 ms
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
const int LOG = ceil(log2(double(NMAX)));

int n, q;
int col[NMAX];
vi adj[NMAX];

vector<vi> bit;
vector<vi> ndInTree;

int sz[NMAX], depth[NMAX], par[NMAX][LOG];
int chainNo, chainHead[NMAX], chainInd[NMAX], posInChain[NMAX];

int bit_sum(int b, int r){
    int ret = 0;
    for(; r >= 0; r = (r&(r+1))-1)
        ret += bit[b][r];
    return ret;
}

int bit_range(int b, int l, int r){
    return bit_sum(b, r) - bit_sum(b, l-1);
}

void bit_add(int b, int idx, int val){
    int n = bit[b].size();
    for(; idx < n; idx = idx | (idx+1))
        bit[b][idx] += val;
}

int query_bit(int b, int l, int r){
    
    if(l == r){   
        int u = ndInTree[b][l];
        return col[u] ? u : -2;
    }
        
    int mid = (l+r)/2;
    int stPath = bit_range(b, l, mid);
    int ndPath = bit_range(b, mid+1, r);
    
    if(stPath) return query_bit(b, l, mid);
    if(ndPath) return query_bit(b, mid+1, r);
    
    return -2;
}

int query(int u){
    
    int p = par[chainHead[chainInd[u]]][0];
    
    if(p != -1){
        int que = query(p);
        if(que != -2) return que;
    }
    
    int que = query_bit(chainInd[u], 0, posInChain[u]);
    
    return que;
}

void hld(int nd, int p){
    
    if(chainHead[chainNo] == -1){
        chainHead[chainNo] = nd;
    }
    
    chainInd[nd] = chainNo;
    posInChain[nd] = bit[chainNo].size();
    bit[chainNo].push_back(0);
    ndInTree[chainNo].push_back(nd);
    
    int sc = -1;
    for(auto nxt : adj[nd]) if(nxt != p){
        if((sc == -1) || (sz[sc] < sz[nxt]))
            sc = nxt;
    }
    
    if(sc != -1)
        hld(sc, nd);
    
    for(auto nxt : adj[nd]) if(nxt != p) if(nxt != sc){
        
        chainNo++;
        bit.push_back({});
        ndInTree.push_back({});
        hld(nxt, nd);
    }
}

int lca(int u, int v){
    
    if(depth[u] < depth[v]) swap(u, v);
    
    int diff = depth[u] - depth[v];
    
    for(int i = 0; i < LOG; i++) if(diff&(1 << i))
        u = par[u][i];
    
    if(u == v) return u;
    
    for(int i = LOG-1; i >= 0; i--) if(par[u][i] != par[v][i]){
        u = par[u][i];
        v = par[v][i];
    }
    
    return par[u][0];
}

void dfs(int nd, int p){
    
    sz[nd] = 1;
    
    for(auto nxt : adj[nd]) if(nxt != p){
        
        depth[nxt] = depth[nd]+1;
        
        par[nxt][0] = nd;
        for(int i = 1; i < LOG; i++)
            par[nxt][i] = par[par[nxt][i-1]][i-1];
        
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
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    memset(par, -1, sizeof par);
    memset(chainHead, -1, sizeof chainHead);
    
    bit.push_back({});
    ndInTree.push_back({});
    
    dfs(0, -1);
    hld(0, -1);
    
    while(q--){
        
        int x, u;
        cin >> x >> u;
        u--;
        
        if(x == 0){
            if(col[u] == 0){
                bit_add(chainInd[u], posInChain[u], 1);
            }
            else{
                bit_add(chainInd[u], posInChain[u], -1);
            }
            col[u] = !col[u];
        }
        else{
            cout << query(u)+1 << endl;
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
