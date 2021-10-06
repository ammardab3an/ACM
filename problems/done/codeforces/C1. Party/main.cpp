#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 2001
array<vector<int>, MAX> adj;
bool vis[MAX];
bool like[MAX][MAX];
vector<int> group;

void dfs(int f)
{
    vis[f] = true;
    group.push_back(f);

    for(auto to : adj[f])
        if(like[f][to] && !vis[to])
            dfs(to);
}
int main()
{
    adj.fill({});
    memset(like, true, sizeof like);

    int n, k, m, i, j;
    cin >> n >> k;
    while(k--)
    {
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    cin >> m;
    while(m--)
    {
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
        like[i][j] = like[j][i] = false;
    }
    int mx = 0;
    for(int i = 1; i <= n; i++)
    {
        group.clear();
        memset(vis, false, sizeof vis);
        dfs(i);

        bool b = true;
        for(auto f1 : group)
        for(auto f2 : group)
            if (f1 != f2 && !like[f1][f2])
            {
                b = false;
                break;
            }
        if (b)
            mx = max(mx, int(group.size()));
    }
    cout << mx;
    return 0;
}
