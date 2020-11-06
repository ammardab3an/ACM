#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int vist[8][8];
pii mvArr[] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};

bool in(int i, int j)
{
    return 0 <= i && i < 8 &&
           0 <= j && j < 8;
}

int bfs(int fi, int fj, int ti, int tj)
{
    memset(vist, 0, sizeof vist);
    vist[fi][fj] = 1;

    queue<pii> que; que.push({fi, fj});

    while(!que.empty())
    {
        pii fr = que.front(); que.pop();

        int nc = vist[fr.first][fr.second] +1;

        if(fr == (pii){ti, tj})
            return nc -2;

        for(auto p : mvArr)
        {
            int ni = fr.first  + p.first;
            int nj = fr.second + p.second;

            if(in(ni, nj) && !vist[ni][nj])
            {
                vist[ni][nj] = nc;
                que.push({ni, nj});
            }
        }
    }
}
int main()
{

    string fr, to;
    while(cin >> fr >> to)
    {
        int dis = bfs(8 - (fr[1] - '0'), fr[0] - 'a', 8 - (to[1] - '0'), to[0] - 'a');
        printf("To get from %s to %s takes %d knight moves.\n", fr.c_str(), to.c_str(), dis);
    }
}
