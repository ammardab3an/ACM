#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 101
#define Pair pair<int,int>
#define cost first
#define id second
array<vector<int>, MAX> adj;
int mem[MAX][MAX][MAX];

bool linked(int i, int j, int nd)
{
    if (mem[i][j][nd] != -1)
        return mem[i][j][nd];

    array<int, MAX> dis;
    dis.fill(INT_MAX);
    dis[i] = 0;

    priority_queue<Pair> q;
    q.push({0, i});
    while(!q.empty())
    {
        Pair cp = q.top(); q.pop();
        cp.cost *= -1;

        if (dis[cp.id] < cp.cost)
            continue;
        if (cp.id == j)
            return mem[i][j][nd] = mem[j][i][nd] = true;

        for(auto to : adj[cp.id])
        {
            if (to == nd) continue;
            if (dis[to] > cp.cost + 1)
            {
                dis[to] = cp.cost + 1;
                q.push({-dis[to], to});
            }
        }
    }
    return mem[i][j][nd] = mem[j][i][nd] = false;
}
int go(int n)
{
    int cnt = 0;
    memset(mem, -1, sizeof mem);
    for(int nd = 1; nd <= n; nd++)
    {
        vector<int> vec = adj[nd];

        for(auto i:vec)
            for(auto j:vec)
                if (i != j && !linked(i, j, nd))
                {
                    cnt++;
                    goto endloop;
                }
    endloop: ;
    }
    return cnt;
}
int main()
{
    char *token;
    char inputStr[1000];
    int n;

    while(scanf("%d ", &n) != EOF)
    {
        if (!n)
            break;

        adj.fill({});
        while(gets(inputStr) != NULL)
        {
            token = strtok(inputStr, " ");

            int nd = stoi(token);

            if (!nd)
                break;

            token = strtok(NULL, " ");
            while (token != NULL)
            {
                int to = stoi(token);
                adj[nd].push_back(to);
                adj[to].push_back(nd);
                token = strtok(NULL, " ");
            }
        }
        cout << go(n) << endl;
    }
    return 0;
}
