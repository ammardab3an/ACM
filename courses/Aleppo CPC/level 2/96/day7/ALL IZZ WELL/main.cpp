#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 101
const string s = "ALLIZZWELL";
char grid[MAX][MAX];
bool vis[MAX][MAX];
int mi[8] = {0, 0, -1, -1, -1, 1, 1, 1};
int mj[8] = {1, -1, -1, 0, 1, -1, 0, 1};
int r, c;
bool ok;

bool in(int i, int j)
{
    return 0 <= i && i < r && 0 <= j && j < c;
}

void dfs(int i, int j, int idx)
{
    if (idx == 10)
    {
        ok = true;
        return;
    }
    for(int k = 0; k < 8; k++)
    {
        int ni = i + mi[k];
        int nj = j + mj[k];
        if (in(ni, nj) && !vis[ni][nj] && grid[ni][nj] == s[idx])
        {
            vis[i][j] = true;
            dfs(ni, nj, idx+1);
            vis[i][j] = false;
        }
    }
}

bool go()
{
    ok = false;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
        {
            if (grid[i][j] == 'A')
            {
                dfs(i, j, 1);
                if(ok)
                    return true;
            }
        }
    return false;
}

void input()
{
    cin >> r >> c;
    for(int i = 0; i < r; i++)
            cin >> grid[i];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        input();
        if(go())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
