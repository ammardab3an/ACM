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
map<int, int> mp;
set<int> st;

void go(int nd, int par, int cost)
{
    
	st.insert(cost);
    
	for(auto nxt : adj[nd]) if(nxt.second != par){
        
		if(cost > nxt.first){
	        go(nxt.second, nd, cost);
			return;
		}
		
    	int ncost = nxt.first + 1;
    	auto it = st.upper_bound(cost);
    	if(it == st.end() || *it > ncost) go(nxt.second, nd, ncost);
		
    }
    
    mp[cost] = nd;
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
		
        go(1, -1, 1);
		
        mp[0] = 1;

        lli su = 0;
        for (int i = 0; i < q; i++) {
        	int x; cin >> x; 
            auto it = mp.upper_bound(x); it--;
            su += it -> second;

        }

        cout << su << endl;
        
        for(int i = 1; i <= n; i++) adj[i].clear();
		st.clear();
        mp.clear();
    }
}