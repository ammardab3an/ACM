#include<bits/stdc++.h>

using namespace std;

vector<int> fac(int n)
{
    vector<int> v;
    int i = 2;
    while(n > 1)
    {
        if (!(n%i))
        {
            v.push_back(i);
            n = n / i;
        }
        else
            i++;
    }
    return v;
}
pair<int, int> simplest(int x, int y)
{
    vector<int> x_f, y_f;
    x_f = fac(x);
    y_f = fac(y);

    vector<int> common;
    set_intersection(x_f.begin(), x_f.end(), y_f.begin(), y_f.end(), back_inserter(common));

    x_f.erase(set_difference(x_f.begin(), x_f.end(),common.begin(), common.end(),x_f.begin()), x_f.end());
    y_f.erase(set_difference(y_f.begin(), y_f.end(),common.begin(), common.end(),y_f.begin()), y_f.end());

    int nx, ny;
    nx = ny = 1;

    for(auto i:x_f)
        nx *= i;

    for(auto i:y_f)
        ny *= i;
    return {nx, ny};
}
int main()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    pair<int, int> s = simplest(x, y);
    x = s.first;
    y = s.second;

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
