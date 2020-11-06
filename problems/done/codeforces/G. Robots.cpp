
// G. Robots
// https://codeforces.com/gym/101915/problem/G

// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

vpii adj[NMAX];
priority_queue<lli> que;

lli dfs(int nd,int par, int mx)
{
	lli ans = 0;
	
	for(pii nxt : adj[nd]) if(nxt.second != par){
		
		if(que.empty()) break;

		int mxx = max(mx, nxt.first);
		
		if(que.top() > mxx) ans += dfs(nxt.second, nd, mxx);

	}
	
	while(!que.empty() && que.top() > mx){
		ans += nd;
		que.pop();
	}
	
	return ans;
}

int32_t main()
{
	fastIO;

	int t; cin >> t; while (t--) {
    	
    	int n, q;
        cin >> n >> q;
                
        for (int i = 0; i < n - 1; i++) {
            int u1, u2, w;
            cin >> u1 >> u2 >> w;
            adj[u1].push_back({ w, u2 });
            adj[u2].push_back({ w, u1 });
        }
		
		for(int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end(), greater<pii>());
		
        for (int i = 0; i < q; i++) {
        	int x; cin >> x; que.push(x);
        }
        
        cout << dfs(1, -1, 0) << endl;
        
        for(int i = 1; i <= n; i++) adj[i].clear();
    }
}
