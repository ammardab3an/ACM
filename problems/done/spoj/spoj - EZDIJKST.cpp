#include <bits/stdc++.h>

using namespace std;

#define MAX 10010
#define pii pair<int, int>
#define weight  first
#define id      second

int A, B;
array<vector<pii>, MAX> adj;

void dij()
{
    array<int, MAX> dist;
    dist.fill(INT_MAX);
    dist[A] = 0;

    priority_queue<pii, vector<pii>, greater<pii> > que; que.push({0, A});

    while(!que.empty())
    {
        pii cur = que.top(); que.pop();

        if(dist[cur.id] < cur.weight)
            continue;

        if(cur.id == B)
        {
            cout << cur.weight << endl;
            return;
        }

        for(auto to : adj[cur.id])
        {
            if(dist[to.id] > cur.weight + to.weight)
            {
                dist[to.id] = cur.weight + to.weight;
                que.push({dist[to.id], to.id});
            }
        }
    }
    cout << "NO" << endl;
}
int main()
{
    int T, V, K, a, b, c;

    for(cin >> T; T; T--)
    {
        adj.fill({});

        for(cin >> V >> K; K; K--)
        {
            cin >> a >> b >> c;
            adj[a].push_back({c, b});
        }

        cin >> A >> B;
        dij();
    }
}
