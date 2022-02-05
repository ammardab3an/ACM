#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, mn, mx;
    cin >> n >> m >> mn >> mx;
    int _mn = INT_MAX, _mx = INT_MIN;
    for(int k = 0; k < m; k++)
    {
        int i;
        cin >> i;
        _mn = min(_mn, i);
        _mx = max(_mx, i);
    }

    bool b1 = _mn == mn && _mx == mx;
    bool b2 = int(_mn > mn) + int(_mx < mx) <= n - m;
    bool b3 = _mn < mn || _mx > mx;

    if (!b3 && (b1 || b2))
        cout << "Correct";
    else
        cout << "Incorrect";

    return 0;
}
