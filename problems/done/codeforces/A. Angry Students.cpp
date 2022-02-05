// By AmmarDab3an - Aleppo University

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    for(cin >> t; t--;)
    {
        int ans = 0;
        int cnt = 0;

        int n; cin >> n;

        bool thereIsOn = false;
        for(int i = 0; i < n; i++)
        {
            char c; cin >> c;

            if(c == 'A')
                cnt =  0, thereIsOn = true;

            else if(thereIsOn)
                ans = max(ans, ++cnt);
        }
        cout << ans << endl;
    }
}
