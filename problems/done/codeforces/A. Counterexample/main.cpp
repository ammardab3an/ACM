#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long l, r;
    cin >> l >> r;
    for(long long a = l  ; a <= r; a++)
    for(long long b = a+1; b <= r; b++) if(__gcd(a, b) == 1)
    for(long long c = b+1; c <= r; c++) if(__gcd(b, c) == 1)
        if(__gcd(a, c) != 1)
        {
            cout << a << ' ' << b << ' ' << c;
            return 0;
        }
    cout << -1;
}
