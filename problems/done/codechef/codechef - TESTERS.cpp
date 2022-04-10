// Problem: Vacation
// Contest: CodeChef - Practice
// URL: https://www.codechef.com/problems/TESTERS
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

// #define endl '\n'
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
const int NMAX = 3e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, nn;
vi adj[NMAX];
bool val[NMAX];
bool used[NMAX];
int sz[NMAX];
int ans;

struct FenwickTree {
	
    int n;
    vector<int> bit;  // binary indexed tree
	vector<int> vis;
	vector<int> _vis;
	
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
        vis.assign(n, 0);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
    	
    	if(!vis[idx]){
    		vis[idx] = true;
    		_vis.push_back(idx);
    	}
    	
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
    
    void clear(){
    	for(auto i : _vis){
    		add(i, -sum(i, i));
    		vis[i] = false; // don't move this
    	}
    	_vis.clear();
    }
    
} tree_cnt(NMAX*2), tree_sum(NMAX*2);

void go(int u, int p, bool b, int cnt_good, int cnt_bad, int dist){
	
	cnt_good += val[u]==1;
	cnt_bad += val[u]==0;
	
	if(!b){
		
		// good[i] + good[j] >= ugly[i] + ugly[j]
		// good[i] - ugli[i] >= ugly[j] - good[j]
		
		int q_sum = tree_sum.sum(cnt_bad-cnt_good+n, 2*n);
		int q_cnt = tree_cnt.sum(cnt_bad-cnt_good+n, 2*n);
		
		ans += q_sum + dist*q_cnt;
	}
	else{
		tree_sum.add(cnt_good-cnt_bad+n, dist);
		tree_cnt.add(cnt_good-cnt_bad+n, 1);
	}
	
	for(auto v : adj[u]) if(v != p) if(!used[v]){
		go(v, u, b, cnt_good, cnt_bad, dist+1);
	}
}

void dfs1(int u, int p){
	
	nn++;
	sz[u] = 1;	
	
	for(auto v : adj[u]) if(v != p) if(!used[v]){
		dfs1(v, u);
		sz[u] += sz[v];
	}
}

int dfs2(int u, int p){
	
	for(auto v : adj[u]) if(v != p) if(!used[v]) if(sz[v] > nn/2){
		return dfs2(v, u);
	}	
	
	return u;
}

void decompose(int u, int p){
	
	nn = 0;
	dfs1(u, u);
	
	int c = dfs2(u, u);	
	
	used[c] = true;
	
	tree_cnt.clear();
	tree_sum.clear();
	
	tree_cnt.add(n + (val[c]==1) - (val[c]==0), 1);
	tree_sum.add(n + (val[c]==1) - (val[c]==0), 1);
	
	int t = ans;
	
	for(auto v : adj[c]) if(!used[v]){
		go(v, c, 0, 0, 0, 1);
		go(v, c, 1, val[c]==1, val[c]==0, 2);	
	}
	
	// cout << c << ' ' << ans-t << endl;
	
	for(auto v : adj[c]) if(!used[v]){
		decompose(v, c);
	}
}

int32_t main(){
    
    // fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    for(int i = 0; i < n; i++){
    	int ai;
    	cin >> ai;
    	while(ai%2==0) ai/=2;
    	int s = sqrt(ai);
    	val[i] = s*s==ai ? 1 : 0;
    	if(val[i]==1) ans++;
    }
    
    // for(int i = 0; i < n; i++) cout << val[i] << ' ' ; cout << endl;
    
    decompose(0, -1);
    
    cout << ans << endl;
}
