#include<bits/stdc++.h>

using namespace std;

int mem[4040];
int n, a, b, c;

int dp(int len)
{
    if (!len)
        return 0;
    if (len < 0)
        return INT_MIN;
    // this if statement should be after checking that (len >= 0);
    if (mem[len] != -1)
        return mem[len];

    int path_1 = 1+dp(len -a);
    int path_2 = 1+dp(len -b);
    int path_3 = 1+dp(len -c);

    return mem[len] = max({path_1, path_2, path_3});
}
int main()
{
    cin >> n >> a >> b >> c;
    memset(mem, -1, sizeof mem);
    cout << dp(n);
    return 0;
}
