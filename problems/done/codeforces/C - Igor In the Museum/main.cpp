#include <bits/stdc++.h>

using namespace std;

char grid[1000][1000];
int vis[1000][1000];
int ans[100000];
int n, m, k;
pair<int,int> mvArr[] = {{+1, 0}, {0, +1}, {-1, 0}, {0, -1}};
bool in(int i, int j)
{
    return 0 <= i && i < n &&
           0 <= j && j < m;
}
int dfs(int i, int j, int id)
{
    vis[i][j] = id;
    int ni, nj, cnt = 0;

    for(auto p:mvArr)
    {
        ni = i + p.first;
        nj = j + p.second;
        if(in(ni, nj))
        {
            if(grid[ni][nj] == '.')
            {
                if(vis[ni][nj] == -1)
                    cnt += dfs(ni, nj, id);
            }
            else cnt++;
        }
    }
    return cnt;
}
int main()
{
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> grid[i];

    memset(vis, -1, sizeof vis);
    for(int i, j, cnt; k && cin >> i >> j; k--)
    {
        i--, j--;
        if(vis[i][j] == -1)
            cnt = ans[k] = dfs(i, j, k);
        else
            cnt = ans[vis[i][j]];
        cout << cnt << endl;
    }
    return 0;
}
