// iiot 
// https://training.olinfo.it/#/task/ois_xortree2

// By AmmarDab3an

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

const int NMAX = 5e4 + 10;
const int BLOCK = 400;

int n, m;
vpii adj[NMAX];
int val[NMAX];
int queries[NMAX];

void dfs(int u, int p){

	for(auto [v, w] : adj[u]) if(v != p){
		val[v] = val[u]^w;
		dfs(v, u);
	}
}

struct node{

	node* nxt[2];
	bool is_leaf;
	int leaf_val;

	node(){
		nxt[0]=nxt[1] = 0;
		is_leaf = false;
		leaf_val = 0;
	}

	node(int val) : node(){
		is_leaf = true;
		leaf_val = val;
	}
	
	~node(){
	    delete nxt[0];
		delete nxt[1];
	}
	
	void insert(int lvl, int val){
		
		if(is_leaf && leaf_val==val){
			return;
		}
		
		if(is_leaf){	
			bool lb = (leaf_val>>lvl)&1;
			nxt[lb] = new node(leaf_val);
			is_leaf = false, leaf_val = 0;
		}
		
		bool b = (val>>lvl)&1;
		
		if(!nxt[b]){
			nxt[b] = new node(val);
		}
		else{
			nxt[b]->insert(lvl-1, val);
		}
	}
};

struct trie{

	node root;
	bool empty = true;
	
	void update(int x){
		empty = false;
		root.insert(30, x);
	}

	int query(int x){
		
		if(empty) return 0;
		
		node *cur = &root;

		for(int i = 30; i >= 0; i--){

			if(cur->is_leaf){
				break;
			}
			
			bool b = (x>>i)&1;
			
			if(cur->nxt[!b]){
				cur = cur->nxt[!b];
			}
			else{
				cur = cur->nxt[b];
			}
		}

		return x^(cur->leaf_val);
	}
};

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);

    cin >> n >> m;
    for(int i = 0; i < n-1; i++){
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
    }

    dfs(0, -1);
	
    for(int i = 0; i < m; i++){
    	cin >> queries[i];
    	queries[i]--;
    }

    bitset<NMAX> vis, tmp;
    trie lst, cur;
    vector<int> st_cur;
    int ans_lst = 0;
    int ans_cur = 0;
	
    for(int i = 0; i < m; i++){

    	if(i%BLOCK == 0){
    		
    		ans_lst = ans_cur = 0;
    		st_cur.clear();
	   		lst.~trie();
	   		cur.~trie();
    		lst = trie();
    		cur = trie();
    		tmp = vis;

    		for(int j = i; (j < m) && (i/BLOCK==j/BLOCK); j++){
    			tmp[queries[j]] = false;
    		}

    		for(int i = 0; i < n; i++){
    			if(tmp[i]){
	    			ans_lst = max(ans_lst, lst.query(val[i]));
	    			lst.update(val[i]);
    			}
    		}

    		for(int i = 0; i < n; i++){
    			if(vis[i] && !tmp[i]){
    				ans_cur = max(ans_cur, cur.query(val[i]));
    				ans_cur = max(ans_cur, lst.query(val[i]));
    				cur.update(val[i]);
    				st_cur.push_back(i);
    			}
    		}
    	}

    	int x = queries[i];

    	if(!vis[x]){
    		vis[x] = true;
			ans_cur = max(ans_cur, cur.query(val[x]));
			ans_cur = max(ans_cur, lst.query(val[x]));
			cur.update(val[x]);
			st_cur.push_back(x);
    	}
    	else{
    		ans_cur = 0;
    		vis[x] = false;
	   		cur.~trie();
    		cur = trie();
    		for(auto i : st_cur) if(vis[i]){
    			ans_cur = max(ans_cur, cur.query(val[i]));
				ans_cur = max(ans_cur, lst.query(val[i]));
				cur.update(val[i]);
    		}
    	}

    	cout << max(ans_lst, ans_cur) << endl;
    }
}
