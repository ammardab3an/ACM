#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

bool grid[55][55];
int N, M, B_1, B_2, E_1, E_2, face;
pii suArr[] = {{0, 0}, {-1, 0}, {-1, -1}, {0, -1}};
pii mvArr[] = {{-1, 0}, {0, 1}, {1, 0} , {0,  -1}};
map<string, int> mp = {{"north", 0}, {"east",  1}, {"south", 2}, {"west",  3}};

bool in(int i, int j)
{
    return 0 < i && i < N &&
           0 < j && j < M;
}
bool Clear(int i, int j)
{
    for(pii p : suArr)
        if(grid[i+p.first][j+p.second])
            return false;
    return true;
}
int bfs()
{
    bool vist[4][55][55];
    memset(vist, false, sizeof vist);
    vist[face][B_1][B_2] = true;

    queue< array<int, 4> > que; que.push({face, B_1, B_2, 0});
    while(!que.empty())
    {
        array<int, 4> fr = que.front(); que.pop();

        int ff = fr[0];
        int fi = fr[1];
        int fj = fr[2];
        int fc = fr[3];

        if(fi == E_1 and fj == E_2)
            return fc;

        for(int nf : {(ff + 1)%4, (ff + 3)%4}) if(!vist[nf][fi][fj]++)
            que.push({nf, fi, fj, fc+1});

        for(int k = 1; k < 4; k++)
        {
            int ni = fi + mvArr[ff].first    *k;
            int nj = fj + mvArr[ff].second   *k;

            if(!(in(ni, nj) && Clear(ni, nj)))
                break;

            if(!vist[ff][ni][nj]++)
                que.push({ff, ni, nj, fc+1});
        }
    }
    return -1;
}
int main()
{
    while(cin >> N >> M && M)
    {
        for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> grid[i][j];

        string face_str;
        cin >> B_1 >> B_2 >> E_1 >> E_2 >> face_str;
        face = mp[face_str];

        cout << bfs() << endl;
    }
}
