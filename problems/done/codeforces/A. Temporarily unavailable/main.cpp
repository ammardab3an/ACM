#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, a, b, c, r;
    for(cin >> t; t--;)
    {
        cin >> a >> b >> c >> r;

        if(a > b)
            swap(a, b);

        int low = max(a, c - r);
        int hi  = min(b, c + r);

        cout << b - a - max(hi - low, 0) << endl;
    }
}
