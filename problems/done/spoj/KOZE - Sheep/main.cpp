#include <iostream>
#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 251
#define Pair pair<pair<int,int>,bool>
#define k_cnt first.first
#define v_cnt first.second
#define canGo second
array<array<char,MAX>,MAX> grid;
array<array<bool,MAX>,MAX> vis;
int mi[4] = {0, 0, 1, -1};
int mj[4] = {-1, 1, 0, 0};
int n, m;

bool in(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

bool atBrd(int x, int y)
{
    return x == n || x == 1 || y == 1 || y == m;
}

Pair dfs(int i, int j)
{
    vis[i][j] = true;
    int K, V;
    K = V = 0;
    if (grid[i][j] == 'k')
        K++;
    else if (grid[i][j] == 'v')
        V++;
    bool b = atBrd(i, j);

    for(int k = 0; k < 4; k++)
    {
        int ni = i + mi[k];
        int nj = j + mj[k];
        if (!in(ni,nj) || vis[ni][nj] || grid[ni][nj] == '#')
            continue;
        Pair p = dfs(ni, nj);
        K += p.k_cnt;
        V += p.v_cnt;
        b = max(b, p.canGo);
    }
    return {{K, V}, b};
}

void go()
{
    int K = 0;
    int V = 0;
    for (int i = 2; i < n; i++)
        for (int j = 2; j < m; j++)
            if (!vis[i][j])
            {
                Pair p = dfs(i,j);
                if (p.canGo)
                {
                    V += p.v_cnt;
                    K += p.k_cnt;
                }
                else
                {
                    if (p.k_cnt > p.v_cnt)
                        K += p.k_cnt;
                    else
                        V += p.v_cnt;
                }
            }
    cout << K << " " << V;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];

    go();
    return 0;
}
