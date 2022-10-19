// Problem: F - Exactly K Steps
// Contest: AtCoder - NEC Programming Contest 2022 (AtCoder Beginner Contest 267)
// URL: https://atcoder.jp/contests/abc267/tasks/abc267_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

vi adj[NMAX];
int depth[NMAX];
int par[NMAX][LOG_MAX];
int nxt[NMAX][LOG_MAX];
int bst[NMAX][2];
int val[NMAX][2];
int ans_max[NMAX];
int ans_nxt[NMAX];

void go0(int u, int p){
	
	for(auto v : adj[u]) if(v != p){
		
		depth[v] = depth[u]+1;
		
		par[v][0] = u;
		for(int i = 1; i < LOG_MAX; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}
		
		go0(v, u);
	}	
}

void go1(int u, int p){
	
	bst[u][0] = bst[u][1] = u;
	val[u][0] = val[u][1] = 0;
	
	for(auto v : adj[u]) if(v != p){
		
		go1(v, u);
		
		if(val[v][0] > val[u][0]){
			bst[u][1] = bst[u][0];
			val[u][1] = val[u][0];
			bst[u][0] = v;
			val[u][0] = val[v][0];
		}
		else if(val[v][0] > val[u][1]){
			bst[u][1] = v;
			val[u][1] = val[v][0];
		}
	}
	
	val[u][0] += 1;
	val[u][1] += 1;
	
	nxt[u][0] = bst[u][0];
	for(int i = 1; i < LOG_MAX; i++){
		nxt[u][i] = nxt[nxt[u][i-1]][i-1];
	}
}

void go2(int u, int p, pii cur){
	
	cur.first++;
	
	for(auto v : adj[u]) if(v != p){
		if(bst[u][0]!=v){
			go2(v, u, max(cur, (pii){val[u][0], bst[u][0]}));
		}
		else if(val[u][1]!=1 && bst[u][1]!=v){
			go2(v, u, max(cur, (pii){val[u][1], bst[u][1]}));
		}
		else{
			go2(v, u, cur);
		}
	}
	
	cur = max(cur, (pii){val[u][0], bst[u][0]});
	ans_max[u] = cur.first-1;
	ans_nxt[u] = cur.second;
}

int get_up(int u, int k){
	for(int i = 0; i < LOG_MAX; i++) if((k>>i)&1){
		u = par[u][i];
	}	
	return u;
}

int get_down(int u, int k){
	for(int i = 0; i < LOG_MAX; i++) if((k>>i)&1){
		u = nxt[u][i];
	}
	return u;
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
    
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    go0(0, -1);
    go1(0, -1);
    go2(0, -1, (pii){-INF, -INF});
    
    int q; cin >> q; while(q--){
    	
    	int u, k;
    	cin >> u >> k;
    	u--;
    	
    	if(k <= depth[u]){
    		cout << get_up(u, k)+1 << endl;
    		continue;
    	}
    	
    	if(k < val[u][0]){
    		cout << get_down(u, k)+1 << endl;
    		continue;
    	}
    	
    	if(k > ans_max[u]){
    		cout << -1 << endl;
    		continue;
    	}
    	
    	int v = ans_nxt[u];
    	int d = depth[u]-depth[par[v][0]];
		int ans = get_down(v, k-(d+1))+1;
		
    	assert(ans != -1);
    	
    	cout << ans << endl;
    }
}
