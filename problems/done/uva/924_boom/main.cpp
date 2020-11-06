#include<bits/stdc++.h>

using namespace std;
//declarations
#define MAX 2501
#define Pair pair<int, int>
#define boomSize first
#define day second
array<vector<int>, MAX> adj;

Pair go(int src)
{
    array<int, MAX> cnt;
    array<int, MAX> vis;

    cnt.fill(+0); cnt[0]   = 1;
    vis.fill(-1); vis[src] = 0;

    queue<int> q; q.push(src);

    while(!q.empty())
    {
        int frm = q.front(); q.pop();
        for(auto to : adj[frm])
        {
            if (vis[to] != -1)
                continue;
            vis[to] = vis[frm] +1;
            cnt[vis[to]]++;
            q.push(to);
        }
    }

    int  mxbs, d;
    mxbs = d = 0;
    for(int i = 1; i < MAX; i++)
    {
        if(!cnt[i]) break;
        if(cnt[i] > mxbs)
        {
            mxbs = cnt[i];
            d = i;
        }
    }
    return {mxbs, d};
}
int main()
{
    int e, n, to, t, src;

    cin >> e;
    for (int frm = 0; frm < e; frm++)
    {
        cin >> n;
        while(n--)
        {
            cin >> to;
            adj[frm].push_back(to);
        }
    }

    cin >> t;
    while(t--)
    {
        cin >> src;
        Pair g = go(src);
        if (!g.day)
            cout << 0 << endl;
        else
            cout << g.boomSize << " " << g.day << endl;
    }
    return 0;
}
