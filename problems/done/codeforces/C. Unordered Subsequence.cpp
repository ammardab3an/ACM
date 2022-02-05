#include<bits/stdc++.h>

using namespace std;

bool goodToGo(int a, int b, int c)
{
    return !((a >= b && b >= c) || (a <= b && b <= c));
}
int main()
{
    int n, arr[100000];

    cin >> n;
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);


    int mn, imn, mx, imx;
    mn = INT_MAX; mx = INT_MIN;
    imn = imx = -1;

    int a, b, c = -1;

    for(int i = 0; i < n; i++)
    {
        if(i > 1)
        {
            if(imn < imx)
            {
                if(goodToGo(mn, mx, arr[i]))
                {
                    a = imn, b = imx, c = i;
                    goto found;
                }
            }
            else
            {
                if(goodToGo(mx, mn, arr[i]))
                {
                    a = imx, b = imn, c = i;
                    goto found;
                }
            }
        }
        mn = min(mn, arr[i]); imn = (mn == arr[i]) ? i : imn;
        mx = max(mx, arr[i]); imx = (mx == arr[i]) ? i : imx;
    }
    found:
    if(c != -1)
    {
        printf("3\n");
        printf("%d %d %d", a+1, b+1, c+1);
    }
    else
        cout << 0;
    return 0;
}
