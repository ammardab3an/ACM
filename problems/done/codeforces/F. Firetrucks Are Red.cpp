// Problem: F. Firetrucks Are Red
// Contest: Codeforces - 2019-2020 ICPC Northwestern European Regional Programming Contest (NWERC 2019)
// URL: https://codeforces.com/gym/102500/problem/F
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
 
const int NMAX = 1e6 + 10;

int par[NMAX];
int sz[NMAX];
vi adj[NMAX];

int get_par(int n){
    return par[n] = (par[n]==n) ? n : get_par(par[n]);
}

bool merge(int u, int v){
    
    if((u=get_par(u)) == (v=get_par(v))){
        return false;    
    }
    
    if(rand()&1) swap(u, v);
    
    par[u] = v;
    sz[v] += sz[u];
    
    return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    vi comp;
    vpii edges;
    
    for(int i = 1; i <= n; i++){
        
        int k;
        cin >> k;
        
        for(int j = 0; j < k; j++){
            
            int v;
            cin >> v;
            v += 1e9;
            
            comp.push_back(v);
            edges.push_back({i, v});
        }    
        
        comp.push_back(i);
    }
    
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    
    for(auto &p : edges){
        p.first = lower_bound(comp.begin(), comp.end(), p.first) - comp.begin();
        p.second = lower_bound(comp.begin(), comp.end(), p.second) - comp.begin();
    }
    
    iota(par, par+comp.size(), 0);
    for(int i = 0; i < n; i++){
        sz[i] = 1;
    }
    
    for(auto [u, v] : edges){
        if(merge(u, v)){
            adj[v].push_back(u);
        }
    }
    
    if(sz[get_par(0)] != n){
        cout << "impossible" << endl;
        return 0;
    }
    
    vector<iii> ans;
    
    for(int v = 0; v < comp.size(); v++){
        for(int i = 1; i < adj[v].size(); i++){
            ans.push_back({v, {adj[v][i-1], adj[v][i]}});
        }
    }
    
    for(auto &p : ans){
        
        p.first = comp[p.first];
        p.second.first = comp[p.second.first];
        p.second.second = comp[p.second.second];
        
        cout << p.second.first << ' ' << p.second.second << ' ' << int(p.first-1e9) << endl;
    }
    
}
