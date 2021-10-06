#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 501
int  sum[MAX][MAX];
int grid[MAX][MAX];

int Sum(int x1, int y1, int x2, int y2)
{
    return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
}

int min(vector<int> l)
{
    int mn = l[0];
    for(int i = 1; i < l.size(); i++)
        mn = min(mn, l[i]);
    return mn;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        cin >> grid[i][j];
        sum[i][j] = grid[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
    }

    int mx = INT_MIN;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        int cur = grid[i][j];
        int lim = min({i-1, j-1, n-i, m-j});
        for(int d = 1; d <= lim; d++)
        {
            cur = Sum(i-d, j-d, i+d, j+d) - cur - grid[i-d+1][j-d];
            mx = max(mx, cur);
        }
    }

    cout << mx;
    return 0;
}
