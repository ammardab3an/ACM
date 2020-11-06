#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 100001
#define INF 2e17
#define ll long long
#define Pair pair<ll, int>
#define id second
#define cost first
array<vector<Pair>,MAX> adj;
array<ll, MAX> dis;
array<int,MAX> parent;

void dij(int n)
{
    dis.fill(INF);
    dis[n] = 0;

    priority_queue<Pair> q;
    q.push({0, n});

    Pair cp, to;
    while(!q.empty())
    {
        cp = q.top(); q.pop();
        cp.cost *= -1;

        if (dis[cp.id] < cp.cost)
            continue;
        if (cp.id == 1)
            break;

        for(auto to : adj[cp.id])
        {
            if (dis[to.id] > cp.cost + to.cost)
            {
                dis[to.id] = cp.cost + to.cost;
                q.push({-dis[to.id], to.id});
                parent[to.id] = cp.id;
            }
        }
    }
}


int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int f, t, c;
    while(m--)
    {
        scanf("%d %d %d", &f, &t, &c);
        adj[f].push_back({c, t});
        adj[t].push_back({c, f});
    }

    dij(n);

    if (!parent[1])
    {
        printf("%d", -1);
        return 0;
    }

    int x = 1;
    while(x)
    {
        printf("%d ", x);
        x = parent[x];
    }

    return 0;
}
