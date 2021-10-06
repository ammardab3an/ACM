// Problem: C. Bakry and Partitioning
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.com/contest/1592/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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

int val[NMAX];
vi adj[NMAX];
int _xor[NMAX];
int par[NMAX];

void dfs(int u, int p){
    
    _xor[u] = val[u];
    
    for(auto v : adj[u]) if(v != p){
        
        par[v] = u;
        dfs(v, u);            
        _xor[u] ^= _xor[v];
    }
}

int mem[NMAX];
int vis[NMAX], vid;

int go(int u, int p){
    
    if(vis[u] == vid){
        return mem[u];
    }
    else{
        vis[u] = vid;
    }
    
    int ret = (_xor[u] == _xor[0]);
    
    for(auto v : adj[u]) if(v != p){
        ret += go(v, u);
    }    
    
    return mem[u] = ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        int n, x;
        cin >> n >> x;
        
        for(int i = 0; i < n; i++){
            cin >> val[i];
            adj[i].clear();
        }
        
        for(int i = 0; i < n-1; i++){
            
            int u, v;
            cin >> u >> v;
            u--, v--;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(0, -1);
        
        if(_xor[0]==0){
            cout << "YES" << endl;
            continue;
        }
        
        if(x < 3){
            cout << "NO" << endl;
            continue;
        }
        
        vid++;
        if(go(0, -1) >= 3){
            cout << "YES" << endl;
            continue;
        }
        
        
        bool found = false;
        for(int i = 0; i < n; i++) if(_xor[i] == 0){
            if(go(i, par[i]) >= 1){
                cout << "YES" << endl;
                found = true;
                break;
            }
        }
        
        if(!found){
            cout << "NO" << endl;
        }
    }	
}
