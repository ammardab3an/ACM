// Problem: Fixed-Length Paths I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2080
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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

int n, k, ans;
int sz[NMAX];
int cnt[NMAX];
int vis[NMAX], vid;
set<int> adj[NMAX];

void go1(int u, int p, int d){

    if(d > k) return;
	
	if(vis[k-d]==vid){	
	    ans += cnt[k-d];
	}	

	for(auto v : adj[u]) if(v != p){
		go1(v, u, d+1);
	}
}

void go2(int u, int p, int d){

    if(d > k) return;

	if(vis[d]==vid){
		cnt[d]++;
	}
	else{	
		vis[d] = vid;
		cnt[d] = 1;
	}

	for(auto v : adj[u]) if(v != p){
		go2(v, u, d+1);
	}
}

// decompose

int nn;
void dfs1(int u, int p){

    nn++;
    sz[u] = 1;
    for(auto v : adj[u]) if(v != p){
        dfs1(v, u);
        sz[u] += sz[v];
    }
}

int dfs2(int u, int p){

    for(auto v : adj[u]) if(v != p) if(sz[v] > nn/2)
        return dfs2(v, u);
	
	vid++;
	vis[0] = vid;
	cnt[0] = 1;
	
    for(auto v : adj[u]){
    	go1(v, u, 1);
    	go2(v, u, 1);
    }

    return u;
}

void decompose(int u, int p){

    nn = 0;
    dfs1(u, u);

    int centroid = dfs2(u, u);
    if(p == -1) p = centroid;

    for(auto v : adj[centroid]){
        adj[v].erase(centroid);
        decompose(v, centroid);
    }

    adj[u].clear();
}

// end decompose

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
//    freopenO;
#endif

    // freopen("name.in", "r", stdin);

    cin >> n >> k;

    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].insert(v);
    	adj[v].insert(u);
    }

    decompose(0, -1);

    cout << ans << endl;
}
