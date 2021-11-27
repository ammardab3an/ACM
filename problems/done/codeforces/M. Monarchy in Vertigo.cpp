// Problem: M. Monarchy in Vertigo
// Contest: Codeforces - 2021-2022 ACM-ICPC Brazil Subregional Programming Contest
// URL: https://codeforces.com/gym/103388/problem/M
// Memory Limit: 1024 MB
// Time Limit: 250 ms
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

int id = 1;
vi adj[NMAX];
int par[NMAX];
bool dead[NMAX];

int dfs(int u, int p){
    
    if(!dead[u]){
        return u;
    }
    
    for(auto v : adj[u]) if(v != p){
        int tmp = dfs(v, u);
        if(tmp != -1) return tmp;
    }    
    
    return -1;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int cur = 1;
    
    int q; cin >> q; while(q--){
        
        int ty, u;
        cin >> ty >> u;    
        
        if(ty == 1){
            id++;
            adj[u].push_back(id);
            par[id] = u;
        }
        else{
            
            dead[u] = true;
            
            if(u == cur){
                
                while(true){   
                    
                    int n_cur = dfs(cur, par[cur]);
        
                    if(n_cur == -1){                
                        adj[par[cur]].erase(find(adj[par[cur]].begin(), adj[par[cur]].end(), cur));
                        cur = par[cur];
                    }
                    else{
                        cur = n_cur;
                        break;
                    }
                }
            }
            
            cout << cur << endl;
        }
        
    }
}
