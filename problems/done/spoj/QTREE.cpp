// Problem: Query on a tree
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/QTREE/
// Memory Limit: 1536 MB
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
 
const int NMAX = 1e4 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));

int n, LOG;
vi adj[NMAX], dis[NMAX], idx[NMAX];
int baseArr[NMAX], baseSz;
int chainNo, chainHead[NMAX], chainInd[NMAX], posInBase[NMAX];
int par[NMAX][LOG_MAX], sz[NMAX], depth[NMAX], otherEnd[NMAX];
int tree[NMAX << 2];

void build(int nd, int l, int r){
    
    if(l == r){
        tree[nd] = baseArr[l];
        return;
    }
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    
    tree[nd] = max(tree[nd*2], tree[nd*2+1]);
}

int query(int nd, int l, int r, int q_l, int q_r){
    
    if(l > q_r || q_l > r) return -1;
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    }
    
    int mid = (l+r)/2;
    int stPath = query(nd*2, l, mid, q_l, q_r);
    int ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return max(stPath, ndPath);    
}

void update(int nd, int l, int r, int p, int val){
    
    if(p < l || r < p)
        return;
        
    if(l == r){
        tree[nd] = val;
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, p, val);
    update(nd*2+1, mid+1, r, p, val);
    
    tree[nd] = max(tree[nd*2], tree[nd*2+1]);
}

int query_up(int u, int v){
    
    if(u == v) return 0;
    int uchain, vchain = chainInd[v], ans = -1;
    
    while(true){
        
        uchain = chainInd[u];
        
        if(uchain == vchain){
            if(u == v) break;
            int que = query(1, 0, baseSz-1, posInBase[v]+1, posInBase[u]);
            ans = max(ans, que);
            break;
        }
        
        int que = query(1, 0, baseSz-1, posInBase[chainHead[uchain]], posInBase[u]);
        ans = max(ans, que);
        
        u = par[chainHead[uchain]][0];
    }
    
    return ans;
}

int LCA(int u, int v){
    
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

void HLD(int nd, int cost, int p){
    
    if(chainHead[chainNo] == -1){
        chainHead[chainNo] = nd;
    }
    
    chainInd[nd] = chainNo;
    posInBase[nd] = baseSz;
    baseArr[baseSz++] = cost;
    
    int sc = -1, sc_cost;
    for(int i = 0; i < adj[nd].size(); i++) if(adj[nd][i] != p){   
        if(sc == -1 || sz[sc] < sz[adj[nd][i]]){
            sc = adj[nd][i], sc_cost = dis[nd][i];
        }
    }
    
    if(sc != -1){
        HLD(sc, sc_cost, nd);
    }
    
    for(int i = 0; i < adj[nd].size(); i++) if(adj[nd][i] != p) if(adj[nd][i] != sc){
        
        chainNo++;
        HLD(adj[nd][i], dis[nd][i], nd);
    }
}

void dfs(int nd, int p){
    
    sz[nd] = 1;
    
    for(int i = 0; i < adj[nd].size(); i++) if(adj[nd][i] != p){
        
        int nxt = adj[nd][i];
    
        otherEnd[idx[nd][i]] = nxt;
    
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
    
    int t; cin >> t; while(t--){

        int n;
        cin >> n;
        
        LOG = ceil(log2(double(n)));
        
        init:{
            baseSz = 0;
            chainNo = 0;
            memset(par, -1, sizeof par);
            
            for(int i = 0; i < n; i++){
                adj[i].clear();
                dis[i].clear();
                idx[i].clear();
                chainHead[i] = -1;
            }
        }
        
        for(int i = 0; i < n-1; i++){
            int u, v, d;
            cin >> u >> v >> d; 
            u--, v--;
            adj[u].push_back(v);
            dis[u].push_back(d);
            idx[u].push_back(i);
            swap(u, v);
            adj[u].push_back(v);
            dis[u].push_back(d);
            idx[u].push_back(i);
        }
        
        dfs(0, -1);
        HLD(0, -1, -1);
        build(1, 0, baseSz-1);
        
        while(true){
            
            string com;
            cin >> com;
            
            if(com == "QUERY"){
                
                int u, v;
                cin >> u >> v;
                u--, v--;
                
                int p = LCA(u, v);
                
                int stPath = query_up(u, p);
                int ndPath = query_up(v, p);
                
                cout << max(stPath, ndPath) << endl;
                
            }   
            else if(com == "CHANGE"){
                
                int u, new_dis;
                cin >> u >> new_dis;
                u--;
                
                update(1, 0, baseSz-1, posInBase[otherEnd[u]], new_dis);
            } 
            else{
                break;
            }
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
