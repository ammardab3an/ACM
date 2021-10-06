// Problem: B. Disjoint Sets Union 2
// Contest: Codeforces - ITMO Academy: pilot course - Disjoint Sets Union - Step 1
// URL: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
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

const int NMAX = 3e5 + 10;

struct node{
    
    int nd, mn, mx, sm;
    
    node(){}
    
    node(int n){
        nd = mn = mx = n;
        sm = 1;
    }
};

node par[NMAX];

int get_par(int nd){
    if(par[nd].nd == nd) return nd;
    return par[nd].nd = get_par(par[nd].nd);
}

void merge(int u, int v){
    
    int par_u = get_par(u);
    int par_v = get_par(v);
    
    if(par_u == par_v) return;
    
    node *st_par = &par[par_u];
    node *nd_par = &par[par_v];
    
    if(rand()&1){
        swap(st_par, nd_par);
    }
    
    nd_par->nd = st_par->nd;
    st_par->sm += nd_par->sm;
    st_par->mn = min(st_par->mn, nd_par->mn);
    st_par->mx = max(st_par->mx, nd_par->mx);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) par[i] = node(i);
    
    while(m--){
        
        int u, v;
        string str;
        
        cin >> str >> u;
        
        if(str[0] == 'u'){
            cin >> v;
            merge(u, v);
        }
        else{
            auto tmp = par[get_par(u)];
            cout << tmp.mn << ' ' << tmp.mx << ' ' << tmp.sm << endl;
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
