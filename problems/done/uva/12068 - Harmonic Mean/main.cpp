#include<bits/stdc++.h>

using namespace std;

int main()
{
    int s, n;
    long long arr[10], lcm, gcd, on, under;

    cin >> s;
    for (int k = 1; k <= s; k++)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        lcm = 1;
        for (int i = 0; i < n; i++)
            lcm = (lcm * arr[i]) / __gcd(lcm, arr[i]);

        on = 0;
        for (int i = 0; i < n; i++)
            on += lcm / arr[i];

        under = lcm * n;

        gcd = __gcd(on, under);
        on /= gcd;
        under /= gcd;

        cout << "Case " << k << ": " << under << "/" << on << endl;
    }
    return 0;
}
