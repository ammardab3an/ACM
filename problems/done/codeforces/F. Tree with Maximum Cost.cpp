// Problem: F. Tree with Maximum Cost
// Contest: Codeforces - Codeforces Round #527 (Div. 3)
// URL: https://codeforces.com/contest/1092/problem/F?fbclid=IwAR01916C5Bic34B-NCTmbeyyiNH9Sse8EJqzL7g3MJ1prc_W9-jcIB5lWIE
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int n;
vi adj[NMAX];
int arr[NMAX];
lli tot[NMAX];
lli ans[NMAX];
lli anss;

lli calcTot(int nd, int par){
	tot[nd] = arr[nd];
	for(auto nxt : adj[nd]) if(nxt != par){
		tot[nd] += calcTot(nxt, nd);
	}
	return tot[nd];
}

lli calcAns(int nd, int par){
	ans[nd] = tot[nd] - arr[nd];
	for(auto nxt : adj[nd]) if(nxt != par){
		ans[nd] += calcAns(nxt, nd);
	}
	return ans[nd];
}

void dfs(int nd, int par){
	
	anss = max(anss, ans[nd]);
	
	for(auto nxt : adj[nd]) if(nxt != par){
		
		ans[nd] -= tot[nxt] + ans[nxt];
		tot[nd] -= tot[nxt];
		
		ans[nxt] += tot[nd] + ans[nd];
		tot[nxt] += tot[nd];
		
		dfs(nxt, nd);
		
		ans[nxt] -= tot[nd] + ans[nd];
		tot[nxt] -= tot[nd];
		
		ans[nd] += tot[nxt] + ans[nxt];
		tot[nd] += tot[nxt];
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v; u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    anss = 0;
    calcTot(0, -1);
    calcAns(0, -1);
    dfs(0, -1);
    
    cout << anss << endl;
}
