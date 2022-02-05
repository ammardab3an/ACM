#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, c;
    cin >> n >> m >> c;

    int arr[100000];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int key[100000];
    for(int i = 0; i < m; i++)
        scanf("%d", &key[i]);

    for(int i = 0; i < n-m+1; i++)
    for(int j = 0; j < m; j++)
        arr[i+j] += key[j];

    for(int i = 0; i < n; i++)
        arr[i] %= c;

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
