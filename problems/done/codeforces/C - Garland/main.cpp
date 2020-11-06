#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, even;
int arr[N];
int dp[N][N][2];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        even += (i%2 == 0);
    }

    for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++)
        dp[i][j][0] = dp[i][j][1] = 1e9;

    dp[0][0][0] = dp[0][0][1] = 0;
    for(int i = 1; i <= n; i++)
    for(int j = 0; j <  i; j++)
    for(int k = 0; k <= 1; k++)
    {
        int t = dp[i-1][j][k];
        if(arr[i])
        {
            if(arr[i]%2)
                dp[i][j][1] = min(dp[i][j][1], t + (k != 1));
            else
                dp[i][j+1][0] = min(dp[i][j+1][0], t + (k != 0));
        }
        else
        {
            for(int l = 0; l <= 1; l++)
                dp[i][j +1 -l][l] = min(dp[i][j +1 -l][l], t + (k != l));
        }
    }
    cout << min(dp[n][even][0], dp[n][even][1]);
}
