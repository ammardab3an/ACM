
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
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
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

vi adj[NMAX];
vi nxt[NMAX];
int sz[NMAX];
int ans;

vi dfs(int u, int p){
    
    vi ret;
    
    for(auto v : adj[u]) if(v != p){
            
        for(auto nd : dfs(v, u)) 
            ret.push_back(nd);    
    }
    
    nxt[u] = ret;
    ret.push_back(u);
    return ret;
}

void go(int u, int cnt, int pro){
    
    vi cnxt = nxt[u];
    int sz = cnxt.size();
    
    int npro = mul(pro, pow_exp(sz, MOD-2));
    
    for(auto v : cnxt){
        go(v, cnt+1, npro);
    }
    
    if(sz == 0){
        ans = add(ans, mul(cnt, pro));
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        int n;
        cin >> n;
        
        for(int i = 0; i < n; i++){
            adj[i].clear();
            nxt[i].clear();
        }
        
        for(int i = 0; i < n-1; i++){
            
            int u, v;
            cin >> u >> v;
            u--, v--;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        ans = 0;
        
        dfs(0, -1);
        go(0, 0, 1);
        
        cout << ans << endl;
    }	
}
