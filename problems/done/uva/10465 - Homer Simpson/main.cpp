#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
pii mem[10010];
int m, n, t;

pii mxPair(pii p1, pii p2)
{
    if(p1.second == p2.second)
        return((p1.first > p2.first) ? p1 : p2);
    else
        return((p1.second < p2.second) ? p1 : p2);
}
pii go(int t)
{
    if(t < n)
        return {0, t};

    if(mem[t].first != -1)
        return mem[t];

    pii ans = go(t - n);

    if(t >= m) ans = mxPair(ans, go(t - m));
    ans.first++;

    return mem[t] = ans;
}
int main()
{
//    freopen("D:\\input.txt", "r", stdin);
//    freopen("D:\\output.txt", "w", stdout);

    while(cin >> m >> n >> t)
    {
        if(n > m)
            swap(n, m);

        for(int i = 0; i < 10010; i++)
            mem[i] = {-1, -1};

        pii ans = go(t);

        if(ans.second)
            cout << ans.first << ' ' << ans.second << endl;
        else
            cout << ans.first << endl;
    }
}
