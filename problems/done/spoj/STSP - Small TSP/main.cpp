// By AmmarDab3an - Aleppo University

#include <bits/stdc++.h>

using namespace std;

const int N = 18;

int n, beg;
int dis[N][N];
int mem[1 << N][N];

int dp(int msk, int last){

    int & ret = mem[msk][last];
    if(ret != -1) return ret;
    if(__builtin_popcount(msk) == n) return dis[last][beg];

    ret = INT_MAX;

    for(int i = 0; i < n; i++) if(~msk & (1 << i))
        ret = min(ret, dis[last][i] + dp(msk | (1 << i), i));

    return ret;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        cin >> dis[i][j];

    memset(mem, -1, sizeof mem);

    int ans = INT_MAX;
    for(beg = 0; beg < n; beg++)
        ans = min(ans, dp(1 << beg, beg));

    cout << ans;
}
