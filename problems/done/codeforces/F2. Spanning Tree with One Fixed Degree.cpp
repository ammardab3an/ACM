// Problem: F2. Spanning Tree with One Fixed Degree
// Contest: Codeforces - Codeforces Round #544 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1133/F2
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

int par[NMAX];
int get_par(int u){
	return par[u] = (par[u]==u) ? u : get_par(par[u]);
}

bool merge(int u, int v){
	
	if((u=get_par(u))==(v=get_par(v))){
		return false;
	}
	
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
    
    int n, m, d;
    cin >> n >> m >> d;
    
    vpii edges;
    vi edges_0;
    
    int cnt = n;
    iota(par, par+n, 0);
    
    for(int i = 0; i < m; i++){
    	
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	
    	if(u > v) swap(u, v);
    	
    	if(u==0){
    		edges_0.push_back(v);
    	}
    	else{
    		edges.push_back({u, v});
    		
    		if(merge(u, v)){
    			cnt--;
    		}
    	}
    }
    
    if(cnt-1 > d || edges_0.size() < d){
    	cout << "NO" << endl;
    	return 0;
    }
    
    vi tmp;
    vi good(edges_0.size());
    
    for(int i = 0; i < edges_0.size(); i++){
    	if(merge(0, edges_0[i])){
    		tmp.push_back(edges_0[i]);
    		good[i] = true;
    	}
    }
    
    assert(tmp.size() <= d);
    
    for(int i = 0; i < edges_0.size(); i++){
    	if(tmp.size()==d){
    		break;
    	}
    	if(!good[i]){
    		tmp.push_back(edges_0[i]);	
    	}
    }
    
    iota(par, par+n, 0);
    
    vpii used;
    
    for(auto u : tmp){
    	merge(0, u);
    	used.push_back({0, u});
    }
    
    for(auto [u, v] : edges){
    	if(merge(u, v)){
    		used.push_back({u, v});
    	}
    }
    
    cout << "YES" << endl;
    for(auto [u, v] : used){
    	cout << u+1 << ' ' << v+1 << endl;
    }
}
