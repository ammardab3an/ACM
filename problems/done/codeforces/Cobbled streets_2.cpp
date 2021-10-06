// Problem: Cobbled streets
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/CSTREET/
// Memory Limit: 1536 MB
// Time Limit: 15000 ms
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

int n, m, p;
iii edges[MMAX];

int par[NMAX];

int get_par(int nd){
	return par[nd] == nd ? nd : par[nd] = get_par(par[nd]);
}

void union_dsu(int u, int v){
	
	int paru = get_par(u);
	int parv = get_par(v);
	
	if(rand() & 1){
		par[paru] = parv;
	}
	else{
		par[parv] = paru;
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
    	
		cin >> p >> n >> m;
		
		for(int i = 1; i <= n; i++) par[i] = i;
		
		for(int i = 0; i < m; i++){
			int u, v, c;
			cin >> u >> v >> c;
			edges[i] = {c, {u, v}};
		}
		
		int ans = 0;
		
		sort(edges, edges+m);
		
		for(int i = 0; i < m; i++){
			
			iii edg = edges[i];
			int c = edg.first;
			int u = edg.second.first;
			int v = edg.second.second;
			
			if(get_par(u) != get_par(v)){
				union_dsu(u, v);
				ans += c;
			}
		}
		
		cout << p * ans << endl;
    }	
}
