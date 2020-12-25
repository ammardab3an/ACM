// Problem: 10048 - Audiophobia
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=989
// Memory Limit: 32 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t

typedef unsigned int		uint;
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
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m, q;
vpii adj[NMAX];
iii edges[MMAX];
bool vist[NMAX];

int par[NMAX];

int get_par(int u){
	return par[u] == u ? u : par[u] = get_par(par[u]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
	int tt = 1;
    while(cin >> n >> m >> q){
    	
    	if(!n && !m && !q) break;
		
		for(int i = 0; i < m; i++){
			int u, v, c;
			cin >> u >> v >> c;
			edges[i] = {c, {u, v}};
		}
		
		for(int i = 1; i <= n; i++) par[i] = i;
		for(int i = 1; i <= n; i++) adj[i].clear();
		
		sort(edges, edges+m);
		
		for(int i = 0; i < m; i++){
			
			int c = edges[i].first;
			int u = edges[i].second.first;
			int v = edges[i].second.second;
			
			int paru = get_par(u);
			int parv = get_par(v);
			
			if(paru != parv){
				
				adj[u].push_back({c, v});
				adj[v].push_back({c, u});
				
				if(rand() & 1){
					par[paru] = parv;
				}
				else{
					par[parv] = paru;
				}
			}
		}
		
		if(false) for(int i = 1; i <= n; i++) for(auto p : adj[i]){
			cout << i << ' ' << p.second << ' ' << p.first << endl;
		}
		
		if(tt > 1) cout << endl;
		cout << "Case #" << tt++ << endl;
		
		
		while(q--){
			
			int u, v;
			cin >> u >> v;
			
			memset(vist, 0, sizeof vist);
			
			queue<pii> que;
			
			vist[u] = 1;
			que.push({0, u});
			
			int dist_v = -1;
			
			while(!que.empty()){
				
				pii fr = que.front(); que.pop();
				
				int cc = fr.first;
				int cn = fr.second;
				
				if(cn == v){
					dist_v = cc;
					break;
				}
				
				for(pii nxt : adj[cn]){
					
					int nc = nxt.first;
					int nn = nxt.second;
					
					if(!vist[nn]){
						vist[nn] = 1;
						que.push({max(cc, nc), nn});
					}
				}
			}
			
			if(dist_v != -1)
				cout << dist_v << endl;
			else
				cout << "no path" << endl;
		}
    }	
}
