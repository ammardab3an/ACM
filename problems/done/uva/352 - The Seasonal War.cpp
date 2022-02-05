#include<bits/stdc++.h>

using namespace std;

// variables declarations
pair<int, int> mvArr[] = {{+1, +1}, {+1, 0}, {0, +1}, {-1, 0}, {0, -1}, {-1, -1}, {-1, +1}, {+1, -1}};
bool grid[25][25], vis[25][25];
int N;

bool in(int i, int j)
{
    return 0 <= i && i < N &&
           0 <= j && j < N;
}
void dp(int i, int j)
{
    vis[i][j] = true;
    for(auto p:mvArr)
    {
        int ni = i + p.first;
        int nj = j + p.second;
        if(in(ni, nj) && grid[ni][nj] && !vis[ni][nj])
            dp(ni, nj);
    }
}
int main()
{
    cin.tie(NULL);
    for(int T = 1; cin >> N; T++)
    {
        char c;
        for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            cin >> c;
            grid[i][j] = (c == '1') ? true : false;
        }

        int result = 0;
        memset(vis, false, sizeof vis);
        for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(grid[i][j] && !vis[i][j])
            {
                dp(i, j);
                result++;
            }
        printf("Image number %d contains %d war eagles.\n", T, result);
    }
    return 0;
}
