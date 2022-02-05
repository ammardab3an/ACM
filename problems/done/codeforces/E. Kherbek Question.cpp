#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, n;
    for(cin >> T;T && cin >> n;T--)
    {
        if(n % 2) n++;
        if(n % 4)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}
