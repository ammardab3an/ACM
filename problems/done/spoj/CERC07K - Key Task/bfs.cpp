#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 101
char grid[MAX][MAX];
int vis[MAX][MAX][16];
int mi[4] = {-1, 1, 0, 0};
int mj[4] = {0, 0, -1, 1};
int r, c;

bool in(int i, int j)
{
    return 0 <= i && i < r && 0 <= j && j < c;
}
int re(int i, int j, int cnt, int colors)
{
    int mn = INT_MAX;
    vis[i][j][colors] = cnt;
    for(int k = 0; k < 4; k++)
    {
        int ni = i + mi[k];
        int nj = j + mj[k];
        int ncolors = colors;

        if (!in(ni, nj))
            continue;
        if (vis[ni][nj][ncolors] != -1)
        {
            if (vis[ni][nj][ncolors] > vis[i][j][colors] + 1)
                vis[ni][nj][ncolors] = vis[i][j][colors] + 1;
            else
                continue;
        }

        switch (grid[ni][nj])
        {
        case 'X':
            return cnt + 1;

        case '#':
            continue;

        case 'B':
            if (!(colors & 1))
                continue; break;
        case 'Y':
            if (!(colors & 2))
                continue; break;
        case 'R':
            if (!(colors & 4))
                continue; break;
        case 'G':
            if (!(colors & 8))
                continue; break;

        case 'b':
            ncolors |= 1; break;
        case 'y':
            ncolors |= 2; break;
        case 'r':
            ncolors |= 4; break;
        case 'g':
            ncolors |= 8; break;
        }
        mn = min(mn, re(ni, nj, cnt+1, ncolors));
    }
    return mn;
}
int go()
{
    int mn = INT_MAX;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if (grid[i][j] == '*')
            {
                memset(vis, -1, sizeof vis);
                mn = min(mn, re(i, j, 0, 0));
            }
    return (mn != INT_MAX) ? mn : 0;
}
void input()
{
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> grid[i][j];
}
void output(int s)
{
    if(s)
        cout << "Escape possible in " << s << " steps." << endl;
    else
        cout << "The poor student is trapped!" << endl;
}
int main()
{
    while(true)
    {
        cin >> r >> c;
        if (!r)
            break;
        input();
        output(go());
    }

    return 0;
}
