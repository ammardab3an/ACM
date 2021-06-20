// Problem: Topological Sorting
// Contest: SPOJ - Tutorial
// URL: https://www.spoj.com/problems/TOPOSORT/en/
// Memory Limit: 1536 MB
// Time Limit: 500 ms
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m;
vi adj[NMAX];
stack<int> st;
int vis[NMAX];
bool bad = false;

void dfs(int nd){
    
    if(bad) return;
        
    vis[nd] = -1;
    
    for(auto nxt : adj[nd]){
        
        if(vis[nxt] == -1){
            bad = true;
            return;
        }
        
        if(vis[nxt] == 0){
            dfs(nxt);
        }
    }
    
    vis[nd] = 1;
    
    st.push(nd);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    
    for(int i = 0; i < n; i++) 
        sort(adj[i].begin(), adj[i].end(), greater<int>());
        
    for(int i = n-1; i >= 0; i--) if(!vis[i])
        dfs(i);
    
    if(bad){
        cout << "Sandro fails." << endl;
    }
    else{
        while(!st.empty()){
            cout << st.top()+1 << ' ';
            st.pop();
        }
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
