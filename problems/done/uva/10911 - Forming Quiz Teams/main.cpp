#include<bits/stdc++.h>

using namespace std;

double dist[16][16], mem[1<<16];
int N;

double dp(int mask)
{
    if(mem[mask] > -0.5)
        return mem[mask];
    if(mask == (1 << 2*N) -1)
        return mem[mask] = 0;

    double mn = pow(INT_MAX,2);
    for(int s1 = 0; s1 < 2*N; s1++) if(!(mask & 1 << s1))
    {
        for(int s2 = s1+1; s2 < 2*N; s2++) if(!(mask & 1 << s2))
            mn = min(mn, dist[s1][s2] + dp(mask | 1 << s1 | 1 << s2));
        return mem[mask] = mn;
    }
}
int main()
{
    for(int T = 1; true; T++)
    {
        cin >> N;
        if(!N) break;

        memset(mem, -1, sizeof mem);

        string name; int x[16], y[16];
        for(int i = 0; i < 2*N; i++)
            cin >> name >> x[i] >> y[i];

        for(int i = 0; i < 2*N; i++)
        for(int j = 0; j < 2*N; j++)
            dist[i][j] =
                sqrt( pow((x[i]-x[j]), 2) + pow((y[i]-y[j]), 2) );

        printf("Case %d: %.2f\n", T, dp(0));
    }
    return 0;
}
