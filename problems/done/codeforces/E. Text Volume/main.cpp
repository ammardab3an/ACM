#include <bits/stdc++.h>

using namespace std;

//declarations


int main()
{
    int len;
    cin >> len;
    cin.ignore(INT_MAX, '\n');

    int mx = 0;

    int cnt = 0;
    while(len--)
    {
        char c = getchar();
        if(c == ' ')
        {
            mx = max(mx, cnt);
            cnt = 0;
            continue;
        }
        if(c < 97)
            cnt++;
    }
    mx = max(mx, cnt);

    cout << mx;
}
