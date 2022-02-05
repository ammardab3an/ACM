#include<bits/stdc++.h>

using namespace std;

// Variables declarations
pair<int, int> movArr[] = {{-1, -1}, {-1, 0}, {0, -1}, {0, +1}, {+1, 0}, {+1, +1}};
char grid[200][200];
bool vis[200][200];
int N;

bool in(int i, int j)
{
    return 0 <= i && i < N &&
           0 <= j && j < N;
}

bool dp(int i, int j, char w_b)
{
    if((w_b == 'w') && (j == N-1))
        return true;
    if((w_b == 'b') && (i == N-1))
        return true;

    vis[i][j] = true;

    for(auto p:movArr)
    {
        int ni = i + p.first;
        int nj = j + p.second;
        if(in(ni, nj) && !vis[ni][nj] && grid[ni][nj] == w_b)
        {
            if(dp(ni, nj, w_b))
                return true;
        }
    }
    return false;
}
int main()
{
    cin.tie(NULL);
    for(int T = 1; cin >> N && N; T++)
    {
        for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> grid[i][j];

        // while
        for(int i = 0; i < N; i++)
        {
            memset(vis, false, sizeof vis);
            if(grid[i][0] == 'w' && dp(i, 0, 'w'))
            {
                cout << T << ' ' << 'W' << endl;
                goto found;
            }
        }
        // black
        for(int j = 0; j < N; j++)
        {
            memset(vis, false, sizeof vis);
            if(grid[0][j] == 'b' && dp(0, j, 'b'))
            {
                cout << T << ' ' << 'B' << endl;
                goto found;
            }
        }
        found:;
    }
    return 0;
}
