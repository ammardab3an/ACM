#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 10001
#define Pair pair<int, int>
#define cost first
#define id second
array<vector<Pair>, MAX> adj;

int dij(int a, int b)
{
    array<int ,MAX> dist;
    dist.fill(INT_MAX);
    dist[a] = 0;

    priority_queue<Pair> q;
    q.push({0, a});

    while(!q.empty())
    {
        Pair cur = q.top(); q.pop();
        cur.cost *= -1;

        if (dist[cur.id] < cur.cost)
            continue;
        if (cur.id == b)
            return cur.cost;

        for(auto to : adj[cur.id])
        {
            if (dist[to.id] > cur.cost + to.cost)
            {
                dist[to.id] = cur.cost + to.cost;
                q.push({-dist[to.id], to.id});
            }
        }
    }
    return false;
}
void input()
{
    adj.fill({});

    int v, k;
    cin >> v >> k;
    while(k--)
    {
        int f, t, c;
        cin >> f >> t >> c;
        adj[f].push_back({c, t});
    }
}
void output(int d)
{
    if (d)
        cout << d << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        input();
        int a, b;
        cin >> a >> b;
        output(dij(a,b));
    }
    return 0;
}
