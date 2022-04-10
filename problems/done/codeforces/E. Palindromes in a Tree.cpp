// Problem: E. Palindromes in a Tree
// Contest: Codeforces - Codecraft-18 and Codeforces Round #458 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/contest/914/problem/E
// Memory Limit: 256 MB
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
    
    fastIO;
    
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
    	adj[u].insert(v);
    	adj[v].insert(u);
    }
    
    cin >> str;
    
    decompose(0, -1);
    
    for(int i = 0; i < n; i++){
    	cout << ans[i] << ' ';
    }
}
