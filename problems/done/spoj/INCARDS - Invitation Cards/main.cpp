#include<bits/stdc++.h>

using namespace std;

//declaration
#define INF 1000000000
#define MAX 1000001
#define id second
#define cost first
array<vector<pair<int, int> >, MAX> adj;
array<vector<pair<int, int> >, MAX> _adj;
array<long long, MAX> dis;

void dij()
{
    // the source node are always the CCS which it's id is 1
    dis.fill(INF);
    dis[1] = 0;
    priority_queue <pair<int,int> > q;
    q.push({0, 1});

    while(!q.empty())
    {
        pair<int,int> cn = q.top(); // current node<node cost, node id>
        cn.cost *= -1;
        q.pop();

        if (cn.cost > dis[cn.id])
            continue;

        for(auto to:adj[cn.id])
        {
            if(dis[to.id] > to.cost + cn.cost)
            {
                dis[to.id] =  to.cost + cn.cost;
                q.push({-dis[to.id], to.id});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // the number of test cases
    cin >> t;
    while(t--)
    {
        int p, q; // p: bus stops + CCS , q: bus lines
        cin >> p >> q;

        int f, t, c; // from, to, cost
        while(q--)
        {
            cin >> f >> t >> c;
            adj[f].push_back({c, t});
            _adj[t].push_back({c, f});// reverse edges so we don't need to run dijkstra more than two times
        }

        int re = 0; // result
        dij(); // calculate the cost of going
        for(int i = 2; i < p+1; i++)
            re += dis[i];
        adj = _adj;// swap arrays so the dijkstra function work on the reversed array
        dij(); // calculate the cost of return
        for(int i = 2; i < p+1; i++)
            re += dis[i];
        cout << re << endl;

        adj.fill({});//fill the array with an empty vectors
        _adj.fill({});
    }
    return 0;
}
