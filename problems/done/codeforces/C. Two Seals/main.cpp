#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, n, m;
    cin >> k >> n >> m;
    if(n > m) swap(n, m);

    int arr[100][2];
    for(int i = 0; i < k; i++)
        cin >> arr[i][0] >> arr[i][1];

    int ans = 0;

    for(int i =  0 ; i < k; i++)
    for(int j = i+1; j < k; j++)
    {

        for(int ii = 0; ii < 2; ii++)
        for(int jj = 0; jj < 2; jj++)
        {
            int sz[2] = {(arr[i][ii] + arr[j][jj]), max(arr[i][(ii+1)%2], arr[j][(jj+1)%2])};

            if(min(sz[0], sz[1]) <= n  &&
               max(sz[0], sz[1]) <= m)
                ans = max(ans, arr[i][0]*arr[i][1] + arr[j][0]*arr[j][1]);
        }
    }

    cout << ans;
}
