#include<bits/stdc++.h>

using namespace std;

// variables declarations
map< int, vector<int> > adj;

int bfs(int n, int ttl)
{
    queue<int> q;
    map<int, int> dist;
    q.push(n); dist[n] = 0;

    while(!q.empty())
    {
        int f = q.front(); q.pop();
        for(auto to:adj[f])
        {
            if(!dist.count(to))
            {
                dist[to] = dist[f] +1;
                q.push(to);
            }
        }
    }
    int tot = 0;
    for(auto i:adj)
        if(!dist.count(i.first))
            tot++;
    for(auto p:dist)
        if(p.second > ttl)
            tot++;
    return tot;
}
int main()
{
//    freopen("D:\\input.txt", "r", stdin);
//    freopen("D:\\output.txt", "w", stdout);

    for(int NC, T = 1; cin >> NC && NC;)
    {
        adj.clear();
        for(int i, j, k = 0; (k < NC) && (cin >> i >> j); k++)
        {
            adj[i]; adj[j];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        for(int i, j; (cin >> i >> j) && i; T++)
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", T, bfs(i, j), i, j);

    }
    return 0;
}
