#include<bits/stdc++.h>

using namespace std;

//declarations
#define pii pair<int,int>
#define ppp pair<pii,pii>
#define I first
#define J second
#define A first
#define B second
#define MAX 2000
char grid[MAX][MAX];
int n, m;

pii mij[] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
bool in(int i, int j)
{
    return 0 <= i && i < n &&
           0 <= j && j < m;
}

pii check(int i, int j)
{
    int ii = -1, jj = -1;
    for(int k = 0; k < 4; k++)
    {
        int ni = i + mij[k].I;
        int nj = j + mij[k].J;
        if(in(ni, nj) && grid[ni][nj] == '.')
        {
            if(jj != -1)
                return {-1, -1};
            ii = ni, jj = nj;
        }
    }
    return {ii, jj};
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        cin >> grid[i][j];

    queue<ppp> que;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(grid[i][j] == '.')
    {
        pii ch = check(i, j);
        if(ch.I != -1)
            que.push({{i, j}, {ch.I, ch.J}});
    }

    while(!que.empty())
    {
        ppp top = que.front(); que.pop();

        if(grid[top.A.I][top.A.J] != '.' ||
           grid[top.B.I][top.B.J] != '.') continue;

        char a, b;
        if(top.B.I > top.A.I)
            a = '^', b = 'v';
        else if(top.B.I < top.A.I)
            a = 'v', b = '^';
        else if(top.B.J > top.A.J)
            a = '<', b = '>';
        else
            a = '>', b = '<';

        grid[top.A.I][top.A.J] = a;
        grid[top.B.I][top.B.J] = b;

        for(auto p:{top.A, top.B})
        for(int k = 0; k < 4; k++)
        {
            int ni = p.I + mij[k].I;
            int nj = p.J + mij[k].J;
            if(!in(ni, nj)) continue;
            pii ch = check(ni, nj);
            if(ch.I != -1)
                que.push({{ni, nj},{ch.I, ch.J}});
        }
    }

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(grid[i][j] == '.')
    {
        cout << "Not unique";
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << grid[i][j];
        cout << endl;
    }

    return 0;
}
