#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 101
char grid[MAX][MAX];
int  dist[MAX][MAX][16];
int  mi[4] = {-1, 1, 0, 0};
int  mj[4] = {0, 0, -1, 1};
int  r, c;

int re(int i, int j, int cnt, int colors)
{
    int ni, nj, ncolors, mn = INT_MAX;
    dist[i][j][colors] = cnt;
    for(int k = 0; k < 4; k++)
    {
        ni = i + mi[k];
        nj = j + mj[k];

        if (0 > ni || ni >= r || 0 > nj || nj >= c)
            continue;

        if (dist[ni][nj][colors] != -1)
        {
            if (dist[ni][nj][colors] > dist[i][j][colors] + 1)
                dist[ni][nj][colors] = dist[i][j][colors] + 1;
            else
                continue;
        }

        ncolors = colors;
        switch (grid[ni][nj])
        {
        case '#':
            continue;

        case 'X':
            return cnt + 1;

        case 'B':
            if (!(colors & 1))
                continue;
            break;
        case 'Y':
            if (!(colors & 2))
                continue;
            break;
        case 'R':
            if (!(colors & 4))
                continue;
            break;
        case 'G':
            if (!(colors & 8))
                continue;
            break;

        case 'b':
            ncolors |= 1;
            break;
        case 'y':
            ncolors |= 2;
            break;
        case 'r':
            ncolors |= 4;
            break;
        case 'g':
            ncolors |= 8;
            break;
        }
        mn = min(mn, re(ni, nj, cnt+1, ncolors));
    }
    return mn;
}

int main()
{
    while(true)
    {
        scanf("%d %d", &r, &c);
        if (!r)
            break;
        int mn = INT_MAX;
        for(int i = 0; i < r; i++)
            scanf("%s", &grid[i]);
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if (grid[i][j] == '*')
                {
                    memset(dist, -1, sizeof dist);
                    mn = min(mn, re(i, j, 0, 0));
                }

        if(mn != INT_MAX)
            printf("Escape possible in %d steps.\n", mn);
        else
            printf("The poor student is trapped!\n");
    }

    return 0;
}
