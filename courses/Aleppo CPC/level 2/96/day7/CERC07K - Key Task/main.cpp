#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 101
#define pos pair<pair<int,int>,int>
#define I first.first
#define J first.second
#define K second
char grid[MAX][MAX];
int  dist[MAX][MAX][16];
int  mi[4] = {-1, 1, 0, 0};
int  mj[4] = {0, 0, -1, 1};
int  n, m;

int bfs(int si, int sj)
{
    queue<pos> q;
    q.push({{si,sj},0});
    dist[si][sj][0] = 0;

    while(!q.empty())
    {
        pos t = q.front(); q.pop();
        int i = t.I;
        int j = t.J;
        int k = t.K;

        if (grid[i][j] == 'X')
            return dist[i][j][k];

        for(int f = 0; f < 4; f++)
        {
            int ni = i + mi[f];
            int nj = j + mj[f];
            int nk = k;

            if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                continue;

            switch (grid[ni][nj])
            {
            case '#':
                continue;

            case 'B':
                if (!(k & 1)) continue; break;
            case 'Y':
                if (!(k & 2)) continue; break;
            case 'R':
                if (!(k & 4)) continue; break;
            case 'G':
                if (!(k & 8)) continue; break;

            case 'b':
                nk |= 1; break;
            case 'y':
                nk |= 2; break;
            case 'r':
                nk |= 4; break;
            case 'g':
                nk |= 8; break;
            }

            if (dist[ni][nj][nk] != -1)
                continue;

            dist[ni][nj][nk] = dist[i][j][k] + 1;
            q.push({{ni, nj}, nk});
        }
    }
    return INT_MAX;
}

int main()
{
    while(true)
    {
        scanf("%d %d", &n, &m);
        if (!n)
            break;
        for(int i = 0; i < n; i++)
            scanf("%s", &grid[i]);

        int mn = INT_MAX;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if (grid[i][j] == '*')
                {
                    memset(dist, -1, sizeof dist);
                    mn = min(mn, bfs(i, j));
                }

        if(mn != INT_MAX)
            printf("Escape possible in %d steps.\n",mn);
        else
            printf("The poor student is trapped!\n");
    }

    return 0;
}
