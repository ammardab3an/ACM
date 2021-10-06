#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int  R, C, CTS;
char grid[20][20];
int  vist[20][20];
pii  mvArr[] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
map<char, int> mp = {{'E', 0}, {'N', 1}, {'W', 2}, {'S', 3}};

bool in(int i, int j)
{
    return 0 <= i && i < R &&
           0 <= j && j < C;
}
void bfs()
{
    memset(vist, -1, sizeof vist);
    vist[0][CTS] = 0;

    queue<pii> que;
    que.push({0, CTS});

    while(!que.empty())
    {
        pii fp = que.front(); que.pop();

        int i = fp.first;
        int j = fp.second;
        pii nij = mvArr[mp[grid[i][j]]];

        int ni = i + nij.first;
        int nj = j + nij.second;
        int nv = vist[i][j] +1;

        if(!in(ni, nj)){
            cout << nv << " step(s) to exit" << endl;
            return;
        }

        if(vist[ni][nj] != -1){
            cout << vist[ni][nj] << " step(s) before a loop of " << nv - vist[ni][nj] << " step(s)" << endl;
            return;
        }

        vist[ni][nj] = nv;
        que.push({ni, nj});
    }
}
int main()
{
    while(cin >> R >> C >> CTS && CTS--)
    {
        for(int r = 0; r < R; r++)
            cin >> grid[r];
        bfs();
    }
}
