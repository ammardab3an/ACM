#include<bits/stdc++.h>

using namespace std;

int x[10000001];
int main()
{
    int a, n;
    cin >> a >> n;

    for(int i = a; i < a+n; i++)
        x[i] = i;

    for(int i = 2; i*i < a+n; i++)
    {
        int p = i*i;
        int t = ((a+p-1)/p)*p;

        for(int j = t; j < a+n; j += p)
            while(x[j] % p == 0)
                x[j] /= p;
    }

    long long ans = 0;
    for(int i = a; i < a+n; i++)
        ans += x[i];
    cout << ans;

    return 0;
}
