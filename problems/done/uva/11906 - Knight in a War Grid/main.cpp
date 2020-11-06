#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 101
#define X first
#define Y second
#define pii pair<int, int>
int R, C, M, N;
bool grid[MAX][MAX];
bool  vis[MAX][MAX];
vector<pii> mv;

bool in(int x, int y)
{
    return 0 <= x && x < R &&
           0 <= y && y < C;
}
void fillMoveVec()
{
    mv = {{+M, +N}, {+M, -N}, {-M, +N}, {-M, -N},
          {+N, +M}, {+N, -M}, {-N, +M}, {-N, -M}};
}
void dfs(int x, int y)
{
    vis[x][y] = true;
    for(auto mp : mv)
    {
        int nx = x + mp.X;
        int ny = y + mp.Y;
        if (in(nx, ny) && !vis[nx][ny] && grid[nx][ny])
            dfs(nx, ny);
    }
}
pii cnt()
{
    int odd = 0, even = 0;

    for(int x = 0; x < R; x++) for(int y = 0; y < C; y++) if(vis[x][y])
    {
        int _cnt = 0;
        for(auto mp : mv)
        {
            int nx = x + mp.X;
            int ny = y + mp.Y;
            if(in(nx, ny) && grid[nx][ny])
                _cnt++;
        }
        if (N == M || !N || !M)
            _cnt /= 2;

        if (_cnt % 2)
            odd++;
        else
            even++;
    }

    return {even, odd};
}
int main()
{
    int T, W, wx, wy;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        memset(grid, 1, sizeof grid);
        memset(vis, 0, sizeof vis);
        cin >> R >> C >> M >> N;
        cin >> W;
        while(W--)
        {
            cin >> wx >> wy;
            grid[wx][wy] = 0;
        }
        fillMoveVec();
        dfs(0, 0);
        pii op = cnt();
        printf("Case %d: %d %d\n", t, op.first, op.second);
    }
    return 0;
}
