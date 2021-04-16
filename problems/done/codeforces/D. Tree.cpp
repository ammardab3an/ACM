// Problem: D. Tree
// Contest: Codeforces - ICM Technex 2018 and Codeforces Round #463 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/problemset/problem/932/D
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

const int NMAX = 4e5 + 10;

const int LOG = ceil(log2(NMAX));

int weight[NMAX];
int par[NMAX][LOG];
int par_sum[NMAX][LOG];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int cur = 1;
    int lst = 0;
    
    weight[0] = INFLL;
    for(int i = 0; i < LOG; i++) par_sum[1][i] = INFLL;
    
    int t; cin >> t; while(t--){
        
        int k, p, q;
        cin >> k >> p >> q;
        
        if(k == 1){
            
            int r = p^lst;
            int w = q^lst;
            
            cur++;
            
            weight[cur] = w;
            
            if(weight[r] >= w){
                par[cur][0] = r;
            }
            else{
                for(int i = LOG-1; i >= 0; i--){
                    if(weight[par[r][i]] < w){
                        r = par[r][i];
                    }
                }
                par[cur][0] = par[r][0];
            }
            
            par_sum[cur][0] = par[cur][0] == 0 ? INFLL : weight[par[cur][0]];
            
            for(int i = 1; i < LOG; i++){
                par[cur][i] = par[par[cur][i-1]][i-1];
                par_sum[cur][i] = par[cur][i-1] == 0 ? INFLL : par_sum[cur][i-1] + par_sum[par[cur][i-1]][i-1];
            }
        }
        
        else{
            
            int r = p^lst;
            int x = q^lst;
            
            int &ans = lst;
            
            ans = 0;
            
            if(weight[r] > x){
                cout << ans << endl;
                continue;
            }
            
            ans = 1;
            x -= weight[r];
            
            for(int i = LOG-1; i >= 0; i--){
                if(par_sum[r][i] <= x){
                    ans += 1 << i;
                    x -= par_sum[r][i];
                    r = par[r][i];
                }
            }
            
            cout << ans << endl;
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
