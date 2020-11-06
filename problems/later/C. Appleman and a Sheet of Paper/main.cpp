#include<bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("D:\\output.txt", "w", stdout);

    int sheet[500000];
    memset(sheet, 0, sizeof sheet);

    int n, q, I = 0;
    scanf("%d%d", &n, &q);

    for(int i = 1; i <= n; i++)
        sheet[i] = 1;

    while(q--)
    {
        int a, b, c;
        scanf("%d%d", &a, &b);
        if(a == 1)
        {
            if(I+n > 400000)
            {
                for(int i = 1; i <= n; i++)
                    sheet[i] = sheet[I+i];
                memset(sheet+n+1, 0, I*sizeof(int))
                I = 0;
            }
            for(int i = 1; i <= b; i++)
                sheet[I+b+i] += sheet[I+b-i+1];
            I += b;
        }
        else
        {
            scanf("%d", &c);
            int tot = 0;
            for(int i = c; i > b; i--)
                tot += sheet[I+i];
            printf("%d\n", tot);
        }
    }

    return 0;
}
