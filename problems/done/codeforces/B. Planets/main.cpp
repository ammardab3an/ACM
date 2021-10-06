#include <bits/stdc++.h>

using namespace std;

const int MAX = 100010;
#define pii pair<int, int>
#define weight first
#define id second

array< vector<pii>, MAX >         adj;
array< map<int, bool>, MAX >    tmArr;

void dij(int N)
{
    array< int, MAX > dist;
    dist.fill(INT_MAX);
    dist[0] = 0;

    priority_queue< pii, vector<pii>, greater<pii> > que; que.push({0, 0});
    while(!que.empty())
    {
        pii fr = que.top(); que.pop();

        if(fr.id == N)
        {
            cout << fr.weight;
            return;
        }

        if(dist[fr.id] > fr.weight)
            continue;

        while(tmArr[fr.id].count(fr.weight))
            fr.weight++;

        for(auto to : adj[fr.id])
        {

            if(dist[to.id] > fr.weight + to.weight)
            {
                dist[to.id] = fr.weight + to.weight;
                que.push({dist[to.id], to.id});
            }
        }
    }
    cout << -1;
}

int main()
{
    int N, M, fr, to, co;
    for(cin >> N >> M; M--;)
    {
        cin >> fr >> to >> co;
        adj[fr].push_back({co, to});
        adj[to].push_back({co, fr});
    }

    for(int n = 1; n <= N; n++)
    {
        int K, T;
        for(cin >> K; K--;)
        {
            cin >> T; tmArr[n][T];
        }
    }

    adj[0].push_back({0, 1});
    dij(N);
}
