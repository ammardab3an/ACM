// Problem: D. 0-1 MST
// Contest: Codeforces - Codeforces Round #599 (Div. 2)
// URL: https://codeforces.com/contest/1243/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int par[NMAX];
int sz[NMAX];
vi adj[NMAX];

int get_par(int n){
    return par[n] == n ? n : par[n] = get_par(par[n]);
}

bool same(int u, int v){
    return get_par(u) == get_par(v);
}

bool merge(int u, int v){
    
    if(same(u, v)) return false;
    
    int par_u = get_par(u);
    int par_v = get_par(v);
    
    if(sz[par_u] > sz[par_v]) swap(par_u, par_v);
    
    par[par_u] = par_v;
    sz[par_v] += sz[par_u];
    
    return true;    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int cnt = n;
    set<int> st;
    for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    
    for(int i = 1; i <= n; i++){
        
        vi tmp;
        
        for(int j : st){
            
            int ccnt = 0;
            int par_j = get_par(j);
            
            for(auto v : adj[i]){
                int par_v = get_par(v);
                if(par_v == par_j){
                    ccnt++;
                }
            }
            
            if(ccnt < sz[par_j]){
                tmp.push_back(j);
                merge(i, j);
                cnt--;
            }
        }
        
        for(auto i : tmp) st.erase(i);
        st.insert(i);
    }
    
    cout << cnt-1 << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
