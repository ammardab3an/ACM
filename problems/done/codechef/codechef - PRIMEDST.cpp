// Problem: Prime Distance On Tree
// Contest: CodeChef - AUG13
// URL: https://www.codechef.com/problems/PRIMEDST
// Memory Limit: 256 MB
// Time Limit: 8000 ms
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int NMAX = 5e4 + 10;

int n;
vi adj[NMAX];
int sz[NMAX], sz_tot;
bool bad[NMAX];
vi primes;
bool not_prime[NMAX];
int cnt_paths;
int frq[NMAX];
int vis[NMAX], vid;

void ds_fix(int x){
	if(vis[x] != vid){
		vis[x] = vid;
		frq[x] = 0;
	}
}

void ds_add(int x, int d){
	ds_fix(x);
	frq[x] += d;	
}

int ds_get(int x){
	ds_fix(x);
	return frq[x];
}

void sieve_init(){
	for(int i = 2; i < NMAX; i++) if(!not_prime[i]){
		primes.push_back(i);
		for(int j = i*i; j < NMAX; j+=i){
			not_prime[j] = true;
		}
	}
}

void dfs0(int u, int p){
	sz[u] = 1;
	for(auto v : adj[u]) if(v != p) if(!bad[v]){
		dfs0(v, u);
		sz[u] += sz[v];
	}	
}

int dfs1(int u, int p){
	for(auto v : adj[u]) if(v != p) if(!bad[v]) if(sz[v]*2 > sz_tot){
		return dfs1(v, u);
	}
	return u;
}

void calc(int u, int p, int depth, bool b){
	
	if(b){
		for(auto p : primes) if(p >= depth){
			cnt_paths += ds_get(p-depth);
		}
	}
	else{
		ds_add(depth, 1);
	}
	
	for(auto v : adj[u]) if(v != p) if(!bad[v]){
		calc(v, u, depth+1, b);
	}
}

void decompose(int u){
	
	dfs0(u, -1);
	sz_tot = sz[u];
	int c = dfs1(u, -1);
	
	vid++;
	ds_add(0, 1);
	
	for(auto v : adj[c]) if(!bad[v]){
		calc(v, c, 1, true);
		calc(v, c, 1, false);
	}
	
	bad[c] = true;
	for(auto v : adj[c]) if(!bad[v]){
		decompose(v);
	}
}

int32_t main(){
    
    fastIO;
    
    sieve_init();
    
    // cout << primes.size() << endl;
    
    cin >> n;
    for(int i = 1; i < n; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    decompose(0);
    
    int tot_paths = n*(n-1)/2;
    double ans = double(cnt_paths) / double(tot_paths);
    cout << fixed << setprecision(7) << ans << endl;
}
