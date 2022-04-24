// Problem: XOR paths
// Contest: HackerEarth - Data Structures - Advanced Data Structures - Trie (Keyword Tree)
// URL: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/xor-path-1-f7009db6/
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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

struct node{

	node *nxt[2] = {nullptr, nullptr};
	multiset<int> st;

	node(){
		st = multiset<int>();
		nxt[0] = nxt[1] = nullptr;
	}
	
	~node(){
		if(nxt[0]) delete nxt[0];
		if(nxt[1]) delete nxt[1];
	}
};

struct TrieXOR{

	node root;

	TrieXOR(){
		root = node();
	}
	
	void insert(int val, int d, bool ins){

		node *cur = &root;

		for(int i = 30; i >= 0; i--){

			bool b = (val>>i)&1;

			if(cur->nxt[b] == nullptr){
				cur->nxt[b] = new node();
			}

			cur = cur->nxt[b];

			if(ins){
				cur->st.insert(d);
			}
			else{
				cur->st.erase(d);
			}
		}
	}

	int query(int val, int d){

		int ret = 0;
		node *cur = &root;
		
		for(int i = 30; i >= 0; i--){

			bool b = (val>>i)&1;

			bool b0 = (cur->nxt[!b]) && !(cur->nxt[!b]->st.empty()) && ((*(cur->nxt[!b]->st.rbegin())) >= d);
			bool b1 = (cur->nxt[b]) && !(cur->nxt[b]->st.empty()) && ((*(cur->nxt[b]->st.rbegin())) >= d);
			
			if(b0){
				ret ^= (1ll << i);
				cur = cur->nxt[!b];
			}
			else if(b1){
				cur = cur->nxt[b];
			}
			else{
				break;
			}
		}

		return ret;
	}

};

int n, q, log_n;
vpii adj[NMAX];
int par[NMAX][LOG_MAX];
int depth[NMAX];
int ans[NMAX];
vector<vi> queries[NMAX];
TrieXOR tree;

void dfs(int u, int p){

	for(auto [v, w] : adj[u]) if(v != p){

		depth[v] = depth[u]+1;

		par[v][0] = u;
		for(int i = 1; i < log_n; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}

		dfs(v, u);
	}
}

int lca(int u, int v){

	if(depth[u] < depth[v]){
		swap(u, v);
	}

	int dif = depth[u] - depth[v];
	for(int i = 0; i < log_n; i++) if((dif>>i)&1){
		u = par[u][i];
	}

	if(u==v) return u;

	for(int i = log_n-1; i >= 0; i--) if(par[u][i] != par[v][i]){
		u = par[u][i];
		v = par[v][i];
	}

	return par[u][0];
}

void go(int u, int p, int lst_w=-1){

	if(p != -1)	tree.insert(lst_w, depth[u], 1);


	for(auto q : queries[u]){

		int pp = q[0];
		int x = q[1];
		int i = q[2];

		int cans = tree.query(x, depth[pp]+1);

		ans[i] = max(ans[i], cans);
	}

	for(auto [v, w] : adj[u]) if(v != p){
		go(v, u, w);
	}

	if(p != -1) tree.insert(lst_w, depth[u], 0);
}

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);

    cin >> n >> q;
    for(int i = 0; i < n-1; i++){
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
    }

    log_n = ceil(log2(double(n)));

    dfs(0, -1);
    
	for(int i = 0; i < q; i++){

		int u, v, x;
		cin >> u >> v >> x;
		u--, v--;

		if(depth[u] < depth[v]){
			swap(u, v);
		}

		int p = lca(u, v);

		if(p==v){
			queries[u].push_back({p, x, i});
		}
		else{
			queries[u].push_back({p, x, i});
			queries[v].push_back({p, x, i});
		}
	}

	go(0, -1);

	for(int i = 0; i < q; i++){
		cout << ans[i] << endl;
	}
}

