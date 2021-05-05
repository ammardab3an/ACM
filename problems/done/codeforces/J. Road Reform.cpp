// Problem: J. Road Reform
// Contest: Codeforces - 2020-2021 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules)
// URL: https://codeforces.com/problemset/problem/1468/J
// Memory Limit: 512 MB
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m, k;
iii edges[NMAX];
int par[NMAX];

int get_par(int n){
    return par[n] == n ? n : par[n] = get_par(par[n]);
}

int merge(int u, int v){
    
    int par_u = get_par(u);
    int par_v = get_par(v);
    
    if(par_u == par_v) return false;
    
    if(rand()&1) swap(par_u, par_v);
    
    par[par_u] = par_v;
    
    return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        cin >> n >> m >> k;
        
        int near_tp = INF;
        int near_be = -INF;
        
        for(int i = 0; i < m; i++){
            
            int u, v, d;
            cin >> u >> v >> d;
            edges[i] = {d, {--u, --v}};
            
            if(d >= k){
                near_tp = min(near_tp, d);
            }
            if(d <= k){
                near_be = max(near_be, d);
            }
        }
        
        for(int i = 0; i < n; i++) par[i] = i;
        
        sort(edges, edges+m);
        
        int mst = 0;
        int mx = 0;
        
        for(int i = 0; i < m; i++){
            int d = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            if(merge(u, v)){
                if(d > k)
                    mst += d-k;;
                mx = d;
            }
        }
        
        if(mx < k){
            mst = min(k-near_be, near_tp-k);
        }
        
        cout << mst << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
