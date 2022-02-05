#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 1001
#define Pair pair<pair<int, int>, int>
#define I first.first
#define J first.second
#define L second
char grid[MAX][MAX];
bool vist[MAX][MAX];
int mi[] = {0, 0, -1, 1};
int mj[] = {-1, 1, 0, 0};
int r, c;

bool in(int i, int j)
{
    return 0 <= i && i < r && 0 <= j && j < c;
}
Pair dfs(int i, int j)
{
    int mxl = 0;
    int mxi = i;
    int mxj = j;

    vist[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int ni = i + mi[k];
        int nj = j + mj[k];
        if (!in(ni, nj) || vist[ni][nj] || grid[ni][nj] == '#')
            continue;
        Pair p = dfs(ni, nj);
        if (p.L +1 > mxl)
        {
            mxl = p.L +1;
            mxi = p.I;
            mxj = p.J;
        }
    }
    return {{mxi, mxj}, mxl};

}
int go()
{
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if (grid[i][j] == '.')
            {
                memset(vist, 0, sizeof vist);
                Pair p = dfs(i, j);
                memset(vist, 0, sizeof vist);
                return dfs(p.I, p.J).L;
            }
}
void input()
{
    cin >> c >> r;
    for(int i = 0; i < r; i++)
        cin >> grid[i];
}
void output(int len)
{
    cout << "Maximum rope length is " << len << "." << endl;
}
int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        input();
        output(go());
    }
    return 0;
}
