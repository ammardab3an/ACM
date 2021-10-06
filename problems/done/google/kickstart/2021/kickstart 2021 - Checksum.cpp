// Problem: Checksum
// Contest: Google Coding Competitions - Round A 2021 - Kick Start 2021
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068c2c3
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
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

int n;
int grid[555][555];
int cost[555][555];
int xor_r[555];
int xor_c[555];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int tt = 1;
    int t; cin >> t; while(t--){
        
        cin >> n;        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> grid[i][j];
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> cost[i][j];
        
        for(int i = 0; i < n; i++) cin >> xor_r[i];
        for(int i = 0; i < n; i++) cin >> xor_c[i];
        
        vi par(n+n);
        for(int i = 0; i < n+n; i++) par[i] = i;
        
        function<int(int)> get_par = [&](int u){
            return par[u] == u ? u : par[u] = get_par(par[u]);
        };
        
        vector<iii> edges;
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) if(grid[i][j] == -1){
            edges.emplace_back(cost[i][j], (pii){i, n+j});
        }
        
        sort(edges.begin(), edges.end(), greater<iii>());
        
        auto merge = [&](int u, int v){
            
            int par_u = get_par(u);
            int par_v = get_par(v);
            
            if(par_u == par_v)
                return false;
            
            if(rand()&1){
                par[par_u] = par_v;
            }
            else{
                par[par_v] = par_u;
            }
            
            return true;
        };
        
        int ans = 0;
        
        for(auto edge : edges){
            
            int u = edge.second.first;
            int v = edge.second.second;
            int c = edge.first;
            
            if(!merge(u, v))
                ans += c;
        }
        
        cout << "Case #" << tt++ << ": ";
        cout << ans << endl;
    }	
}
