// Problem: H. Bridges
// URL: https://codeforces.com/gym/100712/problem/H

// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m, clk;
vpii adj[NMAX];
vi adj2[NMAX];
pii edges[NMAX];
int tin[NMAX], low[NMAX], col[NMAX];
int vis, vist[NMAX];
bool isb[NMAX];

void dfs(int nd, int par){

	vist[nd] = vis;
	tin[nd] = low[nd] = clk++;

	for(auto p : adj[nd]) if(p.first != par){

		int nxt = p.first;

		if(vist[nxt] == vis){
			low[nd] = min(low[nd], tin[nxt]);
		}
		else{
			dfs(nxt, nd);
			low[nd] = min(low[nd], low[nxt]);
			if(low[nxt] > tin[nd]){
				isb[p.second] = 1;
			}
		}
	}
}

void dfs2(int nd, int ccol){

	col[nd] = ccol;
	vist[nd] = vis;

	for(auto p : adj[nd]){
		int nxt = p.first;
		int idx = p.second;
		if(vist[nxt] == vis || isb[idx]) continue;
		dfs2(nxt, ccol);
	}
}

int fl, fi;
void dfs3(int nd, int lvl){

	vist[nd] = vis;
	if(lvl > fl) fl = lvl, fi = nd;
	for(auto nxt : adj2[nd]) if(vist[nxt] != vis) dfs3(nxt, lvl+1);
}


int dfs4(int nd, int par){

	vist[nd] = vis;
	tin[nd] = low[nd] = clk++;
	int ret = 0;

	for(auto nxt : adj2[nd]) if(nxt != par){

		if(vist[nxt] == vis){
			low[nd] = min(low[nd], tin[nxt]);
		}
		else{
			ret += dfs4(nxt, nd);
			low[nd] = min(low[nd], low[nxt]);
			if(low[nxt] > tin[nd]){
				ret++;
			}
		}
	}

	return ret;
}

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

		cin >> n >> m;

		// reset
		vis = 0;
		memset(vist, 0, sizeof vist);
		memset(isb, 0, sizeof isb);
		for(int i = 0; i < n; i++) {
			adj[i].clear();
			adj2[i].clear();
		}

		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v; u--, v--;
			adj[u].push_back({v, i});
			adj[v].push_back({u, i});
			edges[i] = {u, v};
		}

		vis++;
		clk = 0;
		dfs(0, -1);

		vis++;
		int ccol = 0;
		for(int i = 0; i < n; i++) if(vist[i] != vis){
			dfs2(i, ccol++);
		}

		for(int i = 0; i < m; i++) if(isb[i]){

			int u = edges[i].first;
			int v = edges[i].second;
			int cu = col[u];
			int cv = col[v];

			if(cu != cv){
				adj2[cu].push_back(cv);
				adj2[cv].push_back(cu);
			}
		}


		vis++;
		fl = fi = 0;
		dfs3(0, 0);

		int l = fi;

		vis++;
		fl = 0, fi = l;
		dfs3(l, 0);

		int r = fi;

		vis++;
		clk = 0;
		int ans = dfs4(0, -1);

		cout << ans - fl << endl;
    }
}

