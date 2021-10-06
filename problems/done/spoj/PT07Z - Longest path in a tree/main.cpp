#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 10001
#define Pair pair<int, int>
#define id first
#define d second
vector<int> adj[MAX];
bool vis[MAX];

Pair dfs(int src)
{
    vis[src] = true;
    int mxd = 0;
    int mxid = src;

    for(auto to : adj[src])
    {
        if(vis[to])
            continue;
        Pair p = dfs(to);
        if (p.d +1> mxd)
        {
            mxd = p.d +1;
            mxid = p.id;
        }
    }
    return {mxid, mxd};
}
int go()
{
    memset(vis, false, sizeof vis);
    Pair p = dfs(1);
    memset(vis, false, sizeof vis);
    return dfs(p.id).d;
}
void input()
{
    int n;
    cin >> n; n--;
    while(n--)
    {
        int f, t;
        cin >> f >> t;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }
}
int main()
{
    input();
    cout << go();
    return 0;
}
