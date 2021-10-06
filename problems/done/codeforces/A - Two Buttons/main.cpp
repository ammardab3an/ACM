
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int cnt = 0;
    while(m > n)
    {
        n *= 2;
        cnt++;
    }

    for(int i = cnt; i >= 0; i--)
    {
        while((n - pow(2, i)) >= m)
        {
            n -= pow(2, i);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
