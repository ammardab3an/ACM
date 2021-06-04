// Problem: Primitive Queries
// Contest: CodeChef - February Challenge 2017
// URL: https://www.codechef.com/FEB17/problems/DISTNUM3
// Memory Limit: 256 MB
// Time Limit: 6000 ms
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
const int MMAX = 1e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m, LOG;
vi adj[NMAX];
int val[NMAX];
int comp[NMAX+MMAX], comp_sz;
int in[NMAX], out[NMAX];
int depth[NMAX], par[NMAX][LOG_MAX];
int base[NMAX*2], base_sz;
int q_sz, t_sz;
int lo[MMAX], hi[MMAX], idx[MMAX], tim[MMAX], foo[MMAX];
int uold[MMAX], unew[MMAX], uidx[MMAX];
int frq[NMAX+MMAX];
bool vis[NMAX];
int ans[MMAX], cans;

void compress(){
    sort(comp, comp+comp_sz);
    comp_sz = unique(comp, comp+comp_sz) - comp;
    for(int i = 0; i < n; i++){
        val[i] = lower_bound(comp, comp+comp_sz, val[i]) - comp;
    }    
    for(int i = 0; i < t_sz; i++){
        uold[i] = lower_bound(comp, comp+comp_sz, uold[i]) - comp;
        unew[i] = lower_bound(comp, comp+comp_sz, unew[i]) - comp;
    }
}

void dfs(int u, int p){
    
    in[u] = base_sz;
    base[base_sz++] = u;
    
    for(auto v : adj[u]) if(v != p){
        
        depth[v] = depth[u]+1;
        
        par[v][0] = u;
        for(int i = 1; i < LOG; i++)
            par[v][i] = par[par[v][i-1]][i-1];
        
        dfs(v, u);
    }
    
    out[u] = base_sz;
    base[base_sz++] = u;
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u]-depth[v];
    for(int i = 0; i < LOG; i++) if(diff&(1<<i)) u = par[u][i];
    if(u == v) return u;
    for(int i = LOG-1; i >= 0; i--) if(par[u][i] != par[v][i])
        u = par[u][i], v = par[v][i];
    return par[u][0];
}

void add(int u){
    
    vis[u] ^= 1;
    if(vis[u]){
        if(!frq[val[u]]++)
            cans++;
    }
    else{
        if(!--frq[val[u]])
            cans--;
    }
}

void rem(int u){
    add(u);
}

int l = 1, r = 0, &t = t_sz;

void query(int q_idx){
    
    int cl = lo[q_idx];
    int cr = hi[q_idx];
    int ct = tim[q_idx];
    
    while(t < ct){
        
        int u = uidx[t];
        
        if(vis[u]){
            rem(u);
            val[u] = unew[t];
            add(u);    
        }
        else{        
            val[u] = unew[t];
        }
        
        t++;
    }
    
    while(ct < t){
        
        t--;
        
        int u = uidx[t];
        
        if(vis[u]){
            rem(u);
            val[u] = uold[t];
            add(u);    
        }
        else{        
            val[u] = uold[t];
        }
    }
    
    while(r < cr) add(base[++r]);
    while(cl < l) add(base[--l]);
    while(cr < r) rem(base[r--]);
    while(l < cl) rem(base[l++]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> val[i];
        comp[comp_sz++] = val[i];
    }
    
    for(int i = 0; i < n-1; i++){
        
        int u, v;
        cin >> u >> v;
        u--, v--;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    LOG = ceil(log2(double(n)));
    dfs(0, -1);
    
    for(int i = 0; i < m; i++){
        
        int x;
        cin >> x;
        
        if(x == 1){
            
            int u, v;
            cin >> u >> v;
            u--, v--;
            
            if(in[u] > in[v]) swap(u, v);
            
            int p = lca(u, v);
            
            if(p == u){
                lo[q_sz] = in[u];
                hi[q_sz] = in[v];
                foo[q_sz] = -1;
            }
            else{
                lo[q_sz] = out[u];
                hi[q_sz] = in[v];
                foo[q_sz] = p;
            }
            
            idx[q_sz] = q_sz;
            tim[q_sz] = t_sz;
            
            q_sz++;
        }
        
        else{
            
            int u, nval;
            cin >> u >> nval;
            u--;
            
            uold[t_sz] = val[u];
            unew[t_sz] = nval;
            uidx[t_sz] = u;
            
            val[u] = nval;
            
            comp[comp_sz++] = nval;
            
            t_sz++;
        }
    }
    
    compress();
    
    int block = ceil(pow(n, 2.0/3.0));
    sort(idx, idx+q_sz, [block](int i, int j){
        int ilo = lo[i]/block, ihi = hi[i]/block, itim = tim[i]/block; 
        int jlo = lo[j]/block, jhi = hi[j]/block, jtim = tim[j]/block; 
        return tie(ilo, ihi, itim) < tie(jlo, jhi, jtim);
    });
    
    for(int i = 0; i < q_sz; i++){
        
        query(idx[i]);
        ans[idx[i]] = cans;
        
        if(foo[idx[i]] != -1) ans[idx[i]] += frq[val[foo[idx[i]]]] == 0;
    }
    
    for(int i = 0; i < q_sz; i++){
        cout << ans[i] << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
