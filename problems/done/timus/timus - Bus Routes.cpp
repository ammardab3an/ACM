// Problem: URAL 1137 - Bus Routes
// Contest: Virtual Judge - Session 2 Sheet - [Euler,  Hamiltonian, Backtrack, greedy and Classical DP]
// URL: https://vjudge.net/contest/421856#problem/G
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1137
// Memory Limit: 65 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


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

vi ans;
vi adj[1010];
int vis[1010][1010];

void dfs(int nd, int k){
	
	for(int i = 0, sz = adj[nd].size(); i < sz; i++) if(!vis[nd][i]){
		ans.insert(ans.begin() + k, adj[nd][i]);
		vis[nd][i] = true;
		dfs(adj[nd][i], k+1);
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	int begNd = -1;
	int numOfEdges = 0;
	
	int n; cin >> n; while(n--){
		
		int m;
		cin >> m;
		
		numOfEdges += m;
		
		int pst;
		cin >> pst;
		
		if(begNd == -1) begNd = pst;
		
		for(int i = 0; i < m; i++){
			int nxt;
			cin >> nxt;
			adj[pst].push_back(nxt);
			pst = nxt;
		}
		
	}
	
	ans.push_back(begNd);
	dfs(begNd, 1); 
	
	if(numOfEdges != ans.size() - 1){
		cout << 0 << endl;
	}
	else{
		cout << numOfEdges << endl;
		for(int i = 0, sz = ans.size(); i < sz; i++){
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
}
