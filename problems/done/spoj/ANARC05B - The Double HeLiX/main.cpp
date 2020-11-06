#include <iostream>
#include<bits/stdc++.h>

using namespace std;

//declaration
int oo = 1e9;
int n[2];           //first_n = n[0], second_n = n[1]
int a[2][10001];

bool mem[2][10001][2];
int val[2][10001][2];

int bs(bool an, int wanted)
{
    int l,r,m;
    l = 0;
    r = n[an] -1;

    while (r >= l)
    {
        m = (r + l)/2;
        if (wanted == a[an][m])
            return m;
        if (wanted > a[an][m])
            l = m+1;
        else
            r = m-1;
    }
    return -1;
}

int dp(bool an, int index, bool iCan)
{
    if (mem[an][index][iCan])
        return val[an][index][iCan];

    if (index >= n[an])
        return 0;

    int path_1 = a[an][index] + dp(an, index +1, 1);

    int path_2 = -oo;
    if (iCan)
    {
        int f = bs(!an, a[an][index]);
        if (f != -1)
            path_2 = dp(!an, f, 0);
    }

    mem[an][index][iCan] = 1;
    return val[an][index][iCan] = max(path_1, path_2);
}

int main()
{
    while (true)
    {
        scanf("%d",&n[0]);
        if (n[0] == 0)
            break;
        for (int i = 0; i < n[0]; i++)
            scanf("%d",&a[0][i]);

        scanf("%d",&n[1]);
        for (int i = 0; i < n[1]; i++)
            scanf("%d",&a[1][i]);

        printf("%d\n", max(dp(0,0,1), dp(1,0,1)));

        memset(mem, 0, sizeof mem);
    }
    return 0;
}
