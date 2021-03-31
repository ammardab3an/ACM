// Problem: C. Experience
// Contest: Codeforces - ITMO Academy: pilot course - Disjoint Sets Union - Step 1
// URL: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
// Memory Limit: 64 MB
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

const int NMAX = 2e5 + 10;

struct node{
    int par, old_par, old, val, sz;
    node(){}
    node(int nd){
        par = nd;
        old = 0;
        old_par = 0;
        val = 0;
        sz = 1;
    }
};

int n, m;
node par[NMAX];

int get_par(int nd){
    return par[nd].par = par[nd].par == nd ? nd : get_par(par[nd].par);
}

int get_val(int nd){
    if(par[nd].par == nd) return par[nd].val;
    return get_val(par[nd].old_par) - par[nd].old + par[nd].val;
}

void merge(int u, int v){
    
    int par_u = get_par(u);
    int par_v = get_par(v);
    
    if(par_u == par_v) return;
    
    if(par[par_u].sz < par[par_v].sz)
        swap(par_u, par_v);
    
    par[par_u].par = par[par_v].par;
    par[par_u].old = par[par_v].val;
    par[par_u].old_par = par[par_v].par;
    par[par_v].sz += par[par_u].sz;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) par[i] = node(i);
    
    while(m--){
        
        string str;
        cin >> str;
        
        if(str[0] == 'a'){
            int nd, x;
            cin >> nd >> x;
            par[get_par(nd)].val += x;
        }
        
        else if(str[0] == 'j'){
            int u, v;
            cin >> u >> v;
            merge(u, v);
        }
        
        else{
            int nd;
            cin >> nd;
            cout << get_val(nd) << endl;
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
