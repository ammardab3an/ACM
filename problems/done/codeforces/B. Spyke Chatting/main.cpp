#include<bits/stdc++.h>

using namespace std;

int grid[200001][11];
int empCnt[200001];
int chatNo[11];

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for(int e = 1; e <= n; e++)
    for(int c = 1; c <= m; c++)
        scanf("%d", &grid[e][c]);

    memset(empCnt, 0, sizeof empCnt);
    memset(chatNo, 0, sizeof chatNo);
    while(k--)
    {
        int e, c;
        scanf("%d %d", &e, &c);
        chatNo[c]++;
        empCnt[e]--;
    }

    for(int ch = 1; ch <= m; ch++) if(chatNo[ch])
    for(int em = 1; em <= n; em++) if(grid[em][ch])
            empCnt[em] += chatNo[ch];

    for(int e = 1; e <= n; e++)
        printf("%d ", empCnt[e]);

    return 0;
}
