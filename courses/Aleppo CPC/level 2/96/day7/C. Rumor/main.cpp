#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 100001
#define ll long long
array<vector<int>, MAX> adj;
array<ll   ,MAX> cst;
array<bool ,MAX> vis;

int dfs(int nd)
{
    vis[nd] = true;
    int mn = cst[nd] ;
    for(auto to : adj[nd])
        if(!vis[to])
            mn = min(mn, dfs(to)) ;
    return mn;
}

ll go(int n)
{
    ll total = 0;
    int mn;
    for (int i = 1; i <= n; i++)
        if(!vis[i])
            total += mn = dfs(i);
    return total;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> cst[i];

    int x, y;
    while(m--)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << go(n);

    return 0;
}
