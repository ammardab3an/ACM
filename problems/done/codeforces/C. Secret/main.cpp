#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if (3*k > n)
    {
        cout << -1;
        return 0;
    }

    for(int i = 1; i <= k; i++)
        printf("%d ", i);

    for(int i = 1; i <= k; i++)
        printf("%d %d ", i, i);

    for(int i = 3*k+1; i <= n; i++)
        printf("%d ", 1);

    return 0;
}
