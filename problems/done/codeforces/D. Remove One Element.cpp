#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5;

int arr[MAX];
int  dp[MAX][2];

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < 2; j++){

        dp[i][j] = max(dp[i][j] , 1);

        if(arr[i] < arr[i+1])
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + 1);

        if(j && arr[i] < arr[i+2])
            dp[i+2][0] = max(dp[i+2][0], dp[i][1] + 1);

        ans = max(ans, dp[i][j]);
    }

    cout << ans;
}
