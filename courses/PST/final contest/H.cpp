// Problem: H - 8
// Contest: Virtual Judge - Level 3 - Graduation Contest
// URL: https://vjudge.net/contest/414878#problem/H
// Memory Limit: 1024 MB
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

int n, m;
vi adj[NMAX];
bool vis[NMAX];
vi ans;

void dfs(int nd){
	vis[nd] = true;
	for(auto nxt : adj[nd]) if(!vis[nxt]){
		dfs(nxt);
	}
	ans.push_back(nd);
}

int32_t main(){
  	
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    while(cin >> n >> m){
    	
    	if(!n && !m) break;
    	
		for(int i = 0; i < n; i++) adj[i].clear();
		ans.clear();
		memset(vis, 0, sizeof vis);
		
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			adj[v].push_back(u);
		}
		
		for(int i = 0; i < n; i++) if(!vis[i]){
			dfs(i);
		}
		
		for(int i : ans){
			cout << i+1 << ' ';
		}
		cout << endl;
    }	
}
