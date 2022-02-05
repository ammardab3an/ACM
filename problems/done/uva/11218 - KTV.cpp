#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define S second
#define V first

inline int Count(int x)
{
    int cnt = 0;
    for(int ii = 1; ii <= 9; ii++)
        if(x & (1 << ii))
            cnt++ ;
    return cnt;
}
int main()
{
//    freopen("D:\\input.txt", "r", stdin);
//    freopen("D:\\output.txt", "w", stdout);

    for(int T = 1; true; T++)
    {
        int n; cin >> n; if(!n) break;

        pii arr[100];

        for(int i = 0; i < n; i++)
        {
            int a, b, c, s;
            scanf("%d %d %d %d", &a, &b, &c, &s);
            arr[i] = {(1 << a) | (1 << b) | (1 << c), s};
        }

        int mx = -1;

        for(int i = 0+0; i < n; i++)
        for(int j = i+1; j < n; j++)
        for(int k = j+1; k < n; k++)
            if(Count(arr[i].V | arr[j].V | arr[k].V) == 9)
                mx = max(mx, arr[i].S + arr[j].S + arr[k].S);

        printf("Case %d: %d\n", T, mx);
    }
    return 0;
}
