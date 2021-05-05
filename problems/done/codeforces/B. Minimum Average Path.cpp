// Problem: B. Minimum Average Path
// Contest: Codeforces - ITMO Academy: pilot course - Binary Search - Step 4
// URL: https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/B
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

const int NMAX = 1e5 + 10;

int n, m;
vpii adj[NMAX];
double dist[NMAX];
int par[NMAX];

bool can(double m){
    
    for(int i = 1; i <= n; i++) dist[i] = 1e18;
    
    priority_queue< pair<double, int> > que;
    
    dist[1] = 0;
    que.push({0, 1});
    
    while(!que.empty()){
        
        auto tp = que.top(); que.pop();
        
        int cn = tp.second;
        double cd = tp.first;
        cd *= -1;
        
        if(cd > dist[cn]) continue;
        
        // if(cn == n) break;
        
        for(auto p : adj[cn]){
            
            int nn = p.second;
            double nd = p.first - m;
            
            if(dist[nn] > cd + nd){
                dist[nn] = cd + nd;
                que.push({-dist[nn], nn});
                par[nn] = cn;
            }
        }
    }
    
    return dist[n] >= 0;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(c, v);
    }
    
    double l = 0;
    double r = 100;
    
    double ans = -1;
    
    for(int i = 0; i < 100; i++){
        
        double m = (l+r)/2.0;
        
        if(can(m)){
            ans = m;
            l = m;
        }
        else{
            r = m;
        }
    }
    
    vi tmp;
    int cn = n;
    while(cn != 0){
        tmp.push_back(cn);
        cn = par[cn];
    }
    
    cout << tmp.size()-1 << endl;
    reverse(tmp.begin(), tmp.end());
    for(auto i : tmp) cout << i << ' ' ; cout << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
