#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    for(cin >> t; t--;)
    {
        int r, g, b;
        cin >> r >> g >> b;

        if(r-1 > g+b || g-1 > r+b || b-1 > r+g)
        {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
}
