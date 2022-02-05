#include <bits/stdc++.h>

using namespace std;

int L, R, C;
char dungeon[33][33][33];
int     vist[33][33][33];
int    mvArr[6][3] = {{0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};

bool in(int l, int r, int c)
{
    return 0 <= l && l < L &&
           0 <= r && r < R &&
           0 <= c && c < C;
}
void bfs(int sl, int si, int sj)
{
    memset(vist, -1, sizeof vist);
    vist[sl][si][sj] = 0;

    queue< array<int, 3> > que; que.push({sl, si, sj});

    while(!que.empty())
    {
        array<int, 3> fr = que.front(); que.pop();

        int fl = fr[0];
        int fi = fr[1];
        int fj = fr[2];
        int fc = vist[fl][fi][fj];

        if(dungeon[fl][fi][fj] == 'E')
        {
            printf("Escaped in %d minute(s).\n", fc);
            return;
        }

        for(auto a : mvArr)
        {
            int nl = fl + a[0];
            int ni = fi + a[1];
            int nj = fj + a[2];
            int nc = fc + 1;

            if(in(nl, ni, nj) && (dungeon[nl][ni][nj] != '#') && (vist[nl][ni][nj] == -1))
            {
                vist[nl][ni][nj] = nc;
                que.push({nl, ni, nj});
            }
        }
    }

    cout << "Trapped!" << endl;
}
int main()
{
    while(cin >> L >> R >> C && (L && R && C))
    {
        for(int l = 0; l < L; l++)
        for(int r = 0; r < R; r++)
            cin >> dungeon[l][r];

        for(int l = 0; l < L; l++)
        for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            if(dungeon[l][r][c] == 'S')
            {
                bfs(l, r, c); goto next;
            }
        next:;
    }
}
