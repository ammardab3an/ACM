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

const int MAX = 1e5 + 10;

int n, m, ans;
bool cat[MAX];
bool vis[MAX];
vi   adj[MAX];

void dfs(int nd, int cnt){

    cnt = cat[nd] ? cnt+1 : 0;
    if(cnt > m) return;

    bool b = true;

    for(int to : adj[nd]) if(!vis[to]++){
        dfs(to, cnt);
        b = false;
    }

    if(b) ans++;
}

void solve(){

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> cat[i];

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vis[1]++;
    dfs(1, 0);
    cout << ans << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
