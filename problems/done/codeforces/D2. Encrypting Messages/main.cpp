#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, c;
    cin >> n >> m >> c;

    int arr[100001];
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    int key[100001];
    for(int i = 1; i <= m; i++)
        scanf("%d", &key[i]);

    int sum[2][100001];
    sum[0][0] = sum[1][0] = 0;
    for(int i = 1; i <= m; i++)
    {
        sum[0][i] = sum[0][i-1] + key[i];
        sum[1][i] = sum[1][i-1] + key[m-i+1];
    }

    if((m-1)*2 <= n)
    {
        for(int i = 1; i < m; i++)
            arr[i] += sum[0][i];

        for(int i = m; i <= n-m+1; i++)
            arr[i] += sum[0][m];

        for(int i = n; i > n-m+1; i--)
            arr[i] += sum[1][n-i+1];
    }
    else
    {
        for(int i = 1; i <= n-m+1; i++)
            arr[i] += sum[0][i];

        for(int i = n; i >= m; i--)
            arr[i] += sum[1][n-i+1];

        for(int i = 1; i <= n-m+1; i++)
            for(int j = n-m+3 -i; j < m+1 -i; j++)
                arr[i+j-1] += key[j];
    }

    for(int i = 1; i <= n; i++)
        printf("%d ", arr[i] % c);

    return 0;
}
