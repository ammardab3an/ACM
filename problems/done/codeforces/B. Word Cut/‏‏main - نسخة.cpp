#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10, mod = 1e9+7;
int ans = 0, f[N][2], K, n;
char a[N], b[N];

inline bool check(int x)
{
    for(int i = 1; i <= n; i++)
    {
        if(a[x] != b[i])
            return false;
        x++;
        if(x == n+1)
            x = 1;
    }
    return true;
}

int main()
{
    scanf("%s%s%d", a+1, b+1, &K);
    n = strlen(a+1);

    f[0][0] = 1;
    for(int i = 1; i <= K; i++)
    {
        f[i][0] = 1ll * f[i-1][1] * (n-1) % mod;
        f[i][1] = (f[i-1][0] + 1ll * f[i-1][1] * (n-2)) % mod;
    }

    for(int i = 1; i <= n; i++)
    if(check(i))
    {
        if(i == 1)
            ans = (ans + f[K][0]) % mod;
        else
            ans = (ans + f[K][1]) % mod;
    }

    cout << ans;
    return 0;
}
