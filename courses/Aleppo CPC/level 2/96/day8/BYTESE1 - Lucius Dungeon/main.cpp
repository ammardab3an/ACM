#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 101
#define pii pair<int, int>
#define ppi pair<int, pii>
#define cost first
#define I second.first
#define J second.second
int grid[MAX][MAX];
int mi[] = {0, 0, -1, 1};
int mj[] = {-1, 1, 0, 0};
int n, m;

bool in(int i, int j)
{
    return 1 <= i && i <= n &&
           1 <= j && j <= m;
}
void fill_INF(int dist[MAX][MAX])
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dist[i][j] = INT_MAX;
}
int dij(int i, int j)
{
    int dist[MAX][MAX]; fill_INF(dist);
    dist[1][1] = grid[1][1];

    priority_queue<ppi> q;
    q.push({-dist[1][1], {1, 1}});

    while(!q.empty())
    {
        ppi cur = q.top(); cur.cost *= -1; q.pop();

        if( dist[cur.I][cur.J] < cur.cost)
            continue;
        if (cur.I == i && cur.J == j)
            return cur.cost;

        for(int k = 0; k < 4; k++)
        {
            int ni = cur.I + mi[k];
            int nj = cur.J + mj[k];
            if (!in(ni, nj))
                continue;
            if (dist[ni][nj] > cur.cost + grid[ni][nj])
            {
                dist[ni][nj] = cur.cost + grid[ni][nj];
                q.push({-dist[ni][nj], {ni, nj}});
            }
        }
    }
}
void input()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> grid[i][j];

}
void output(int g, int t)
{
    if (g < t)
    {
        cout << "YES" << endl;
        cout << t - g << endl;
    }
    else
        cout << "NO" << endl;
}
int main()
{
    int k;
    cin >> k;
    while(k--)
    {
        input();
        int i, j, t;
        cin >> i >> j >> t;
        output(dij(i, j), t);
    }
    return 0;
}
