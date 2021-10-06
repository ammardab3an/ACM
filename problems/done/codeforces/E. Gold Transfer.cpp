// Problem: E. Gold Transfer
// Contest: Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1535/problem/E
// Memory Limit: 256 MB
// Time Limit: 4500 ms
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

// #define endl '\n'
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

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 3e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int q;
int ton[NMAX], cost[NMAX];
int par[NMAX][LOG_MAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> q >> ton[0] >> cost[0];
    
    int LOG = ceil(log2(double(q)));
    memset(par, -1, sizeof par);
    
    for(int i = 1; i <= q; i++){
        
        int x;
        cin >> x;
        
        if(x == 1){
            
            int p, a, c;
            cin >> p >> a >> c;
            
            par[i][0] = p;
            for(int j = 1; j < LOG; j++) if(par[i][j-1] != -1)
                par[i][j] = par[par[i][j-1]][j-1];
            
            ton[i] = a;
            cost[i] = c;
        }
        else{
            
            int v, w;
            cin >> v >> w;
            
            int u = v;
            int dist = 0;
            for(int i = LOG-1; i >= 0; i--) if(par[u][i] != -1){
                if(ton[par[u][i]] > 0){
                    dist += 1 << i;
                    u = par[u][i];
                }
            }
            
            int tot_take = 0;
            int tot_cost = 0;
            
            while(w && dist >= 0){
                
                int u = v;
                for(int i = 0; i < LOG; i++) if(dist & (1 << i)){
                    u = par[u][i];
                }
                
                int take = min(ton[u], w);
                
                tot_take += take;
                tot_cost += take * cost[u];
                
                ton[u] -= take;
                w -= take;
                dist--;
            }
            
            cout << tot_take << ' ' << tot_cost << endl;
        }
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
