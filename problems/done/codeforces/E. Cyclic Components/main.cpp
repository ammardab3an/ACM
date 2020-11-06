// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<lli, lli>      pll;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<pii>         vpii;

// Global Variables

const int MAX = 2e5 + 10;
vector<int> adj[MAX];
vector<int> comp;
int vis[MAX];
int dig[MAX];

void dfs(int nd){
    vis[nd] = true;
    comp.push_back(nd);
    for(auto v : adj[nd])
        if(!vis[v])
            dfs(v);
}

void solve(){

    int n, m;
    cin >> n >> m;

    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dig[u]++;
        dig[v]++;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) if(!vis[i]){
        comp.clear();
        dfs(i);
        bool good = true;
        for(auto nd : comp)
            good &= dig[nd] == 2;
        ans += good;
    }
    cout << ans;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
