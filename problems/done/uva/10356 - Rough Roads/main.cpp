#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pip pair<int, pii>

int N, R, setNum = 1;
array<vector<pii>, 555>  adj;

int dij()
{
    int dist[555][2];
    for(int i = 0; i < 555; i++)
        dist[i][0] = dist[i][1] = INT_MAX;
    dist[0][0] = 0;

    priority_queue< pip, vector<pip>, greater<pip> > que; que.push({0, {0, 0}});
    while(!que.empty())
    {
        pip cu = que.top(); que.pop();

        int cc = cu.first;
        int cp = cu.second.first;
        int cb = cu.second.second;

        if(dist[cp][cb] < cc)
            continue;
        if(cp == N-1 and cb == 0)
            return cc;

        for(pii to : adj[cp])
        {
            if(dist[to.second][!cb] > cu.first + to.first)
            {
                dist[to.second][!cb] = cu.first + to.first;
                que.push({dist[to.second][!cb], {to.second, !cb}});
            }
        }
    }
    return INT_MAX;
}

int main()
{
    #ifdef LOCAL_PROJECT
        cout << "hi" << endl;
        int choose; cin >> choose;
        if(choose)
            freopen("D:\\input.txt", "r", stdin);
        if(choose == 2)
            freopen("D:\\output.txt", "w", stdout);
    #endif


    while(cin >> N >> R)
    {
        adj.fill({});

        while(R--)
        {
            int fr, to, co;
            cin >> fr >> to >> co;
            adj[fr].push_back({co, to});
            adj[to].push_back({co, fr});
        }

        int minCost = dij();
        string ans = (minCost != INT_MAX) ? to_string(minCost) : "?";

        printf("Set #%d\n%s\n", setNum++, ans.c_str());
    }
}
