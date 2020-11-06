#include <bits/stdc++.h>
using namespace std;

const int nMAX = 2e5;

int n, arr[nMAX];
vector<int> adj[nMAX];
int ans[nMAX], dp[nMAX];

void dfs1(int u = 0, int p = -1)
{
    dp[u] = arr[u];
    for(int v : adj[u]) if(v != p){
        dfs1(v, u);
        dp[u] += max(dp[v], 0);
    }
}

void dfs2(int u = 0, int p = -1, int pd = 0){
    ans[u] = dp[u] + pd;
    for(int v : adj[u]) if(v != p)
        dfs2(v, u, max(ans[u] - max(dp[v], 0), 0));
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(!arr[i]) arr[i] = -1;
    }

    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1();
    dfs2();

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
}
