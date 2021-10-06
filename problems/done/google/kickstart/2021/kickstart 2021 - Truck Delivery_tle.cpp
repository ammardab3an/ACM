// Problem: Increasing Substring
// Contest: Google Coding Competitions - Round B 2021 - Kick Start 2021
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a882
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
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

const int  MAX = 2e5 + 10;
const int NMAX = 5e4 + 10;
const int MMAX = 2e5 + 10;

int n, q;
vector<iii> adj[NMAX];
int par[NMAX];
pii tmp[NMAX];

void init(int nd, int p){
    
    for(auto nxt : adj[nd]) if(nxt.first != p){
        par[nxt.first] = nd;
        tmp[nxt.first] = nxt.second;
        init(nxt.first, nd);
    }    
}

int go_up(int nd, int w){
    
    if(nd == 0) return -1;
    if(nd == 1) return -1;
    
    int cgcd = -1;
    
    int p = par[nd];
    int l = tmp[nd].first;
    int a = tmp[nd].second;
    
    if(w >= l) cgcd = a;
    
    int tmp = go_up(p, w);
    
    if(tmp != -1){
        if(cgcd == -1) cgcd = tmp;
        else cgcd = __gcd(cgcd, tmp);
    }
    
    return cgcd;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int tt = 1;
    int t; cin >> t; while(t--){

        cin >> n >> q;
        
        for(int i = 1; i <= n; i++) adj[i].clear();
        for(int i = 1; i <= n; i++) tmp[i] = {0, 0};
        for(int i = 1; i <= n; i++) par[i] = 0;
        
        for(int i = 1; i < n; i++){
            
            int u, v, l, a;
            cin >> u >> v >> l >> a;
            
            adj[u].push_back({v, {l, a}});
            adj[v].push_back({u, {l, a}});
        }
        
        init(1, 0);
        
        cout << "Case #" << tt++ << ": ";
        
        while(q--){
            int c, w;
            cin >> c >> w;
            int tmp = go_up(c, w);
            if(tmp == -1) tmp = 0;
            cout << tmp << ' ' ;
        }
        
        cout << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
