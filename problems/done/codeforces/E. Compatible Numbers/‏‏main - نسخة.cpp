#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int arr[1000000];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    map<int, int> mem;
    for(int i = 0; i < n; i++)
    {
        if(mem.count(arr[i]))
        {
            printf("%d ", mem[arr[i]]);
            goto endLoop;
        }

        for(int j = 0; j < n; j++)
        if(!(arr[i] & arr[j]))
        {
            mem[arr[j]] = arr[i];
            mem[arr[i]] = arr[j];
            printf("%d ", arr[j]);
            goto endLoop;
        }
        printf("-1 ");
        endLoop:;
    }

    return 0;
}
