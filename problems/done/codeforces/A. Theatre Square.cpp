#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a;
    cin >> n >> m >> a;
    int _n = int(n/a) * a;
    int _m = int(m/a) * a;

    if (_n < n)
        _n += a;
    if (_m < m)
        _m += a;

    long long int _a_ = (_n / a), _b_ = (_m / a);
    cout << _a_ * _b_;


    return 0;
}
