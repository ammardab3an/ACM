// Problem: D. Help Conan
// Contest: Codeforces - 2018 JUST Programming Contest 1.0
// URL: https://codeforces.com/gym/101778/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int par[22];
int get_par(int u){
    return par[u] = par[u] == u ? u : get_par(par[u]);
}

bool merge(int u, int v){
    
    if((u=get_par(u)) == (v=get_par(v))) return false;    
    if(rand()&1) swap(u, v);
    par[u] = v;
    return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        int n, m, k;
        cin >> n >> m >> k;
        
        vector<vpii> adj(n);
        
        for(int i = 0; i < m; i++){
            
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        int b = 0;
        for(int i = 0; i < k; i++){
            int u; cin >> u; u--;
            b ^= 1 << u;
        }
        
        int ans = INFLL;
        
        for(int i = 0; i < (1<<n); i++) if((i&b)==b){
            
            int cmsk = i;
            
            int cans = 0;
            
            vector<iii> edges;
            
            for(int u = 0; u < n; u++) if(cmsk&(1<<u))
            for(auto p : adj[u]) {
                
                int v = p.first;
                int w = p.second;
                
                if(cmsk&(1<<v)){
                    edges.push_back({w, {u, v}});
                }
            }
            
            sort(edges.begin(), edges.end());
            for(int i = 0; i < n; i++) par[i] = i;
            
            for(auto p : edges){
                
                int w = p.first;
                int u = p.second.first;
                int v = p.second.second;
                
                if(merge(u, v)){
                    cans += w;
                }
            }
            
            bool good = true;
            
            for(int i = 0; i < n; i++) if(cmsk&(1<<i))
            for(int j = i+1; j < n; j++) if(cmsk&(1<<j)){
                if(merge(i, j)){
                    good = false;
                    break;
                }
            }
            
            // cout << bitset<3>(cmsk) << ' ' << cans << ' ' << good << endl;
            
            if(good) ans = min(ans, cans);
        }
        
        cout << ans << endl;
    }	
}
