// Problem: 11228 - Transportation system.
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2169
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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

int par[1010];

int getPar(int u){
    return par[u] == u ? u : par[u] = getPar(par[u]);
}

bool samePar(int u, int v){
    return getPar(u) == getPar(v);  
}

void mergeDSU(int u, int v){
    
    if(samePar(u, v)) return;
    
    int parU = getPar(u);
    int parV = getPar(v);
    
    if(rand()&1){
        par[parU] = parV;
    }
    else{
        par[parV] = parU;
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int tt = 1;
    int t; cin >> t; while(t--){
        
        int n, r;
        cin >> n >> r;
        
        vector<pii> vec(n);
        for(auto &p : vec) cin >> p.first >> p.second;
        
        vector< pair< double, pii >  > edges;
        
        for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++){
            
            pii p0 = vec[i];
            pii p1 = vec[j];
            
            double dis = sqrt( pow(p0.first-p1.first, 2) + pow(p0.second-p1.second, 2) );
            
            edges.push_back({dis, {i, j}});
        }
        
        sort(edges.begin(), edges.end());
        
        for(int i = 0; i < n; i++) par[i] = i;
        
        int cnt = 0;
        double totr = 0, totb = 0;
        
        for(int i = 0; i < edges.size(); i++){ // edges.size()
            
            auto p = edges[i];
            
            double cdis = p.first;
            int u = p.second.first;
            int v = p.second.second;
            
            if(!samePar(u, v)){
                mergeDSU(u, v);
                if(cdis > double(r)){
                    cnt++;
                    totr += cdis;
                }
                else{
                    totb += cdis;
                }
            }
        }
        
        cout << "Case #" << tt++ << ": ";
        cout << cnt+1 << ' ' << round(totb) << ' ' << round(totr) << endl;
    }	
}
