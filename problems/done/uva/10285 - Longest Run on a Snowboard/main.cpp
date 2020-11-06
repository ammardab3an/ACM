#include <bits/stdc++.h>

using namespace std;

int R, C;
int grid[100][100];
bool vis[100][100];
int  mem[100][100];
pair<int, int> mvArr[] = {{-1, 0}, {0, -1}, {+1, 0}, {0, +1}};

inline bool in(int i, int j)
{
    return 0 <= i && i < R &&
           0 <= j && j < C;
}
int go(int i, int j)
{
    if(mem[i][j] != -1)
        return mem[i][j];

    vis[i][j] = true;

    int mx = 0;
    for(auto p:mvArr)
    {
        int ni = i + p.first;
        int nj = j + p.second;
        if(in(ni, nj) && !vis[ni][nj] && grid[ni][nj] < grid[i][j])
            mx = max(mx, 1+go(ni, nj));
    }

    vis[i][j] = false;
    return mem[i][j] = mx;
}
int main()
{
    int N;
    for(cin >> N;N;N--)
    {
        string name;
        cin >> name >> R >> C;

        for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> grid[i][j];

        memset(mem, -1, sizeof mem);

        int mx = 0;
        for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
        {
            memset(vis, false, sizeof vis);
            mx = max(mx, 1+go(i, j));
        }

        printf("%s: %d\n", name.c_str(), mx);
    }
}
