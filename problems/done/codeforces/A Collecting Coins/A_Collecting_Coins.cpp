// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    for(cin >> t; t--;)
    {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        
        int mx = max(a, max(b, c));
        
        n -= mx - a;
        n -= mx - b;
        n -= mx - c;

        if(n >= 0 && n%3 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}