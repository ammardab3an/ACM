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

map<vi, double> mem[31];

double go(vi vec, int n){
    
    if(vec.size()==1) return 0;
    
    double &ret = mem[n].emplace(vec, -1).first->second;
    if(ret != -1) return ret;
    
    double p = 0, q = 0;
    
    for(auto i : vec) p += (i*(i-1))/2;
    p /= (n*(n-1))/2;
    
    for(int i = 0; i < vec.size(); i++)
    for(int j = i+1; j < vec.size(); j++){
        
        vi nvec = vec;
        nvec[i] += nvec[j];
        swap(nvec[j], nvec.back());
        nvec.pop_back();
        sort(nvec.begin(), nvec.end());
        
        q += (double) (vec[i] * vec[j]) / ((n*(n-1))/2) * (1 + go(nvec, n));
    }
    
    return (p + q) / (1.0 - p);
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
        
        double ans = go(tmp, n);
        
        cout << fixed << setprecision(10) << ans << endl;
    }
}
