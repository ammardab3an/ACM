// By AmmarDab3an - Aleppo University

#include <bits/stdc++.h>

using namespace std;

typedef long long lli;

const int N = 18;

int n, m, k;
int arr[N];
int rul[N][N];
lli mem[1 << N][N];

lli dp(int msk, int last){

    lli & ret = mem[msk][last];
    if(ret != -1) return ret;
    if(__builtin_popcount(msk) == m) return 0;

    ret = 0;

    for(int i = 0; i < n; i++) if(~msk & (1 << i))

        ret = max(ret, (lli)arr[i] + dp(msk | (1 << i), i) + (lli)rul[last][i]);

    return ret;
}

int main()
{
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        cin >> rul[x-1][y-1];
    }

    memset(mem, -1, sizeof mem);

    lli ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, arr[i] + dp(1 << i, i));

    cout << ans;
}
