// Problem: G. Maximum People
// Contest: Codeforces - bld.ai Summer22 Internship Contest [Official]
// URL: https://codeforces.com/group/tKWnzvWA4V/contest/388002/problem/G
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

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

int n, m;
iii edges[NMAX];
set<int> queries[NMAX];
int par[NMAX];
int lst[NMAX];

int get_par(int u){
	return par[u] = (par[u]==u) ? u : get_par(par[u]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	edges[i] = {w, {u, v}};
    }
    
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	queries[u].insert(i);
    	queries[v].insert(i);
    }
    
    sort(edges, edges+m);
    reverse(edges, edges+m);
    
    for(int i = 0; i < n; i++){
    	par[i] = i;
    	lst[i] = i;
    }
    
    vi ans(q);
    
    for(int i = 0; i < m; i++){
    	
    	int w = edges[i].first;
    	int u = edges[i].second.first;
    	int v = edges[i].second.second;
    	
    	u = get_par(u);
    	v = get_par(v);
    	
    	if(u != v){
    		
    		if(queries[lst[u]].size() > queries[lst[v]].size()){
    			swap(u, v);	
    		}
    		
    		auto &queries_v = queries[lst[v]];
    		
    		for(auto q : queries[lst[u]]){
    			auto it = queries_v.find(q);
    			if(it != queries_v.end()){
    				ans[q] = w;
    				queries_v.erase(it);
    			}
    			else{
    				queries_v.insert(q);
    			}
    		}
    		
    		par[u] = v;
    		queries[lst[u]] = set<int>();
    	}
    }
    
    for(auto i : ans) cout << i << endl;
}
