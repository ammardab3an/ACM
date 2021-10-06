#include <iostream>
#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 51
#define Pair pair<int, bool>
#define tot first
#define ocean second
#define I second.first
#define J second.second
char grid[MAX][MAX];
bool vis[MAX][MAX];
int mi[4] = {0, 0, 1, -1};
int mj[4] = {1, -1, 0, 0};
int n, m, k;

bool in(int i, int j)
{
    return 1 <= i && i <= n && 1 <= j && j <= m;
}

bool atBrd(int i, int j)
{
    return i == 1 || i == n || j == 1 || j == m;
}

Pair dfs(int i, int j, bool colorIt)
{
    vis[i][j] = true;
    bool oc = atBrd(i,j);
    if (colorIt)
        grid[i][j] = '*';
    int total = 1;
    for (int k = 0; k < 4; k++)
    {
        int ni = i + mi[k];
        int nj = j + mj[k];
        if (!in(ni, nj) || vis[ni][nj] || grid[ni][nj] == '*')
            continue;
        Pair ch = dfs(ni, nj, colorIt);
        oc = max(oc, ch.ocean);
        total += ch.tot;
    }
    return {total, oc};
}

int go()
{
    priority_queue<pair<int, pair<int,int> > > pq;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                Pair ch = dfs(i, j, false);
                if (!ch.ocean)
                    pq.push({-ch.tot, {i, j}});
            }
        }

    int cnt = 0;
    int ch = pq.size() - k;
    memset(vis, 0, sizeof vis);
    while(ch--)
    {
        cnt += dfs(pq.top().I, pq.top().J, true).tot;
        pq.pop();
    }
    return cnt;
}


void input()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];
}

void output(int cnt)
{
    cout << cnt << endl;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cout << grid[i][j];
        cout << endl;
    }
}

int main()
{
    input();
    output(go());
    return 0;
}
