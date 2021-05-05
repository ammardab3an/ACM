// Problem: F. Asya And Kittens
// Contest: Codeforces - Codeforces Round #541 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1131/F
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
int par[NMAX];
int id[NMAX];
vi gr[NMAX];

int get_par(int n){
    return par[n] == n ? n : par[n] = get_par(par[n]);
}

bool merge(int u, int v){
    
    int par_u = get_par(u);
    int par_v = get_par(v);
    
    if(par_u == par_v) return false;
    
    int sz_u = gr[id[par_u]].size();
    int sz_v = gr[id[par_v]].size();
    
    if(sz_u > sz_v){
        swap(par_u, par_v);
    }
    
    for(auto i : gr[id[par_u]]){
        id[i] = par_v;
        gr[id[par_v]].push_back(i);
    }
    
    par[par_u] = par_v;
    
    return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        id[i] = i;
        gr[i].push_back(i);
        par[i] = i;
    }
    
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }   
    
    for(auto i : gr[id[get_par(1)]]){
        cout << i << ' ';
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
