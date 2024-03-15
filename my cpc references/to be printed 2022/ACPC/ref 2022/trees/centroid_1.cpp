// centroid 2 
// Problem: E. Palindromes in a Tree

/*
ou are given a tree (a connected acyclic undirected graph) of n vertices. Vertices are numbered from 1 to n and each vertex is assigned a character from a to t.
A path in the tree is said to be palindromic if at least one permutation of the labels in the path is a palindrome.
For each vertex, output the number of palindromic paths passing through it.
*/

string str;
int n, k;
int sz[NMAX];
int cnt[1 << 20];
int vis[1 << 20], vid;
set<int> adj[NMAX];

int otmp[1 << 20];
vpii oends[1 << 20];

int tmp[NMAX];
int ans[NMAX];

int idx[NMAX], idx_sz;

int c;

void go(int u, int p, int msk, bool b){
	
	msk ^= 1 << (str[u]-'a');
	
	if(!b){
		if(vis[msk]==vid){		
			tmp[u] += oends[msk].size();
			otmp[msk] += 1;
			tmp[c] -= oends[msk].size();
		}
		for(int i = 0; i < 20; i++){
			if(vis[msk^(1<<i)] == vid){
				tmp[u] += oends[msk^(1<<i)].size();
				otmp[msk^(1<<i)] += 1;
				tmp[c] -= oends[msk^(1<<i)].size();
			}
		}
	}
	else{
		if(vis[msk]==vid){
			oends[msk].push_back({u, -otmp[msk]});
		}
		else{
			vis[msk] = vid;
			otmp[msk] = 0;
			idx[idx_sz++] = msk;
			oends[msk].clear();
			oends[msk].push_back({u, 0});
		}
	}
	
	for(auto v : adj[u]) if(v != p){
		go(v, u, msk, b);
	}
}

// decompose

int nn;
void dfs1(int u, int p){
    
    nn++;
    sz[u] = 1;
    tmp[u] = 0;
    for(auto v : adj[u]) if(v != p){
        dfs1(v, u);
        sz[u] += sz[v];
    }
}

int dfs2(int u, int p){
    
    for(auto v : adj[u]) if(v != p) if(sz[v] > nn/2)
        return dfs2(v, u);
    
    return u;
}

void build(int u, int p){
	for(auto v : adj[u]) if(v != p){
		build(v, u);
		tmp[u] += tmp[v];
	}	
	ans[u] += tmp[u];
}

void decompose(int u, int p){
    
    nn = 0;
    dfs1(u, u);
    
    int c = dfs2(u, u);
    
    {	
		::c = c;
	    vid++;
	    tmp[c]++;
	    idx_sz = 0;
	    
	    {
	    	int msk = 1 << (str[c]-'a');
	    	vis[msk] = vid;
	    	otmp[msk] = 0;
	    	oends[msk].clear();
	    	oends[msk].push_back({c, 0});
	    	idx[idx_sz++] = msk;
	    }
	    
	    for(auto v : adj[c]){
	    	go(v, c, 0, 0);
	    	go(v, c, (1 << (str[c]-'a')), 1);
	    }
	    
	    for(int i = 0; i < idx_sz; i++){
	    	int msk = idx[i];
	    	int lvl = otmp[msk];
	    	for(auto [v, cc] : oends[msk]){
	    		tmp[v] += cc + lvl;
	    	}	
	    }
	    
	    build(c, c);
    }
    
    for(auto v : adj[c]){
        adj[v].erase(c);
        decompose(v, c);
    }
    
    adj[u].clear();
}

// end decompose

int32_t main(){
    
    cin >> n;
    
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].insert(v);
    	adj[v].insert(u);
    }
    
    cin >> str;
    
    decompose(0, -1);
    
    for(int i = 0; i < n; i++){
    	cout << ans[i] << ' ';
    }
}