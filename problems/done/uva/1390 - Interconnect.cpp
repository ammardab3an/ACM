// Problem: 1390 - Interconnect
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4136
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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
int vis[NMAX], vid;

int dfs(int u){
    
    int ret = 1;
    vis[u] = vid;
    
    for(auto v : adj[u]) if(vis[v] != vid){
        ret += dfs(v);
    }
    
    return ret;
}

map<vi, double> mem;

double go(vi vec){
    
    if(vec.size() == 1){
        return 0;
    }
    
    auto it = mem.find(vec);
    if(it != mem.end()) return it->second;
    
    double ans = 0;
    
    int sz = vec.size();
    
    int n = 0;
    for(int i = 0; i < sz; i++) n += vec[i];
    
    double tp = 0;
    for(int i = 0; i < sz; i++){
        tp += ((double) (vec[i]*(vec[i]-1))/2.0) / ((double) ((n*(n-1))/2.0));
    }
    
    double cp = 1.0 / (1.0 - tp);
    ans += cp;
    
    for(int i = 0; i < sz; i++)
    for(int j = i+1; j < sz; j++){
        
        vi nvec;
        for(int k = 0; k < sz; k++) if((k != i) && (k != j)) nvec.push_back(vec[k]);
        nvec.push_back(vec[i]+vec[j]);
        sort(nvec.begin(), nvec.end());
        
        double np = ((double) (vec[i] * vec[j])) / ((double) ((n*(n-1))/2.0));   
        
        ans += cp * np * go(nvec);
    }
    
    return mem[vec] = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    while(cin >> n >> m){
        
        init:{
            vid++;
            for(int i = 0; i < n; i++) adj[i].clear();
        }
        
        for(int i = 0; i < m; i++){
            
            int u, v;
            cin >> u >> v; 
            u--, v--;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vi tmp;
        
        for(int i = 0; i < n; i++) if(vis[i] != vid){
            tmp.push_back(dfs(i));
        }
        
        sort(tmp.begin(), tmp.end());
        
        double ans = go(tmp);
        
        cout << fixed << setprecision(10) << ans << endl;
    }
}
