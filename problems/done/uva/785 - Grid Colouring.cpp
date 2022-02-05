#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int N;
char grid[33][88];
bool visted[33][88];

pii mvArr[] = {{0, 1},{1, 0},{0,-1},{-1,0}};

void bfs(int i, int j, char color)
{
    queue<pii> que; que.push({i, j});
    while(!que.empty())
    {
        pii cu = que.front(); que.pop();
        int ci = cu.first;
        int cj = cu.second;

        grid[ci][cj] = color;

        for(auto to : mvArr)
        {
            int ti = ci + to.first;
            int tj = cj + to.second;
            if(grid[ti][tj] != 'X' and !visted[ti][tj]++)
                que.push({ti, tj});
        }
    }
}

int main()
{
//    freopen("D:\\input.txt", "r", stdin);
//    freopen("D:\\output.txt", "w", stdout);

    while(true)
    {
        int n = 0;
        while(true)
        {
            if(!cin.getline(grid[n], 256))
                return 0;

            if(grid[n][0] == '_')
                break;

            n++;
        }

        memset(visted, false, sizeof visted);

        for(int i = 0; i < n; i++)
        for(int j = 0; grid[i][j]; j++)
            if(grid[i][j] != 'X' and grid[i][j] != ' ' and !visted[i][j]++ )
                bfs(i, j, grid[i][j]);

        for(int i = 0; i < n; i++)
            cout << grid[i] << endl;

        cout << "_____________________________" << endl;
    }
}
