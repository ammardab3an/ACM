#include <bits/stdc++.h>

#define int int64_t
#define endl '\n'

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n = 6;

    vector<int> a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    int x = 0;
    int y = 6*6;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        x += a[i] > b[j];
    }

    int g = __gcd(x, y);
    x /= g, y /= g;

    cout << x << '/' << y << endl;
}
