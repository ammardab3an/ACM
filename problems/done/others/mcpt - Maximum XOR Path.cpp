// https://mcpt.ca/problem/xorpath

// By AmmarDab3an - Aleppo University

#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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

struct node{
	
	int mx;
	node *nxt[2];
	
	node(){
		mx = -1;
		nxt[0] = nxt[1] = nullptr;
	}
};

void dfs_delete(node *nd){
	
	if(!nd) return;
	
	dfs_delete(nd->nxt[0]);
	dfs_delete(nd->nxt[1]);
	
	delete nd->nxt[0];
	delete nd->nxt[1];
}

struct TrieXOR{
		
	node root;
	
	~TrieXOR(){
		clear();
	}
	
	void clear(){
		dfs_delete(root.nxt[0]);
		dfs_delete(root.nxt[1]);
		root.nxt[0] = nullptr;
		root.nxt[1] = nullptr;
	}
	
	void insert(int val, int d){
		
		node *cur = &root;
		
		for(int i = 30; i >= 0; i--){
			
			bool b = (val>>i)&1;
			
			if(!cur->nxt[b]){
				cur->nxt[b] = new node();
			}
			
			cur->nxt[b]->mx = max(cur->nxt[b]->mx, d);
			
			cur = cur->nxt[b];
		}
	}
	
	int query(int val, int d, int k){
		
		int ret = 0;
		node *cur = &root;
		
		for(int i = 30; i >= 0; i--){
			
			bool b = (val>>i)&1;
			
			bool b0 = (cur->nxt[b]) && (d >= k || (cur->nxt[b]->mx >= k-d));
			bool b1 = (cur->nxt[!b]) && (d >= k || (cur->nxt[!b]->mx >= k-d));
			
			if(b1){
				ret ^= (1ll << i);
				cur = cur->nxt[!b];
			}
			else if(b0){
				cur = cur->nxt[b];
			}
			else{
				return -1;
			}
		}
		
		return ret;
	}
};

int n, k;
int val[NMAX];
vi adj[NMAX];
bool used[NMAX];
int sz[NMAX], nn;
TrieXOR tree;
int ans = -1;

void go(int u, int p, int d, bool b, int _xor){
	
	if(!b){
		int q = tree.query(_xor, d, k);
		ans = max(ans, q);
	}	
	else{
		tree.insert(_xor, d);
	}
	
	for(auto v : adj[u]) if(v != p) if(!used[v]){
		go(v, u, d+1, b, _xor ^ val[v]);
	}
}

void dfs1(int u, int p){
	nn++;
	sz[u] = 1;	
	for(int v : adj[u]) if(v != p) if(!used[v]){
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

void centroid(int u, int p){
	
	nn = 0;
	dfs1(u, u);
	
	int c = dfs2(u, u);
	
	used[c] = true;
	
	tree.clear();
	tree.insert(val[c], 0);
	
	for(auto v : adj[c]) if(!used[v]){
		go(v, c, 1, 0, val[v]);
		go(v, c, 1, 1, val[v] ^ val[c]);
	}
	
	for(auto v : adj[c]) if(!used[v]){
		centroid(v, c);
	}
}

int32_t main(){
    
    fastIO;
    // #undef endl
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++){
    	cin >> val[i];
    }
    
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    centroid(0, -1);
    
    cout << ans << endl;
}