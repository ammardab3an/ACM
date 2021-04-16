
// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

// #define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

class TreeAncestor {
    
public:
    
    int LOG;
    vector< vector<int> > adj;
    vector< vector<int> > par;
    
    TreeAncestor(int n, vector<int>& parent) {
        
        adj.assign(n, vector<int>());
        
        int root = -1;
        
        for(int i = 0; i < n; i++){
            
            if(parent[i] != -1){
                adj[parent[i]].push_back(i);
            }
            else{
                root = i;
            }
        }
        
        LOG = log2(n) + 1;
        
        par.assign(n, vector<int>(LOG, -1));
        
        dfs(root);
    }
    
    void dfs(int nd){
        
        for(auto nxt : adj[nd]){
            
            par[nxt][0] = nd;
            for(int i = 1; i < LOG; i++){
                if(par[nxt][i-1] == -1) break;
                par[nxt][i] = par[par[nxt][i-1]][i-1];
            }
            dfs(nxt);
        }
    }
    
    int getKthAncestor(int node, int k) {
        
        int cur = node;
        
        for(int i = LOG-1; i >= 0; i--) if(k & (1 << i)){
            
            cur = par[cur][i];
            if(cur == -1) break;
        }
        
        return cur;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    
    TreeAncestor* obj = new TreeAncestor(7, {-1, 0, 0, 1, 1, 2, 2});
    int param_1 = obj->getKthAncestor(3, 1);
    
    cout << param_1 << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
