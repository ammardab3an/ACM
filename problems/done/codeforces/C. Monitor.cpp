#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int gcd = __gcd(x, y);
    x /= gcd;
    y /= gcd;

    double x_i, y_i, sz, mxa, mxb, mxs;
    mxa = mxb = mxs = 0;

    for(double i = 1; true; i++)
    {
        x_i = x * i;
        y_i = y * i;
        sz = x_i * y_i;

        if (x_i > a || y_i > b)
            break;
        if (sz > mxs)
        {
            mxs = sz;
            mxa = x_i;
            mxb = y_i;
        }
    }

    cout << int(mxa) << " " << int(mxb) << endl;
    return 0;
}
