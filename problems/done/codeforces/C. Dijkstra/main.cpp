#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
#define plli  pair<long long, int>
#define weight first
#define id second

array< vector<plli>, MAX > adj;

void dij(int N)
{
    array<long long, MAX> dist;
    array<int, MAX> parent;
    dist.fill(2e17);
    dist[N] = 0;

    priority_queue<plli, vector<plli>, greater<plli> > que; que.push({0, N});

    while(!que.empty())
    {
        plli cur = que.top(); que.pop();

        if(dist[cur.id] < cur.weight)
            continue;

        if(cur.id == 1)
        {
            cout << "1 ";
            for(int k = 1; k != N; k = parent[k])
                cout << parent[k] << ' ';
            return;
        }

        for(auto to : adj[cur.id])
        {
            if( dist[to.id] > cur.weight + to.weight )
            {
                dist[to.id] = cur.weight + to.weight;
                parent[to.id] = cur.id;

                que.push({dist[to.id], to.id});
            }
        }
    }
    cout << -1;
}
int main()
{
    long long N, M, a, b, c;
    cin >> N >> M;
    while(M--)
    {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    dij(N);
}
