#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 10001
#define INF INT_MAX
#define pii pair<int, int>
#define hasHotel first
#define adj second
#define id second
#define cost first
array< pair< bool, vector<pii> >, MAX> graph;
array<int, MAX> dist[MAX];

void dij(int f)
{
    dist[f].fill(INF);
    dist[f][f] = 0;

    priority_queue<pii> pq;
    pq.push({0, f});

    while(!pq.empty())
    {
        pii cp = pq.top(); pq.pop();
        cp.cost *= -1;

        if (dist[f][cp.id] > cp.cost)
            continue;

        for(auto to : graph[cp.id].adj)
        {
            if (dist[f][to.id] > to.cost + cp.cost)
            {
                dist[f][to.id] = to.cost + cp.cost;
                pq.push({-dist[f][to.id], to.id});
            }
        }
    }
}
int bfs(int n)
{
    array<int, MAX> d;
    d.fill(INF);
    d[1] = 0;

    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int f = q.front(); q.pop();

        for(int t = 2; t <= n; t++)
        {
            if (graph[t].hasHotel && dist[f][t] <= 60*10)
            {
                if (d[t] == INF)
                {
                    if (t == n) return d[f];
                    d[t] = d[f] +1;
                    q.push(t);
                }
            }
        }
    }
    return -1;
}
int go(int n)
{
    for(int i = 1; i <= n; i++)
        if(graph[i].hasHotel)
            dij(i);

    return bfs(n);
}
void input(int n)
{
    graph.fill({});

    int k, _k, a, b, t;
    cin >> k;
    while(k--)
    {
        cin >> _k;
        graph[_k].hasHotel = true;
    }
    graph[1].hasHotel = true;
    graph[n].hasHotel = true;

    cin >> k;
    while(k--)
    {
        cin >> a >> b >> t;
        graph[a].adj.push_back({t, b});
        graph[b].adj.push_back({t, a});
    }
}
int main()
{
    while(true)
    {
        int n;
        cin >> n;
        if (!n) break;

        input(n);
        cout << go(n) << endl;
    }
    return 0;
}
