// Problem: D. Cutting a graph
// Contest: Codeforces - ITMO Academy: pilot course - Disjoint Sets Union - Step 1
// URL: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int par[NMAX];

int get_par(int nd){
    return par[nd] = par[nd] == nd ? nd : get_par(par[nd]);
}

void merge(int u, int v){
    
    int par_u = get_par(u);
    int par_v = get_par(v);
    
    if(par_u == par_v) return ;
    
    if(rand()&1){
        par[par_u] = par_v;
    }
    else{
        par[par_v] = par_u;
    }
}
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif


    int n, m, q;
    cin >> n >> m >> q;
    
    for(int i = 1; i <= n; i++) par[i] = i;
    
    while(m--){
        int u, v;
        cin >> u >> v;
    }
    
    vector< pair<string, pii> > queries(q);
    for(auto &que : queries) 
        cin >> que.first >> que.second.first >> que.second.second;
        
    reverse(queries.begin(), queries.end());
    
    vector<string> ans;
    
    for(auto que : queries){
         
        int u = que.second.first;
        int v = que.second.second;
        
        if(que.first[0] == 'c'){
            merge(u, v);
        }
        else{
            ans.push_back(get_par(u) == get_par(v) ? "YES" : "NO");
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    for(auto s : ans) cout << s << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
