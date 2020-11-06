#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 101
vector<int> adj[MAX], l_adj[MAX];
bool        vis[MAX], l_vis[MAX];
int         n, m;

void dfs(int i, bool f)
{
    if(f)
    {
        vis[i] = true;
        for(auto to:adj[i])
            if(!l_vis[to])
                dfs(to, false);
    }
    else
    {
        l_vis[i] = true;
        for(auto to:l_adj[i])
            if(!vis[to])
                dfs(to, true);
    }
}

int go()
{
    int cnt = l_adj[0].size();
    for(int i = 1; i <= m; i++)
    {
        if(!l_vis[i] && l_adj[i].size())
        {
            dfs(i, false);
            cnt++;
        }
    }
    if (cnt != l_adj[0].size())
        cnt--;
    return cnt;
}

void input()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int k, l;
        cin >> k;
        if (!k)
        {
            adj[i].push_back(0);
            l_adj[0].push_back(i);
        }
        while(k--)
        {
            cin >> l;
            adj[i].push_back(l);
            l_adj[l].push_back(i);
        }
    }
}

int main()
{
    input();
    cout << go();
    return 0;
}
