#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 501
#define pii pair<int, int>
#define ppi pair<pii, int>
#define X first.first
#define Y first.second
#define T second
int grid[MAX][MAX][4];
int visited[MAX][MAX][4];
pii mxy[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int r, c;

bool in(int x, int y)
{
    return 0 <= x && x < r &&
           0 <= y && y < c;
}

void bfs()
{
    memset(visited, 0, sizeof visited);
    visited[0][0][0] = true;

    pii np; ppi fp;
    int x, y, t, nx, ny;

    queue<ppi> q;
    q.push({{0,0},0});

    while (!q.empty())
    {
        fp = q.front(); q.pop();
        x = fp.X;
        y = fp.Y;
        t = fp.T;

        if(x == r-1 && y == c-1)
        {
            printf("%d\n", t);
            return;
        }
        for(int k = 0; k < 4; k++)
        {
            if(!grid[x][y][k])
                continue;
            np = mxy[(k+t)%4];
            nx = x + np.first;
            ny = y + np.second;

            if(in(nx, ny)&& !visited[nx][ny][(t+1)%4])
            {
                visited[nx][ny][(t+1)%4] = true;
                q.push({{nx, ny},t+1});
            }
        }
    }

    printf("no path to exit\n");
}
int main()
{
    map<char, int> mp;
    mp['N'] = 0;
    mp['E'] = 1;
    mp['S'] = 2;
    mp['W'] = 3;

    char inputChar[4];
    while(scanf("%d %d", &r, &c) == 2)
    {
        memset(grid, 0, sizeof grid);
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
            {
                if (i == r-1 && j == c-1)
                    break;
                scanf("%s", inputChar);
                for(int k = 0; k < strlen(inputChar); k++)
                    grid[i][j][mp[inputChar[k]]] = true;
            }
        bfs();
    }
    return 0;
}
